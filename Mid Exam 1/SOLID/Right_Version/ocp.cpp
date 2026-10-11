#include <iostream>

class Car {
public:
    virtual void brake() {
        std::cout << "Slowing down the car...\n";
    }

    virtual ~Car() = default;
};

class ModernCar : public Car {
public:
    void brake() override {
        Car::brake();
        turnOnBrakeLights();
    }

    void turnOnBrakeLights() {
        std::cout << "Brake lights turned ON!\n";
    }
};

int main() {
    Car* myCar = new ModernCar();
    myCar->brake(); 
    delete myCar;
    return 0;
}