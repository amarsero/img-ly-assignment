#pragma once

#include "pipeline_stage.h"

class DecodeImageStage : public PipelineStage {
protected:
	using PipelineStage::PipelineStage;
	virtual std::vector<uint8_t> process_data();
	DecodeImageStage() = delete;
};