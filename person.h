#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Person {
private:
    string cccd;
    string phoneNumber;
    string hoten; //fullname
    Date dob;

public:
    Person();
    Person(string cccd, string phoneNumber, string hoten, Date dob);

    void addPerson(string cccd, string phoneNumber, string hoten);
    void updatePerson(string cccd, string phoneNumber, string hoten);
    void deletePerson();
    void searchPerson();
    void ViewPerson();

    // Các hàm Getter để sau này Thành viên 1 và Thành viên 5 lấy dữ liệu làm Bộ lọc/Tìm kiếm
    string getCCCD() const;
    string getPhoneNumber() const;
    string getHoTen() const;
};