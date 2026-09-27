#include <iostream>
#include <memory>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Square\n";
    }
};

class ShapeFactory {
public:
    virtual ~ShapeFactory() = default;
    virtual std::unique_ptr<Shape> createShape() const = 0;
};

class CircleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() const override {
        return std::make_unique<Circle>();
    }
};

class SquareFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() const override {
        return std::make_unique<Square>();
    }
};

void clientCode(const ShapeFactory& factory) {
    auto shape = factory.createShape();
    shape->draw();
}

int main() {
    CircleFactory circleFactory;
    clientCode(circleFactory);

    SquareFactory squareFactory;
    clientCode(squareFactory);

    return 0;
}