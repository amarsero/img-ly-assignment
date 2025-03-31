#pragma once

#include "pipeline_stage.h"

class DecodeImageStage : public PipelineStage {
public:
	using PipelineStage::PipelineStage;
	virtual std::vector<uint8_t> process_data();
	DecodeImageStage() = delete;
};