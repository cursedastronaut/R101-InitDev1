//BUT1 - TP1K - Galaad Martineaux
#include <iostream>
#include <vector>
#include <limits>
#define STOP -999.f

using namespace std;

void clearIn();

int main() {
    vector<float> tab;
    float input = 0;

    cout << "Write multiple decimal numbers, separated by a newline. To stop, enter -999." << endl;

    while (input != STOP) {
        while (!(cin >> input)){
            cout << "Invalid input, please retry." << endl;
            clearIn();
        }

        tab.push_back(input);
    }

    tab.pop_back();

    std::cout   << endl << "Content of tab:" << endl
                << (tab.size() > 0 ? "[ " : "tab is empty.\n");
    for (size_t i = 0; i < tab.size(); ++i)
        std::cout << tab[i] << (i < tab.size() -1 ? ", " : " ]");

}


void clearIn() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
