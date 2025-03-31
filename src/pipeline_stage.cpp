#include "pipeline_stage.h"

#include "decode_image_stage.h"

#include <string>
#include <stdexcept>

PipelineStage* PipelineStage::process()
{
	this->data = this->process_data();
	this->action = this->get_next_action();
	if (this->action == Action::Done) {
		return this;
	}
	return create_stage(this->action, std::move(this->data), std::move(this->metadata));
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

PipelineStage* PipelineStage::create_stage(PipelineStage::Action action, std::vector<uint8_t>&& data, std::unordered_map<std::string, std::string>&& metadata)
{
	switch (action)
	{
	case PipelineStage::Action::DecodeImage:
		return new DecodeImageStage(action, std::move(data), std::move(metadata));
	case PipelineStage::Action::DecompressData:
		break;
	case PipelineStage::Action::ParseJson:
		break;
	case PipelineStage::Action::Done:
	default:
		throw std::runtime_error("Unimplemented pipeline stage");
	}
}

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

//PipelineStage::Action PipelineStage::get_next_action()
//{
//	std::string& uri = this->metadata.at("uri");
//	size_t last_dot = uri.find_last_of(".");
//	if (last_dot == std::string::npos) {
//		return Action::Done;
//	}
//	std::string_view new_uri = std::string_view(uri).substr(last_dot);
//	PipelineStage::Action action = PipelineStage::get_action_from_uri(new_uri);
//	uri.resize(last_dot);
//	return action;
//}
