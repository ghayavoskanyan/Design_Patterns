#include "DIP.cpp"

int main()
{
    EmailNotifier emailNotifier;
    NotificationManager emailManager(emailNotifier);

    emailManager.sendNotification("Hello by email");

    SMSNotifier smsNotifier;
    NotificationManager smsManager(smsNotifier);

    smsManager.sendNotification("Hello by SMS");

    return 0;
}