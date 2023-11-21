#include <iostream>

int main() {
    int base = -1, temp;

    while(base < 0 || base % 2 == 0) {
        std::cout << "Enter base triangle." << std::endl;
        std::cin >> base;
        if (base < 0 || base % 2 == 0)
            std::cout << "Error. Please enter a strictly positive uneven number." << std::endl;
    }


    for (temp = 1; temp < (base+1)/2; ++temp);
    for (int j = 1; j < base+1; j+=2, --temp) {
        for (int i = 0; i <= temp; ++i)
            std::cout << " ";
        for (int i = 0; i < j; ++i)
            std::cout << "*";
        std::cout << std::endl;
    }

    return 0;
}

/*
Enter base triangle.
45
                        *
                       ***
                      *****
                     *******
                    *********
                   ***********
                  *************
                 ***************
                *****************
               *******************
              *********************
             ***********************
            *************************
           ***************************
          *****************************
         *******************************
        *********************************
       ***********************************
      *************************************
     ***************************************
    *****************************************
   *******************************************
  *********************************************

  -----------------------------------------------

46
Error. Please enter a strictly positive uneven number.
Enter base triangle.
-54
Error. Please enter a strictly positive uneven number.
Enter base triangle.
0
Error. Please enter a strictly positive uneven number.
Enter base triangle.
1
  *

  -----------------------------------------------


*/