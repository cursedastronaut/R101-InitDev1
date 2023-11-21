// HBM,JL 2023
// gestion d'une equipe de sportives : equipe de France de football feminin 2023
// g++ -std=c++14
#include "main.h"

using namespace std;


int main() {
    //vector<string> equipe = {"DURAND","BACHA","RENARD","GEYORO","DIANI","SOMMER"};

    vector<string> equipe = {};

    b_part(equipe);
    c_part(equipe);
    d_part(equipe);
    e_part(equipe);
    int next = f_part(equipe);
    if (next != 1)
        g_part(equipe, next);
    h_part(equipe);

    return 0;
}

void clearIn() {
    /*Through my various checks, this is not that bad.
    It actually seems very common to do. What I saw in
    the email could not handle the user inputting a string*/
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
