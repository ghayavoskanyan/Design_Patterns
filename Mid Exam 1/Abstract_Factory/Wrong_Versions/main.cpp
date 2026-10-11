#include <iostream>
#include <string>

class WinButton {
public:
    void paint() {
        std::cout << "Render Windows Button\n";
    }
};

class WinCheckbox {
public:
    void paint() {
        std::cout << "Render Windows Checkbox\n";
    }
};

class MacButton {
public:
    void paint() {
        std::cout << "Render Mac Button\n";
    }
};

class MacCheckbox {
public:
    void paint() {
        std::cout << "Render Mac Checkbox\n";
    }
};

int main() {
    std::string os = "Win";

    if (os == "Win") {
        WinButton btn;
        WinCheckbox chk;
        btn.paint();
        chk.paint();
    } else {
        MacButton btn;
        MacCheckbox chk;
        btn.paint();
        chk.paint();
    }

    return 0;
}