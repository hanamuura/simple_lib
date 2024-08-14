#include <iostream>
#include <fstream> 
#include <system_error>
#include <vector>
#include <cstdint>

namespace image {
    class Processor;
}

class Processor {
private:
    std::istream& image;
    std::vector<uint8_t> data;
    std::vector<uint8_t> meta;
    int width;
    int height;
public:
    bool scan(int& image_width, int& image_height);
    inline bool rbyte(int& byte);
    inline bool rword(int& word);
    Processor(std::istream &image);
    ~Processor();
    void print();
    //TODO: implement later
    // void resize(int new_width, int new_height);
    std::vector<uint8_t> get_data();
    Processor change();
};
