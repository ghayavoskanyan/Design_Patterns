class Singleton {
private:
    Singleton() {}
    Singleton(const Singleton &) = delete;
    Singleton & operator = (const Singleton &) = delete;
    ~Singleton() = default;
public:
    static Singleton & getInst() {
        static Singleton inst;
        return inst;
    }
    void doSmth() {}
};

int main() {
    Singleton & obj = Singleton::getInst();
    obj.doSmth();
    return 0;
}