#include <cppunit/TestCase.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

using namespace CppUnit;

class TestMemorie : public TestFixture
{
 public:
  void setUp()
  {
   
  }
  void tearDown()
  {
  }
  static Test *suite()
  {
   TestSuite *suitaDeTeste = new TestSuite("TestMemorie");
   suitaDeTeste->addTest(new TestCaller<TestMemorie>("testeazaComentarii",
                                                     &TestMemorie::testeazaComentarii));

   return suitaDeTeste;
  }

  void testeazaComentarii()
  {
   CPPUNIT_ASSERT(!2);
   CPPUNIT_ASSERT(1 == 2);
  }
};
