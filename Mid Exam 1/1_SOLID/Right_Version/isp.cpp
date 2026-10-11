#include <iostream>

class IBreadBaker {
public:
    virtual void bakeBread() = 0;
    virtual ~IBreadBaker() = default;
};

class ICookieBaker {
public:
    virtual void bakeCookies() = 0;
    virtual ~ICookieBaker() = default;
};

class ICakeBaker {
public:
    virtual void bakeCake() = 0;
    virtual ~ICakeBaker() = default;
};

class BreadBaker : public IBreadBaker {
public:
    void bakeBread() override {
        std::cout << "Baking fresh bread...\n";
    }
};

class CookieBaker : public ICookieBaker {
public:
    void bakeCookies() override {
        std::cout << "Baking chocolate cookies...\n";
    }
};

class MasterBaker : public IBreadBaker, public ICookieBaker, public ICakeBaker {
public:
    void bakeBread() override { std::cout << "Master baking bread...\n"; }
    void bakeCookies() override { std::cout << "Master baking cookies...\n"; }
    void bakeCake() override { std::cout << "Master baking cake...\n"; }
};

int main() {
    BreadBaker breadBaker;
    breadBaker.bakeBread();

    MasterBaker master;
    master.bakeBread();
    master.bakeCake();

    return 0;
}