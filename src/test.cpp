#include <string>
#include <iostream>
#include <vector>
#include "Dictionnaire.h"
#include "Tuile.h"
#include "test.h"

using namespace std;


void tests()
{
    cout<<"Le test commance ***********************"<<endl;
    Dictionnaire d("assets/dictionnaire.txt");
    d.afficher();
    Tuile t;
    bool trouve;
    string ch="Mur_pierres_3";
    trouve = d.recherche(ch,t);
    if ((trouve))
    {
        cout<<"la Tuile est dans le diccionnaire"<<endl;
        t.afficher();
    }
    else
        cout<<"La tuile n'a pas ete trouve"<<endl;

    cout<<"Le test est termine***********************"<<endl;

    cout<<"***********************"<<endl;
    Dictionnaire n("assets/niveau.txt");


    /*
    cout << endl << "----- Manual tests for Search -----------------------------------------" << endl;
    bool ok =true;
    if(!(r.isLarger(r1))){
        ok=false;
        cout<<"ERROR: The area of your target is smaller that the one passed as parameter (expected the contrary)"<<endl;
    }
    else
        cout<<"the area of the target is larger than the area of the room passed as a parameter."<<endl;

    if(r1.isLarger(r)){
        ok=false;
        cout<<"ERROR: The area of your target is larger that the one passed as parameter (expected the contrary)"<<endl;
    }
    else
        cout<<"the area of the target is smaller than the area of the room passed as a parameter."<<endl;*/
}
