#include <iostream>
#include <string>

class Notifier
{
public:
    virtual ~Notifier() = default;
    virtual void notify(std::string const& msg) = 0;
};

class EmailNotifier : public Notifier
{
public:
    void notify(std::string const& msg) override
    {
        std::cout << "Email: " << msg << '\n';
    }
};

class SMSNotifier : public Notifier
{
public:
    void notify(std::string const& msg) override
    {
        std::cout << "SMS: " << msg << '\n';
    }
};

class NotificationManager
{
private:
    Notifier& notifier;

public:
    explicit NotificationManager(Notifier& n) : notifier{n} {}

    void sendNotification(std::string const& msg)
    {
        notifier.notify(msg);
    }
};