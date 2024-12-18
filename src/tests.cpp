#include <iostream>
#include <assert.h>
#include "collection.h"


bool test(int test_id) {
    switch (test_id) {
        case 1: {

            break;
        }
    
        default:
            return false;
    }
    return true;
}

int main() {
    int testid = 0;
    while(test(++testid)) {
        std::cout << "Test " << testid << " passed" << std::endl;
    }
    std::cout << "All tests passed" << std::endl;
}
