#include "complex_t.hpp"

complex_t::complex_t() : real(0.0), imaginary(0.0)
{}

complex_t::complex_t(float rl, float img) : real(rl), imaginary(img)
{}

complex_t::complex_t(const complex_t&copy)
{
	real = copy.real;
	imaginary = copy.imaginary;
} 

float complex_t::real_() const
{
	return real;
}

float complex_t::imaginary_() const
{
	return imaginary;
}

bool complex_t::operator == (const complex_t& c2)
{
	if ((real == c2.real) && (imaginary == c2.imaginary))
		return true;
}

complex_t& complex_t::operator = (const complex_t& result)
{
	if (this != &result) {
		real = result.real;
		imaginary = result.imaginary;
	}
	return *this;
}

istream& operator >> (istream& is, complex_t& result)
{
	is >> result.real >> result.imaginary;
	return is;
}

ostream& operator << (ostream& os, complex_t& result)
{
	if (result.imaginary < 0)
	{
		os << result.real << result.imaginary << "i" << endl;
	}
	else
		os << result.real << "+" << result.imaginary << "i" << endl;
	return os;
}

complex_t complex_t::operator * (const complex_t& c2) const
{
	complex_t tmp(*this);
	tmp *= c2;
	return tmp; 
}

complex_t complex_t::operator / (const complex_t& c2) const
{
	complex_t tmp(*this);
	tmp /= c2;
	return tmp;
}

complex_t& complex_t::operator += (const complex_t& c2)
{
	real += c2.real;
	imaginary += c2.imaginary;
	return *this;
}

complex_t& complex_t::operator -= (const complex_t& c2)
{
	real -= c2.real;
	imaginary -= c2.imaginary;
	return *this;
}
complex_t& complex_t::operator /= (const complex_t& c2)
{
	float real_ = (real*c2.real + imaginary*c2.imaginary) / (c2.real*c2.real + c2.imaginary*c2.imaginary);
	imaginary = (c2.real*imaginary - real*c2.imaginary) / (c2.real*c2.real + c2.imaginary*c2.imaginary);
	real = real_;
	return *this;
}

complex_t& complex_t::operator *= (const complex_t& c2)
{
	float real_ = real*c2.real - imaginary*c2.imaginary;
	imaginary = real*c2.imaginary + c2.real*imaginary;   
	real = real_;
	return *this;
}
