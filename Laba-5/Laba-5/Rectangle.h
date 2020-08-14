#pragma once
#include <string>
#include <vector>
#include <algorithm>
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
	Rectangle(Loc lDown, Loc lUp, Loc rDown, Loc rUp) : lUp(lUp),
		rDown(rDown),
		rUp(rUp),
		lDown(lDown) {

	}
	;
	vector<Loc> locations;//
	vector<Rectangle> children;
	Loc lDown;
	Loc lUp;
	Loc rDown;
	Loc rUp;
	void addLocation(Loc location);
	bool check(Loc location);
	double dist(double& A1, double& B1, double& A2, double& B2);
	void restructure(Loc location);
	void devideRoot();

};

