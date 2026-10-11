#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
public:
    static Point NewCartesian(double x, double y) {
        return Point(x, y);
    }
    static Point NewPolar(double r, double theta) {
        return Point(r * std::cos(theta), r * std::sin(theta));
    }
};

int main() {
    auto obj1 = Point::NewCartesian(3, 4);
    auto obj2 = Point::NewPolar(5, 1.57);
    return 0;
}