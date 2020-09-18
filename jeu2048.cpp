/**
  @file jeu2048.cpp
  @brief implémantation du moteur de jeu du 2048
  @version 1.0
  @author dylan grammont
  @date 18/09/2020
  @details classe 2048
  */
#include "jeu2048.h"

/**
 * @brief Jeu2048::Jeu2048
 * @details constructeur de la classe
 *          initialise le score et le nombre de coups a 0
 *          initialise la grille
 *          place une première tuile
 */
Jeu2048::Jeu2048():nbCoups(0),score(0)
{
    srand(time(nullptr));
    for(int i=0;i<4;i++){
        for(int o=0;o<4;o++){
            grille[i][o]=0;
        }
    }
    PlacerNouvelleTuille();
}
/**
 * @brief Jeu2048::ObtenirNbCoups
 * @return
 */
int Jeu2048::ObtenirNbCoups()
{
    return nbCoups;
}
/**
 * @brief Jeu2048::ObtenirScore
 * @return
 */
int Jeu2048::ObtenirScore()
{
    return score;
}
/**
 * @brief Jeu2048::ObtenirGrille
 * @param _grille paramete de sortie
 * @details renvoie la grille du jeu
 */
void Jeu2048::ObtenirGrille(int _grille[][4])
{
    for(int i=0;i<4;i++){
        for(int o=0;o<4;o++){
            _grille[i][o]=grille[i][o];
        }
    }

}
/**
 * @brief Jeu2048::TirerAleatoire
 * @param _mode
 * @detailsChoisi une valeur de manière aléatoire en fonction du paramètre mode,
    si mode = POSITION la valeur obtenu est comprise entre 0 et NB_VAL -1
    Si mode = TUILE la valeur est 2 ou 4
 * @return
 */
int Jeu2048::TirerAleatoire(const MODE_ALEATOIRE _mode)
{
    if(_mode==POSITION){
        return (rand()%4);
    }
    else{
        return (((rand()%2)+1)*2);

    }
}
/**
 * @brief Jeu2048::PlacerNouvelleTuille
 * @details Place une nouvelle tuile de valeur 2 ou 4 à un emplacement libre sur la grille.
    Cet emplacement est choisi au hasard.
 */
void Jeu2048::PlacerNouvelleTuille()
{
    int ligne;
    int colone;
    do{
        ligne=TirerAleatoire(POSITION);
        colone=TirerAleatoire(POSITION);
    }while (grille[ligne][colone]!=0);
    grille[ligne][colone]=TirerAleatoire(TUILE);
}
/**
 * @brief Jeu2048::Calculer
 * @details permet de definir si deux case cote a cote sont egal et de les ajouter
 */
bool Jeu2048::Calculer()
{
    bool verif = false;
    switch (direction) {
    case 'G':for(int ligne=0; ligne<NB_VAL; ligne++){
            for(int colonne=0; colonne<NB_VAL-1; colonne++){
                if(grille[ligne][colonne] == grille[ligne][colonne+1]){
                    grille[ligne][colonne] = grille[ligne][colonne]*2;
                    grille[ligne][colonne+1] = 0;
                    verif = true;
                }
            }
        }
        break;
    case 'D':for(int ligne=0; ligne<NB_VAL; ligne++){
            for(int colonne=NB_VAL-1; colonne>0; colonne--){
                if(grille[ligne][colonne] == grille[ligne][colonne-1]){
                    grille[ligne][colonne] = grille[ligne][colonne]*2;
                    grille[ligne][colonne-1] = 0;
                    verif = true;
                }
            }
        }
        break;
    case 'B':for(int colonne=0; colonne<NB_VAL; colonne++){
            for(int ligne=NB_VAL-1; ligne>0; ligne--){
                if(grille[ligne][colonne] == grille[ligne-1][colonne]){
                    grille[ligne][colonne] = grille[ligne][colonne]*2;
                    grille[ligne-1][colonne] = 0;
                    verif = true;
                }
            }
        }
        break;
    case 'H':for(int colonne=0; colonne<NB_VAL; colonne++){
            for(int ligne=0; ligne<NB_VAL-1; ligne++){
                if(grille[ligne][colonne] == grille[ligne+1][colonne]){
                    grille[ligne][colonne] = grille[ligne][colonne]*2;
                    grille[ligne+1][colonne] = 0;
                    verif = true;
                }
            }
        }
        break;
    }
    return verif;
}

/**
 * @brief Jeu2048::Deplacer
 * @details deplace la grille si les valeur sont 0
 */
void Jeu2048::Deplacer()
{
    for (int indice=0; indice< NB_VAL;indice++)
    {

        switch (direction) {
        case 'G':for(int ligne=0; ligne<NB_VAL; ligne++){
                for(int colonne=0; colonne<NB_VAL-1; colonne++){
                    if(grille[ligne][colonne] == 0){
                        grille[ligne][colonne] = grille[ligne][colonne+1];
                        grille[ligne][colonne+1] = 0;
                    }
                }
            }
            break;
        case 'D':for(int ligne=0; ligne<NB_VAL; ligne++){
                for(int colonne=NB_VAL-1; colonne>0; colonne--){
                    if(grille[ligne][colonne] == 0){
                        grille[ligne][colonne] = grille[ligne][colonne-1];
                        grille[ligne][colonne-1] = 0;
                    }
                }
            }
            break;

            break;
        case 'B':for(int colonne=0; colonne<NB_VAL; colonne++){
                for(int ligne=NB_VAL-1; ligne>0; ligne--){
                    if(grille[ligne][colonne] == 0){
                        grille[ligne][colonne] = grille[ligne-1][colonne];
                        grille[ligne-1][colonne] = 0;
                    }
                }
            }
            break;
        case 'H':for(int colonne=0; colonne<NB_VAL; colonne++){
                for(int ligne=0; ligne<NB_VAL-1; ligne++){
                    if(grille[ligne][colonne] == 0){
                        grille[ligne][colonne] = grille[ligne+1][colonne];
                        grille[ligne+1][colonne] = 0;
                    }
                }
            }
            break;
        }
    }
}
/**
 * @brief Jeu2048::CalculerScore
 * @details Le score est calculé en effectuant la somme de toutes les cases
 */
int Jeu2048::CalculerScore()
{
    int somme=0;
    for(int i=0;i<NB_VAL;i++)
    {
        for(int o=0;o<NB_VAL;o++)
        {
            somme = somme+grille[i][o];
        }
    }
    return somme;
}
/**
 * @brief Jeu2048::RechercherFinDePartie
 * @details Une partie se termine lorsqu’une des cases de la grille contient 2048
    ou toutes les cases possèdent une valeur différente de 0
 */
bool Jeu2048::RechercherFinDePartie()
{
    bool fin=false;
    int cpt=0;
    for(int ligne=0;ligne<NB_VAL;ligne++)
    {
        for(int colonne=0;colonne<NB_VAL;colonne++)
        {
            if(grille[ligne][colonne]==2048)
            {
                fin=true;
            }
            if(grille[ligne][colonne]==0)
            {
                cpt++;
            }
        }
    }
    if(cpt ==0 )
    {
        fin=true;
    }
    return fin;
}
