#pragma once
//template taken from https://stackoverflow.com/questions/2758080/how-to-sort-an-stl-vector

template <typename T, typename U>
struct CompareByMember {
	// This is a pointer-to-member, it represents a member of class T
	// The data member has type U
	U T::*field;
	CompareByMember(U T::*f) : field(f) {}
	bool operator()(const T &lhs, const T &rhs) {
		return lhs.*field < rhs.*field;
	}
};

