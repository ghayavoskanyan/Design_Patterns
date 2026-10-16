#include <iostream>
#include <string>
#include <memory>
#include <map>

using namespace std;

struct HotDrink {
    virtual void prepare(int volume) = 0;
    virtual ~HotDrink() = default;
};

struct Tea : HotDrink {
    void prepare(int volume) override {
        cout << "take tea bag, boil water, pour " << volume << "ml" << endl;
    }
};

struct Coffee : HotDrink {
    void prepare(int volume) override {
        cout << "Boil water, grind coffee beans, pour " << volume << "ml" << endl;
    }
};

struct HotDrinkFactory {
    virtual unique_ptr<HotDrink> make() const = 0;
    virtual ~HotDrinkFactory() = default;
};

struct CoffeeFactory : HotDrinkFactory {
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffee>();
    }
};

struct TeaFactory : HotDrinkFactory {
    unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    }
};

class DrinkFactory {
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;
public:
    DrinkFactory() {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string& name) {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
};

int main() {
    DrinkFactory factory;
    auto coffee = factory.make_drink("coffee");
    auto tea = factory.make_drink("tea");
    return 0;
}