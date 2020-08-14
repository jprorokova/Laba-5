#include "Rectangle.h"




double Rectangle::dist(double& A1, double& B1, double& A2, double& B2) {
    double a1, b1, a2, b2, delta1, delta2, result;
    double radius = 6367444.65;
    a1 = (A1 * 2 * acos(0.0)) / 180;
    b1 = (B1 * 2 * acos(0.0)) / 180;
    a2 = (A2 * 2 * acos(0.0)) / 180;
    b2 = (B2 * 2 * acos(0.0)) / 180;
    delta1 = a2 - a1;
    delta2 = b2 - b1;
    double squereRoot = sqrt(pow(sin(delta1 / 2), 2) + cos(a2) * cos(a1) * pow(sin(delta2 / 2), 2));
    result = 2 * asin(squereRoot) * radius;
    return result;
}
void Rectangle::restructure(Loc location) {
    double left = min(this->lDown.latitude,location.latitude);
    double right = max(this->rDown.latitude, location.latitude);
    double up= min(this->lUp.longitude, location.longitude);
    double down = max(this->lDown.longitude, location.longitude);
    this->lUp.longitude = up;
    this->rUp.longitude = up;
    this->lDown.longitude = down;
    this->rDown.longitude = down;
    this->lDown.latitude = left;
    this->lUp.latitude = left;
    this->rDown.latitude = right;
    this->rUp.latitude = right;
}
bool Rectangle::check(Loc location) {
    return location.longitude >= this->lUp.longitude && location.longitude <= this->lDown.longitude
        && location.latitude >= this->lUp.latitude && location.latitude <= this->rUp.latitude;
        
}
void Rectangle::addLocation(Loc location) {
    if (!this->check(location)) {
        this->restructure(location);
    }
    locations.push_back(location);
}
void Rectangle::devideRoot() {
    if (this->locations.size() > 5) {
        double width = dist(this->lUp.latitude, this->lUp.longitude, this->rUp.latitude, this->rUp.longitude);
        double height = dist(this->lUp.latitude, this->lUp.longitude, this->lDown.latitude, this->lDown.longitude);
        if (width > height) {
            double halfWidth = this->lUp.latitude + abs(this->lUp.latitude - this->rUp.latitude) / 2;
            Loc  up(halfWidth, this->lUp.longitude, this->lUp.type, this->lUp.subtype, this->lUp.name, this->lUp.street);
            Loc down(halfWidth, this->lDown.longitude, this->lUp.type, this->lUp.subtype, this->lUp.name, this->lUp.street);
            Rectangle rectLeft(this->lDown, this->lUp, down, up);
            Rectangle rectRight(down, up, this->rDown, this->rUp);
            while (this->locations.size() > 0) {

                if (rectLeft.check(this->locations[this->locations.size() - 1]))
                    rectLeft.addLocation(this->locations[this->locations.size() - 1]);
                else
                    rectRight.addLocation(this->locations[this->locations.size() - 1]);
                this->locations.pop_back();
            }
            this->children.push_back(rectLeft);
            this->children.push_back(rectRight);
            rectLeft.devideRoot();
            rectRight.devideRoot();
        }
        else {
            double halfHight = this->lUp.longitude + abs(this->lUp.longitude - this->lDown.longitude) / 2;
            Loc  left(this->lUp.latitude, halfHight, this->lUp.type, this->lUp.subtype, this->lUp.name, this->lUp.street);
            Loc right(this->rUp.latitude, halfHight, this->lUp.type, this->lUp.subtype, this->lUp.name, this->lUp.street);
            Rectangle rectUp(left, this->lUp, right, this->rUp);
            Rectangle rectDown(this->lDown, left, this->rDown, right);
            while (this->locations.size() > 0) {
                if (rectUp.check(this->locations[this->locations.size() - 1]))
                    rectUp.addLocation(this->locations[this->locations.size() - 1]);
                else
                    rectDown.addLocation(this->locations[this->locations.size() - 1]);
                this->locations.pop_back();
            }
            this->children.push_back(rectUp);
            this->children.push_back(rectDown);
            this->children[0].devideRoot();
            this->children[1].devideRoot();
        }
    }
}