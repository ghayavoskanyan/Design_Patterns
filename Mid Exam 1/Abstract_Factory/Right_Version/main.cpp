#include <iostream>
#include <memory>
#include <string>

class Button {
public:
    virtual ~Button() = default;
    virtual void paint() const = 0;
};

class WinButton : public Button {
public:
    void paint() const override {
        std::cout << "Render Windows Button\n";
    }
};

class MacButton : public Button {
public:
    void paint() const override {
        std::cout << "Render Mac Button\n";
    }
};

class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual void paint() const = 0;
};

class WinCheckbox : public Checkbox {
public:
    void paint() const override {
        std::cout << "Render Windows Checkbox\n";
    }
};

class MacCheckbox : public Checkbox {
public:
    void paint() const override {
        std::cout << "Render Mac Checkbox\n";
    }
};

class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
};

class WinFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<WinButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<WinCheckbox>();
    }
};

class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<MacButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<MacCheckbox>();
    }
};

class Application {
private:
    std::unique_ptr<Button> button;
    std::unique_ptr<Checkbox> checkbox;

public:
    Application(const GUIFactory& factory) {
        button = factory.createButton();
        checkbox = factory.createCheckbox();
    }

    void render() const {
        button->paint();
        checkbox->paint();
    }
};

int main() {
    WinFactory winFactory;
    Application app1(winFactory);
    app1.render();

    MacFactory macFactory;
    Application app2(macFactory);
    app2.render();

    return 0;
}