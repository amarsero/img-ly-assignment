#include "pipeline_stage.h"

#include "decode_image_stage.h"
#include "decompress_data_stage.h"
#include "parse_json_stage.h"

#include <string>
#include <stdexcept>

std::vector<uint8_t> PipelineStage::get_result()
{
	return this->data;
}

PipelineStage::Action PipelineStage::get_action_from_uri(const std::string_view uri)
{
	if (uri.ends_with(".jpeg")) {
		return Action::DecodeImage;
	}
	else if (uri.ends_with(".gz")) {
		return Action::DecompressData;
	}
	else if (uri.ends_with(".json")) {
		return Action::ParseJson;
	}
	return Action::Done;
}

// Factory to create the right stage instance
std::unique_ptr<PipelineStage> PipelineStage::create_stage(PipelineStage::Action action, std::vector<uint8_t>&& data, std::unordered_map<std::string, std::string>&& metadata)
{
	switch (action)
	{
	case PipelineStage::Action::DecodeImage:
		return std::make_unique<DecodeImageStage>(action, std::move(data), std::move(metadata));
	case PipelineStage::Action::DecompressData:
		return std::make_unique<DecompressDataStage>(action, std::move(data), std::move(metadata));
	case PipelineStage::Action::ParseJson:
		return std::make_unique<ParseJsonStage>(action, std::move(data), std::move(metadata));
	case PipelineStage::Action::Done:
		std::unreachable();
	default:
		throw std::runtime_error("Unimplemented pipeline stage");
	}
}

PipelineStage::PipelineStage(PipelineStage::Action action, std::vector<uint8_t>&& data, std::unordered_map<std::string, std::string>&& metadata)
	: action(action), data(std::move(data)), metadata(std::move(metadata))
{
}

// Example implementation of a way to get the next action.
// Can be overriden by the pipeline
PipelineStage::Action PipelineStage::get_next_action()
{
	std::string& uri = this->metadata.at("uri");
	size_t last_dot = uri.find_last_of(".");
	if (last_dot == std::string::npos) {
		return Action::Done;
	}
	uri.resize(last_dot);
	return PipelineStage::get_action_from_uri(uri);
}