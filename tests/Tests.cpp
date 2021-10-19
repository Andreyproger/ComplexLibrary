#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>
#include <complex.hpp>

#include <climits>
#include <cstddef>

typedef boost::mpl::list<int> test_types;

BOOST_AUTO_TEST_SUITE(TESTSUITE_Equation)

BOOST_AUTO_TEST_CASE(TEST_CHECK_Create_null_object)
{
	Complex compNum(0,0);
	BOOST_CHECK_EQUAL(compNum.real(), 0);
	BOOST_CHECK_EQUAL(compNum.image(), 0);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Create_NotNull_object)
{
	Complex compNum(1,1);
	BOOST_CHECK_EQUAL(compNum.real(), 1);
	BOOST_CHECK_EQUAL(compNum.image(), 1);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Create_Negative_object)
{
	Complex compNum(-1,-1);
	BOOST_CHECK_EQUAL(compNum.real(), -1);
	BOOST_CHECK_EQUAL(compNum.image(), -1);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Create_MAX_VALUES_object)
{
	Complex compNum(INT_MAX, INT_MIN);
	BOOST_CHECK_EQUAL(compNum.real(), INT_MAX);
	BOOST_CHECK_EQUAL(compNum.image(), INT_MIN);
}

BOOST_AUTO_TEST_SUITE_END()