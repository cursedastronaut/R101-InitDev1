//BUT1-TP1K	GALAAD MARTINEAUX
#include <iostream>
#include <vector>

using namespace std;
const int NBETUD = 20 ;
const int AFFICHENOTES = 1 ;
const int MOY = 2 ;
const int MAJOR = 3 ;
const int QUIT = 0;

void calcMoyenne(const vector<vector<int>> &notes , vector<float> & moy);
bool invalide(int c);
unsigned int menu();
void affichageNotes(vector<vector<int>> &notes, vector<string> &etudiants);
void affichageMoyennes(vector<vector<int>> &notes, vector<string> &etudiants, vector<float> &moyennes);
size_t trouverMeilleurEtudiant(vector<string> &etudiants, vector<float> &moyennes);
