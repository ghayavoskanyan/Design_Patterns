#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
public:
    struct Factory {
        static Point NewCartesian(double x, double y) {
            return Point(x, y);
        }
        static Point NewPolar(double r, double t) {
            return Point(r * std::cos(t), r * std::sin(t));
        }
    };
};

int main() {
    auto obj = Point::Factory::NewPolar(5, 3.14);
    return 0;
}