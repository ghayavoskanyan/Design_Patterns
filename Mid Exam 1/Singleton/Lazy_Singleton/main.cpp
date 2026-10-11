class LazySingleton {
public:
    static LazySingleton & getInstance() {
        if (inst == nullptr) inst = new LazySingleton();
        return *inst;
    }
    LazySingleton(const LazySingleton &) = delete;
    LazySingleton & operator = (const LazySingleton &) = delete;
private:
    LazySingleton() = default;
    ~LazySingleton() = default;
    static LazySingleton* inst;
};

LazySingleton* LazySingleton::inst = nullptr;

int main() {
    LazySingleton& s = LazySingleton::getInstance();
    (void)s;
    return 0;
}