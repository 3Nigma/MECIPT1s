#include <iostream>
#include <cstdio>

#include "memorie.hpp"
#include "mecipt1.hpp"

using namespace std;

void afiseazaModFolosire(void);

int main(int argc, char *argv[])
{
 if(argc != 2)
 {
  afiseazaModFolosire();
  exit(EXIT_FAILURE);
 }

 Memorie *memSis = new Memorie();
 Mecipt1 *masina;

 memSis->incarcaMemorie(argv[1]);

 delete memSis;
 //delete masina;
 return 0;
}

void afiseazaModFolosire(void)
{
 cout << "Simulatorul informatic al calculatorului MECIPT1 (primul calculator universitar Romanesc realizat in 1961)" << endl
      << "Realizat de Victor ADASCALITEI (2011, Tm/Ro^UPT) > victor.adascalitei@gmail.com. Toate drepturile rezervate." << endl
      << "Mod de folosire : mecipt1s <fis_incarcator>" << endl
      << "Unde :" << endl
      << "      <fis_incarcator> - fisier ce contine instructiunile initiale incarcate in memoria Mecipt1-ului" << endl;
}
