/**
 * \file Personne.h
 * à compléter
 *
 * \author: T.E.
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <string>
#include "Adresse.h"

class Personne
{
public:
  Personne () = delete;
  Personne (const std::string& p_nom, const std::string& p_prenom,
            const Adresse& p_adresse);
  
  

  const std::string& reqNom () const;
  const std::string& reqPrenom () const;
  const Adresse& reqAdresse () const;

  void asgAdresse (const Adresse& p_adresse);

  std::string reqPersonneFormate ()const;

  friend std::ostream& operator<< (std::ostream& os, const Personne& p_personne);

private:
  std::string m_nom;
  std::string m_prenom;
  Adresse* m_adresse;

  void verifieInvariant () const;
};

#endif /* PERSONNE_H_ */
