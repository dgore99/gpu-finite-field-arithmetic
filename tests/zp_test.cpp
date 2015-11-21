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

#include "../include/zp.h"

using gpu_finite_field::mod;
using gpu_finite_field::mod_add;
using gpu_finite_field::mod_sub;
using gpu_finite_field::mod_mul;
using gpu_finite_field::mod_exp;
using gpu_finite_field::mod_inv;

class zp_test : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(zp_test);

	CPPUNIT_TEST(test_mod_pos_greater);
	CPPUNIT_TEST(test_mod_pos_lesser);
	CPPUNIT_TEST(test_mod_neg_greater);
	CPPUNIT_TEST(test_mod_neg_lesser);
	CPPUNIT_TEST(test_add);
	CPPUNIT_TEST(test_sub);
	CPPUNIT_TEST(test_mul);
	CPPUNIT_TEST(test_exp);
	CPPUNIT_TEST(test_inv);

	CPPUNIT_TEST_SUITE_END();

	public:
	protected:
        void test_mod_pos_greater(void)
        {
        	int			n(100);
        	unsigned	p(11);
        	unsigned	e(1);
        	unsigned	o(mod(n, p));

        	CPPUNIT_ASSERT_EQUAL_MESSAGE("Mod 1 failed", e, o);
        }
        void test_mod_pos_lesser(void)
        {
        	int			n(1);
        	unsigned	p(11);
        	unsigned	e(1);
        	unsigned	o(mod(n, p));

        	CPPUNIT_ASSERT_EQUAL_MESSAGE("Mod 2 failed", e, o);
        }
        void test_mod_neg_greater(void)
        {
        	int			n(-100);
        	unsigned	p(11);
        	unsigned	e(10);
        	unsigned	o(mod(n, p));

        	CPPUNIT_ASSERT_EQUAL_MESSAGE("Mod 3 failed", e, o);
        }
        void test_mod_neg_lesser(void)
        {
        	int			n(-1);
        	unsigned	p(11);
        	unsigned	e(10);
        	unsigned	o(mod(n, p));

        	CPPUNIT_ASSERT_EQUAL_MESSAGE("Mod 4 failed", e, o);
        }
        void test_add(void)
        {
        	unsigned	n(3), m(10);
        	unsigned	p(11);
        	unsigned	e(2);
        	unsigned	o(mod_add(n, m, p));

			CPPUNIT_ASSERT_EQUAL_MESSAGE("Mod Add failed", e, o);
        }
        void test_sub(void)
        {
        	unsigned	n(3), m(10);
        	unsigned	p(11);
        	unsigned	e(4);
        	unsigned	o(mod_sub(n, m, p));

			CPPUNIT_ASSERT_EQUAL_MESSAGE("Mod Sub failed", e, o);
        }
        void test_mul(void)
        {
        	unsigned	n(3), m(10);
        	unsigned	p(11);
        	unsigned	e(8);
        	unsigned	o(mod_mul(n, m, p));

			CPPUNIT_ASSERT_EQUAL_MESSAGE("Mod Mul failed", e, o);
        }
        void test_exp(void)
        {
        	unsigned	n(10), k(9);
        	unsigned	p(11);
        	unsigned	e(10);
        	unsigned	o(mod_exp(n, k, p));

			CPPUNIT_ASSERT_EQUAL_MESSAGE("Mod Exp failed", e, o);
        }
        void test_inv(void)
        {
        	unsigned	n(10);
        	unsigned	p(11);
        	unsigned	e(10);
        	unsigned	o(mod_inv(n, p));

			CPPUNIT_ASSERT_EQUAL_MESSAGE("Mod Inv failed", e, o);
        }
};
