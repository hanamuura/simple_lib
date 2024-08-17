#include <iostream>
#include <fstream> 
#include <optional>
#include <system_error>
#include <vector>
#include <cstdint>

namespace image {
    class Processor;
}

class Processor {
private:
    std::optional<std::istream> image;
    std::vector<std::vector<uint8_t>> data;
    // TODO: impl meta declaration
    // std::vector<uint8_t> meta;
    int width;
    int height;
public:
    bool scan_dimensions(int& image_width, int& image_height);
    bool scan_data(std::vector<std::vector<uint8_t>>& data);
    inline bool rbyte(int& byte);
    inline bool rword(int& word);
    Processor(std::istream image);
    Processor(std::string);
    ~Processor();
    void print();
    //TODO: implement later
    // void resize(int new_width, int new_height);
    std::vector<uint8_t> get_data();
    Processor change();
};

