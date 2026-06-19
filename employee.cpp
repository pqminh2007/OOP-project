#include "Employee.h"

Employee::Employee() : Person() {
    employeeID = position = shift = "";
    salary = 0.0;
}

Employee::Employee(string cccd, string phone, string name, Date dob, string id, string pos, double sal, string sh) 
    : Person(cccd, phone, name, dob) {
    this->employeeID = id;
    this->position = pos;
    this->salary = sal;
    this->shift = sh;
}

string Employee::getEmployeeID() const { 
    return employeeID; 
}

string Employee::getPosition() const { 
    return position; 
}