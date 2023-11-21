//GALAAD MARTINEAUX BUT1 - TP1K
//TP7 - INITDEV1
// HBM, JL  2023
// vecteurs à 2 dimensions
// les lignes et les colonnes representent des personnes
// chaque case (i,j) contient  un booleen
// indiquant si i et j sont des amis


#include "fonctionsFacebook.h"
const size_t NBMEMBRES = 5;
using namespace std;

int main(){
    vector <vector <bool> >  amis;
    vector <string> amis_name;

    initialisation(NBMEMBRES, amis, amis_name);
    int i,j;

    cout << "Pour tester si les trois premiers utilisateurs sont amis,"
    << " les amis doivent être A0, A1, et A2." << endl;
    affiche(amis, amis_name);
    //Ajout Amis
    if (amis.size() > 0)
    {
        char rep;
        string i = "",j = "";
        do {
            cout<<" quels sont les nouveaux amis ? ";
            while((!(cin >> i >> j))
                   || recherche(amis_name, i) == -1
                   || recherche(amis_name, j) == -1
                  )  {
                cout << "essaie encore " << endl;
            }

            cout << "OK, 2 nouveaux amis :-)"<< endl;
            ajoutAmis(amis, amis_name, i, j);

            cout << "Encore des amis ? (o/n)";
            cin>>rep;
        }  while(rep =='o' || rep == 'O');
    }

    affiche(amis, amis_name);

    /// Personne qui a le plus d'amis
    int nbA; // nombre d'amis de i
    int nbMax;// nombre d'amis le plus grand
    int imax; // indice de la 1er personne qui a le plus d'amis
    // calcul du nombre d'amis le plus grand
    nbMax=0; // au minimum 0 amis
    imax=0;
    for (i=0; i<amis.size(); i++) {
        nbA=0;   // calcul du nombre d'amis de i
        for (j=0; j<amis.size(); j++) {
            if(amis[i][j]) nbA++;
        }
        // mise à jour du max
        if (nbA>nbMax) {
            nbMax=nbA;
            imax=i;
        }
    }
    cout << "La personne qui a le plus d'amis est " << imax <<endl;

    cout << "Les deux premiers utilisateurs ont " << amisCommun(amis, 0, 1)
    << " amis communs." << endl;
    if (amis.size() == 0) return 0;
    cout << (groupeAmis(amis, 0, 1, 2) ? "Les 3 premiers utilisateurs sont amis."
             : "Les 3 derniers utilisateurs ne sont pas amis.") << endl;

    vector<size_t> awa = {0, 1, 2};
    cout << (grandGroupeAmis(amis, amis_name, awa) ? "they are fr"
             : "NO FRIEND????") << endl;
    return 0;
}
