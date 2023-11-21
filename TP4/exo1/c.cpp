#include "main.h"
using namespace std;

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

