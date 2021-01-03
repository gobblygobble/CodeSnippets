#include "2d-vector.hpp"

int main(int argc, char **argv) {
    // create 3x4 vector
    vector_2d v2d = Vector2D(3, 4);
    PrintVector_2d(v2d);
    // set element in vector
    SetElement_2d(v2d, 100, 2, 2);
    PrintVector_2d(v2d);
    // get element of vector
    std::cout << GetElement_2d(v2d, 2, 2) << std::endl;
    
    return 0;
}
