#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct GraphicObject {
    virtual void draw() = 0;
    virtual ~GraphicObject() = default;
};

struct Circle : GraphicObject {
    void draw() override {
        cout << "Circle" << endl;
    }
};

struct Group : GraphicObject {
    string name;
    vector<GraphicObject*> objects;
    explicit Group(const string& name) : name{name} {}

    void draw() override {
        cout << "Group " << name.c_str() << " contains" << endl;
        for (auto&& o : objects) {
            o->draw();
        }
    }
};

int main() {
    Group root("Root");
    Circle c1;
    Circle c2;
    root.objects.push_back(&c1);
    root.objects.push_back(&c2);

    root.draw();

    return 0;
}