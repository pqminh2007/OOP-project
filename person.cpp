#include "Person.h"

Person::Person() { 
    cccd = phoneNumber = hoten = ""; 
}

Person::Person(string cccd, string phoneNumber, string hoten, Date dob) {
    this->cccd = cccd;
    this->phoneNumber = phoneNumber;
    this->hoten = hoten;
    this->dob = dob;
}

void Person::addPerson(string cccd, string phoneNumber, string hoten) {
    this->cccd = cccd;
    this->phoneNumber = phoneNumber;
    this->hoten = hoten;
}

void Person::updatePerson(string cccd, string phoneNumber, string hoten) {
    this->cccd = cccd;
    this->phoneNumber = phoneNumber;
    this->hoten = hoten;
}

void Person::deletePerson() {}

void Person::searchPerson() {}

void Person::ViewPerson() {}

string Person::getCCCD() const { 
    return cccd; 
}

string Person::getPhoneNumber() const { 
    return phoneNumber; 
}

string Person::getHoTen() const { 
    return hoten; 
}