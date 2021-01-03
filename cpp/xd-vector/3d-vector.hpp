#ifndef XD_VECTOR_3D_VECTOR
#define XD_VECTOR_3D_VECTOR

#include <iostream>
#include <vector>

typedef std::vector<std::vector<std::vector<int> > > vector_3d;

vector_3d Vector3D(int z, int y, int x) {
    vector_3d v;
    for (int i = 0; i < z; ++i) {
        std::vector<std::vector<int> > temp_2d;
        for (int j = 0; j < y; ++j) {
            std::vector<int> temp(x);
            //std::vector<int> temp(x, i+j);
            temp_2d.push_back(temp);
        }
        v.push_back(temp_2d);
    }
    return v;
}

void PrintVector_3d(vector_3d v) {
    std::cout << "3D vector consists of: " << std::endl;
    for (auto& zit : v) {
        for (auto& yit : zit) {
            for (auto& xit : yit) {
                std::cout << xit << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
}

int GetElement_3d(vector_3d& v, int z, int y, int x) {
    auto zit = v.begin() + z;
    auto yit = (*zit).begin() + y;
    auto xit = (*yit).begin() + x;

    return *(xit);
}

void SetElement_3d(vector_3d& v, int value, int z, int y, int x) {
    auto zit = v.begin() + z;
    auto yit = (*zit).begin() + y;
    auto xit = (*yit).begin() + x;

    *xit = value;
}


#endif // XD_VECTOR_3D_VECTOR
