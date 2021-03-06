// Atoll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <forward_list>
#include <map>
#include "latitude.h"
#include "longitude.h"
#include "location.h"
#include "haversine.h"

struct compareByLatitude
{
	bool operator ()(const GPS::Location & location1, const GPS::Location & location2) const
	{

		if (location1.getLatCardinal() == location2.getLatCardinal()) {
			if (location1.getLatDeg() == location2.getLatDeg()) {
				if (location1.getLatMin() == location2.getLatMin()) {
					if (location1.getLatSec() == location2.getLatSec()) {
						return true;
					}
					else { return location1.getLatSec() < location2.getLatSec(); }
				}
				else { return location1.getLatMin() < location2.getLatMin(); }
			}
			else { return location1.getLatDeg() < location2.getLatDeg(); }
		}
		else { return location1.getLatCardinal() < location2.getLatCardinal(); }

	}
};

struct compareByLongitude
{
	bool operator ()(const GPS::Location & location1, const GPS::Location & location2) const
	{
		if (location1.getLongCardinal() == location2.getLongCardinal()) {
			if (location1.getLongDeg() == location2.getLongDeg()) {
				if (location1.getLongMin() == location2.getLongMin()) {
					if (location1.getLongSec() == location2.getLongSec()) {
						return true;
					}
					else { return location1.getLongSec() > location2.getLongSec(); }
				}
				else { return location1.getLongMin() > location2.getLongMin(); }
			}
			else { return location1.getLongDeg() > location2.getLongDeg(); }
		}
		else { return location1.getLongCardinal() < location2.getLongCardinal(); }
	}
};

double sumDistancesVector(const std::vector<GPS::Location> &islandVector)
{
	std::vector<double> distancesVector;
	auto distance{ 0.0 };

	for (unsigned i = 0; i < islandVector.size() - 1; i++)
	{
		distance = haversine(islandVector[i], islandVector[i + 1]);
		distancesVector.push_back(distance);
	}

	return std::accumulate(distancesVector.begin(), distancesVector.end(), 0.0);
}

double sumDistancesFList(const std::forward_list<GPS::Location> &islandList)
{
	std::vector<double> distancesVector;
	auto distance{ 0.0 };

	//intialize current and next iterators
	auto it = islandList.begin();
	auto nextIt = std::next(it, 1);

	while (nextIt != islandList.end())
	{
		distance = haversine(*it, *nextIt);
		distancesVector.push_back(distance);
		++it;
		nextIt = std::next(it, 1);
	}

	return std::accumulate(distancesVector.begin(), distancesVector.end(), 0.0);
}

double sumDistancesMap(const std::map<int, GPS::Location> & islandMap)
{
	std::vector<double> distancesVector;
	auto distance{ 0.0 };

	auto it = islandMap.begin();
	auto nextIt = std::next(it, 1);

	//it->second accesses second element in map pair
	while (nextIt != islandMap.end())
	{
		distance = haversine(it->second, nextIt->second);
		distancesVector.push_back(distance);
		++it;
		nextIt = std::next(it, 1);
	}

	return std::accumulate(distancesVector.begin(), distancesVector.end(), 0.0);
}

int main()
{
	auto distanceSum{ 0.0 };

	//initialize array of locations
	std::array<GPS::Location, 12> island
	{
			GPS::Location{ "Faichuk Islands ", GPS::Latitude{ GPS::Latitude::Cardinal::N,  7, 21,   8 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 151, 36, 30 } },
			GPS::Location{ "Hawaii          ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 21, 18,  41 }, GPS::Longitude{ GPS::Longitude::Cardinal::W, -157, 47, 47 } },
			GPS::Location{ "Mariana Islands ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 17,  0,   0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 146,  0,  0 } },
			GPS::Location{ "Johnston Atoll  ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 16, 44,  13 }, GPS::Longitude{ GPS::Longitude::Cardinal::W, -169, 31, 26 } },
			GPS::Location{ "Kosrae          ", GPS::Latitude{ GPS::Latitude::Cardinal::N,  5, 19,   0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 162, 59,  0 } },
			GPS::Location{ "Falalop         ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 10,  1,  14 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 139, 47, 23 } },
			GPS::Location{ "Guam            ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 13, 30,   0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 144, 48,  0 } },
			GPS::Location{ "Pohnpei         ", GPS::Latitude{ GPS::Latitude::Cardinal::N,  6, 51,   0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 158, 13,  0 } },
			GPS::Location{ "Marshall Islands", GPS::Latitude{ GPS::Latitude::Cardinal::N,  7,  7,   0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 171,  4,  0 } },
			GPS::Location{ "Yap             ", GPS::Latitude{ GPS::Latitude::Cardinal::N,  9, 32,   0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 138,  7,  0 } },
			GPS::Location{ "Wake Island     ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 19, 17,  43 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 166, 37, 52 } },
			GPS::Location{ "New Zealand     ", GPS::Latitude{ GPS::Latitude::Cardinal::S, -41, 17,   0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 174, 27,  0 } },
	};


	//***********VECTOR****************
	std::vector<GPS::Location> islandVector;
	std::copy(island.begin(), island.end(), back_inserter(islandVector));

	//sort S to N
	std::sort(islandVector.begin(), islandVector.end(), compareByLatitude());
	//sum distances
	distanceSum = sumDistancesVector(islandVector);

	//sort W to E
	std::sort(islandVector.begin(), islandVector.end(), compareByLongitude());
	//sum distances
	distanceSum = sumDistancesVector(islandVector);


	//**********FORWARD LIST*********
	std::forward_list<GPS::Location> islandList;
	std::copy(island.begin(), island.end(), front_inserter(islandList));

	//sort S to N
	islandList.sort(compareByLatitude());
	distanceSum = sumDistancesFList(islandList);

	//sort W to E
	islandList.sort(compareByLongitude());
	distanceSum = sumDistancesFList(islandList);


	//********  MAP  ***************
	std::map<int, GPS::Location> islandMap;

	//sort vector S to N
	std::sort(islandVector.begin(), islandVector.end(), compareByLatitude());
	//copy to map
	for (unsigned i = 0; i < islandVector.size(); i++)
	{
		islandMap.insert(std::pair <int, GPS::Location>(i, islandVector[i]));
	}
	distanceSum = sumDistancesMap(islandMap);

	//don't forget
	islandMap.clear();

	//sort vector W to E
	std::sort(islandVector.begin(), islandVector.end(), compareByLongitude());
	//copy to map
	for (unsigned i = 0; i < islandVector.size(); i++)
	{
		islandMap.insert(std::pair <int, GPS::Location>(i, islandVector[i]));
	}
	distanceSum = sumDistancesMap(islandMap);

	return 0;
}


