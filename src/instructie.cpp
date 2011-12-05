#include "instructie.hpp"
#include "instrexcept.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>

Instructie::Instructie(string txtInstr)
{
 // presupune ca textul instructiunii nu are spatii la inceput => campul de operatiune se extrage din prima bucata direct

 size_t indexSpatiu = txtInstr.find_first_of(" ");

 if(indexSpatiu != string::npos)
 {
  // extragem operandul
  string op = txtInstr.substr(0, indexSpatiu);
  std::transform(op.begin(), op.end(), op.begin(), ::toupper);
  if(op == "O") aromainstr = TipInstr::O;
  else if(op == "U") aromainstr = TipInstr::U;
  else if(op == "UN") aromainstr = TipInstr::UN;
  else if(op == "UM") aromainstr = TipInstr::UM;
  else if(op == "UMN") aromainstr = TipInstr::UMN;
  else if(op == "A") aromainstr = TipInstr::A;
  else if(op == "SC") aromainstr = TipInstr::SC;
  else if(op == "AM") aromainstr = TipInstr::AM;
  else if(op == "SCM") aromainstr = TipInstr::SCM;
  else if(op == "IN") aromainstr = TipInstr::IN;
  else if(op == "INR") aromainstr = TipInstr::INR;
  else if(op == "D") aromainstr = TipInstr::D;
  else if(op == "MS") aromainstr = TipInstr::MS;
  else if(op == "T") aromainstr = TipInstr::T;
  else if(op == "TN") aromainstr = TipInstr::TN;
  else if(op == "TP") aromainstr = TipInstr::TP;
  else if(op == "TF") aromainstr = TipInstr::Tf;
  else if(op == "DLS") aromainstr = TipInstr::DLS;
  else if(op == "DLD") aromainstr = TipInstr::DLD;
  else if(op == "DS") aromainstr = TipInstr::DS;
  else if(op == "DD") aromainstr = TipInstr::DD;
  else if(op == "ME") aromainstr = TipInstr::ME;
  else if(op == "ISME") aromainstr = TipInstr::ISME;
  else if(op == "UI") aromainstr = TipInstr::UI;
  else if(op == "CU") aromainstr = TipInstr::CU;
  else if(op == "IL") aromainstr = TipInstr::IL;
  else if(op == "AC") aromainstr = TipInstr::AC;
  else
   throw InstrExcept("Nu recunosc instructiunea curenta!");
  txtInstr = txtInstr.substr(op.length());

  // extragem valoarea octala imediat urmatoare
  size_t indexNonSpatiu = txtInstr.find_first_not_of(" ");
  if(indexNonSpatiu != string::npos)
  {
   string vImedSir = txtInstr.substr(indexNonSpatiu);

   if(esteFormatOctal(vImedSir))
   {
    valImediata = atoi(vImedSir.c_str());
   }
   else throw InstrExcept("Valoarea imediata nu este corect formatata (trebuie scrisa in baza 8)!");
  }
  else throw InstrExcept("Valoarea imediata nu exista!");
 }
 else throw InstrExcept("Instructiunea este prost formatata!");
}

bool Instructie::esteFormatOctal(const string &adr)
{
 size_t adrNeOctal = adr.find_first_not_of("01234567");
 return (adrNeOctal == string::npos);
}
