#include <iostream>
using namespace std;
int main()
{
    float note, totalnote = 0, nbnotes = 0, moyenne;
    char rep;

    do
    {
        cout << "Saisir une note" << endl;
        cin >> note;
        while (note < 0 || note > 20)
        {
            cout << "Erreur : La note doit etre entre 0 et 20" << endl;
            cout << "Recommencez la saisie" << endl;
            cin >> note;
        }
        totalnote = totalnote + note;
        nbnotes = nbnotes + 1;
        cout << "Y a-t-il d'autres notes a saisir ?" << endl;
        cout << "(repondre par o ou n)" << endl;
        cin >> rep;
    } while (rep == 'o');

    moyenne = totalnote / nbnotes;
    cout << "La moyenne est " << moyenne << "." << endl;

    return 0;
}