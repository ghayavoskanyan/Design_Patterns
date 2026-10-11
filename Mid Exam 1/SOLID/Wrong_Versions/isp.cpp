#include <iostream>

class IBakery {
public:
    virtual void bakeBread() = 0;
    virtual void bakeCookies() = 0;
    virtual void bakeCake() = 0;
    virtual ~IBakery() = default;
};

class BreadBaker : public IBakery {
public:
    void bakeBread() override {
        std::cout << "Baking fresh bread...\n";
    }

    void bakeCookies() override {
        std::cout << "I don't bake cookies!\n";
    }

    void bakeCake() override {
        std::cout << "I don't bake cakes!\n";
    }
};

int main() {
    BreadBaker b;
    b.bakeBread();
    return 0;
}