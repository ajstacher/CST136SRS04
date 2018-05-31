#pragma once
namespace GPS
{
	template<int min, int max>
	class Angle
	{
		static_assert(min < max, "Bad template arguments");

	private:
		const int degree_ = 0;
		const unsigned minute_ = 0;
		const unsigned second_ = 0;

	public:
		Angle(const int degree, unsigned minute, const unsigned second);

		int getDegree() const;
		unsigned getMinute() const;
		unsigned getSecond() const;

	};

	template<int min, int max>
	inline Angle<min, max>::Angle(const int degree, unsigned minute, const unsigned second) : degree_{ degree }, minute_{ minute }, second_{ second }
	{
	}

	template<int min, int max>
	inline int Angle<min, max>::getDegree() const
	{
		return degree_;
	}
	template<int min, int max> 
	inline unsigned Angle<min, max>::getMinute() const
	{
		return minute_;
	}
	template<int min, int max>
	inline unsigned Angle<min, max>::getSecond() const
	{
		return second_;
	}
}
	


