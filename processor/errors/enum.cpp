#include "enum.h"
#include <stdexcept>

void error::raise(exceptions error){
    switch (error) {
        case SCAN_FAILED:
            throw std::runtime_error("scan failed");
            break;
    }
}