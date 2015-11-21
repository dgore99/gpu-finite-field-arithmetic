#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

#include "../include/polynomial.h"

class polynomial_test : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(polynomial_test);
	
	CPPUNIT_TEST(test_add1);
	CPPUNIT_TEST(test_add2);
	CPPUNIT_TEST(test_add3);
	
	CPPUNIT_TEST_SUITE_END();
	
	public:
	
	protected:
		
	
	private:
}
