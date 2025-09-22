//
// Created by JeanR on 2025-09-20.
//

#include "Personne.h"
#include "ContratException.h"
#include "Adresse.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Personne::Personne(const string& p_nom, const string& p_prenom, const Adresse& p_adresse)
        : m_nom(p_nom), m_prenom(p_prenom), m_adresse(new Adresse(p_adresse)) {
    PRECONDITION(!p_prenom.empty());
    PRECONDITION(!p_nom.empty());
    PRECONDITION(&p_adresse != nullptr);
    POSTCONDITION(m_prenom == p_prenom);
    POSTCONDITION(m_nom == p_nom);
    POSTCONDITION(m_adresse != nullptr);
}

const string& Personne::reqNom() const {
    return m_nom;
}

const string& Personne::reqPrenom() const {
    return m_prenom;
}

const Adresse& Personne:: reqAdresse() const {
    // this line dereferences the attribute m_adresse which is a pointer to an Adresse object
    // by dereferencing it (*m_adresse), we get the original (the reference) object
    return *m_adresse;
}

void Personne::asgAdresse(const Adresse& p_adresse) {
    *m_adresse = p_adresse;
}

std::string Personne::reqPersonneFormate() const {
    std::ostringstream os;
    // arrow operator is used to access the methods and attributes of an object through its pointer
    os << m_prenom << " " << m_nom << ", habite au " << m_adresse -> reqDetailAdresse() << endl;
    return os.str();
}

std::ostream& operator<< (std::ostream& os, const Personne& p_personne) {
    return os << p_personne.reqPersonneFormate();
}

void Personne::verifieInvariant() const {
    INVARIANT(!m_prenom.empty());
    INVARIANT(!m_nom.empty());
    INVARIANT(m_adresse != nullptr);
}
