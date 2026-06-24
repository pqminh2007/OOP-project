#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Person {
protected:
    string cccd;
    string phoneNumber;
    string hoten; //fullname
    string email;
    Date dob;

public:
    Person();
    Person(string hoten, string phoneNumber, string cccd, string email, Date dob);
    
    // Hàm ảo thuần ảo để biến Person thành lớp trừu tượng (Abstraction)
    virtual void displayInfo() const = 0;

    // Các hàm Getter
    string getHoTen() const;
    string getPhoneNumber() const;
    string getCCCD() const;
    string getEmail() const;
    Date getDob() const;
};