#include <iostream>
#include <string>

class TwitterShare {
public:
    void sendTweet() {
        std::cout << "Sharing post on Twitter...\n";
    }
};

class FacebookShare {
public:
    void postToFB() {
        std::cout << "Sharing post on Facebook...\n";
    }
};

class Distributor {
private:
    TwitterShare twitter;
    FacebookShare facebook;

public:
    void shareOnTwitter() {
        twitter.sendTweet();
    }

    void shareOnFacebook() {
        facebook.postToFB();
    }
};

int main() {
    Distributor d;
    d.shareOnTwitter();
    return 0;
}