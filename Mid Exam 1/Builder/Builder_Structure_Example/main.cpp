#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct Burger {
    std::string bun;
    std::string patty;
    std::string sause;
    std::vector<std::string> toppings;
    void show() const {
        std::cout << bun << "+" << patty << "+" << sause << "\n";
    }
};

class BurgerBuilder {
public:
    virtual ~BurgerBuilder() = default;
    virtual void buildBun() = 0;
    virtual void buildPatty() = 0;
    virtual void buildSause() = 0;
    virtual void buildTappings() = 0;
    virtual Burger getResult() = 0;
};

class CheeseBurgerBuilder : public BurgerBuilder {
public:
    void buildBun() override { b.bun = "seasame"; }
    void buildPatty() override { b.patty = "beef 150g"; }
    void buildSause() override { b.sause = "secret sause"; }
    void buildTappings() override { b.tappings = {"chedder"}; }
    Burger getResult() override { return std::move(b); }
private:
    Burger b;
};

class VeggieBurgerBuilder : public BurgerBuilder {
public:
    void buildBun() override { b.bun = "plain"; }
    void buildPatty() override { b.patty = "veggie"; }
    void buildSause() override { b.sause = "bbq"; }
    void buildTappings() override { b.tappings = {"lettuce"}; }
    Burger getResult() override { return std::move(b); }
private:
    Burger b;
};

class Chef {
public:
    Burger cook(BurgerBuilder & b) {
        b.buildBun();
        b.buildPatty();
        b.buildSause();
        b.buildTappings();
        return b.getResult();
    }
};

int main() {
    Chef chef;
    CheeseBurgerBuilder cheese;
    Burger a = chef.cook(cheese);
    a.show();

    VeggieBurgerBuilder veggie;
    Burger b = chef.cook(veggie);
    b.show();

    return 0;
}