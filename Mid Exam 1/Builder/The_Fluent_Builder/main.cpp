#include <iostream>
#include <string>
#include <stdexcept>

enum class Roof { Flat, Sloped };

struct House {
    int walls = 0;
    Roof roof = Roof::Flat;
    bool pool = false;
};

class Housebuilder {
public:
    Housebuilder & walls(int n) { h.walls = n; return *this; }
    Housebuilder & roof(Roof r) { h.roof = r; return *this; }
    Housebuilder & pool(bool on) { h.pool = on; return *this; }
    House build() {
        if (h.walls < 3) throw std::logic_error("not a house");
        return std::move(h);
    }
private:
    House h;
};

int main() {
    House house = Housebuilder()
                      .walls(4)
                      .roof(Roof::Sloped)
                      .pool(true)
                      .build();

    std::cout << "House built with " << house.walls << " walls.\n";
    return 0;
}