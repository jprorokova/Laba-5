#pragma once
#include <string>
#include "Rectangle.h"
using namespace std;
class RTree
{
public:
	void readingFile(string name);
	void findPlaces(double latitude, double longitude, long int size);
	Rectangle* root;
	Rectangle* getRoot();
};

