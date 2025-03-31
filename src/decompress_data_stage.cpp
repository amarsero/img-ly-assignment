#include "decompress_data_stage.h"

#include <iostream>

std::vector<uint8_t> DecompressDataStage::process_data() {
	std::cout << "Decompressing data: " + this->metadata.at("uri") + "\n";
	std::vector<uint8_t> create_new_data{ 1, 2, 3 };
	return create_new_data;
}