#ifndef LISTE_HPP
#define LISTE_HPP

#include "Liste.h"
#include "ContratException.h"

namespace lab03 {
    /**
     * \brief Constructeur par défaut
     * \post Une instance de la classe Liste est initialisée
     */
    template<typename T>
    Liste<T>::Liste():m_dernier(nullptr), m_cardinalite(0) {

    }

    /**
     * \brief Destructeur
     * \post L'instance de Liste est détruite.
     */
    template<typename T>
    Liste<T>::~Liste() {
         _detruire();
     }

    /**
     *\brief Destruction profonde de la liste
     *\post La liste est détruite
     */
   template<typename T>
   void Liste<T>::_detruire() {
       if(m_dernier != nullptr) {
        elem sentinelle = m_dernier->m_suivant;
        elem remover = sentinelle;
        while (sentinelle != m_dernier) {
         sentinelle = sentinelle->m_suivant;
         remover->m_suivant = nullptr;
         delete remover;
         remover = sentinelle;
        }
        m_dernier->m_suivant = nullptr;
        delete m_dernier;
       }
       m_dernier = nullptr;
       m_cardinalite = 0;
      }
 /**
  *\brief Constructeur de copie
  *\pre Il faut qu'il y ait suffisamment de mémoire
  *\post La liste passée en paramètre est copiée
  *\param[in] p_source La liste à copier
  *\exception bad_alloc s'il n'y a pas assez de mémoire
  */
 template<typename T>
 Liste<T>::Liste(const Liste<T> & p_source) {

     if(!p_source.estVide()) {
      _copier(p_source.m_dernier);
     }
     INVARIANTS();
    }


 /**
  * \brief Surcharge de l'opérateur =
  *
  * \pre Il y a assez de mémoire pour l'opération
  * \post La liste passée en paramètre est copiée
  * @param[in] p_source La liste à copier
  * \exception bad_alloc si la précondition n'est pas respectée
  */
 template<typename T>
 const Liste<T>& Liste<T>::operator=(const Liste<T>& p_source) {
     if(this != &p_source) {
      _detruire();
      if(!p_source.estVide()) {
       _copier(p_source.m_dernier);
      }
     }
     // zone de code à vérifier
     return *this;
    }

/**
 *\param[in] p_element l'élément à ajouter
 *\param[in] p_position La position de l'élément à ajouter
 *\exception bad alloc si pas assez de mémoire
 */
 template<typename T>
 void Liste<T>::ajouter(const T & p_element, const int & p_position) {
     PRECONDITION(p_position > 0 and p_position <= m_cardinalite + 1);

     //liste vide
     if(m_dernier == nullptr) {
      m_dernier = new Noeud(p_element);
      m_dernier->m_suivant = m_dernier;
     }
     //première position
     else if (p_position == 1) {
      m_dernier->m_suivant = new Noeud(p_element, m_dernier->m_suivant);
     }
     //dernière position
     else if(p_position == m_cardinalite +1) {
      m_dernier->m_suivant = new Noeud(p_element, m_dernier->m_suivant);
      m_dernier= m_dernier->m_suivant;
     }
     //position quelconque
     else {
      elem sentinelle = _pointeurSurNoeud(p_position-1);
      sentinelle->m_suivant = new Noeud(p_element, sentinelle->m_suivant);
     }

     int cardinaliteCourante = m_cardinalite;
     m_cardinalite++;

     POSTCONDITION(cardinaliteCourante + 1 == m_cardinalite);
     POSTCONDITION(element(p_position)==p_element);
     INVARIANTS();
    }

 /**
  *\brief Elever la première occurence d'un élément
  *
  *\pre L'élément doit être présent dans la liste
  *\post La liste comprend un élément de moins
  *\post La liste est inchangée sinon
  *\param[in] p_elementARetirer L'élément à retirer
  */
 template<typename T>
 void Liste<T>::enleverEl(const T & p_elementARetirer) {
     PRECONDITION(appartient(p_elementARetirer));

     elem sentinelle = m_dernier->m_suivant;
     while(sentinelle != m_dernier && sentinelle->m_suivant->m_el != p_elementARetirer) {
      sentinelle =  sentinelle->m_suivant;
     }
     _enlever(sentinelle);

     int cardinaliteCourante = m_cardinalite;
     m_cardinalite--;

     POSTCONDITION(cardinaliteCourante -1 == m_cardinalite);
     INVARIANTS();
    }

