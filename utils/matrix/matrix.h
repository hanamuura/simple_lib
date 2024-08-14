#include <iostream>
#include <vector>


//two pointer implemention of matrix have no destructor 
namespace utils {
    template <typename T>
    class Matrix;
}

template <typename T>
class Matrix {
private:
    std::vector<T> data;
    int rows;
    int cols;
public:
    Matrix (std::vector<T> data);
    ~Matrix ();

    int& at(int row, int col);
    int at(int row, int col) const;
    int getRows() const;
    int getCools() const;
    void print();
};