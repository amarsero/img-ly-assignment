#include "parse_json_stage.h"

#include <iostream>

std::vector<uint8_t> ParseJsonStage::process_data() {
	std::cout << "Parsing json: " + this->metadata.at("uri") + "\n";
	std::vector<uint8_t> create_new_data{ 1, 2, 3 };
	return create_new_data;
}