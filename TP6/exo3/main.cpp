/*
    GALAAD MARTINEAUX
    BUT1 - TP1K
    17/10/2023
*/

#include "calcul.h"
#include "menu.h"
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Veuillez entrer un nombre strictement positif." << endl;

    while (!(cin >> n) || !estPositif(n) || n > 10) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Veuillez entrer un nombre strictement positif inferieur ou egal a 10." << endl;
    }
    bool shouldQuit = false;
    while (!shouldQuit) {
        switch(menu()) {
            case FACT:
                cout << "La factorielle de " << n << " est " << facto(n) << endl;
                break;

            case SOM:
                cout << "La somme est " << somme(n) << endl;
                break;

            case DIV:
                { //Or just use -fpermissive
                    vector<uint32_t> liste_de_diviseurs = divis(n);
                    for (size_t i = 0; i < liste_de_diviseurs.size(); ++i)
                        cout << liste_de_diviseurs[i] << " est diviseur de "
                        << n << endl;
                }
                break;

            case QUIT:
                shouldQuit = true;
                break;
            default:
                cout << "Invalid input, please retry." << endl;
        }
    }
    return 0;
}
/*
    Jeu d'essai

    Entrée de n:
        NORMAL      NÉGATIF     NUL     OVERFLOW    TYPE INCORRECT  OVER 10
        n = 5       n = -1      0       n = 4 294   n = "std"       n = 11
                                        967 296

    Résultat
        Le prog-    Rééssayez   Rééssa- Rééssayez   Rééssayer       Rééssayez
        yez                     yez
        -gramme
        continue.


    Pour la suite, n ne peut être ni nul, ni négatif, ni trop grand, ni
    d'un mauvais type, ni supérieur à dix.

            1   2   3   4   5   6   7       8       9       10
    Facto:  1   2   6   24  120 720 5040    40320   362880  3628800
    Somme:  1   3   6   10  15  21  28      36      45      55

    Divis:  1   1   1   1   1   1   1       1       1       1
                2   3   2   5   2   7       2       3       2
                        4       3           3       9       5
                                6           4               10
*/
