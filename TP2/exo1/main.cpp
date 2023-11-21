#include <iostream>

using namespace std;

int main() {
    float a, b;

    cin >> a >> b;
    cout << (a <= b ? "ordre croissant" : "ordre decroissant") << endl;


    return 0;
}
//Cas:
//  1 et 5.5 -> ordre croissant
//  1.5 et 5 -> ordre croissant
//  5.5 et 2.1 -> ordre décroissant
