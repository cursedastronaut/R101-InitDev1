#include <iostream>

int main() {
    uint64_t nb;
    std::cin >> nb;
    uint64_t modulo;
    modulo = nb % 10;
    uint8_t i;
    for (i = 1; modulo == 0 ; ++i)
    {
        modulo %= 10;
    }
    std::cout << i << std::endl;
}