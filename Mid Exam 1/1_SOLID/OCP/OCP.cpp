#include <iostream>
#include <memory>
#include <vector>

class Shape
{
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing Circle\n";
    }
};

class Square : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing Square\n";
    }
};

void draw(const std::vector<std::unique_ptr<Shape>>& shapes)
{
    for (const auto& s : shapes)
    {
        s->draw();
    }
}