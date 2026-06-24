#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Employee : public Person {
private:
    string employeeID; // Mã nhân viên riêng
    string position;   // Chức vụ: Quản lý / Nhân viên
    double salary;     // Mức lương
    string shift;      // Ca làm việc

public:
    Employee();

    Employee(string hoten, string phone, string cccd, string email, Date dob, string id, string pos, double sal, string sh);

    // HÀM KIỂM TRA QUYỀN CHỈNH SỬA
    bool hasWritePermission() const;

    // Định nghĩa lại hàm ảo của lớp cha Person để in ra thông tin
    void displayInfo() const override;

    // Các hàm Getter/Setter cần thiết cho hệ thống
    string getEmployeeID() const;
    string getPosition() const;
    double getSalary() const;
    string getShift() const;

    void setSalary(double sal);
    void setShift(string sh);
    void setPosition(string pos);

    // Hàm cập nhật thông tin khi Quản lý chỉnh sửa trên GUI
    void updateEmployeeInfo(string name, string phone, string cccd, string email, Date dob, string pos, double sal, string sh);
};