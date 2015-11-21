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
	CPPUNIT_TEST(test_move_ctor);
	CPPUNIT_TEST(test_copy_ctor);
	CPPUNIT_TEST(test_add1);
	CPPUNIT_TEST(test_add2);
	CPPUNIT_TEST(test_add3);
	
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
		
		void test_copy(void)
		{
			unsigned coeffs[4] = {0,1,2,3};
			polynomial p(coeffs, 3, 7);
			polynomial q(p.copy());
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Degree not correct", 3, q.get_degree());
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Charecteristic not correct", 7, q.get_charecteristic());
			
			unsigned* q_coeffs = q.get_coeffs();
			for (unsigned i = 0 ; i < 4 ; i++)
				CPPUNIT_ASSERT_EQUAL_MESSAGE("Coeffs not stored/retrieved properly", coeffs[i], q_coeffs[i]);
		}
		
		void test_add1(void)
		{
			unsigned	p_coeffs[4]	= {0,1,2,3};
			unsigned	q_coeffs[4]	= {0,6,2,4};
			unsigned	charec		= 7;
			
			polynomial	p(p_coeffs, 3, charec);
			polynomial	q(q_coeffs, 3, charec);
			polynomial	r(p+q);
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong charecteristic", charec, r.get_charecteristic());
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong degree", 2, r.get_degree());
			
			unsigned	e_coeffs[3]	= {0,0,4};
			unsigned*	r_coeffs	= r.get_coeffs();
			
			for ( unsigned i = 0 ; i < 4 ; i++) 
				CPPUNIT_ASSERT_EQUAL_MESSAGE("Bad coeffs", e_coeffs[i], r_coeffs[i]);
		}
		
		void test_add2(void)
		{
			unsigned	p_coeffs[4]	= {0,1,2,3};
			unsigned	q_coeffs[3]	= {0,6,2};
			unsigned	charec		= 7;
			
			polynomial	p(p_coeffs, 3, charec);
			polynomial	q(q_coeffs, 2, charec);
			polynomial	r(p+q);
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong charecteristic", charec, r.get_charecteristic());
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong degree", 3, r.get_degree());
			
			unsigned	e_coeffs[4]	= {0,0,4,3};
			unsigned*	r_coeffs	= r.get_coeffs();
			
			for ( unsigned i = 0 ; i < 5 ; i++) 
				CPPUNIT_ASSERT_EQUAL_MESSAGE("Bad coeffs", e_coeffs[i], r_coeffs[i]);
		}
		
		void test_add3(void)
		{
			unsigned	p_coeffs[4]	= {0,1,2,3};
			unsigned	q_coeffs[3]	= {0,6,2};
			unsigned	charec		= 7;
			
			polynomial	p(p_coeffs, 3, charec);
			polynomial	q(q_coeffs, 2, charec);
			polynomial	r(q+p);
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong charecteristic", charec, r.get_charecteristic());
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong degree", 3, r.get_degree());
			
			unsigned	e_coeffs[4]	= {0,0,4,3};
			unsigned*	r_coeffs	= r.get_coeffs();
			
			for ( unsigned i = 0 ; i < 5 ; i++) 
				CPPUNIT_ASSERT_EQUAL_MESSAGE("Bad coeffs", e_coeffs[i], r_coeffs[i]);
		}
		
		void test_mult(void)
		{
			unsigned	p_coeffs[4]	= {0,1,2,3};
			unsigned	q_coeffs[3]	= {0,6,2};
			unsigned	charec		= 7;
			
			polynomial	p(p_coeffs, 3, charec);
			polynomial	q(q_coeffs, 2, charec);
			polynomial	r(p*q);
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong charecteristic", charec, r.get_charecteristic());
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong degree", 5, r.get_degree());
			
			unsigned	e_coeffs[6]	= {0,0,6,0,1,6};
			unsigned*	r_coeffs	= r.get_coeffs();
			
			for ( unsigned i = 0 ; i < 7 ; i++) 
				CPPUNIT_ASSERT_EQUAL_MESSAGE("Bad coeffs", e_coeffs[i], r_coeffs[i]);
		}
		
		void test_scalar_mult(void)
		{
			unsigned	p_coeffs[4]	= {0,1,2,3};
			unsigned	charec		= 7;
			unsigned	mult		= charec - 1;
			
			polynomial	p(p_coeffs, 3, charec);
			polynomial	r(mult*p);
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong charecteristic", charec, r.get_charecteristic());
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong degree", 3, r.get_degree());
			
			unsigned	e_coeffs[4]	= {0, mult, 2*mult%charec, 3*mult%charec};
			unsigned*	r_coeffs	= r.get_coeffs();
			
			for ( unsigned i = 0 ; i < 5 ; i++) 
				CPPUNIT_ASSERT_EQUAL_MESSAGE("Bad coeffs", e_coeffs[i], r_coeffs[i]);
		}
	
	private:
}
