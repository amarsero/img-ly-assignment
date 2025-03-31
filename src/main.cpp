#include "compute_pipeline.h"

int main()
{
	ComputePipeline pipeline;

	PipelineStage* stage = pipeline.load("http://image.jpeg.gz");
	while (stage->action != PipelineStage::Action::Done) {
		PipelineStage* newStage{ stage->process() };
		if (newStage != stage) {
			delete stage;
		}
		stage = newStage;
	}

	return 0;
}
