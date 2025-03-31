#pragma once

#include <string>
#include <vector>

#include "pipeline_stage.h"

class ComputePipeline {
public:
	PipelineStage* load(const std::string& uri);
	PipelineStage* process(PipelineStage&& action);
private:
	std::vector<uint8_t> get_bytes_from_uri(const std::string& uri);
	std::vector<PipelineStage::Actions> get_uri_actions(const std::string& uri);
	PipelineStage* create_stage(PipelineStage::Actions action, std::vector<uint8_t> bytes);
};
