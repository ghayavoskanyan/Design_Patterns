#include <iostream>
#include <string>

class Circle {
public:
    void draw() {
        std::cout << "Drawing Circle\n";
    }
};

class Square {
public:
    void draw() {
        std::cout << "Drawing Square\n";
    }
};

int main() {
    std::string type = "circle";

    if (type == "circle") {
        Circle c;
        c.draw();
    } else if (type == "square") {
        Square s;
        s.draw();
    }

    return 0;
}