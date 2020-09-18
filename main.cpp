#include <iostream>
#include <string.h>
#include "jeu2048.h"
using namespace std;
/**
  @file main.cpp
  @brief programme principale du 2048
  @version 1.0
  @author dylan grammont
  @date 18/09/2020
  @details classe 2048
  */
void AfficherGrille( Jeu2048 &_leJeu);
int main()

{
    char direction;
    bool finDePartie=false;
    Jeu2048 _leJeu;


    do{
        AfficherGrille(_leJeu);

        cout<<"Saire un déplacment (H:Haut B:Bas D:Droite G:Gauche F:Fin de partie)";
        cin>>direction;
        direction=static_cast<char>(toupper(direction));
        if(strchr("HBGD",direction )!=nullptr ){

            finDePartie=_leJeu.JouerCoup(direction);
        }
    }while (direction!= 'F' && finDePartie==false);
    return 0;
}
/**
 * @brief AfficherGrille
 * @param _leJeu
 * @details Affiche les chiffres contenus dans la grille si ce chiffre est différent de 0
 */
void AfficherGrille(Jeu2048 &_leJeu){
    system("clear");
    cout<<"Votre est est de : " << _leJeu.ObtenirScore()<< " et votre nombre de coup est de : "<< _leJeu.ObtenirNbCoups()<<endl;
    int _grille[4][4];
    _leJeu.ObtenirGrille(_grille);
    cout <<"+" << setfill('-') <<setw(6) << "+" << setfill('-') <<setw(6)  <<"+" << setfill('-') <<setw(6)<<"+" << setfill('-') <<setw(6) <<"+"<<endl;

    for(int i=0;i<4;i++){
        if(i!=0){
            cout<<"|";
            cout<<endl;
            cout <<"+" << setfill('-') <<setw(6) << "+" << setfill('-') <<setw(6)  <<"+" << setfill('-') <<setw(6)<<"+" << setfill('-') <<setw(6) <<"+"<<endl;



        }
        for(int o=0;o<4;o++){
            if(_grille[i][o]!=0){
                cout<<"|"<<setfill(' ')<<setw(5);
                cout<<_grille[i][o];

            }
            else{
                cout<<"|"<<setfill(' ')<<setw(5);
                cout<<" ";
            }
        }
    }
    cout<<"|"<<endl;
    cout <<"+" << setfill('-') <<setw(6) << "+" << setfill('-') <<setw(6)  <<"+" << setfill('-') <<setw(6)<<"+" << setfill('-') <<setw(6) <<"+"<<endl;

}
/**
 * @brief Jeu2048::JouerCoup
 * @param _direction
 * @return
 * @details tester le fonctionnement des fonction
 */
bool Jeu2048::JouerCoup(char _direction)
{
    direction=_direction;
    Deplacer();
    if(Calculer())Deplacer();
    CalculerScore();
    score=CalculerScore();
    nbCoups=nbCoups+1;
    bool fin=RechercherFinDePartie();
    if(!fin)PlacerNouvelleTuille();
    return fin;
}

