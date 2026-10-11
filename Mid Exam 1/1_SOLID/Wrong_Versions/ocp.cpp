#include <iostream>

class Car {
public:
    void brake() {
        std::cout << "Slowing down the car\n";
        turnOnBrakeLights(); 
    }

    void turnOnBrakeLights() {
        std::cout << "Brake lights turned on\n";
    }
};

int main() {
    Car c;
    c.brake();
    return 0;
}