/*
 * testPersonne.cpp
 *
 *      Author: T.E.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include "Personne.h"
#include "Adresse.h"

using namespace std;

int
main ()
{
  vector<Personne> v_personnes;
  Personne autre ("bill", "Boquet", Adresse ("ailleurs"));
  cout << "autre : " << autre;
  {
    Personne moi ("Joe", "blo", Adresse ("ici"));

    cout << "moi : " << moi;
    {
      Personne lui (moi);
      cout << "lui : " << lui;
      v_personnes.push_back (move (lui));
    }
    autre = move (moi);
//    cout << "moi : " << moi; //Segmentation fault
  }
  cout << v_personnes[0];
  cout << autre;
  return 0;
}

