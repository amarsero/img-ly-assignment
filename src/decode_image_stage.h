#pragma once

#include "pipeline_stage.h"

class DecodeImageStage : public PipelineStage {
protected:
	virtual std::vector<uint8_t> process_data();
	using PipelineStage::PipelineStage;
};