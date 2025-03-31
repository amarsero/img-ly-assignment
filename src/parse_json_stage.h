#pragma once

#include "pipeline_stage.h"

class ParseJsonStage : public PipelineStage {
protected:
	using PipelineStage::PipelineStage;
	virtual std::vector<uint8_t> process_data();
};