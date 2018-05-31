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
		int getLatDeg() const;
		int getLatMin() const;
		int getLatSec() const;
	};
}


