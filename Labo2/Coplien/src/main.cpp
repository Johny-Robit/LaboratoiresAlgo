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

template <typename T>
std::ostream& affichePointeur(std::ostream& os, const std::string& nom_du_type, const T* ptr) {
  os << "<" << "Pointeur de type " << nom_du_type << " : " << ptr;
  if(ptr) {
    os << " valeur=" << *ptr;
  }
  os << ">";
  return os;
}

template <typename T>
std::ostream& afficherUnPointeur(std::ostream& os, const std::string& nom_du_type, const T* ptr) {
  if (ptr != nullptr) {
    // the object type must have an overloaded operator<< for std::ostream (a print function).
    os << "Pointeur de type " << nom_du_type << " : " << *ptr << endl;
  }
  return os;
}

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

  Personne johny ("Doe", "John", Adresse ("1234 rue des Lilas"));
  Personne* ptr = &johny;
  //affichePointeur(cout, "Personne", ptr);
  afficherUnPointeur(std::cout, "Personne", ptr);

  return 0;
}

