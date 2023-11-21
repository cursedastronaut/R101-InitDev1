//Galaad MARTINEAUX - BUT1 TP1K
// HBM novembre 2023
// vers les exceptions
// TP8 programme a completer
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

float operation(char op, float a, float b);

int main()
{
    try
    {
        char op; // operation demandee
        float a,b; // on met ici des valeurs pour tester
        float res;
        a=5,b=2;
        op = '*'; //-----------------    test de la multiplication
        cout << a << op << b << endl;
        res =    operation(op,a,b);
        if(res==10)cout << "test OK "<< res<<endl;
        else cout <<"Erreur"<< res << endl;
        op = '+';    //----------------- test de l'addition
        cout << a << op << b << endl;
        res =    operation(op,a,b);
        if(res==7)cout << "test OK "<< res<<endl;
        else cout <<"Erreur"<< res << endl;
        op = '-';    //------------------    test de la soustraction
        cout << a << op << b << endl;
        res =    operation(op,a,b);
        if(res==3)cout << "test OK "<< res<<endl;
        else cout <<"Erreur"<< res << endl;

        op = '/';    //------------------    test de la division
        cout << a << op << b << endl;
        res =    operation(op,a,b);
        if(res==2.5)cout << "test OK "<< res<<endl;
        else cout <<"Erreur"<< res << endl;

        op = '/';    //------------------    test de la division par zéro
        cout << a << op << 0 << endl;

        res =    operation('/',a,0); //retirez cette ligne pour tester l'erreur 2
        res =    operation('a',a,0);

    }
    catch (int except)
    {
        switch(except) {
            case 1:
                cerr << "Division par zero impossible" << endl;
                break;
            case 2:
                cerr << "operation inconnue" << endl;
                break;
            default:
                cerr << "erreur inconnue" << endl;
                break;
        }
    }
    return 0;
}

// retourne le resultat de l'operation entre a et b
// precisee par le caractere op (+, -, /, *)
float operation(char op, float a, float b)
{
    float res;
    switch(op)
    {
    case '/':
        if (b == 0)
            throw (1);
        res = a/b;

        break;

    case '+':
        res = a+b;
        break;
    case '*':
        res = a*b;
        break;
    case '-':
        res = a-b;
        break;
    default:
        throw(2);
        break;
    }
    return res;
}
