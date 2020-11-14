#include <iostream>

int main()
{

    std::cout << "Hello world!" << std::endl;
    return 0;
}

std::vector<std::vector<float>> initialiseMatrix(unsigned height, unsigned width) {
    return std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
}
