#ifndef _MEMORIE_HPP_
#define _MEMORIE_HPP_

#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Instructie;

class Memorie
{
 public:
  ~Memorie();

  bool incarcaMemorie(const string &fisier);
  bool adaugaInstructie(Instructie *instr);
  bool adaugaInstructie(Instructie *instr, unsigned int index);
  bool eliminaInstructie(unsigned int index);
  Instructie *aduInstructie(unsigned int adr) const;
 private:
  map<unsigned int, const Instructie *> comenzi;
};

#endif
