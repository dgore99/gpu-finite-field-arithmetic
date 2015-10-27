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
	
	CPPUNIT_TEST(test_std_ctor);
	
	CPPUNIT_TEST_SUITE_END();
	
	public:
	
	protected:
		void test_std_ctor(void)
		{
			unsigned coeffs[4] = {0,1,2,3};
			polynomial p(coeffs,3,7);
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Degree not initialized correctly", 3, p.get_degree());
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Charecteristic not initialized correctly", 7, p.get_charecteristic());
			
			unsigned* p_coeffs = p.get_coeffs();
			for (unsigned i = 0 ; i < 4 ; i++)
				CPPUNIT_ASSERT_EQUAL_MESSAGE("Coeffs not stored/retrieved properly", coeffs[i], p_coeffs[i]);
		}
		
		void test_move_ctor(void)
		{
			unsigned coeffs[4] = {0,1,2,3};
			polynomial p(polynomial(coeffs,3,7));
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Degree not initialized correctly", 3, p.get_degree());
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Charecteristic not initialized correctly", 7, p.get_charecteristic());
			
			unsigned* p_coeffs = p.get_coeffs();
			for (unsigned i = 0 ; i < 4 ; i++)
				CPPUNIT_ASSERT_EQUAL_MESSAGE("Coeffs not stored/retrieved properly", coeffs[i], p_coeffs[i]);
		}
	
	private:
}
