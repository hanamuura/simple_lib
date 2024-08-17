#include "matrix.h"
#include <cstdint>
#include <cstdlib>
#include <stdexcept>

template class utils::Matrix<int>;
template class utils::Matrix<uint8_t>;
template class utils::Matrix<char>;
template class utils::Matrix<std::string>;

template <typename T>
utils::Matrix<T>::Matrix(int rows, int cols, T partial_data) {
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<T>(rows * cols, partial_data);
}

template <typename T>
utils::Matrix<T>::Matrix(int rows, int cols, std::vector<T> data) {
    this->rows = rows;
    this->cols = cols;
    this->data = data;
}

template <typename T>
int utils::Matrix<T>::getCols() {
    return this->cols;
}

template <typename T>
int utils::Matrix<T>::getRows() {
    return this->rows;
}

template <typename T>
T utils::Matrix<T>::at(int row, int col) {
    if (row < 0 || row >= this->rows || col < 0 || col >= this->cols)
        throw std::out_of_range("Invalid matrix access: row or column out of bounds");

    return this->data.at(row * this->cols + col);
}

template <typename T>
void utils::Matrix<T>::print() {
    auto demension = this->demensions();
    for(int i = 0; i < demension->height; i++){
        for(int j = 0; j < demension->width; j++){
            std::cout << this->at(i, j);
        }
    }
}

template <typename T>
utils::Demensions* utils::Matrix<T>::demensions() {
    auto demensions = new utils::Demensions(this->getCols(), this->getRows());
    return demensions;
}


template <typename T>
utils::Matrix<T>::~Matrix<T>() = default;

utils::Demensions::Demensions(int height, int width){
    this->height = height;
    this->width = width;
}