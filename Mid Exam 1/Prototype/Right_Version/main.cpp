#include <iostream>
#include <string>
#include <memory>

class Enemy {
public:
    virtual ~Enemy() = default;
    virtual std::unique_ptr<Enemy> clone() const = 0;
    virtual void attack() const = 0;
};

class Orc : public Enemy {
private:
    int health;
    int damage;

public:
    Orc(int h, int d) : health(h), damage(d) {}

    std::unique_ptr<Enemy> clone() const override {
        return std::make_unique<Orc>(*this);
    }

    void attack() const override {
        std::cout << "Orc attacks with " << damage << " damage and " << health << " HP!\n";
    }
};

int main() {
    auto prototypeOrc = std::make_unique<Orc>(100, 20);

    auto enemy1 = prototypeOrc->clone();
    auto enemy2 = prototypeOrc->clone();

    enemy1->attack();
    enemy2->attack();

    return 0;
}