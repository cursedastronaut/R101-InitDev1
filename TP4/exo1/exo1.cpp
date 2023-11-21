#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

using namespace std;

void a_part(vector<string> &equipe);
void b_part(vector<string> &equipe);
void c_part(vector<string> &equipe);
void d_part(vector<string> &equipe);
void e_part(vector<string> &equipe);
bool f_part(vector<string> &equipe);
void g_part(vector<string> &equipe, int n);
void h_part(vector<string> &equipe);

int searchInVector(vector<string> &equipe);
void clearIn();

//This part is used to be able to cout a vector directly.
template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

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

#include "main.h"
using namespace std;

void b_part(vector<string> &equipe) {
    if (equipe.size() == 0) {
        cout << "b) Skipped because equipe vector is empty." << endl;
        return;
    }
    cout << "b) Last: " << equipe.front() << endl;
    cout << "   First: " << equipe.back() << endl;
}

void c_part(vector<string> &equipe) {
    cout << "c) All the players in normal order of vector:" << endl;

    if (equipe.size() == 0) {
        cout << "   Skipped because equipe vector is empty." << endl;
        return;
    }

    for (size_t i = 0; i < equipe.size(); ++i)
        std::cout << equipe[i] << " ";
    /*There is an operator overload I included in main.cpp
      So I can just write this:
        std::cout << equipe << endl;
      I decided not to use it for this exercise as it would
      go against what is expected.
    */

}

void d_part(vector<string> &equipe) {
    cout << "\nd) All the players in reversed order of vector:" << endl;

    if (equipe.size() == 0) {
        cout << "   Skipped because equipe vector is empty." << endl;
        return;
    }

    //We check i is between 0 and the vector size.
    for (size_t i = equipe.size()-1; i >=0 && i < equipe.size(); i--)
    {
        std::cout << equipe[i] << " ";
    }
}

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

void g_part(vector<string> &equipe, int n) {
    cout << "\ng) Enter a name to replace last index with:" << endl;
    string newName;
    cin >> newName;

    equipe[n] = newName;
    cout << equipe << endl;
}

void h_part(vector<string> &equipe) {
    cout << "\nh) Making everything uppercase:" << endl;
    for (size_t i = 0; i < equipe.size(); ++i)
    {
        for (size_t j = 0; j < equipe[i].size(); ++j)
            equipe[i][j] = toupper(equipe[i][j]);
        std::cout << equipe[i] << " ";
    }
}


