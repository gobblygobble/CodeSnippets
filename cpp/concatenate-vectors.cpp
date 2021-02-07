#include <iostream>
#include <vector>

int main (int argc, char *argv[])
{
    std::vector<int> aggregated_vector;
    std::vector<std::vector<int> > little_vectors = {{1, 2, 3, 4, 5},
                                                     {6, 7, 8, 9, 10},
                                                     {11, 12, 13, 14, 15},
                                                     {16, 17, 18, 19, 20}};
    // unnecessary, but this may help speed up the process for huge vectors
    // 1. get total size of all vectors and reserve capacity
    unsigned int total_size = 0;
    for (auto& vec : little_vectors) {
        total_size += vec.size();
    }
    aggregated_vector.reserve(total_size);
    
    // 2 - (a) copy to aggregated_vector with std::vector::insert()
    for (auto& vec : little_vectors) {
        aggregated_vector.insert(
            aggregated_vector.end(), // dest.to
            vec.begin(), // src.from
            vec.end() // src.to
        );
    }
    /*
    // 2 - (b) move to aggregated_vector with std::make_move_iterator()
    for (auto& vec : little_vectors) {
        aggregated_vector.insert(
            aggregated_vector.end(),
            std::make_move_iterator(vec.begin()),
            std::make_move_iterator(vec.end())
        );
    }
    */
    // 3. do experiments
    // 3 - (a) check if all moved correctly
    std::cout << "=============== exp A ==============="
              << std::endl;
    std::cout << "after move, destination now holds "
              << aggregated_vector.size()
              << " elements"
              << std::endl;
    // 3 - (b) check source size
    std::cout << "=============== exp B ==============="
              << std::endl;
    std::cout << "after move, source now holds "
              << little_vectors.size()
              << " vectors, each holding: ";
    for (auto& vec : little_vectors) {
        std::cout << vec.size() << " ";
    }
    std::cout << "elements each" << std::endl;
    // 3 - (c) delete source and see if values are still there
    std::cout << "=============== exp C ==============="
              << std::endl;
    for (auto& vec : little_vectors) {
        vec.clear();
    }
    little_vectors.clear();
    std::cout << "after deleting source, destination now holds "
              << aggregated_vector.size()
              << " elements, whose values are:"
              << std::endl;
    for (int elem : aggregated_vector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}
