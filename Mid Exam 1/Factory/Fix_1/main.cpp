#include <iostream>
#include <cmath>

enum PointType { Cartesian, Polar };

class Point {
private:
    double x, y;
public:
    Point(double a, double b, PointType cs = Cartesian) {
        if (cs == Cartesian) { x = a; y = b; }
        else { x = a * std::cos(b); y = a * std::sin(b); }
    }
};

int main() {
    Point p(3, 4, Cartesian);
    return 0;
}