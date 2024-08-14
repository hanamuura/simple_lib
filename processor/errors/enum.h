#include <iostream>

enum exceptions {
    SCAN_FAILED,
};

namespace error {
    void raise(exceptions error);
}