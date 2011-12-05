#ifndef _INSTRUCTIE_HPP_
#define _INSTRUCTIE_HPP_

//#include <iostream>
#include <string>

using namespace std;

class Instructie
{
 enum class TipInstr { O = 1, U, UN, UM, UMN, A, SC, AM, SCM, IN,
                       INR, D, MS, T, TN, TP, Tf, DLS, DLD, DS,
                       DD, ME, ISME, UI, CU, IL, AC };
 public:
  Instructie(string);

  bool esteFormatOctal(const string &);
  void aplicaInstructie(double &regS, double &regI, unsigned int &cntProg); 
 private:
  TipInstr aromainstr;
  int valImediata;
};

#endif
