//BUT1 - TP1K - Galaad Martineaux
#include <iostream>
#include <vector>
#define STOP -999.f

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "[ ";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << (ii < v.end()  && ii > v.begin() ? ", " : "") << *ii;
    }
    os << "]";
    return os;
}

using namespace std;

struct size_t2 { size_t maxi; size_t mini; };
float  b_part(vector<float> &tab);
size_t2 c_part(vector<float> &tab);
void d_part();
void e_part();
void f_part();

int main() {

    vector<float> tab = {10.f, 15.f, 9.f};

    //Partie b
    cout << "b)" << endl;
    cout <<  "Sum of vector tab is: " << b_part(tab) << endl << endl;

    //Partie c
    cout << "c)" << endl;
    size_t2 temp = c_part(tab);
    cout << "Max:" << temp.maxi << "; Mini: " << temp.mini << endl;
    if (tab.size() > 0)
        cout << "MaxIndex:" << tab[temp.maxi] << "; MiniIndex: " <<
            tab[temp.mini] << endl << endl;

    //Partie d
    d_part();
    cout << endl;
    //Partie e
    e_part();
    //Partie f
    f_part();

    cout << endl;

    return 0;
}


//Returns the average of all the floats contained within tab
float b_part(vector<float> &tab) {
    float sum = 0;
    for (size_t i = 0; i < tab.size(); ++i)
        sum += tab[i];

    return (tab.size() != 0 ? sum / tab.size() : 0);
}

//Returns the maximum and minimum values' index
size_t2 c_part(vector<float> &tab) {
    size_t maxi = 0, mini = 0;

    //get max
    for (size_t i = 0; i < tab.size(); ++i)
        if (tab[i] > tab[maxi])
            maxi = i;

    mini = maxi;
    for (size_t i = 0; i < tab.size(); ++i)
        if (tab[i] <= tab[mini])
            mini = i;
    return {maxi, mini};
}

//Prints a custom tab, and its number separated in two other vectors depending
//on their sign.
void d_part() {
    vector<float> tab = {1.2f, -2.0f, 13.4f, 14.5f, -13.6f};
    vector<float> tabNeg, tabPos;

    if (tab.size() == 0) {
        cout << "d) Skipped because tab does not contain any values." << endl;
        return;
    }

    for (size_t i = 0; i < tab.size(); ++i) {
        if (tab[i] < 0) //0 here is considered positive.
            tabNeg.push_back(tab[i]);
        else
            tabPos.push_back(tab[i]);
    }

    cout    << "d)  Content of tab:     " << tab << endl
            << "    Content of tabNeg:  " << tabNeg << endl
            << "    Content of tabPos:  " << tabPos << endl
            << endl;

}

//Prints a custom tab, before and after removing its zero values.
void e_part() {
    vector<float> tab = {1.2f, 0.f, -2.2f, 13.6f, 0.f, 0.f, 14.5f, -13.8f};

    cout    << "e) Content of tab before removing zero values: "
            << endl << tab << endl;
    if (tab.size() != 0)
        for (size_t i = 0; i < tab.size(); ++i)
            if (tab[i] == 0)
                tab.erase(tab.begin()+i);

    cout    << "Content of tab after removing zero values: "
            << endl << tab << endl;
}

//Same as c_part() but also prints the indexes.
void f_part() {
    vector<float> tab = {1.2f, -2.0f, 13.4f, 14.5f, -13.6f};
    vector<float> tabNeg, tabPos;
    if (tab.size() == 0) {
        cout << "f) Skipped because tab does not contain any values." << endl;
        return;
    }

    for (size_t i = 0; i < tab.size(); ++i) {
        if (tab[i] < 0) //0 here is considered positive.
            tabNeg.push_back(i);
        else
            tabPos.push_back(i);
    }

    cout << "\nf) Content of tabNeg: " << tabNeg << endl;

    cout << "\n   Content of tabPos: " << tabPos << endl;

    cout << "\n   Negative values: [ ";
    for (size_t i = 0; i < tabNeg.size(); ++i)
        cout << tab[tabNeg[i]] << (i < tabNeg.size()-1 ? ", " : " ]");

    cout << "\n   Positive values: [ ";
    for (size_t i = 0; i < tabPos.size(); ++i)
        cout << tab[tabPos[i]] << (i < tabPos.size()-1 ? ", " : " ]");
}

