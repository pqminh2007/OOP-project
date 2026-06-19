#include "Customer.h"

Customer::Customer() : Person() {
    customerID = "";
    customerType = "Normal";
}

Customer::Customer(string cccd, string phone, string name, Date dob, string id, string type) 
    : Person(cccd, phone, name, dob) {
    this->customerID = id;
    this->customerType = type;
}

/*// Ghi đè (Override) hàm hiển thị thông tin riêng của Khách hàng
void Customer::displayInfo() const {
    // Đoạn code này đang bị comment lại
}

void Customer::input() {
    // Đoạn code này đang bị comment lại
}*/

// Getter cho thành viên số 5 tính hóa đơn
string Customer::getCustomerType() const { 
    return customerType; 
}

string Customer::getCustomerID() const { 
    return customerID; 
}