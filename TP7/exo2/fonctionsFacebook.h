//GALAAD MARTINEAUX BUT1 - TP1K
//TP7 - INITDEV1
#pragma once
#ifndef FACEBOOK_GUARDS
#define FACEBOOK_GUARDS
#include <iostream>
#include <vector>
using namespace std;


void initialisation(const size_t NBMEMBRES, vector<vector<bool>> &amis, vector<string> &amis_name);
void affiche(vector<vector<bool>> &amis, vector<string> &amis_name);
void ajoutAmis(vector<vector<bool>> &amis, vector<string> &amis_name, string a, string b);
size_t amisCommun(vector<vector<bool>> &amis, size_t a, size_t b);
// la fonction groupeAmis retourne vrai si 3 personnes forment un
// groupe d’amis où chacun est amis avec les deux autres et faux sinon.
bool groupeAmis(const vector<vector<bool>> &reseau, int a, int b, int c);
int recherche(vector<string> &amis_name, string input);
bool grandGroupeAmis(const vector<vector<bool>> &reseau, vector<string> &amis_name, vector<size_t> &friendList);


#endif // FACEBOOK_GUARDS
