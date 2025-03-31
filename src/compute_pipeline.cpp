#include "compute_pipeline.h"

#include <iostream>

ComputePipeline::ComputePipeline(std::string&& uri)
	: pipeline(_load(std::move(uri)))
{
}

void ComputePipeline::process_fully()
{
	while (!is_done()) {
		process();
	}
}

bool ComputePipeline::process()
{
	if (!is_done()) {
		std::vector<uint8_t> new_data = this->pipeline->process_data();
		this->pipeline->action = this->pipeline->get_next_action();
		if (this->pipeline->action == PipelineStage::Action::Done) {
			return true;
		}
		this->pipeline = PipelineStage::create_stage(this->pipeline->action, std::move(new_data), std::move(this->pipeline->metadata));
	}
	return false;
}

std::vector<uint8_t> ComputePipeline::get_result()
{
	process_fully();
	return this->pipeline->get_result();
}

bool ComputePipeline::is_done()
{
	return this->pipeline->action == PipelineStage::Action::Done;
}

void ComputePipeline::load(std::string&& uri)
{
	this->pipeline = _load(std::move(uri));
}

std::unique_ptr<PipelineStage> ComputePipeline::_load(std::string&& uri)
{
	std::vector<uint8_t> bytes = get_bytes_from_uri(uri);
	std::unique_ptr<PipelineStage> stage = PipelineStage::create_stage(
		PipelineStage::get_action_from_uri(uri),
		std::move(bytes),
		{ {"uri", uri} }
	);
	return stage;
}

// Mockup
void download(const std::string& method, const std::string& uri, std::vector<uint8_t>& data) {
	std::cout << method << ": " << uri << "\n";
	data.push_back(1);
}

std::vector<uint8_t> ComputePipeline::get_bytes_from_uri(const std::string& uri)
{
	std::vector<uint8_t> data;
	if (uri.starts_with("file://")) {
		download("Read file", uri, data);
	}
	else if (uri.starts_with("http://")) {
		download("Downloading file", uri, data);
	}
	else if (uri.starts_with("bundle://")) {
		download("Downloading asset", uri, data);
	}
	else {
		throw std::runtime_error("Unimplemented storage type");
	}
	// NRVO
	return data;
}
