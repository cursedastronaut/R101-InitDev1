#include <iostream>

bool isPrime(uint32_t n);

int main() {
    uint32_t n;
    std::cout << "Enter a valid positive number above 1" << std::endl;
    std::cin >> n;

    if (isPrime(n))
        std::cout << "\nThe inputted number is prime\n";
    else
        std::cout << "\nThe inputted number is NOT prime\n";

    return 0;
}

bool isPrime(uint32_t n) {

    if (n % 2 == 0) return false;
    for (uint32_t i = 3; i < n / 2; i+=2)
        if (n % i == 0)
            return false;

    return true;
}
