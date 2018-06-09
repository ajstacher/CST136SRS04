#include "stdafx.h"
#include "location.h"

GPS::Location::Location(const std::string name, const Latitude latitude, const Longitude longitude) : name_{ name }, latitude_{ latitude }, longitude_{ longitude }
{
}

GPS::Latitude::Cardinal GPS::Location::getLatCardinal() const
{
	return latitude_.getCardinal();
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

GPS::Longitude::Cardinal GPS::Location::getLongCardinal() const
{
	return longitude_.getCardinal();
}

int GPS::Location::getLongDeg() const
{
	return longitude_.getDegree();
}

int GPS::Location::getLongMin() const
{
	return longitude_.getMinute();
}

int GPS::Location::getLongSec() const
{
	return longitude_.getSecond();
}
