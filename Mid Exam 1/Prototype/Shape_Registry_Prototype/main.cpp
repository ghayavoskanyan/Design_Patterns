#include <iostream>
#include <string>
#include <map>

using namespace std;

class Shape {
public:
    virtual ~Shape() = default;
    virtual Shape* clone() const = 0;
    virtual void info() const = 0;
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int r) : radius(r) {}

    Shape* clone() const override {
        return new Circle(*this);
    }
    void info() const override {
        cout << "Circle with radius " << radius << endl;
    }
};

int main() {
    map<string, Shape*> shapeRegistry;
    shapeRegistry["Circle"] = new Circle(5);
    Shape* clonedCircle = shapeRegistry["Circle"]->clone();
    clonedCircle->info();

    delete clonedCircle;
    delete shapeRegistry["Circle"];
    return 0;
}