#include "compute_pipeline.h"

int main()
{
	ComputePipeline pipeline ("http://image.jpeg.gz");
	std::vector<uint8_t> result = pipeline.get_result();

	// You can also reuse the pipeline with new data
	pipeline.load("bundle://db.json.gz");
	pipeline.process_fully();

	auto second_result = pipeline.get_result();

	pipeline.load("file://db.jpeg");
	// Or call process multiple times, like a coroutine
	while(pipeline.process()) {}
}
