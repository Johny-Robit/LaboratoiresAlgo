#include <algorithm>
#include <array>
#include <iostream>
#include <string>

class Etudiant
{
public:

  Etudiant (const std::string& p_nom, int p_points) : m_nom (p_nom), m_points (p_points) { };

  //private:
  std::string m_nom;
  int m_points;
};

int
main ()
{
  std::array<Etudiant, 8> resultats {
    {
      { "Albert", 3},
      { "Ben", 5},
      { "Christine", 2},
      { "Dan", 8},
      { "Enchilada", 4},
      { "Francis", 1},
      { "Greg", 3},
      { "Hagrid", 5}
    }};

  const auto meilleur { 
    std::max_element (resultats.begin (), resultats.end (), /* lambda */)// retourne un iterator
	};

  std::cout << meilleur->m_nom << " est le meilleur étudiant\n"; // on doit déréférencer l'itarateur pour avoir accès à l'élément

  return 0;
}