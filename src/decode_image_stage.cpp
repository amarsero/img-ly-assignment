#include "decode_image_stage.h"

#include <iostream>

std::vector<uint8_t> DecodeImageStage::process_data() {
	std::cout << "Decoding image: " + this->metadata.at("uri") + "\n";
	std::vector<uint8_t> create_new_data{ 1, 2, 3 };
	return create_new_data;
}