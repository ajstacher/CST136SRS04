#pragma once

#include <assert.h>

template<typename T, T min, T max>
class Range // You should re-code and simplify your SRS01 RangeInt
{
private:
	using value_type = T;

	value_type value_;

public:
	Range(const value_type value);
	
};

template<typename T, T min, T max>
inline Range<T, min, max>::Range(const value_type value)
{
	assert(value < max && value >= min, "Value is out of range!");
	value_ = value;
}
