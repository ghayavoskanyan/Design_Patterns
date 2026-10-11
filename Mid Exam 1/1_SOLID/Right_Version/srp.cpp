#include <iostream>

class Chef {
public:
    void cookFood() { std::cout << "Cooking food...\n"; }
};

class Gardener {
public:
    void waterPlants() { std::cout << "Watering plants...\n"; }
};

class Painter {
public:
    void paintPicture() { std::cout << "Painting...\n"; }
};

class Driver {
public:
    void driveCar() { std::cout << "Driving car...\n"; }
};

int main() {
    Chef chef;
    chef.cookFood();
    return 0;
}