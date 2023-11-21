#include "main.h"
using namespace std;

void e_part(vector<string> &equipe) {
    cout << "\ne) How many players to add (STRICTLY POSITIVE)" << endl;
    int input = -1;
    while (input < 0)
    {
        if (!(cin >> input) || input < 0) {
            cout << "Invalid entry! Please retry!" << endl;
            clearIn(); //Check main.cpp
            input = -1;
        }

    }

    string newName;

    for (int i = 0; i < input; ++i)
    {
        cout << "Enter the name:" << endl;
        cin >> newName;
        equipe.push_back(newName);
    }
    std::cout << equipe << endl;
}
