#define BOOST_TEST_MODULE 
#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>
#include <complex.hpp>

#include <iostream>

#include <climits>
#include <cstddef>

#include <cmath>

const double TOLERANCE = 0.01;

//typedef boost::mpl::list<int> test_types;

BOOST_AUTO_TEST_SUITE(TESTSUITE_null_object)

BOOST_AUTO_TEST_CASE(TEST_CHECK_null_object)
{
	BOOST_TEST_CONTEXT("Create_null_object")
	{
		const Complex compNum(0,0);
		BOOST_CHECK_EQUAL(compNum.real(), 0);
		BOOST_CHECK_EQUAL(compNum.image(), 0);
	}

	BOOST_TEST_CONTEXT("Create_NotNull_object")
	{
		const Complex compNum(1,1);
		BOOST_CHECK_EQUAL(compNum.real(), 1);
		BOOST_CHECK_EQUAL(compNum.image(), 1);
	}

	BOOST_TEST_CONTEXT("Create_Negative_object")
	{
		const Complex compNum(-1,-1);
		BOOST_CHECK_EQUAL(compNum.real(), -1);
		BOOST_CHECK_EQUAL(compNum.image(), -1);
	}

	BOOST_TEST_CONTEXT("Create_MAX_VALUES_object")
	{
		const Complex compNum(INT_MAX, INT_MIN);
		BOOST_CHECK_EQUAL(compNum.real(), INT_MAX);
		BOOST_CHECK_EQUAL(compNum.image(), INT_MIN);
	}
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TESTSUITE_OPERATORS_PLUS)

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Plus_1)
{
		const Complex compNum1(0, 0);
		const Complex compNum2(1, 1);

		Complex compNumResult(1,1);	
		BOOST_CHECK_EQUAL(compNum1 + compNum2, compNumResult);
}
	
BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Plus_2)
{
		const Complex compNum1(0, INT_MAX);
		const Complex compNum2(INT_MAX, 0);

		const Complex compNumResult(INT_MAX, INT_MAX);	
		BOOST_CHECK_EQUAL(compNum1 + compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Plus_3)
{
		const double Num1(5);
		const Complex compNum2(5, 5);

		const Complex compNumResult(10, 5);	
		BOOST_CHECK_EQUAL(Num1 + compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Plus_4)
{
		const double Num2(5);
		const Complex compNum1(5, 5);

		const Complex compNumResult(10, 5);	
		BOOST_CHECK_EQUAL(compNum1 + Num2, compNumResult);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TESTSUITE_OPERATORS_MINUS)

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Minus_1)
{
	const Complex compNum1(INT_MAX, INT_MAX);
	const Complex compNum2(INT_MAX, INT_MAX);

	const Complex compNumResult(0, 0);	
	BOOST_CHECK_EQUAL(compNum1 - compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Minus_N)
{
	const Complex compNum1(INT_MAX, INT_MAX);
	const Complex compNum2(0, 0);
	//BOOST_TEST_MESSAGE(INT_MIN);

	const Complex compNumResult(INT_MAX, INT_MAX);	
	BOOST_CHECK_EQUAL(compNum1 + compNum2, compNumResult);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TESTSUITE_OPERATORS_MULTIPLY)

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Multiply_1)
{
	Complex compNum1(1, 1);
	Complex compNum2(1, 1);

	Complex compNumResult(0, 2);
	BOOST_CHECK_EQUAL(compNum1 * compNum2, compNumResult);
}

 BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TESTSUITE_OPERATORS_DEVIDE)

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Devide_1)
{
	Complex compNum2(-2, 1);
	Complex compNum1(0, 0);

	BOOST_TEST_CONTEXT("Complex Number is Null?")
	{
		BOOST_REQUIRE(compNum2 != Complex());
	}

	Complex compNumResult(0, 0);	
	BOOST_CHECK_EQUAL(compNum1 / compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Devide_2)
{
	Complex compNum1(1, 1);
	Complex compNum2(1, 1);

	BOOST_TEST_CONTEXT("Complex Number is Null?")
	{
		BOOST_REQUIRE(compNum2 != Complex());
	}

	Complex compNumResult(1, 0);	
	//BOOST_CHECK_EQUAL(compNum1 / compNum2, compNumResult);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( BLOCK_OPERATORS )

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_EQUAL)
{
	const Complex compNum1(1, 10);
	const Complex compNum2(1, 10);

	BOOST_CHECK_EQUAL(compNum1, compNum2);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_NOT_EQUAL)
{
	BOOST_TEST_CONTEXT("Unequal real part")
	{
		const Complex compNum1(2, 10);
		const Complex compNum2(1, 10);

		BOOST_CHECK(compNum1 != compNum2);
	}

	BOOST_TEST_CONTEXT("Unequal image part")
	{
		const Complex compNum1(1, 11);
		const Complex compNum2(1, 10);

		BOOST_CHECK(compNum1 != compNum2);
	}
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_ASSIGN)
{
	const Complex compNum1(1, 10);
	Complex compNum2;

	compNum2 = compNum1;

	BOOST_CHECK_EQUAL(compNum2, compNum1);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_PLUSASSIGN)
{
	Complex compNum1(1, 10);
	const Complex compNum2(-1, -10);

	compNum1 += compNum2;

	const Complex answer;

	BOOST_CHECK_EQUAL(compNum1, answer);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_MINESASSIGN)
{
	Complex compNum1(1, 10);
	const Complex compNum2(1, 10);

	compNum1 -= compNum2;

	const Complex answer;

	BOOST_CHECK_EQUAL(compNum1, answer);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_MULTIPLYASSIGN)
{
	Complex compNum1(1, 10);
	const Complex compNum2(1, 10);

	compNum1 *= compNum2;

	const Complex answer(-99, 20);

	//BOOST_CHECK_EQUAL(compNum1, answer);
	BOOST_CHECK(answer == compNum1);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_DEVIDEASSIGN)
{
	Complex compNum1(1, 10);
	const Complex compNum2(1, 10);

	compNum1 /= compNum2;

	const Complex answer(-99, 20);

	BOOST_CHECK_CLOSE_FRACTION(compNum1.real(), answer.real(), 0.01);
	BOOST_CHECK_CLOSE_FRACTION(compNum1.image(), answer.image(), 0.01);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_EQUALEQUAL)
{
	const Complex compNum1(99, 99);
	const Complex compNum2(99, 99);
	bool result = (compNum1 == compNum2);

	BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_EQUAL_NUMBER)
{
	const Complex compNum1(99, 99);
	const int Num2 = 99;
	bool result = (compNum1 == Num2);

	BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_EQUAL_NUMBER_BY_COMPLEX)
{
	const Complex compNum1(99, 99);
	const int Num2 = 99;
	bool result = (Num2 == compNum1);

	BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_NOTEQUALEQUAL)
{
	const Complex compNum1(9, 99);
	const Complex compNum2(99, 99);
	bool result = (compNum1 != compNum2);

	BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_NOTEQUAL_NUMBER)
{
	const Complex compNum1(9, 99);
	const int Num2 = 99;
	bool result = (compNum1 != Num2);

	BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_NOTEQUAL_NUMBER_BY_COMPLEX)
{
	const Complex compNum1(9, 99);
	const int Num2 = 99;
	bool result = (Num2 != compNum1);

	BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_SUITE_END()
