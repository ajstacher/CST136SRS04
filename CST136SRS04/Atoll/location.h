#pragma once
#include <string>
#include "latitude.h"
#include "longitude.h"

namespace GPS
{
	class Location
	{
	private:
		std::string name_;
		Latitude latitude_;
		Longitude longitude_;
	public:
		Location(const std::string name, const Latitude latitude, const Longitude longitude);

		GPS::Latitude::Cardinal getLatCardinal() const;
		int getLatDeg() const;
		int getLatMin() const;
		int getLatSec() const;
		GPS::Longitude::Cardinal getLongCardinal() const;
		int getLongDeg() const;
		int getLongMin() const;
		int getLongSec() const;
	};
}


