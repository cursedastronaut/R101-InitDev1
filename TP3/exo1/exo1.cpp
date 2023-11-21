#include <iostream>

int main() {
    uint64_t n;
    std::cout << "Veuillez entrer un nombre:\n";
    std::cin >> n;

    for (uint64_t i = 2; i < n; ++i) //for(init; tant que; itération)
        if (n%i == 0)
            std::cout << i << " est diviseur de " << n << std::endl;

    return 0;
}