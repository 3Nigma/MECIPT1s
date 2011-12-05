#include <iostream>
#include <fstream>
#include "memorie.hpp"
#include "instructie.hpp"

Memorie::~Memorie()
{
 // d-tor implicit
 comenzi.clear();
}

bool Memorie::incarcaMemorie(const string &fisier)
{
 ifstream fCit(fisier.c_str());
 string instrCurenta;
 Instructie *instrIncarcata;

 while(!fCit.eof())
 {
  getline(fCit, instrCurenta);
  if(!instrCurenta.empty())
  {
   // elimina spatiile de la inceputul instructiei (daca exista)
   if(instrCurenta.at(0) == ' ') instrCurenta = instrCurenta.substr(instrCurenta.find_first_not_of(" "));
   if(instrCurenta.find("--") != 0)
   {
    // instructiunea curenta nu este una de tip comentariu
    cout << instrCurenta << endl;
    instrIncarcata = new Instructie(instrCurenta);
    delete instrIncarcata;
   }
  }
 }

 fCit.close();
 return true;
}

//bool Memorie::adaugaInstructie(Instructie * instr)
//{
// return this->adaugaInstructie(instr, comenzi.size());
//}

bool Memorie::adaugaInstructie(Instructie * instr, unsigned int index = comenzi.size())
{
 if(index > comenzi.size()) return false;
 else if(index == comenzi.size()) comenzi.push_back(instr);

 comenzi.insert({index, instr});
 return true;
}

bool Memorie::eliminaInstructie(unsigned int index)
{
 if(index >= comenzi.size()) return false;

 //list<Instructie *>::iterator pozStergere = comenzi.begin();
 //advance(pozStergere, index);
 //comenzi.erase(pozStergere);
 return true;
}

Instructie *Memorie::aduInstructie(unsigned int adr) const
{
 if(adr >= comenzi.size()) return nullptr;

 return nullptr;//comenzi.at(adr);
}
