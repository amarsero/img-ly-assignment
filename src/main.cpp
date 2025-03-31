#include "compute_pipeline.h"

int main()
{
	ComputePipeline pipeline;

	PipelineStage* stage = pipeline.load("http://image.json.gz");
	while (!stage->actions.empty()) {
		stage = pipeline.process(std::move(*stage));
	}

	return 0;
}
