//
// Created by JeanR on 2025-09-20.
//
#include "Adresse.h"
#include "ContratException.h"
#include <string>
#include <iostream>
using namespace std;

// Adresse::Adresse(const string& p_adresse)
//     : m_detailAdresse(p_adresse) {
//     PRECONDITION(!p_adresse.empty());
//     INVARIANTS();
// }

Adresse::Adresse(const string& p_adresse) {
    PRECONDITION(!p_adresse.empty());
    m_detailAdresse = new std::string(p_adresse);
    INVARIANTS();
}

Adresse& Adresse::operator=(const Adresse& p_adresse) {
    if (this != &p_adresse) {
        delete m_detailAdresse;
        m_detailAdresse = new std::string(p_adresse.reqDetailAdresse());
    }
    return *this;
}

void Adresse::asgAdresse(const std::string& adresse) {
    PRECONDITION(!adresse.empty());
    m_detailAdresse = &adresse;
    POSTCONDITION(m_detailAdresse == &adresse);
    INVARIANTS();
}

const std::string& Adresse::reqDetailAdresse() const {
    return m_detailAdresse;
}

void Adresse::verifieInvariant() const {
    INVARIANT(!m_detailAdresse.empty());
}
