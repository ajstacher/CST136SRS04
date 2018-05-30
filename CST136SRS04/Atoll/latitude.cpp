#include "stdafx.h"
#include "latitude.h"

GPS::Latitude::Latitude(const Cardinal cardinal, const int degree, const unsigned minute, const unsigned second) : Angle(degree, minute, second), cardinal_{cardinal}
{
}

GPS::Latitude::Cardinal GPS::Latitude::getCardinal()
{
	return cardinal_;
}
