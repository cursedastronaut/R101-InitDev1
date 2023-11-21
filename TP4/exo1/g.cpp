#include "main.h"

using namespace std;

void g_part(vector<string> &equipe, int n) {
    cout << "\ng) Enter a name to replace last index with:" << endl;
    string newName;
    cin >> newName;

    equipe[n] = newName;
    cout << equipe << endl;
}
