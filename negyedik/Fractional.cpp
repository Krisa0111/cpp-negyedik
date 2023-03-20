#include "Fractional.h"

Fractional::Fractional(const int16_t numerator, const uint16_t denumerator)
	:mEnumerator(numerator)
	, nDenumerator(denumerator)
{
	
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