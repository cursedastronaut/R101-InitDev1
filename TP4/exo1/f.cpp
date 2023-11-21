#include "main.h"

using namespace std;

bool f_part(vector<string> &equipe) {
    int input = searchInVector(equipe);
    if (input != -1)
        cout << "Player has been found in the " << input << " index of the vector." << endl;
    else
        cout << "Player was not found in the vector" << endl;

    return input != -1 ? true : false;
}


int searchInVector(vector<string> &equipe)
{
    cout << "\nf) Enter a player's name: " << endl;
    string input;
    while (!(cin >> input)) {
        cout << "Invalid entry, please retry." << endl;
    }
    for (size_t i = 0; i < equipe.size(); ++i)
        if (input == equipe[i])
            return (int)i;
    return -1;
}
bool nom;
