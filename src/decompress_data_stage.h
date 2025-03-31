#pragma once

#include "pipeline_stage.h"

class DecompressDataStage : public PipelineStage {
protected:
	using PipelineStage::PipelineStage;
	virtual std::vector<uint8_t> process_data();
	DecompressDataStage() = delete;
};