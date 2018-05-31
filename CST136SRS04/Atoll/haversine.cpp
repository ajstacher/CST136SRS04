#include "stdafx.h"
#include <cmath>
#include "haversine.h"


auto haversine(const int lat1, const int lat2, const int long1, const int long2)
{
	const auto myPi{ 3.14159265359 };
	const auto radius{ 6378.0 };
	auto distance{ 0.0 };
	
	const auto lat1r = lat1 * (myPi / 180.0);
	const auto lat2r = lat2 * (myPi / 180.0);
	const auto long1r = long1 * (myPi / 180.0);
	const auto long2r = long2 * (myPi / 180.0);

	distance = 2.0 * radius * asin(sqrt(pow(sin((lat2r - lat1r) / 2.0), 2)  +  cos(lat1r) * cos(lat2r) *  pow(sin((long2r - long1r) / 2.0), 2)));

	return distance;
};
