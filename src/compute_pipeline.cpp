#include "compute_pipeline.h"

#include <iostream>

PipelineStage* ComputePipeline::load(const std::string& uri)
{
	std::vector<uint8_t> bytes = get_bytes_from_uri(uri);
	PipelineStage* stage = PipelineStage::create_stage(
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
