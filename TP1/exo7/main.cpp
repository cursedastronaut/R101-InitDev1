//Galaad Martineaux - TP1K
#include <iostream>

//using namespace std;

int main()
{
    int temp[3];
    std::cout << "Saisissez trois températures, dont on fera la moyenne: " << endl;
    cin >> temp[0] >> temp[1] >> temp[2];
    cout << endl << "\nMoyenne: " << ((temp[0] + temp[1]) / 2.f) << endl;
    return 0;
}
/*
    Exercice 7:
        a:
            #include <iostream>

            using namespace std;

            int main()
            {
                int temp[2];
                cout << "Saisissez trois températures, dont on fera la moyenne: " << endl;
                cin >> temp[0] >> temp[1];
                cout << endl << "\nMoyenne: " << ((temp[0] + temp[1]) / 2.f) << endl;
                return 0;
            }
        b:
            int temp[3]; // J'ai remplacé la ligne "int temp[2]".
        c:
            Le code précédent est déjà correct.

*/
