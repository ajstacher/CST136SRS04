#pragma once
#include "angle.h"
namespace GPS
{
	class Longitude : public Angle<-180, 180>
	{
	public:
		enum class Cardinal { W = -1, E = +1 };

		Longitude(const Cardinal cardinal, const int degree, const unsigned minute, const unsigned second);

		Cardinal getCardinal() const;

	private:
		Cardinal cardinal_;
	};
}

