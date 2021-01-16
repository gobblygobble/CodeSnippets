#include <iostream>
#include <cstdlib>
#include <vector>   // std::vector
#include <map>      // std::map
#include <utility>  // std::pair
//#include <algorithm>

struct coordinate {
    int x;
    int y;
    int z;
};
typedef struct coordinate coordinate;
// only operator< is required
// but let's also define operator== just for fun
bool operator==(coordinate a, coordinate b) {
    return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z));
}
bool operator<(coordinate a, coordinate b) {
    return ((a.x < b.x) ||
            ((a.x == b.x) && (a.y < b.y)) ||
            ((a.x == b.x) && (a.y == b.y) && (a.z < b.z)));
}

struct partial_sum {
    float value;
    coordinate loc;
};
typedef struct partial_sum partial_sum;

partial_sum ps_create(float value, int x, int y, int z) {
    partial_sum ps;
    ps.value = value;
    coordinate coord {.x = x, .y = y, .z = z};
    ps.loc = coord;

    return ps;
}

int main(int argc, char* argv[])
{
    // GOAL: aggregate the 'value' of the items that have same coordinates

    // make vector with duplicate coordinate items
    std::vector<partial_sum> nonunique_buffer;
    nonunique_buffer.push_back(ps_create(1.0, 1, 1, 1));
    nonunique_buffer.push_back(ps_create(2.0, 2, 2, 2));
    nonunique_buffer.push_back(ps_create(3.0, 3, 3, 3));
    nonunique_buffer.push_back(ps_create(10.0, 1, 1, 1));
    nonunique_buffer.push_back(ps_create(20.0, 2, 2, 2));
    nonunique_buffer.push_back(ps_create(100.0, 1, 1, 1));
    
    // make map to track duplicate items
    std::map<coordinate, float> uniqueMap;
    for (auto& ps : nonunique_buffer) {
        auto result = uniqueMap.insert(std::pair<coordinate, float>(ps.loc, ps.value));
        if (result.second == false) {
            // duplicate key --> add value to existing element
            result.first->second += ps.value;
        }
    }
    
    // print out all elements of uniqueMap to check
    for (auto& elem : uniqueMap) {
        std::cout << "(" 
                  << elem.first.x
                  << ", "
                  << elem.first.y
                  << ", "
                  << elem.first.z
                  << ") holds value: "
                  << elem.second
                  << std::endl;
    }
    
    return 0;
}
