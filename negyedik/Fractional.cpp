#include "Fractional.h"
#include <exception>

Fractional::Fractional(const int16_t numerator, const uint16_t denumerator)
	:mEnumerator(numerator)
	, nDenumerator(denumerator)
{
	if (nDenumerator ==0)
	{
		//throw std::string("Invalid");
		throw std::runtime_error("Invalid");
	}
}
Fractional::Fractional(const int16_t num)
	:mEnumerator(num)
	, nDenumerator(1)
{

}

std::ostream& operator<<(std::ostream& outputstream,const Fractional& fractional)
{
	return outputstream << fractional.mEnumerator << "/" << fractional.nDenumerator;
}

Fractional Fractional::operator+(const Fractional& rhs)
{
	Fractional result;
	result.mEnumerator = mEnumerator * rhs.nDenumerator + nDenumerator * rhs.mEnumerator;
	result.nDenumerator = nDenumerator * rhs.nDenumerator;
	return result;
}
Fractional operator+(const int16_t lhs, const Fractional& rhs)
{
	return Fractional(lhs) + rhs;
}

void Fractional::operator+=(const Fractional& rhs)
{
	mEnumerator = mEnumerator * rhs.nDenumerator + nDenumerator * rhs.mEnumerator;
	nDenumerator = nDenumerator * rhs.nDenumerator;
	/**this = *this + rhs;*/
}

Fractional Fractional::ReadLine()
{
	int16_t numerator;
	uint16_t denumerator;
	std::cin >> numerator >> denumerator;
	return Fractional(numerator, denumerator);
}

Fractional::operator double()
{
	return static_cast<double>(mEnumerator) / nDenumerator;
}

Fractional::operator bool()
{
	return mEnumerator;
}

bool Fractional::operator==(const Fractional& other) const
{
	return mEnumerator * other.nDenumerator == nDenumerator + other.nDenumerator;
}