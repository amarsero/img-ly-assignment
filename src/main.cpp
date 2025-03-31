#include "compute_pipeline.h"

int main()
{
	ComputePipeline pipeline;

	PipelineStage* stage = pipeline.load("http://image.jpeg");
	while (stage->action != PipelineStage::Action::Done) {
		stage->process();
	}

	return 0;
}
