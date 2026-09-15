#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Person {
protected:
    std::string name;
public:
    Person(const std::string& n) : name(n) {}
    virtual ~Person() = default;
};

class Student : public Person {
private:
    int roll;
    std::string section;

public:
    Student(const std::string& n, int r, const std::string& s)
        : Person(n), roll(r), section(s) {}

    void Display() const {
        std::cout << name << " " << roll << " " << section << '\n';
    }
};

class Printer {
public:
    void printDocument(const std::string& doc) const {
        std::cout << doc << '\n';
    }
};

class Document {
public:
    void print(const Printer& p) const {
        p.printDocument("Document content");
    }
};

class Professor {
private:
    std::string name;
public:
    Professor(const std::string& n) : name(n) {}
};

class Department {
private:
    std::vector<Professor*> professors;
public:
    void addProfessor(Professor* p) {
        professors.push_back(p);
    }
};

class Room {
private:
    int number;
public:
    Room(int n) : number(n) {}
};

class House {
private:
    std::vector<Room> rooms;
public:
    void addRoom(int number) {
        rooms.emplace_back(number);
    }
};

int main() {
    Student s("Gayane", 101, "EDA");
    s.Display();

    Printer p;
    Document doc;
    doc.print(p);

    Professor prof("Dr. Smith");
    Department dept;
    dept.addProfessor(&prof);

    House house;
    house.addRoom(1);
    house.addRoom(2);

    return 0;
}