#pragma once
#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

class Customer : public Person {
private:
    string customerID;   // Mã khách hàng riêng
    string customerType; // Loại khách hàng: "VIP" - 15%, "Corporate" - 10%, "Normal" - 0% (được giảm)

public:
    Customer();

    // Constructor đầy đủ tham số (Đồng bộ thứ tự với Person: name, phone, cccd, email, dob)
    Customer(string hoten, string phone, string cccd, string email, Date dob, string id, string type);

    // Ghi đè (Override) hàm hiển thị thông tin riêng của Khách hàng
    void displayInfo() const override;

    // Getter trả về tỷ lệ giảm giá dựa trên phân loại khách
    double getDiscountRate() const;

    // Các hàm Getter/Setter cần thiết
    string getCustomerType() const;
    string getCustomerID() const;
    
    void setCustomerType(string type);

    // Hàm cập nhật thông tin khách khi Quản lý/Tiếp tân chỉnh sửa trên GUI
    void updateCustomerInfo(string name, string phone, string cccd, string email, Date dob, string type);
};