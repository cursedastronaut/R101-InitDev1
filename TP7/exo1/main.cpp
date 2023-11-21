//BUT1-TP1K	GALAAD MARTINEAUX
#include "gestionNotes.h"
using namespace std;




int main() {
    vector<vector<int>> notes (NBETUD );
    vector<float> moyennes (NBETUD,0.0);
    vector<string> etudiants={"Robert","Johnson","Lucy","Emily","Sean","Clarence","Max",
                            "Vladymmir","Franck","Shaun","Thesee","Carla","Eli","Olga",
                            "Freeman","Benjamin","Baxter","Philipps","Taylor","Kewani"};
    /* g�n�ration des notes des �tudiants
            NE PAS MODIFIER !
    */
    int C = 314 ;
    int n =  C%117 + 53;
    for(unsigned int i=0; i<NBETUD; i++ ){
        int nbnotes = 12 + (C*(i+7))%53;
        for(int  j=0; j< nbnotes ; j++ ){
            notes[i].push_back(n%21);
            n= (17*n +31)% 367;
        }
    }
    /* FIN de la g�n�ration des notes*/

    unsigned int i,j,imax,choix;

    //remplissage du vecteur des moyennes
    calcMoyenne(notes, moyennes);
    /*for(i=0; i<NBETUD ; i++){
        for(j=0; j< notes[i].size(); j++)
            moyennes[i]+=notes[i][j];
        moyennes[i]=moyennes[i]/notes[i].size();
    }*/

    // boucle principale qui se relance tant que l'utilisateur ne choisit pas de QUITter
    do{

        choix = menu();

        // r�alisation du traitement choisi par l'utilisateur
        switch(choix){
            case(AFFICHENOTES ) :
                    affichageNotes(notes, etudiants);
                    break;
            case(MOY) :
                    affichageMoyennes(notes, etudiants, moyennes);
                    break;

            case(MAJOR) :
                    imax = trouverMeilleurEtudiant(etudiants, moyennes);

                    //affichage du meilleur �tudiant
                    cout<<"Le major de promo est \t";
                    cout << etudiants[imax]<<endl;
                    break;

        case(QUIT) : cout << " Au revoir !" <<endl; break;
        default : cout << " Entr�e non reconnue " << endl;
        }

    }while(choix!=QUIT);

    return 0;
}
