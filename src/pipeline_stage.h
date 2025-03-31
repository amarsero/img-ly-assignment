#pragma once

#include <unordered_map>
#include <string>

class PipelineStage {
public:
	enum class Action { DecodeImage, DecompressData, ParseJson, Done };

	Action action;
	PipelineStage* process();

	static PipelineStage::Action get_action_from_uri(const std::string_view uri);
	static PipelineStage* create_stage(PipelineStage::Action action, std::vector<uint8_t>&& data, std::unordered_map<std::string, std::string>&& metadata);
protected:
	std::unordered_map<std::string, std::string> metadata;
	std::vector<uint8_t> data;

	PipelineStage(PipelineStage::Action action, std::vector<uint8_t>&& data, std::unordered_map<std::string, std::string>&& metadata)
		: action(action), data(std::move(data)), metadata(std::move(metadata))
	{
	}

	virtual std::vector<uint8_t> process_data() = 0;
	virtual PipelineStage::Action get_next_action();
};