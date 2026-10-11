#include <iostream>
#include <string>

class Enemy {
public:
    std::string type;
    int health;
    int damage;

    Enemy(std::string t, int h, int d) : type(t), health(h), damage(d) {}

    void attack() {
        std::cout << type << " attacks with " << damage << " damage!\n";
    }
};

int main() {
    Enemy e1("Orc", 100, 15);
    e1.attack();

    Enemy e2("Orc", 100, 15);
    e2.attack();

    return 0;
}