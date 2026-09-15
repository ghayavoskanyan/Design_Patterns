#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct Burger {
    std::string bun;
    std::string patty;
    std::string sauce;
    std::vector<std::string> toppings;

    void show() const {
        std::cout << bun << " + " << patty << " + " << sauce << '\n';
    }
};

class BurgerBuilder {
public:
    virtual ~BurgerBuilder() = default;
    virtual void buildBun() = 0;
    virtual void buildPatty() = 0;
    virtual void buildSauce() = 0;
    virtual void buildToppings() = 0;
    virtual Burger getResult() = 0;
};

class CheeseBurgerBuilder : public BurgerBuilder {
public:
    void buildBun() override { b.bun = "sesame"; }
    void buildPatty() override { b.patty = "beef 150g"; }
    void buildSauce() override { b.sauce = "secret sauce"; }
    void buildToppings() override {
        b.toppings = { "cheddar", "pickles", "onion" };
    }
    Burger getResult() override { return std::move(b); }

private:
    Burger b;
};

class VeggieBurgerBuilder : public BurgerBuilder {
public:
    void buildBun() override { b.bun = "plain"; }
    void buildPatty() override { b.patty = "veggie"; }
    void buildSauce() override { b.sauce = "BBQ"; }
    void buildToppings() override {
        b.toppings = { "pickles", "onion" };
    }
    Burger getResult() override { return std::move(b); }

private:
    Burger b;
};

class Chef {
public:
    Burger cook(BurgerBuilder& b) {
        b.buildBun();
        b.buildPatty();
        b.buildSauce();
        b.buildToppings();
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