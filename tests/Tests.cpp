#define BOOST_TEST_MODULE 
#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>
#include <complex.hpp>

#include <climits>
#include <cstddef>

typedef boost::mpl::list<int> test_types;

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

BOOST_AUTO_TEST_SUITE(TESTSUITE_OPERATORSOBJECT)

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Plus_1)
{
	const Complex compNum1(INT_MAX, INT_MAX);
	const Complex compNum2(INT_MAX, INT_MAX);

	const Complex compNumResult(INT_MAX-1, INT_MAX-1);	
	BOOST_CHECK_EQUAL(compNum1 + compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Plus_2)
{
	const Complex compNum1(0, INT_MAX);
	const Complex compNum2(INT_MAX, 0);

	const Complex compNumResult(INT_MAX, INT_MAX);	
	BOOST_CHECK_EQUAL(compNum1 + compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Mines_1)
{
	const Complex compNum1(INT_MAX, INT_MAX);
	const Complex compNum2(INT_MAX, INT_MAX);

	const Complex compNumResult(0, 0);	
	BOOST_CHECK_EQUAL(compNum1 - compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Mines_2)
{
	const Complex compNum1(0, INT_MAX);
	const Complex compNum2(INT_MAX, 0);

	const Complex compNumResult(-INT_MAX, INT_MAX);	
	BOOST_CHECK_EQUAL(compNum1 - compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Multiply_1)
{
	const Complex compNum1(2, 2);
	const Complex compNum2(2, 2);

	const Complex compNumResult(0, 0);	
	BOOST_CHECK_EQUAL(compNum1 * compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Multiply_2)
{
	const Complex compNum1(0, INT_MAX);
	const Complex compNum2(1, 0);

	const Complex compNumResult(1, INT_MAX);	
	BOOST_CHECK_EQUAL(compNum1 - compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Devide_1)
{
	const Complex compNum1(2, 2);
	const Complex compNum2(2, 2);

	const Complex compNumResult(0, 0);	
	BOOST_CHECK_EQUAL(compNum1 / compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_Devide_2)
{
	const Complex compNum1(0, INT_MAX);
	const Complex compNum2(1, 0);

	const Complex compNumResult(1, INT_MAX);	
	BOOST_CHECK_EQUAL(compNum1 / compNum2, compNumResult);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_EQUAL)
{
	const Complex compNum1(1, 10);
	const Complex compNum2(1, 10);

	BOOST_CHECK_EQUAL(compNum1, compNum2);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_NOT_EQUAL)
{
	const Complex compNum1(1, 10);
	const Complex compNum2(1, 10);

	BOOST_CHECK(compNum1 != compNum2);
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

	const Complex answer(20, 0);

	BOOST_CHECK_EQUAL(compNum1, answer);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_DEVIDEASSIGN)
{
	Complex compNum1(1, 10);
	const Complex compNum2(1, 20);

	compNum1 /= compNum2;

	const Complex answer(20, 0);

	BOOST_CHECK_EQUAL(compNum1, answer);
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
	const Complex compNum1(99, 99);
	const Complex compNum2(99, 99);
	bool result = (compNum1 != compNum2);

	BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_NOTEQUAL_NUMBER)
{
	const Complex compNum1(99, 99);
	const int Num2 = 99;
	bool result = (compNum1 != Num2);

	BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_CASE(TEST_CHECK_Operator_NOTEQUAL_NUMBER_BY_COMPLEX)
{
	const Complex compNum1(99, 99);
	const int Num2 = 99;
	bool result = (Num2 != compNum1);

	BOOST_CHECK_EQUAL(result, true);
}

// int& abs() const;
BOOST_AUTO_TEST_CASE(TEST_CHECK_ABS)
{
	BOOST_TEST_CONTEXT("First compare check abs")
	{
		const Complex compNum(1, 1);
		const double result = 1.41421; 
		BOOST_CHECK_CLOSE_FRACTION(compNum.abs(), result, 0.0001);
	}

	BOOST_TEST_CONTEXT("Second compare check abs")
	{
		const Complex compNum(0, 0);
		const double result = 0; // implicit conversion 
		BOOST_CHECK_CLOSE_FRACTION(compNum.abs(), result, 0.0001);
	}

	BOOST_TEST_CONTEXT("Second compare check abs for max num")
	{
		const Complex compNum(INT_MAX, INT_MAX);
		const double result = INT_MAX; // implicit conversion 
		BOOST_CHECK_CLOSE_FRACTION(compNum.abs(), result, 0.0001);
	}
}

// BOOST_AUTO_TEST_CASE(TEST_CHECK_CONJ)
// {
// 	//Complex& conj(const Complex& complValue);
// 	BOOST_TEST_CONTEXT("First compare check abs")
// 	{
// 		const Complex compNumber = Complex(1,1);
// 		const Complex answerNumber = compNumber.conj();
// 		BOOST_CHECK_EQUAL(compNumber, -answerNumber);
// 	}
// }

// int& arg() const;
// BOOST_AUTO_TEST_CASE(TEST_CHECK_ABS)
// {
// 	BOOST_TEST_CONTEXT("First compare check arg")
// 	{
// 	}
// }
	// int& norm() const;

	// Complex& conj(const Complex& complValue);
	// Complex& polar(const Complex& complValue);
	// Complex& proj(const Complex& complValue);

BOOST_AUTO_TEST_SUITE_END()