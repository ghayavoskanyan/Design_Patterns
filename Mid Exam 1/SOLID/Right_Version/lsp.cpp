#include <iostream>

class Car {
public:
    virtual void startEngine() {
        std::cout << "Engine started.\n";
    }

    virtual void drive() {
        std::cout << "Car is driving...\n";
    }

    virtual ~Car() = default;
};

class GasolineCar : public Car {
public:
    void startEngine() override {
        std::cout << "Gasoline engine started with combustion!\n";
    }

    void drive() override {
        std::cout << "Gasoline car is driving on the highway...\n";
    }

    void refillGas() {
        std::cout << "Refill gasoline tank.\n";
    }
};

void testDrive(Car& car) {
    car.startEngine();
    car.drive();
}

int main() {
    Car simpleCar;
    GasolineCar gasCar;

    testDrive(simpleCar);
    testDrive(gasCar);

    return 0;
}