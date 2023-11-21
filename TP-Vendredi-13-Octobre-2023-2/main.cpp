/*
    GALAAD MARTINEAUX
    TP-1K   13/10/2023
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v1 = {-2, 3, 7, 1, 2, 3, 7, 3, -2, 7, 0};

    //Question 1
    std::cout << "Question 1)\n\tAffichage des valeurs de v1:" << endl << "\t";
    for (size_t i = 0; i < v1.size(); ++i)
        std::cout << v1[i] << ((i == v1.size() -1) ? "\n" : ", ");

    //Question 2
    vector<int> v2;
    for (size_t i = v1.size()-1; i < v1.size() && i >= 0; --i) //since size_t is strictly positive, it shouldn't be able to go under 0
        v2.push_back(v1[i]);

    std::cout << "Question 2)\n\tAffichage des valeurs de v2:" << endl << "\t";
    for (size_t i = 0; i < v2.size(); ++i)
        std::cout << v2[i] << ((i == v2.size() -1) ? "\n" : ", ");


    //Question 3
    cout << "Question 3) " << endl;
    if (v1.size() > 0) {
        int maxi = v1[0];
        int sum = 0;
        //I'm not sure how to do it in one time.
        //Searching for maxi
        for (size_t i = 0; i < v1.size(); ++i)
            if (v1[i] > maxi)
                maxi = v1[i];
        //Counting maxi occurences
        for (size_t i = 0; i < v1.size(); ++i)
            if (v1[i] == maxi)
                sum++;

        cout << "\tLa valeur la plus grande est " << maxi
        << " et elle apparait " << sum << " fois." << endl;
    }
    else {
        cout << "\tImpossible de calculer le maximum puisque"
        << " le vecteur v1 est vide." << endl;
    }


    //Question 4
    cout << "Question 4)\n\tSaisissez une valeur, puis un nombre positif." << endl;

    int val, n, sum = 0;
    cin >> val >> n;

    for (size_t i = 0; i < v1.size(); ++i)
        if (v1[i] == val)
            ++sum;
    if (sum >= n)
        cout << "\tLa valeur " << val << " apparait au moins "
        << n << " fois." << endl;
    else
        cout << "\tLa valeur " << val << " n'apparait pas au moins "
        << n << " fois." << endl;


    return 0;
}
/*

    JEU D'ESSAI

    Fonctionnement:
        On parcourt le vecteur à la recherche de val,
        et on compte ses occurences.

    Test:

        Input       7, 2            7,2

        Contenu     {-2, 3, 7,      {}
        de v1       1, 2, 3, 7,
                    3, -2, 7, 0
                    }

        Résultat    La valeur 7     La valeur 7 n'apparait
                    apparait au     pas au moins 2 fois.
                    moins 2 fois.

    La somme des occurences de val est initialisé à zéro, donc
    si le vecteur est vide, il ne trouve jamais val, et son nombre
    d'occurence reste donc zéro.

*/
