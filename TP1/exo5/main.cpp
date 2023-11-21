#include <iostream>

using namespace std;

int main()
{
    double a = 0, b = 1, temp;
    cout << a << ", " << b << endl;
    temp = a;
    a = b;
    b = temp;
    cout << a << ", " << b << endl;
    return 0;
}
