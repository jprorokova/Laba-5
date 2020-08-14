#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Rectangle.h"
using namespace std;
class RTree
{
public:
	RTree();
	void readingFile(string name);
	void findPlaces(double latitude, double longitude, double size, Rectangle rect);
	Rectangle* root;
	Rectangle* getRoot();
};

