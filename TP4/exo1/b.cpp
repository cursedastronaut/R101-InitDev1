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
