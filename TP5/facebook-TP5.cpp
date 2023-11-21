/*
    GALAAD MARTINEAUX - TP1K
    11 / 10 / 2023                                                                                                                                      10 / 11 / 주체112
*/

// JL/HBM  2023
// vecteurs 2 dimensions
// les lignes et les colonnes representent des personnes
// chaque case (i,j) contient  un booleen
// indiquant si i et j sont des amis


#include <iostream>
#include <vector>
#include <limits>
#define dis_a_lutilisateur cout
using namespace std;
const size_t NUMBER_OF_PERSON = 4;

void draw(vector <vector <bool> > &amis, vector<string> &names, bool showSelf);
uint32_t findNumofFriends(vector <vector <bool> > &amis, size_t person);
void clearIn();

int main(){
    //Friend matrix
    vector <vector <bool> >  amis(NUMBER_OF_PERSON, vector<bool>(NUMBER_OF_PERSON, false));  // le reseau des amis.
    //question 8:
    vector <string> name;
    name.push_back("Pimprenelle");
    name.push_back("Bernadette");
    name.push_back("Nicolas");
    name.push_back("Azalee");

    //Checks if amis matrix dimensions match, and if its size is not zero.
    if (amis.size() == 0 || amis.size() != amis[0].size()) {
        cout << "ERROR: amis vector is either empty or both dimensions have different sizes." << endl;
        return 1;
    }

    //Checks that the amis matrix first dimension's size and name vector's size match
    if (amis.size() != name.size()) {
        cout << "ERROR: amis vector does not have the same size as name vector" << endl;
        return 1;
    }

    // Question 1 : initialiser le reseau. Toutes les cases avec false sauf celles de la diagonale (une personne est amie avec elle-meme)
    for (size_t i = 0; i < NUMBER_OF_PERSON; ++i) {
        amis[i][i] = true;
    }

    //Question 2 : Afficher le contenu du réseau sous la forme présentée ci-dessus (une ligne par personne
    // contenant : “la personne X est amie avec : Z X Y”).
    // Question 3:  Modifier pour n’afficher que les amis autres que soi-même.
    // ATTENTION : préférez faire 2 boucles successives plutôt qu’une boucle avec un test sur l’indice…
    dis_a_lutilisateur << "Q1, Q2 and Q8)\n    Content of tab amis:" << endl;
    draw(amis, name, true);
    cout << "Q3)\n  Content of tab amis WITHOUT showing persons being friend with themselves:" << endl;
    draw(amis, name, false);
    //Question 4
    cout << "Q4)\n  You will enter two numbers. One corresponding to the first user, and the second corresponding to another. They will become friend." << endl;
    char keepOn = 'o';
    while (keepOn == 'o') {
        uint32_t input[2];
        for (uint8_t i = 0; i < 2; ++i) {
            cout << "   Please enter a number between 0 and " << NUMBER_OF_PERSON -1 << endl;
            while (!(cin >> input[i]) || input[i] > NUMBER_OF_PERSON)
            {
                clearIn();
                cout << "   Incorrect entry. Please enter a number between 0 and " << NUMBER_OF_PERSON -1 << endl;
            }
        }
        amis[input[0]][input[1]] = true;
        amis[input[1]][input[0]] = true;
        keepOn = 'k';
        cout << endl << "   Wanna continue making friends ? ('o' for yes, 'n' for no)" << endl;
        while (!(cin >> keepOn) || (keepOn != 'o' && keepOn != 'n'))
        {
            clearIn();
            cout << "   Incorrect input. Please enter 'o' or 'n'." << endl;
        }
    }

    draw(amis, name, true);


    //Question 5
    cout << "Q5)" << endl;
    size_t mostFriend = 0;
    uint32_t lastFriendNum = 0;
    for (size_t i = 0; i < amis.size(); ++i)
    {
        uint32_t friendNumber = findNumofFriends(amis, i);
        if (lastFriendNum < friendNumber) {
            mostFriend = i;
            lastFriendNum = friendNumber;
        }
    }
    cout << "   Person " << mostFriend << " has the most friends with " << lastFriendNum
        << " friends (themselves included)." << endl;

    //Question 6
    cout << "Q6)\n  Please enter two people to check their common friends." << endl;
    uint32_t input[2];
    for (uint8_t i = 0; i < 2; ++i) {
        cout << "Please enter a number between 0 and " << NUMBER_OF_PERSON -1 << endl;
        while (!(cin >> input[i]) || input[i] > NUMBER_OF_PERSON)
        {
            clearIn();
            cout << "Incorrect entry. Please enter a number between 0 and " << NUMBER_OF_PERSON -1 << endl;
        }
    }

    //Displays all the common friends between the two inputted user id
    cout << endl << "Person " << input[0] << " and " << input[1]
        << " have as common friends : ";
    for (size_t j = 0; j < amis[input[0]].size() && j < amis[input[1]].size(); ++j) {
        if (amis[input[0]][j] && amis[input[1]][j])
            cout << " " << j << " ";
    }
    cout << endl;


    //Question 7
    bool correct = true;
    for (size_t i = 0; i < amis.size() && !correct; ++i) {
        for (size_t j = 0; j < amis[i].size(); ++j) {
            if (correct && amis[i][j]) {
                correct = amis[j][i];
            }
        }
    }
    cout << "Q7)\n  The tab amis is " << (correct ? "correctly" : "incorrectly") << " made." << endl;


    return 0;
}

