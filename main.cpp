#include <iostream>
#include <fstream> 
#include <vector>
#include <cstdint>
#include "processor/image.h"


void printHex(const std::vector<uint8_t>& data){
    for (size_t i = 0; i < data.size(); i++){
        std::cout << std::hex << static_cast<int>(data[i]) << " ";
        if ((i + 1) % 16 == 0){
            std::cout << std::endl;
        }
    }
}

int main() {
    int width = 0, height = 0;
    std::string filename = "test.jpg";
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "error open file";
    }

    return 0;
}