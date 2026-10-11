#include <iostream>
#include <memory>
#include <vector>

class ISharing {
public:
    virtual void sharePost() = 0;
    virtual ~ISharing() = default;
};

class TwitterShare : public ISharing {
public:
    void sharePost() override {
        std::cout << "Sharing post on Twitter...\n";
    }
};

class FacebookShare : public ISharing {
public:
    void sharePost() override {
        std::cout << "Sharing post on Facebook...\n";
    }
};

class LinkedInShare : public ISharing {
public:
    void sharePost() override {
        std::cout << "Sharing post on LinkedIn...\n";
    }
};

class Distributor {
private:
    std::shared_ptr<ISharing> sharer;

public:
    Distributor(std::shared_ptr<ISharing> service) : sharer(service) {}

    void setSharer(std::shared_ptr<ISharing> service) {
        sharer = service;
    }

    void publish() {
        sharer->sharePost();
    }
};

int main() {
    auto twitter = std::make_shared<TwitterShare>();
    auto facebook = std::make_shared<FacebookShare>();

    Distributor distributor(twitter);
    distributor.publish();

    distributor.setSharer(facebook);
    distributor.publish();

    return 0;
}