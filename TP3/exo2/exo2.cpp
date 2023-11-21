#include <iostream>

int main() {
    int n = -1, nbl = -1;
    char unCar;
    std::cout << "Enter a character" << std::endl;
    std::cin >> unCar; //No verifications were asked.
    
    //Asking for user input "unCar". The character we'll draw our block with.
    while(n < 0) {
        std::cout << "How much char?" << std::endl;
        std::cin >> n;
        if (n < 0)
            std::cout << "Error. Please enter a strictly positive number." << std::endl;
    }

    //Asking for user input "nbl". The number of lines of our block.
    while(nbl < 0) {
        std::cout << "How much lines ?" << std::endl;
        std::cin >> nbl;
        if (nbl < 0)
            std::cout << "Error. Please enter a strictly positive number." << std::endl;
    }

    //Actual drawing
    for (int j = 0; j < nbl; ++j) {
        for (int i = 0; i < n; ++i)
            std::cout << unCar;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
/*
Enter a character
f
How much char?
45
How much lines ?
2
fffffffffffffffffffffffffffffffffffffffffffff
fffffffffffffffffffffffffffffffffffffffffffff

-

Enter a character
5
How much char?
-1
Error. Please enter a strictly positive number.
How much char?
0
How much lines ?
5





-

Enter a character
o
How much char?
71
How much lines ?
-1
Error. Please enter a strictly positive number.
How much lines ?
12
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
*/