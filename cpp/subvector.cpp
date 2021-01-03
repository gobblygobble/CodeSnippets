#include <vector>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    std::vector<int> bigvector;
    for (int i = 0; i < 10; ++i)
        bigvector.push_back(i);
    int boundary = 5;

    std::vector<int> subvector1 = std::vector<int>(bigvector.begin(), bigvector.begin() + boundary);
    std::vector<int> subvector2 = std::vector<int>(bigvector.begin() + boundary, bigvector.end());
    std::cout << "subvectors of <0 ~ 9> with boundary 5):" << std::endl;
    for (std::vector<int>::iterator it = subvector1.begin(); it != subvector1.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
    for (std::vector<int>::iterator it = subvector2.begin(); it != subvector2.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
    
    return 0;
}
