#include "stdafx.h"
#include "longitude.h"

GPS::Longitude::Longitude(const Cardinal cardinal, const int degree, const unsigned minute, const unsigned second) : Angle(degree, minute, second), cardinal_{ cardinal }
{
}

GPS::Longitude::Cardinal GPS::Longitude::getCardinal()
{
	return cardinal_;
}
