#pragma once

#include <memory>
#include <string>
#include <vector>

#include "pipeline_stage.h"

/// <summary>
/// Represents a full pipeline of actions to perform on a resource loaded from an uri
/// </summary>
class ComputePipeline {
public:
	/// <summary>
	/// Loads a resource from an uri to be processed
	/// </summary>
	ComputePipeline(std::string&& uri);
	/// <summary>
	/// Processes all the actions until it is done
	/// </summary>
	void process_fully();
	/// <summary>
	/// Processes one action
	/// </summary>
	/// <returns>Returns true if it is done</returns>
	bool process();
	/// <summary>
	/// Returns the result of the pipeline. 
	/// It should be only called once, since it moves the data from the pipeline.
	/// The pipeline can be reused with load();
	/// </summary>
	/// <returns></returns>
	std::vector<uint8_t> get_result();
	/// <summary>
	/// Returns if all the actions where processed
	/// </summary>
	/// <returns>Returns true if it is done</returns>
	bool is_done();
	/// <summary>
	/// Loads a new resource to process. 
	/// </summary>
	void load(std::string&& uri);
private:
	std::unique_ptr<PipelineStage> _load(std::string&& uri);
	std::unique_ptr<PipelineStage> pipeline;
	std::vector<uint8_t> get_bytes_from_uri(const std::string& uri);
};
