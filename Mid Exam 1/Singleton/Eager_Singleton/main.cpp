class EagerSingleton {
public:
    static EagerSingleton & getInstance() {
        return inst;
    }
    EagerSingleton(const EagerSingleton &) = delete;
    EagerSingleton & operator = (const EagerSingleton &) = delete;
private:
    EagerSingleton() = default;
    ~EagerSingleton() = default;
    static EagerSingleton inst;
};

EagerSingleton EagerSingleton::inst;

int main() {
    EagerSingleton& s = EagerSingleton::getInstance();
    (void)s;
    return 0;
}