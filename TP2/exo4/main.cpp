//Galaad Martineaux
#include <iostream>

const uint32_t COURT_ABONNEE_ENFANT = 6;
const uint32_t COURT_ABONNEE_ADULTE = 15;

const uint32_t COURT_NONABONNEE_ENFANT = 8;
const uint32_t COURT_NONABONNEE_ADULTE = 18;

const uint32_t LONG_ABONNEE_ENFANT = 10;
const uint32_t LONG_ABONNEE_ADULTE = 18;

const uint32_t LONG_NONABONNEE_ENFANT = 12;
const uint32_t LONG_NONABONNEE_ADULTE = 22;

using namespace std;

int main() {
    char typeSpectacle = 'a', abonne = 'a';
    uint32_t age = 0;
    uint32_t prix;

    while (typeSpectacle != 'c' && typeSpectacle != 'l') {
        cout << "Veuillez entrer le type de spectacle que vous souhaitez regarder. (Entrez 'c' pour court, ou 'l' pour long)." << endl;
        cin >> typeSpectacle;
        typeSpectacle = tolower(typeSpectacle);
    }

    while (age == 0) {
        //Clear std::cin so that the program does not loop indefinitely.
        cin.clear();
        fflush(stdin);
        //Making a function to translate a std::string in an uint32_t
        //and verifying its validity is out of the scope of this exercise
        //but it would be a better option.

        cout << "Veuillez entrer l'" << (char)131 << "ge du spectateur." << endl;
        cin >> age;

    }

    while(abonne != 'o' && abonne != 'n') {
        cout << "Etes-vous abonn" << (char)130 << " ? (o ou n)" << endl;
        cin >> abonne;
        abonne = tolower(abonne);
    }

    //Enfant
    if (age < 18) {
        //Court ou long
        if (typeSpectacle == 'c')
        {
            //Abonné ou non
            if (abonne == 'o')
                prix = COURT_ABONNEE_ENFANT;
            else
                prix = COURT_NONABONNEE_ENFANT;
        }
        else
        {
            //Abonné ou non
            if (abonne == 'o')
                prix = LONG_ABONNEE_ENFANT;
            else
                prix = LONG_NONABONNEE_ENFANT;
        }
    }
    //Adulte
    else {
        //Court ou long
        if (typeSpectacle == 'c')
        {
            //Abonné ou non
            if (abonne == 'o')
                prix = COURT_ABONNEE_ADULTE;
            else
                prix = COURT_NONABONNEE_ADULTE;
        }
        else
        {
            //Abonné ou non
            if (abonne == 'o')
                prix = LONG_ABONNEE_ADULTE;
            else
                prix = LONG_NONABONNEE_ADULTE;
        }
    }

    cout << prix << endl;
    return 0;
}
/*
Type    Âge     Abonné      Résultat
c       15      o           6
l       15      o           10
c       20      o           15
l       20      o           18
c       20      n           18
l       20      n           11
c       15      n           8
l       15      n           12
*/
