#ifndef ROOM_H
#define ROOM_H

#include <string>

// 1. Lớp cơ sở (Class cha) - Phải nằm ĐẦU TIÊN
class Room {
protected:
    int roomNumber;
    double price;
    std::string status; // "Trong", "Da dat", "Don phong"

public:
    Room(int num, double p, std::string stat = "Trong")
        : roomNumber(num), price(p), status(stat) {}

    virtual ~Room() {}
    virtual std::string getRoomType() const = 0; // Thuần ảo

    int getRoomNumber() const { return roomNumber; }
    double getPrice() const { return price; }
    std::string getStatus() const { return status; }
    void setStatus(std::string stat) { status = stat; }
};

// 2. Các lớp con kế thừa (Phải nằm BÊN DƯỚI class Room)
class StandardRoom : public Room {
public:
    StandardRoom(int num) : Room(num, 500000.0) {}
    std::string getRoomType() const override { return "Standard"; }
};

class DeluxeRoom : public Room {
public:
    DeluxeRoom(int num) : Room(num, 900000.0) {}
    std::string getRoomType() const override { return "Deluxe"; }
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int num) : Room(num, 2000000.0) {}
    std::string getRoomType() const override { return "Suite"; }
};

class FamilyRoom : public Room {
public:
    FamilyRoom(int num) : Room(num, 1200000.0) {}
    std::string getRoomType() const override { return "Family"; }
};

#endif // ROOM_H
