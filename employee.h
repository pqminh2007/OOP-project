#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Employee : public Person {
private:
    string employeeID; // Mã nhân viên riêng
    string position;   // Chức vụ: Admin, Receptionist, Manager (Theo mục Actors của Use-case)
    double salary;     // Mức lương
    string shift;      // Ca làm việc

public:
    Employee();
    Employee(string cccd, string phone, string name, Date dob, string id, string pos, double sal, string sh);

    string getEmployeeID() const;
    string getPosition() const;
};