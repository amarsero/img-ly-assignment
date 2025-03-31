#include "decode_image_stage.h"

#include <iostream>

std::vector<uint8_t> DecodeImageStage::process_data() {
	std::cout << "Decoding image\n";
	return this->data;
}