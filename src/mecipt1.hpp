#ifndef _MECIPT1_HPP_
#define _MECIPT1_HPP_

#include <string>

using namespace std;

class Memorie;

class Mecipt1
{
 public:
 Mecipt1();
 ~Mecipt1();

 void interogheazaSistem(void);
 bool initializeazaSistem(const string *fisInit);
 void executaInstructieUrmatoare();

 private:
  Memorie *mem;
  unsigned int contorProgram;
  double registruS;
  double registruI;
};

#endif
