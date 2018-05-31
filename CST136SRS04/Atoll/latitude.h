#pragma once
#include "angle.h"
namespace GPS
{
	class Latitude : public Angle<-89, 90>
	{
	public:
		enum class Cardinal { S = -1, N = +1 };

		Latitude(const Cardinal cardinal, const int degree, const unsigned minute, const unsigned second);

		Cardinal getCardinal() const;
		
	private:
		Cardinal cardinal_;
	};
}


