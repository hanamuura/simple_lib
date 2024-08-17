#include <iostream>
#include <vector>
#include <cstdint>
#include "utils/matrix/matrix.h"

void printHex(const std::vector<uint8_t>& data){
    for (size_t i = 0; i < data.size(); i++){
        std::cout << std::hex << static_cast<int>(data[i]) << " ";
        if ((i + 1) % 16 == 0){
            std::cout << std::endl;
        }
    }
}

int main() {
    // int width = 0, height = 0;
    // std::string filename = "test.jpg";
    // std::ifstream fin(filename);
    std::vector<int> data = {1,2,3,4,5,6,7,8,9};
    auto matrix = utils::Matrix<int>(3, 3, data);

    auto matrix_demensions = matrix.demensions();

    std::cout << matrix_demensions->height;
    for (int i = 0; i < matrix_demensions->height; i++) {
        for (int j = 0; j < matrix_demensions->width; j++) {
            std::cout << matrix.at(i, j) << " ";
        }
        std::cout << std::endl;  
    }

    return 0;
}