#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>


using namespace std;

void a_part(vector<string> &equipe);
void b_part(vector<string> &equipe);
void c_part(vector<string> &equipe);
void d_part(vector<string> &equipe);
void e_part(vector<string> &equipe);
bool f_part(vector<string> &equipe);
void g_part(vector<string> &equipe, int n);
void h_part(vector<string> &equipe);

int searchInVector(vector<string> &equipe);
void clearIn();

//This part is used to be able to cout a vector directly.
template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}
