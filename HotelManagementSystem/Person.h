#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
protected:
    std::string name;
    std::string idCard;
    std::string phoneNumber;

public:
    Person(std::string n, std::string id, std::string phone)
        : name(n), idCard(id), phoneNumber(phone) {}
    virtual ~Person() {}
    virtual void showRole() = 0; 
    std::string getName() const { return name; }
    std::string getIdCard() const { return idCard; }
    std::string getPhoneNumber() const { return phoneNumber; }
};
#endif
