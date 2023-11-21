//GALAAD MARTINEAUX BUT1 - TP1K
//TP7 - INITDEV1
#include "fonctionsFacebook.h"
using namespace std;

void initialisation(const size_t NBMEMBRES, vector<vector<bool>> &amis, vector<string> &amis_name) {
    for (size_t i = 0; i < NBMEMBRES; ++i) {
        amis.push_back(vector<bool>(NBMEMBRES, false));
        amis[i][i] = true;
        amis_name.push_back("A" + to_string(i));
    }
}

void affiche(vector<vector<bool>> &amis, vector<string> &amis_name) {
    for(size_t i=0; i<amis.size(); i++) {
        cout<< amis_name[i] << " est ami avec :" ;
        for( size_t j=0; j<i; j++)
            if(amis[i][j]) cout << " " << amis_name[j];
        for( size_t j=i+1; j<amis[i].size(); j++)
            if(amis[i][j]) cout << " " << amis_name[j];
        cout << endl;
    }
}

void ajoutAmis(vector<vector<bool>> &amis, vector<string> &amis_name, string a, string b) {
    size_t friendA = (size_t)recherche(amis_name, a);
    size_t friendB = (size_t)recherche(amis_name, b);

    amis[friendA][friendB]=amis[friendA][friendB] = true;
}

size_t amisCommun(vector<vector<bool>> &amis, size_t a, size_t b) {
    if (a >= amis.size() || b >= amis.size())
        return 0;
    int sum = 0;
    for (size_t i = 0; i < amis[a].size() && i < amis[b].size(); ++i) {
        sum += (amis[a][i] && amis[b][i] ? 1 : 0);
    }

    return sum;
}

bool groupeAmis(const vector<vector<bool>> &reseau, int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0)
        return false;
    if (a >= (reseau.size()) || ( b >= reseau.size()) || (c >= reseau.size()))
        return false;
    if (!(reseau[a].size() == reseau[b].size() && reseau[a].size() == reseau[c].size()))
        return false;

    return ( reseau[a][b]&&reseau[b][a])
        && ( reseau[a][c]&&reseau[c][a])
        && ( reseau[c][b]&&reseau[b][c]);
}

int recherche(vector<string> &amis_name, string input) {
    for (size_t i = 0; i < amis_name.size(); ++i)
        if (input == amis_name[i])
            return (int)i;
    return -1;
}

bool grandGroupeAmis(const vector<vector<bool>> &reseau, vector<string> &amis_name, vector<size_t> &friendList) {
    for (size_t i = 0; i < friendList.size(); ++i) {
        if (friendList[i] >= reseau.size())
            return false;

        if (i > 0)
            if (!reseau[friendList[i]][friendList[i-1]])
                return false;
    }

    return true;
}
