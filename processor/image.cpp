#include "image.h"
#include <istream>
#include <vector>
#include "errors/enum.h"

bool Processor::rbyte(int& byte) {
    return (byte = this->image->get()) >= 0;
}

bool Processor::rword(int& word) {
    int cc = 0, dd = 0;
    if( (cc = this->image->get()) < 0 || (dd = this->image->get()) < 0 )
        return false;
    word = (cc << 8) + dd;
    return true;
}

bool Processor::scan_dimensions(int& width, int& height) {
    int marker = 0, dummy = 0;

    if ( this->image->get() != 0xFF || this->image->get() != 0xD8 )
        return 0;

    while (true){
        int discarded_bytes = 0;
        this->rbyte(marker);

        while (marker != 0xFF) {
            ++discarded_bytes;
            this->rbyte(marker);
        }

        do this->rbyte(marker); while (marker == 0xFF);

        if (discarded_bytes != 0)
            return 0;
   

        switch (marker){
            case 0xC0: case 0xC1: case 0xC2: case 0xC3: case 0xC5:
            case 0xC6: case 0xC7: case 0xC9: case 0xCA: case 0xCB:
            case 0xCD: case 0xCE: case 0xCF:{
                this->rword( dummy );    
                this->rbyte( dummy );
                this->rword( width );  
                this->rword( height );  
                this->rbyte( dummy );
                return true;
            }

            case 0xDA: case 0xD9:
                return false;

            default: {
                int length;
                this->rword(length);

                if (length < 2)
                    return 0;
                length -= 2;

                for ( ; length > 0; --length)
                    this->rbyte(dummy);
            }
        }
    }
}

Processor::Processor(std::istream image) {
    int w, h;
    std::vector<uint8_t> d;
    if (!this->scan_dimensions(w, h)) error::raise(exceptions::SCAN_FAILED);
    this->width = w;
    this->height = h;
}

Processor::Processor(std::string){}

void Processor::print() {

}

Processor::~Processor() = default;

