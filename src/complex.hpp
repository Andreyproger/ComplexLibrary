#pragma once
#include <sstream>
//MAKE class template
//template<typename _T>

class Complex{
	//template<typename _T>
public:

	Complex(const int real = 0, const int image = 0)
		: m_real(real)
		, m_image(image)
	{}

	const int real() const;

	const int image() const;

	friend std::istream& operator>> (std::istream& is, int& value);
	friend std::ostream& operator<< (const std::ostream& _stream, const int& value);

	// list operators and operations https://ru.wikipedia.org/wiki/%D0%9E%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80%D1%8B_%D0%B2_C_%D0%B8_C%2B%2B 

	friend Complex operator+ (const Complex& compNum1, const Complex& compNum2);
	friend Complex operator- (const Complex& compNum1, const Complex& compNum2);

	friend Complex operator* (const Complex& compNum1, const Complex& compNum2);
	friend Complex operator/ (const Complex& compNum1, const Complex& compNum2);

	friend bool operator==(const Complex lhs, const Complex rhs);
	friend bool operator==(const Complex lhs, const int val);
	friend bool operator==(const int val, const Complex rhs);

	friend bool operator!=(const Complex lhs, const Complex rhs);
	friend bool operator!=(const Complex lhs, const int val);
	friend bool operator!=(const int val, const Complex rhs);

	Complex& operator=(const Complex& complValue);

	Complex& operator+=(const Complex& complValue);
	Complex& operator-=(const Complex& complValue);

	Complex& operator*=(const Complex& complValue);
	Complex& operator/=(const Complex& complValue);

	int& abs() const;
	int& arg() const;
	int& norm() const;

	Complex& conj(const Complex& complValue);
	Complex& polar(const Complex& complValue);
	Complex& proj(const Complex& complValue);

	private:
		int m_real = 0;
		int m_image = 0;
};
//if implement template class need implementation specialization