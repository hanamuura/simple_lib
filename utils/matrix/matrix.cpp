#include "matrix.h"
#include <stdexcept>

template <typename T>
Matrix<T>::Matrix(int rows, int cols, T partial_data) {
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<T>(rows * cols, partial_data);
}

template <typename T>
Matrix<T>::Matrix(int rows, int cols, std::vector<T> data) {
    this->rows = rows;
    this->cols = cols;
    this->data = data;
}

template <typename T>
int Matrix<T>::getCols() {
    return this->cols;
}

template <typename T>
int Matrix<T>::getRows() {
    return this->rows;
}

template <typename T>
T Matrix<T>::at(int rows, int cols) {
    if(rows > this->rows || cols > this->cols)
        throw std::out_of_range( "you dumb" );//rewrite message log
    return this->data.at( ( rows + 1 ) * cols );
}   

template <typename T>
void print() {
    std::cout << "hahahahahahahahahahahahahahahahahahahaha";
}