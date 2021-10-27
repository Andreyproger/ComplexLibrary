#pragma once
#include <iostream>
#include <sstream>

class Complex
{
public:

	Complex():
		m_real(0),
		m_image(0)
	{}

	Complex(const double real, const double image):
		m_real(real),
		m_image(image)
	{}

	const double real() const
	{
		return m_real;
	}

	const double image() const
	{
		return m_image;
	}

	friend std::istream& operator>> (std::istream& is, Complex& value)
	{
		return is >> value;
	}

	friend std::ostream& operator<< (std::ostream& os, const Complex& value)
	{
		return os << value;
	}

	Complex& operator=(const Complex& complValue);

	private:
	friend bool operator==(const Complex& lhs, const Complex& rhs);
	friend bool operator==(const Complex& lhs, const double val);
	friend bool operator==(const double val, const Complex& rhs);

	friend bool operator!=(const Complex& lhs, const Complex& rhs);
	friend bool operator!=(const Complex& lhs, const double val);
	friend bool operator!=(const double val, const Complex& rhs);

	friend Complex operator+ (const Complex& compNum1, const Complex& compNum2);
	friend Complex operator+ (const double val, const Complex& compNum);
	friend Complex operator+ (const Complex& compNum, const double val);

	friend Complex operator- (const Complex& compNum1, const Complex& compNum2);
	friend Complex operator- (const double val, const Complex& compNum);
	friend Complex operator- (const Complex& compNum, const double val);

	friend Complex operator* (const Complex& compNum1, const Complex& compNum2);

	friend Complex operator/ (const Complex& compNum1, const Complex& compNum2);

	Complex& operator+=(const Complex& complValue);
	Complex& operator-=(const Complex& complValue);

	Complex& operator*=(const Complex& complValue);
	Complex& operator/=(const Complex& complValue);

	double& abs() const;
	// double& arg() const;
	// double& norm() const;

	Complex& conj(const Complex& complValue);
	// Complex& polar(const Complex& complValue);
	// Complex& proj(const Complex& complValue);

	private:
		double m_real = 0;
		double m_image = 0;
};

bool operator==(const Complex& lhs, const Complex& rhs)
{
	return (lhs.real() == rhs.real() && lhs.image() == rhs.image());
}

bool operator==(const Complex& lhs, const double val)
{
	return (lhs.real() == val);
}

bool operator==(const double val, const Complex& rhs)
{
	return (rhs.real() == val);
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
	return !(operator==(lhs,rhs));
}

bool operator!=(const Complex& lhs, const double val)
{
	return !(operator==(lhs,val));
}

bool operator!=(const double val, const Complex& rhs)
{
	return !(operator==(val,rhs));
}

Complex operator+ (const Complex& compNum1, const Complex& compNum2)
{
	return Complex(compNum1.real() + compNum2.real(), compNum1.m_image + compNum2.m_image);
}

Complex operator+ (const double Num1, const Complex& compNum2)
{
	return Complex(Num1 + compNum2.real(), compNum2.image());
}

Complex operator+ (const Complex& compNum1, const double Num2)
{
	return Complex(compNum1.real() + Num2, compNum1.image());
}

Complex operator- (const Complex& compNum1, const Complex& compNum2)
{
	return Complex(compNum1.real() - compNum2.real(), compNum1.m_image - compNum2.m_image);
}

Complex operator* (const Complex& compNum1, const Complex& compNum2)
{
	return Complex(compNum1.real()*compNum2.real() - compNum1.image()*compNum2.image(), compNum1.real()*compNum2.image() + compNum1.image()*compNum2.real());
}

Complex operator/ (const Complex& compNum1, const Complex& compNum2)
{
	const double deniminator = compNum2.real()*compNum2.real() + compNum2.image()*compNum2.image();

	return Complex(
					(compNum1.real()*compNum2.real()+compNum1.image()*compNum2.image())/deniminator, 
					(compNum1.image()*compNum2.real() - compNum1.real()*compNum2.image())/deniminator
					);
}
