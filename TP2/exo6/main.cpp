#include <iostream>

int main() {
    std::string suffix;
    uint32_t number;

    std::cout << "Enter a number" << std::endl;
    std::cin >> number;
    std::cout << number%10 << std::endl;

    switch (number%10) {
    case 1:
        suffix = "st";
        break;
    case 2:
        suffix = "nd";
        break;
    case 3:
        suffix = "rd";
        break;
    default:
        suffix = "th";
        break;
    }

    std::cout << number << suffix << std::endl;
    return 0;
}
