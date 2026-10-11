#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Component {
public:
    virtual ~Component() = default;
    virtual void operation() const = 0;
};

class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf\n";
    }
};

class Composite : public Component {
private:
    std::vector<std::unique_ptr<Component>> children;

public:
    void add(std::unique_ptr<Component> component) {
        children.push_back(std::move(component));
    }

    void operation() const override {
        std::cout << "Composite(";
        for (const auto& child : children) {
            child->operation();
        }
        std::cout << ")\n";
    }
};

int main() {
    auto tree = std::make_unique<Composite>();
    auto branch = std::make_unique<Composite>();

    branch->add(std::make_unique<Leaf>());
    branch->add(std::make_unique<Leaf>());

    tree->add(std::move(branch));
    tree->add(std::make_unique<Leaf>());

    tree->operation();

    return 0;
}