void draw(vector <vector <bool> > &amis, vector <string> &names, bool showSelf) {
    for (size_t i = 0; i < amis.size(); ++i) {
        cout << endl << "La personne " << names[i] << " est amie avec : ";
        for (size_t j = 0; j < amis[i].size(); ++j) {
            if (amis[i][j] && (showSelf || i != j))
                cout << " " << j;
        }
    }
    cout << endl;
}

uint32_t findNumofFriends(vector <vector <bool> > &amis, size_t person) {
    uint32_t sum = 0;
        for (size_t j = 0; j < amis[person].size(); ++j)
            if (amis[person][j])
                ++sum;
    return sum;
}

void clearIn() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

/*
---------JEU D'ESSAIS---------

Q2)Q3)Q4)Q5)Q6)Q7)Q8)
    Conditions  NORMALES    VECTEUR VIDE    DIMENSIONS DIFFÉRENTES

    Retour                  Fin du prog     Fin du programme*
    correcte.   Oui         -ramme*

    *Le programme montre l'erreur et s'arrête sans planter.

Q4)Q6)
        Conditions  NORMALES    OVER        MISINPUT        MISTYPE

        Input user  0 3         0 5         -1              "std"

        Résultat    0 et 3      --->        Le programme    Le programme demande
                    deviennent              demande à       à l'utilisateur de
                    amis                    l'utilisateur   recommencer
                                        de retenter.

    Partie validation:
        Conditions  NORMALES    OVER        MISINPUT        MISTYPE

        Input user  o n         ù           k              "std"

        Résultat    Le prog     --->        Le programme    Le programme demande
                    recommence              demande à       à l'utilisateur de
                    une fois                l'utilisateur   recommencer
                                            de retenter.

Q7)
    Conditions      NORMALES        PAS SYMÉTRIQUE

    Matrice Amis    1 0 0 1         1 0 0 1
                    0 1 0 0         0 1 0 0
                    0 0 1 0         0 0 1 0
                    1 0 0 1         0 0 0 1

    Résultat        Correct         Incorrect

Q8) Conditions      NORMALES        PAS DE MÊME TAILLE

    Amis . Noms     1. Pimprenelle  Fin du programme
                    2. Bernadette
                    3. Nicolas
                    4. Azalee

    *Le programme montre l'erreur et s'arrête sans planter.
*/
