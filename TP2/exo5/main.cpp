#include <iostream>


int main() {

    char season;
    std::cout << "Veuillez entrer la première lettre d'une saison." << std::endl;
    std::cin >> season;
    std::cout << season;
    std::cout << (uint8_t)season << std::endl;
    season = tolower(season);
    switch(season) {
    case 'p':
        std::cout << "Printemps" << std::endl;
        break;
    case 'a':
        std::cout << "Automne" << std::endl;
        break;
    case (uint8_t)144:
    case 'e':
        std::cout << "Et" << (char)144 << std::endl;
        break;
    case 'h':
        std::cout << "Hiver" << std::endl;
        break;
    default:
        std::cout << "Ce n'est pas une lettre valide!" << std::endl;

    }
    return 0;
}
