/*
    GALAAD MARTINEAUX
    TP-1K   13/10/2023
*/
#include <iostream>
using namespace std;
const int SUP = 10;
const int MAXESSAIS = 4;

//Main function
int main() {
    int nombre, multiple;
    int essais = 1;
    cout << "Donne-moi un nombre positif plus petit que 10" << endl;
    cin >> nombre;

    cout << "Bien. maintenant donne-moi un multiple de " << nombre << endl;
    cin >> multiple;
    while (multiple % nombre != 0 && essais < MAXESSAIS) {
        cout << multiple << " n'est pas un multiple de " << nombre << ". Essaie encore:" << endl;
        essais++;
        cin >> multiple;


    }

    if (essais >= MAXESSAIS)
        cout << "Dommage, " << multiple << " n'est toujours pas un multiple de "
        << nombre << ". Relance le programme quand tu voudras rejouer!" << endl;
    else
        cout << "Bravo ! Tu as trouve un multiple de " << nombre << " en "
        << essais << " essais." << endl;
    return 0;
}
