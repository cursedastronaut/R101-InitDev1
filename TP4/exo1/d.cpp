#include "main.h"
using namespace std;

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


