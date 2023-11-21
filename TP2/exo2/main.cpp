#include <iostream>

using namespace std;

int main() {

    int temperature;
    cin >> temperature;
    cout << temperature;
    if (temperature > 25)
        cout << "Il fait trop chaud :-(" << endl;
    else if (temperature < 15)
        cout << "Il fait trop froid:-(" << endl;
    else
        cout << "Cette température me convient :-)";

    return 0;
}
//14 -> Il fait trop froid:-(
//28 -> Il fait trop chaud :-(
//18 -> Cette température me convient :-)
//-4 -> Il fait trop froid:-(
