#include "RTree.h"
#include <string>
#include <sstream>
using namespace std;
RTree::RTree() {
	this->root = nullptr;
}

void RTree::readingFile(string name) {
	
	ifstream in(name.c_str());
	if (in) {
        string latitude, lontitude, type, subtype, name, street;
        while (!in.eof()) {
            getline(in, latitude, ';');
            if (latitude == "\n") {
                break;
            }
            getline(in, lontitude, ';');
            for (int i = 0; i < latitude.size(); i++) {
                if (latitude[i] == ',') {
                    latitude[i] = '.';
                }
            }
            for (int i = 0; i < lontitude.size(); i++) {
                if (lontitude[i] == ',') {
                    lontitude[i] = '.';
                }
            }
            getline(in, type, ';');
            getline(in, subtype, ';');
            getline(in, name, ';');
            getline(in, street, ';');
            Loc location(stod(latitude), stod(lontitude), type, subtype, name, street);
            if (this->root == nullptr) {
                this->root = new Rectangle(location, location, location, location);
                this->root->addLocation(location);
            }
            this->root->addLocation(location);
        }
        this->root->devideRoot();
        in.close();
    }
    else {
        cout << "File wasn't opened" << endl;
    }

   
}
Rectangle* RTree::getRoot() {
    return this->root;
}

void RTree::findPlaces(double latitude, double longitude, double size, Rectangle rect) {
    if (rect.check(Loc(latitude, longitude, "", "", "", "")) ||
        rect.dist(latitude, longitude, rect.lUp.latitude, longitude) < size ||
        rect.dist(latitude, longitude, rect.rUp.latitude, longitude) < size ||
        rect.dist(latitude, longitude, latitude, rect.lUp.longitude) < size ||
        rect.dist(latitude, longitude, latitude, rect.lDown.longitude) < size)
    {
        for (int i = 0; i < rect.locations.size(); i++) {
            if (rect.dist(latitude, longitude, rect.locations[i].latitude, rect.locations[i].longitude) < size) {
                cout << rect.locations[i].name << " " << rect.locations[i].type << " " << rect.locations[i].subtype << " "
                    << rect.locations[i].street << " " << rect.locations[i].latitude << " " << rect.locations[i].longitude << endl;
            }
        }
        if (!rect.children.empty()) {
            findPlaces(latitude, longitude, size, rect.children[0]);
            findPlaces(latitude, longitude, size, rect.children[1]);
        }
    }
}