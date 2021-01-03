#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > vector_2d;

vector_2d Vector2D(int y, int x) {
    vector_2d v;
    for (int i = 0; i < y; ++i) {
        std::vector<int> temp(x);
        //std::vector<int> temp(x, i);
        v.push_back(temp);
    }
    return v;
}

void PrintVector_2d(vector_2d v) {
    //std::vector<int> temp;
    std::cout << "2D vector consists of: " << std::endl;
    for (auto& yit : v) {
        for (auto& xit : yit) {
            std::cout << xit;
        }
        std::cout << std::endl;
    }
}

int GetElement_2d(vector_2d& v, int y, int x) {
    auto yit = v.begin() + y;
    auto xit = (*yit).begin() + x;

    return *(xit);
}

void SetElement_2d(vector_2d& v, int value, int y, int x) {
    auto yit = v.begin() + y;
    auto xit = (*yit).begin() + x;

    *xit = value;
}

int main(int argc, char **argv) {
    // create 3x4 vector
    vector_2d v2d = Vector2D(3, 4);
    // set element in vector
    SetElement_2d(v2d, 100, 2, 2);
    // get element of vector
    std::cout << GetElement_2d(v2d, 2, 2) << std::endl;
    
    return 0;
}
