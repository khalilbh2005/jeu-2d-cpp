#include "Personnage.h"
#include "Moteur.h"
#include "Niveau.h"
#include <stdlib.h>
using namespace std;

Personnage::Personnage()
{
    cout<<"constrcuteur vide"<<endl;
    _direction=BAS;
}
Personnage::Personnage(const Image& img, int x, int y, int skinx, int skiny,Direction d)
{
    _img=img;
    _x=x;
    _y=y;
    _skin_x=skinx;
    _skin_y=skiny;
    _direction=d;
    _frame=0;
}
void Personnage::mettreAJourAnimation()
{
    _frame = (_frame+1)%4;
}


void Personnage::dessiner() const
{
    int rx=_skin_x*TAILLE_CASE;
    int ry=_skin_y*TAILLE_CASE;
    int w=TAILLE_CASE;
    int h=TAILLE_CASE;
    _img.dessiner(_x,_y, rx,ry,w,h);
    switch (_direction)
    {
    case BAS :
        _img.dessiner(_x,_y, rx,ry,w,h);
        break;
    case GAUCHE :
        _img.dessiner(_x,_y, rx,ry+TAILLE_CASE,w,h);
        break;
    case DROITE :
        _img.dessiner(_x,_y, rx,ry+(TAILLE_CASE*2),w,h);
        break;
    case HAUT :
        _img.dessiner(_x,_y, rx,ry+(TAILLE_CASE*3),w,h);
        break;
    default:
        _img.dessiner(_x,_y, rx,ry,w,h);
        break;

    }

}


void Personnage::regarderDroite()
{
    _direction = DROITE;
}

void Personnage::regarderGauche()
{
    _direction = GAUCHE;
}
void Personnage::regarderBas()
{
    _direction = BAS;
}
void Personnage::regarderHaut()
{
    _direction = HAUT;
}

void Personnage::deplacer(int dx, int dy)
{
    _y+=dy;
    _x+=dx;
}

bool Personnage::peutBougerVers(Direction dir, const Niveau& niveau) const
{
    int cibleX = _x;
    int cibleY = _y;
    bool res=true;
    switch (dir)
    {
    case GAUCHE:
        cibleX -= TAILLE_CASE;
        break;
    case DROITE:
        cibleX += TAILLE_CASE;
        break;
    case HAUT:
        cibleY -= TAILLE_CASE;
        break;
    case BAS:
        cibleY += TAILLE_CASE;
        break;
    }

    // 1) test bord de l'écran
    if (cibleX < 0 || cibleY < 0 ||
            cibleX >= LARGEUR_FENETRE ||
            cibleY >= HAUTEUR_FENETRE)
    {
        res=false;
    }

    if (!niveau.caseEstLibre(cibleX, cibleY))
    {
        res=false;
    }

    return res;
}

Direction Personnage::getDirection() const
{
    return _direction;
}

int Personnage::getX() const
{
    return _x;
}

int Personnage::getY() const
{
    return _y;
}

void Personnage::inverserDirection()
{
    switch (_direction)
    {
    case BAS :
        _direction=HAUT;
        break;
    case GAUCHE :
        _direction=DROITE;
        break;
    case DROITE :
        _direction=GAUCHE;
        break;
    case HAUT :
        _direction=BAS;
        break;
    }
}
