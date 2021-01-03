#include "3d-vector.hpp"

int main(int argc, char **argv) {
    // create 2x3x4 vector
    vector_3d v3d = Vector3D(2, 3, 4);
    PrintVector_3d(v3d);
    // set element in vector
    SetElement_3d(v3d, 100, 1, 1, 1);
    PrintVector_3d(v3d); 
    // get element of vector
    std::cout << GetElement_3d(v3d, 1, 1, 1) << std::endl;
    
    return 0;
}
