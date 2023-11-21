#include "main.h"
#include <cctype>
using namespace std;

void h_part(vector<string> &equipe) {
    cout << "\nh) Making everything uppercase:" << endl;
    for (size_t i = 0; i < equipe.size(); ++i)
    {
        for (size_t j = 0; j < equipe[i].size(); ++j)
            equipe[i][j] = toupper(equipe[i][j]);
        std::cout << equipe[i] << " ";
    }
}
