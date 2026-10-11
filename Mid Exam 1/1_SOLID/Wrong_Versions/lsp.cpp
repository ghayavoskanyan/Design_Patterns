#include <iostream>
#include <stdexcept>

class Car {
public:
    virtual void drive() {
        std::cout << "Car is driving\n";
    }

    virtual void refillGas() {
        std::cout << "Refilling gasoline\n";
    }

    virtual ~Car() = default;
};

class ElectricCar : public Car {
public:
    void refillGas() override {
        throw std::logic_error("Electric cars do not use gasoline!");
    }
};

void serviceStation(Car& car) {
    car.drive();
    car.refillGas();
}

int main() {
    Car normalCar;
    ElectricCar tesla;

    serviceStation(normalCar);

    try {
        serviceStation(tesla);
    } 
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}