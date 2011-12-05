#include "TestMemorie.cpp"
#include <cppunit/ui/text/TextTestRunner.h>

#define FIS_INCARCATOR instrIncarcator

using namespace CppUnit;

int main(int argc, char* argv[])
{
 TextTestRunner evaluator;

 evaluator.addTest(TestMemorie::suite());
 evaluator.run("");

 return 0;
}
