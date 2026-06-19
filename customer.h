#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Customer : public Person {
private:
    string customerID;   // Mã khách hàng riêng
    string customerType; // Loại khách hàng: VIP, Membership, Normal (Cực kỳ quan trọng cho UC38 Apply Discount)

public:
    Customer();
    Customer(string cccd, string phone, string name, Date dob, string id, string type);

    /*// Ghi đè (Override) hàm hiển thị thông tin riêng của Khách hàng
    void displayInfo() const override {
        cout << "[KHACH HANG] ID: " << customerID << " | Ten: " << hoten 
             << " | SDT: " << phoneNumber << " | Loai: " << customerType << endl;
    }

    void input() override {
        cout << "--- NHAP THONG TIN KHACH HANG ---\n";
        cout << "Nhap Ma Khach Hang: "; cin >> customerID;
        Person::input(); // Gọi lại hàm nhập chung của lớp cha Person
        cout << "Nhap loai khach hang (VIP / Membership / Normal): "; cin >> customerType;
    }*/

    // Getter cho thành viên số 5 tính hóa đơn
    string getCustomerType() const;
    string getCustomerID() const;
};