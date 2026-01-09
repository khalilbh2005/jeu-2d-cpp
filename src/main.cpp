#include <vector>
#include "Moteur.h"
#include "Personnage.h"
#include "Image.h"
#include "Avatar.h"
#include "Ennemi.h"
#include "Dictionnaire.h"
#include "test.h"
#include "Niveau.h"
#include <ctime>
#include <stdexcept>

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    try
    {
        // Initialisation du jeu
        Moteur moteur("Mon super jeu vidéo");
        int randomPosition;
        // TODO: charger images, creer personnages, etc.
        Image fond(moteur, "assets/fond.png");
        Image tuiles(moteur,"assets/objets.png");
        Image coffreFerme (moteur,"assets/coffre_ferme.png");
        Image coffreOuvert(moteur, "assets/coffre_ouvert.png");
        Image gameover(moteur,"assets/gameover.png");
        Image bravo(moteur,"assets/bravo.png");
        bool espace=false;
        bool quitter = false;
        int y=0;
        int x=0;
        Image pers;
        pers=Image(moteur,"assets/personnages.png");
        Avatar chevalier(pers,1*TAILLE_CASE,2*TAILLE_CASE,5,0,BAS);
        srand(time(nullptr));


        cout<<"randomPosition "<<randomPosition<<endl;
        Ennemi ennemi1(pers,5*TAILLE_CASE,TAILLE_CASE,9,0,HAUT);
        Ennemi ennemi2(pers,TAILLE_CASE,5*TAILLE_CASE,6,4,DROITE);


        ///*******seance4/5
        Image objets(moteur, "assets/objets.png");
        Dictionnaire dictionnaire("assets/dictionnaire.txt");
        Niveau niveau(objets, "assets/niveau.txt", dictionnaire);

        /// test***************************************************
        /*
            Dictionnaire d("assets/dictionnaire.txt");
            d.afficher();
        */
        cout<<"bonus de cette niveau === "<<niveau.getBonus()<<endl;
        //tests();
        /// test***************************************************

        /* int directionY=1;
        int directionX=1;*/

        // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
        // (en general, 60 fois par seconde)

        while (!quitter)
        {
            // I. Gestion des evenements
            Evenement evenement = moteur.evenementRecu();

            while (evenement != AUCUN)
            {


                switch (evenement)
                {
                // QUITTER = croix de la fenetre ou Echap
                case QUITTER_APPUYE:
                    quitter = true;
                    break;

                case ESPACE_APPUYE:
                    espace=true;
                    break;
                case ESPACE_RELACHE:
                    espace=false;
                    break;

                case GAUCHE_APPUYE:
                    chevalier.allerGauche(niveau);
                    chevalier.dessiner();
                    niveau.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
                    cout << "Bonus restants : " << niveau.getBonus() << endl;

                    break;
                case DROITE_APPUYE:
                    chevalier.allerDroite(niveau);
                    chevalier.dessiner();
                    niveau.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
                    cout << "Bonus restants : " << niveau.getBonus() << endl;

                    break;
                case HAUT_APPUYE:
                    chevalier.allerHaut(niveau);
                    chevalier.dessiner();
                    niveau.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
                    cout << "Bonus restants : " << niveau.getBonus() << endl;

                    break;
                case BAS_APPUYE:
                    chevalier.allerBas(niveau);
                    chevalier.dessiner();
                    niveau.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
                    cout << "Bonus restants : " << niveau.getBonus() << endl;

                    break;
                // TODO: gerer les autres evenements
                default:
                    break;
                }

                evenement = moteur.evenementRecu();
            }

            // II. Mise à jour de l'état du jeu

            // TODO: faire bouger vos personnages, etc.

            // III. Generation de l'image à afficher

            moteur.initialiserRendu(); /// efface ce qui avait ete affiche precedemment et reinitalise en ecran noir
            if (moteur.animationsAmettreAjour())
            {
                ennemi2.avancer(niveau);
                ennemi1.avancer(niveau);
            }



            // TODO: afficher vos personnages, objets, etc.
            fond.dessiner(0,0);
            //coffreFermé.dessiner(x,y);
            // affichage du niveau
            niveau.dessiner();
            chevalier.dessiner();
            ennemi1.dessiner();
            ennemi2.dessiner();
            ///perdu
            if (chevalier.touche(ennemi1)|| chevalier.touche(ennemi2))
            {
                gameover.dessiner(2*TAILLE_CASE,3*TAILLE_CASE);
                moteur.finaliserRendu();

                moteur.attendre(5);
                quitter=true;

            }
            else
            {
                if(niveau.gagne())
                {
                    bravo.dessiner(2*TAILLE_CASE,3*TAILLE_CASE);
                    moteur.finaliserRendu();

                    moteur.attendre(5);
                    quitter=true;
                }
            }


            moteur.finaliserRendu();
        }
    }
    catch(runtime_error e)
    {
        cerr<<e.what()<<endl;
    }

    return 0;
}







// : _perso(moteur, x, y, skin_x, skin_y, dir), _perso est créé correctement dès le départ
//avec _perso=Personnage (moteur, x, y, skin_x, skin_y, dir) _perso est d’abord construit avec le constructeur par défaut puis remplacé par un autre Personnage ==> _perso est créé puis réassigné
