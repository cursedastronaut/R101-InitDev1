#include <iostream>
#include <vector>

int main() {
    int max = -1, min = -1;
    std::vector<int> array;
    std::cout << "Max: Please enter a strictly positive number." << std::endl;
    std::cin >> max;
    while (max <= 0) {
        std::cout << "Error: You must enter a strictly positive number. Please retry." << std::endl;
        std::cin >> max;
    }

    std::cout << "Min Please enter a strictly positive number." << std::endl;
    std::cin >> min;

    while (min <= 0 || min >= max) {
        std::cout << "Error: You must enter a strictly positive number, that is inferior to max. Please retry." << std::endl;
        std::cin >> min;
    }
    


    for (int i = max-1; i < max && i > min; --i)
        if (i%7 == 0)
            array.push_back(i);

    for (size_t i = 0; i < array.size(); ++i)
        std::cout   << array[i] << ((size_t)(i+1) == array.size() ? "." : ", ")
                    << (((i+1) % 10) == 0 ? "\n" : "");

    return 0;
}