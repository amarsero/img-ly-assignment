#include "compute_pipeline.h"

#include <iostream>

PipelineStage* ComputePipeline::load(const std::string& uri)
{
	std::vector<uint8_t> bytes = get_bytes_from_uri(uri);
	std::vector<PipelineStage::Actions> types = get_uri_actions(uri);
	PipelineStage* stage = create_stage(types.back(), bytes);
	stage->actions = types;
	return stage;
}

PipelineStage* ComputePipeline::process(PipelineStage&& action)
{
	return nullptr;
}

std::vector<uint8_t> ComputePipeline::get_bytes_from_uri(const std::string& uri)
{
	std::vector<uint8_t> data;
	if (uri.starts_with("file://")) {
		download("read file", uri, data);
	}
	else if (uri.starts_with("http://")) {
		download("downloading file", uri, data);
	}
	else if (uri.starts_with("bundle://")) {
		download("downloading asset", uri, data);
	}
	else {
		throw std::runtime_error("Unimplemented storage type!");
	}
	// NRVO
	return data;
}

std::vector<PipelineStage::Actions> ComputePipeline::get_uri_actions(const std::string& uri)
{
	return std::vector<PipelineStage::Actions>();
}

PipelineStage* ComputePipeline::create_stage(PipelineStage::Actions action, std::vector<uint8_t> bytes)
{
	return nullptr;
}

// Mockup
 void download(const std::string& method, const std::string& uri, std::vector<uint8_t> data) {
	std::cout << method << ": " << uri << "\n";
	data.push_back(1);
}