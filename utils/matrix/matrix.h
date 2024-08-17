#include <iostream>
#include <vector>


//two pointer implemention of matrix have no destructor 
namespace utils {
    struct Demensions {
        int width;
        int height;
        Demensions(int width, int height);
    };
    template <typename T>
    class Matrix {
    private:
        std::vector<T> data;
        int rows;
        int cols;
    public:
        //default matrix constructor
        Matrix (int rows, int cols, std::vector<T> data);
        //matrix full of 'partial_data' values
        Matrix (int rows, int cols, T partial_data); 
        ~Matrix ();

        T at(int row, int col);
        int getRows();  
        int getCols();
        void print();
        utils::Demensions* demensions();
    };
}



