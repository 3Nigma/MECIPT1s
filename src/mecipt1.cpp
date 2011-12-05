#include "mecipt1.hpp"
#include "memorie.hpp"
#include "instrexcept.hpp"

Mecipt1::Mecipt1()
        : contorProgram(0), registruS(0), registruI(0)
{

}

Mecipt1::~Mecipt1()
{
 delete mem;
}

void Mecipt1::executaInstructieUrmatoare()
{
 const Instructie *instr = mem->aduInstructie(contorProgram);
 
}

void Mecitp1::interogheazaSistem()
{

}

bool Mecipt1::initializeazaSistem(const string &fisInit)
{
 try
 {
  mem = new Memorie(fisInit);
 }
 catch(InstrExcept ex)
 {
  return false;
 }

 return true;
}
