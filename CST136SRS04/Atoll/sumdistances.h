#pragma once
#include <vector>
#include "haversine.h"

template <typename Container>
auto SumDistances(Container c)
{
	// **haversine function returns a double**

	constexpr auto distance{ 0.0 };
	vector<double> distVector;
	
	for (int i = 0; i < c.size() - 1; i++)
	{
		distance = haversine(c[i], c[i + 1]);
		

	}
}

