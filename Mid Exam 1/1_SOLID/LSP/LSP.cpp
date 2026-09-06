#include <iostream>

class Shape
{
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override
    {
        return width * height;
    }

private:
    double width;
    double height;
};

class Square : public Shape
{
public:
    explicit Square(double s) : side(s) {}

    double getArea() const override
    {
        return side * side;
    }

private:
    double side;
};

void printArea(const Shape& shape)
{
    std::cout << "Area: " << shape.getArea() << '\n';
}