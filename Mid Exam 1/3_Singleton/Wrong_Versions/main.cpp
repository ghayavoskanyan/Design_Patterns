#include <iostream>
#include <string>

class Logger {
public:
    static Logger* s_instance;

    Logger() {}

    static Logger* getInstance() {
        if (s_instance == nullptr) {
            s_instance = new Logger();
        }
        return s_instance;
    }

    void log(const std::string& msg) {
        std::cout << "Log: " << msg << '\n';
    }
};

Logger* Logger::s_instance = nullptr;

int main() {
    Logger* l1 = Logger::getInstance();
    Logger* l2 = new Logger();

    l1->log("Hello from l1");
    l2->log("Hello from l2");

    return 0;
}