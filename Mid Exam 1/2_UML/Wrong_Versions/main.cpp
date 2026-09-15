#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    std::string name;
    int age;
};

class Student {
public:
    std::string name;
    int roll;
    std::string section;

    void Display() {}
    void Add(std::string c) {}
    void Delete(std::string c) {}
};

class Room {
public:
    int number;
};

class House {
public:
    Room* room;

    House() {
        room = new Room();
    }
};

int main() {
    Student s;
    s.name = "Gayane";
    s.roll = 101;

    House h;

    return 0;
}