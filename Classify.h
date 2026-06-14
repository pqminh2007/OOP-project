#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "Data.h"

class Customer {
    protected:
        string id;
        string name;
        string phone;
        CustomerType type;
    public:
        Customer();
        Customer(string id, string name, string phone, CustomerType type);
    
        string getId() const {
            return id;
        }
        string getName() const {
            return name;  
        }
        string getPhone() const {
            return phone;
        }
        CustomerType getType()  const { 
            return type;  
        }
};

class Room{
    private:
        string roomNumber;
        RoomType type;
        RoomStatus status;
        double pricePerDay; 
    
        void RoomPrice();
    public:
        Room();
        Room(string number, RoomType type);
    
        string getNumber() const { 
            return roomNumber;
        }
        RoomType getType() const { 
            return type;
        }
        RoomStatus getStatus() const { 
            return status;
        }
        double getPricePerDay() const { 
            return pricePerDay; 
        }
        bool isAvailable() const { 
            return status == RoomStatus::AVAILABLE; 
        }
    
        void occupy(){ 
            status = RoomStatus::OCCUPIED;  
        }
        void vacate(){ 
            status = RoomStatus::AVAILABLE; 
        }
};

class Booking{
    private:
        string customerId;
        string roomNumber;
        string checkInDate;
        string checkOutDate;
        bool isCheckedOut;
    public:
        Booking();
        Booking(string customerId, string roomNumber, string checkInDate);
    
        string getCustomerId() const { 
            return customerId;
        }
        string getRoomNumber() const { 
            return roomNumber;
        }
        string getCheckIn() const { 
            return checkInDate;
        }
        string getCheckOut() const { 
            return checkOutDate;
        }
        bool checkedOut() const { 
            return isCheckedOut;
        }
    
        void completeCheckOut(const string& date) {
            checkOutDate  = date;
            isCheckedOut  = true;
        }
};