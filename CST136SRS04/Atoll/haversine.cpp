#include "stdafx.h"
#include <math.h>
#include "haversine.h"
#include "latitude.h"
#include "longitude.h"
#include "location.h"
#include "angle.h"


double haversine(const GPS::Location & location1, const GPS::Location & location2)
{
	const auto myPi{ 3.14159265359 };
	const auto radius{ 6378.0 };
	auto distance{ 0.0 };

	//DD = d + (min/60) + (sec/3600)
	//long2 * (myPi / 180.0)

	//convert to signed decimal degrees, then convert to radians
	const auto lat1r = (location1.getLatDeg() + (location1.getLatMin() / 60) + (location1.getLatSec() / 3600)) * (myPi/180.0);
	const auto lat2r = (location2.getLatDeg() + (location2.getLatMin() / 60) + (location2.getLatSec() / 3600)) * (myPi / 180.0);
	const auto long1r = (location1.getLongDeg() + (location1.getLongMin() / 60) + (location1.getLongSec() / 3600)) * (myPi / 180.0);
	const auto long2r = (location2.getLongDeg() + (location2.getLongMin() / 60) + (location2.getLongSec() / 3600)) * (myPi / 180.0);

	distance = 2.0 * radius * asin(sqrt(pow(sin((lat2r - lat1r) / 2.0), 2)  +  cos(lat1r) * cos(lat2r) *  pow(sin((long2r - long1r) / 2.0), 2)));

	return distance;
};
