#include <iostream>

using namespace std;

int main() {
    double min, max;
    double x, y, z;
    cin >> x >> y >> z;

    max = x;
    //Sorting the maximum
    if (max < y)
        max = y;
    if (max < z)
        max = z;

    min = x;
    //Sorting the minimum
    if (min > y)
        min = y;
    if (min > z)
        min = z;

    cout << max << " " << min << endl;
    return 0;
}
/*
a)b)
 x  y   z   resultat
14  15  16  16
5   7   2   7
-9  27  0   27
-85 -10 -99 -10
4   4   2   4

c)
 x  y   z   resultat
14  15  16  16 14
5   7   2   7 2
-9  27  0   27 -9
-85 -10 -99 -10 -99
4   4   2   4 2
*/
