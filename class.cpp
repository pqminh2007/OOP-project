#include <iostream>
using namespace std;
class Date {
public:
    int day, month, year;
    Date() { day = 1; month = 1; year = 2000; }
    Date(int d, int m, int y) { day = d; month = m; year = y; }
    void input() { cin >> day >> month >> year; }
    void print() const { cout << day << "/" << month << "/" << year; }
};
class Person{
private:
    string cccd;
    string phoneNumber;
    string hoten; //fullname
    Date dob;
public:
    Person(){ cccd = phoneNumber = hoten = ""; }
    Person(string cccd, string phoneNumber, string hoten, Date dob){
        this->cccd = cccd;
        this->phoneNumber = phoneNumber;
        this->hoten = hoten;
        this->dob = dob;
    }
    void addPerson(string cccd, string phoneNumber, string hoten){
        this->cccd = cccd;
        this->phoneNumber = phoneNumber;
        this->hoten = hoten;
    }
    void updatePerson(string cccd, string phoneNumber, string hoten){
        this->cccd = cccd;
        this->phoneNumber = phoneNumber;
        this->hoten = hoten;
    }
    void deletePerson(){}
    void searchPerson(){}
    void ViewPerson(){}

    // Các hàm Getter để sau này Thành viên 1 và Thành viên 5 lấy dữ liệu làm Bộ lọc/Tìm kiếm
    string getCCCD() const { return cccd; }
    string getPhoneNumber() const { return phoneNumber; }
    string getHoTen() const { return hoten; }
};
class Customer : public Person{
private:
    string customerID;   // Mã khách hàng riêng
    string customerType; // Loại khách hàng: VIP, Membership, Normal (Cực kỳ quan trọng cho UC38 Apply Discount)
public:
    Customer() : Person() {
        customerID = "";
        customerType = "Normal";
    }
    Customer(string cccd, string phone, string name, Date dob, string id, string type) : Person(cccd, phone, name, dob) {
        this->customerID = id;
        this->customerType = type;
    }
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
    string getCustomerType() const { return customerType; }
    string getCustomerID() const { return customerID; }
};
class Employee : public Person{
private:
    string employeeID; // Mã nhân viên riêng
    string position;   // Chức vụ: Admin, Receptionist, Manager (Theo mục Actors của Use-case)
    double salary;     // Mức lương
    string shift;      // Ca làm việc
public:
    Employee() : Person() {
        employeeID = position = shift = "";
        salary = 0.0;
    }

    Employee(string cccd, string phone, string name, Date dob, string id, string pos, double sal, string sh) : Person(cccd, phone, name, dob) {
        this->employeeID = id;
        this->position = pos;
        this->salary = sal;
        this->shift = sh;
    }

    string getEmployeeID() const { return employeeID; }
    string getPosition() const { return position; }
};