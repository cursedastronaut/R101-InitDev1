#include "calcul.h"

bool estPositif(int input) {
    return (input > 0);
}

uint32_t somme(int input) {
    uint32_t sum = 0;
    for (uint32_t i = 0; (int)i <= input; ++i)
        sum += i;
    return sum;
}

uint32_t facto(int input) {
    uint32_t facto = 1;
    for (uint32_t i = 1; (int)i <= input; ++i)
        facto *= i;
    return facto;
}

vector<uint32_t> divis(int input) {
    vector<uint32_t> liste;
    for (uint32_t i = 1; (int)i <= input; ++i)
        if (input % i == 0)
            liste.push_back(i);
    return liste;
}
