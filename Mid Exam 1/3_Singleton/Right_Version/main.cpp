#include <iostream>
#include <string>
#include <mutex>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    void log(const std::string& msg) {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::cout << "Log: " << msg << '\n';
    }

private:
    Logger() = default;
    ~Logger() = default;

    std::mutex m_mutex;
};

int main() {
    Logger& l1 = Logger::getInstance();
    l1.log("Hello from Meyers Singleton");

    Logger& l2 = Logger::getInstance();
    l2.log("Second log call");

    return 0;
}