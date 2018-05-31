#include "stdafx.h"
#include "location.h"

GPS::Location::Location(const std::string name, const Latitude latitude, const Longitude longitude) : name_{name}, latitude_{ latitude }, longitude_{longitude}
{
}

int GPS::Location::getLatDeg() const 
{
	return latitude_.getDegree();
}

int GPS::Location::getLatMin() const
{
	return latitude_.getMinute();
}

int GPS::Location::getLatSec() const
{
	return latitude_.getSecond();
}
