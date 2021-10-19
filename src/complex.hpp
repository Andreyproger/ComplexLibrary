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

	friend Complex operator+ (const Complex& compNum1, const Complex& compNum2);
	friend Complex operator- (const Complex& compNum1, const Complex& compNum2);

	private:
		int m_real = 0;
		int m_image = 0;
};
//need todo specialization