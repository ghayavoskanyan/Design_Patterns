#include <iostream>
#include <string>

class House {
public:
    int walls;
    int doors;
    int windows;
    bool hasRoof;
    bool hasGarage;
    bool hasPool;
    bool hasGarden;
    bool hasHeating;

    House() : walls(0), doors(0), windows(0), hasRoof(false), hasGarage(false), hasPool(false), hasGarden(false), hasHeating(false) {}

    House(int w, int d, int win, bool r, bool g, bool p, bool gar, bool h)
        : walls(w), doors(d), windows(win), hasRoof(r), hasGarage(g), hasPool(p), hasGarden(gar), hasHeating(h) {}

    void setWalls(int w) { walls = w; }
    void setRoof(bool r) { hasRoof = r; }
    void setPool(bool p) { hasPool = p; }
};

int main() {
    House h1(4, 1, 2, true, false, false, true, false);

    House h2;
    h2.setWalls(4);
    h2.setRoof(true);
    h2.setPool(true);

    return 0;
}