//BUT1-TP1K	GALAAD MARTINEAUX
#include "gestionNotes.h"
using namespace std;

void calcMoyenne(const vector<vector<int>> &notes , vector<float> & moy) {
    //remplissage du vecteur des moyennes
    for(size_t i=0; i<notes.size() ; i++){
        for(size_t j=0; j< notes[i].size(); j++)
            moy[i]+=notes[i][j];
        moy[i]=moy[i]/notes[i].size();
    }
}

bool invalide(int c) {
    return (c!=AFFICHENOTES  && c!=MOY && c!=MAJOR &&c!=QUIT);
}

unsigned int menu() {
    unsigned int choix;
    // affichage du menu
    cout<< "\n Que voulez-vous faire  ?" << endl;
    cout << AFFICHENOTES<<"  pour afficher toutes les notes de chaque etudiant."<< endl;
    cout <<MOY<<"  pour afficher toutes les moyennes de chaque etudiant."<< endl;
    cout << MAJOR<<"  pour afficher l'etudiant ayant la meilleure moyenne."<< endl;
    cout << QUIT <<"  pour quitter le programme."<< endl;

    //choix de l'utilisateur
    cin >> choix;
    while (invalide(choix)) {
        cout << "Choix invalide"<<endl;
        cin>> choix;
    }

    return choix;
}

void affichageNotes(vector<vector<int>> &notes, vector<string> &etudiants) {
    // affichage des notes
    for(size_t i=0; i< NBETUD ; i++){
        cout<<"Les "<<notes[i].size() <<" notes de "<<etudiants[i]<<" :"<<endl;
        for(size_t j=0; j<notes[i].size(); j++){
            cout << notes[i][j]<<" ";}
    cout << endl << endl;
    }
}

void affichageMoyennes(vector<vector<int>> &notes, vector<string> &etudiants, vector<float> &moyennes) {
    //affichage des moyennes
    for(size_t i=0; i< NBETUD ; i++){
        cout<<"La moyenne de "<<etudiants[i]<<":\t";
        cout << moyennes[i]<<endl;
    }
}

//calcul de l'indice du meilleur etudiant
size_t trouverMeilleurEtudiant(vector<string> &etudiants, vector<float> &moyennes) {
    size_t imax;
    for(size_t i=1;i<NBETUD; i++)
        imax = moyennes[imax]< moyennes[i] ? i : imax;

    return imax;
}
