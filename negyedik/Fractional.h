#pragma once
#include<cstdint>
#include<iostream>
class Fractional
{
public:
	Fractional() = default;
	Fractional(const int16_t num);
	Fractional(const int16_t numerator, const uint16_t denumerator);

	void operator+=(const Fractional& rhs);

	friend std::ostream& operator<<(std::ostream& outputstream, const Fractional& fractional);
	Fractional operator+(const Fractional& rhs);
private:
	int16_t mEnumerator = 0;
	uint16_t nDenumerator = 1;
};

Fractional operator+(const int16_t lhs, const Fractional& rhs);
