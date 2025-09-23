/**
 * \file Adresse.h
 *
 * \author: T.E.
 */

#ifndef ADRESSE_H_
#define ADRESSE_H_

#include <string>

class Adresse {
public:
  Adresse () = delete; //C++11

  // Coplien
  // constructeur par copie
  Adresse (const std::string& p_adresse);
  // Operateur d'affectation
  Adresse& operator= (const Adresse& p_adresse);
  // Destructeur
  ~Adresse();

  void asgAdresse (const std::string& adresse);
  const std::string& reqDetailAdresse () const;

private:
  std::string* m_detailAdresse;

  void verifieInvariant () const;
};
#endif /* ADRESSE_H_ */
