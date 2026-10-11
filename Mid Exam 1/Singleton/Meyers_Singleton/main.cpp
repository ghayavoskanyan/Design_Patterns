class Config {
public:
    static Config & getInst() {
        static Config inst;
        return inst;
    }
    Config(const Config &) = delete;
    Config & operator = (const Config &) = delete;
private:
    Config() = default;
    ~Config() = default;
};

int main() {
    Config& c = Config::getInst();
    (void)c;
    return 0;
}