 /**
  *\brief Enlever un élément à une certaine position
  *
  *\pre La position doit être comprise entre 1 et ...
  *\post La liste comprend un élément de moins
  *\post La liste est inchangée sinon
  *\param[in] p_position La position à effacer
  */
 template<typename T>
 void Liste<T>::enleverPos(const int & p_position) {
     PRECONDITION(p_position > 0 and p_position <= m_cardinalite);

     elem sentinelle(nullptr);
     if (p_position == 1) {
      sentinelle = m_dernier;
     }
     else {
      sentinelle = _pointeurSurNoeud(p_position -1);
     }
     _enlever(sentinelle);

     int cardinaliteCourante = m_cardinalite;
     m_cardinalite--;

     POSTCONDITION(cardinaliteCourante -1 == m_cardinalite);
     INVARIANTS();
    }

 /**
  *\brief Retourner la position d'un élément
  *
  *\pre L'élément doit être présent dans la liste
  *\post La liste est inchangée dans tous les cas
  *\param[in] p_elementATrouver L'élément à trouver
  *\return La position de l'élément est retournée
  */
 template<typename T>
 int Liste<T>::position(const T & p_elementATrouver) const {
     elem sentinelle = m_dernier->m_suivant;
     int position = 1;
     while(sentinelle != m_dernier) {
      if (sentinelle->m_el == p_elementATrouver) {
       return position;
      }
      sentinelle = sentinelle->m_suivant;
      position++;
     }
     if (m_dernier->m_el == p_elementATrouver) {
      return m_cardinalite;
     }
     PRECONDITION(false);
    }

 /**
  *\brief Afficher la liste
  *\param[in, out] p_out le flux de sortie
  *\parm[in] p_liste Une liste
  *\post La Liste est inchangée
  *\return Une référence sur le flux de sortie
  */
 template<typename T>
 std::ostream& operator <<(std::ostream & p_out, const Liste<T> & p_liste) {
     typename Liste<T>::elem sentinelle = p_liste.m_dernier->m_suivant;
     p_out << "[";
     while (sentinelle != p_liste.m_dernier) {
      p_out << sentinelle->m_el << ", ";
      sentinelle = sentinelle->m_suivant;
     }
     p_out << p_liste.m_dernier->m_el << "]";

     return p_out;
    }

 /**
  *\brief Recherche d'un élément dans la liste
  *\post La liste est inchangée
  *\param[in] p_elementATrouver L'élément à trouver
  *\return Bool indique si l'élément est dans la liste
  */
 template<typename T>
 bool Liste<T>::appartient(const T & p_elementATrouver) const {
     if (m_dernier == nullptr) {
      return false;
     }
     elem sentinelle = m_dernier->m_suivant;
     while (sentinelle != m_dernier) {
      if (sentinelle->m_el == p_elementATrouver) {
       return true;
      }
      sentinelle = sentinelle->m_suivant;
     }
     if (m_dernier->m_el == p_elementATrouver) {
      return true;
     }
     return false;
    }

 /**
  *\brief Retrourner l'élément à une certaine position
  *\pre La position est comprise entre 1 et |L|
  *\post la liste est inchangée dans tous les cas
  *\param[in] p_position La position où trouver l'élément
  *\return l'élément à la position demandée est retourné
  */
 template<typename T>
 T Liste<T>::element(const int & p_position) const {
     PRECONDITION(p_position > 0 and p_position <= m_cardinalite);
     return _pointeurSurNoeud(p_position)->m_el;
    }

 /**
  *\brief Vérifier si la Liste est vide
  *\post La liste est inchangée
  *\return Bool indique si la liste est vide
  */
 template<typename T>
 bool Liste<T>::estVide() const {
     return m_cardinalite == 0;
    }

 /**
  *\brief Retourne la cardinalité de la liste
  *\post La liste est inchangée
  *\return la cardinalité de la liste est retournée
  */
 template<typename T>
 int Liste<T>::taille() const {
     return m_cardinalite;
    }



 /**
  *\brief Eleve un noeud et gère les liaisons
  *\param[in] Un pointeur sur le noeud AVANT celui à enlever.
  *\post le noeud est enlevé
  *\post La liste est correctement liée
  */
 template<typename T>
 void Liste<T>::_enlever(elem p_precedentSentinelle) {

     elem sentinelle = p_precedentSentinelle->m_suivant;

     //un seul élément
     if(taille() == 1) {
      m_dernier = nullptr;
     }
     //premier élément
     else if (m_dernier->m_suivant == sentinelle) {
      m_dernier->m_suivant = m_dernier->m_suivant->m_suivant;
     }
     //dernier élément
     else if(m_dernier == sentinelle) {
      p_precedentSentinelle->m_suivant = m_dernier->m_suivant;
     }
     // position quelconque
     else {
      p_precedentSentinelle->m_suivant = sentinelle->m_suivant;
     }

     sentinelle->m_suivant = nullptr;
     delete sentinelle;
    }


}


#endif //LISTE_HPP
