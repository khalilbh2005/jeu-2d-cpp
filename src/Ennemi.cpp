#include "Ennemi.h"
#include "Personnage.h"
#include "Moteur.h"

Ennemi::Ennemi(const Image& img, int x, int y, int skin_x, int skin_y,Direction d)
{
    _perso = Personnage(img, x, y, skin_x, skin_y, d);
}

void Ennemi::dessiner() const
{
    _perso.dessiner();
}


void Ennemi::avancer(const Niveau& niveau)
{
    if (!(_perso.peutBougerVers(_perso.getDirection(),niveau)))
    {
        _perso.inverserDirection();
    }

    switch (_perso.getDirection())
    {
    case (DROITE):
        _perso.deplacer(TAILLE_CASE,0);
        break;
    case (GAUCHE):
        _perso.deplacer(-TAILLE_CASE,0);
        break;
    case (BAS):
        _perso.deplacer(0,TAILLE_CASE);
        break;
    case (HAUT):
        _perso.deplacer(0,-TAILLE_CASE);
        break;
    }

}

int Ennemi::getX() const
{
    int x= _perso.getX();
    return x;
}

int Ennemi::getY() const
{
    int y= _perso.getY();
    return y;
}
