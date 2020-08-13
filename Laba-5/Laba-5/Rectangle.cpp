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