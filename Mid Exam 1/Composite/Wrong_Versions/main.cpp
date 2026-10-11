#include <iostream>
#include <string>
#include <vector>

class Leaf {
public:
    void operation() {
        std::cout << "Leaf operation\n";
    }
};

class Composite {
private:
    std::vector<Leaf> leaves;
public:
    void add(const Leaf& l) {
        leaves.push_back(l);
    }
    void operation() {
        std::cout << "Composite operation with " << leaves.size() << " leaves\n";
    }
};

int main() {
    Leaf l;
    l.operation();

    Composite c;
    c.add(l);
    c.operation();

    return 0;
}