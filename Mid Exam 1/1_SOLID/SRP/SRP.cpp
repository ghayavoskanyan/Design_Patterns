#include <iostream>

struct Vector3D {};
struct Quaternion {};
struct Screen {};
struct Printer {};
struct ByteStream {};

class Circle {
private:
    double radius;

public:
    explicit Circle(double rad) : radius(rad) {}

    double getRadius() const noexcept {
        return radius;
    }

    void translate(Vector3D const&) {}
    void rotate(Quaternion const&) {}
};

class CircleRenderer {
public:
    void draw(Circle const& circle, Screen&) const {
        std::cout << "Drawing circle with radius " << circle.getRadius() << " to Screen\n";
    }

    void draw(Circle const& circle, Printer&) const {
        std::cout << "Drawing circle with radius " << circle.getRadius() << " to Printer\n";
    }
};

class CircleSerializer {
public:
    void serialize(Circle const&, ByteStream&) const {}
};