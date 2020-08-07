#pragma once
#include <string>
#include <vector>
using namespace std;
struct Loc {
	double latitude;
	double longitude;
	string type;
	string subtype;
	string name;
	string street;
	Loc(double latitude, double longitude, string type, string subtype, string name, string street)
		: latitude(latitude), longitude(longitude), type(type), subtype(subtype), name(name), street(street)
	{
	}

};
class Rectangle
{
public:
	Rectangle();
	vector<Loc> locations;//
	

};

