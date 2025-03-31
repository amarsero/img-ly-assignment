#pragma once

#include <string>
#include <vector>

#include "pipeline_stage.h"

class ComputePipeline {
public:
	PipelineStage* load(const std::string& uri);
private:
	std::vector<uint8_t> get_bytes_from_uri(const std::string& uri);
};
