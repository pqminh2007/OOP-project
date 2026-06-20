#include "RoomFactory.h"
#include "Room.h"

// Định nghĩa chi tiết hàm nằm ở file .cpp này
std::unique_ptr<Room> RoomFactory::createRoom(const std::string& type, int roomNumber) {
    if (type == "Standard") {
        return std::make_unique<StandardRoom>(roomNumber);
    } else if (type == "Deluxe") {
        return std::make_unique<DeluxeRoom>(roomNumber);
    } else if (type == "Suite") {
        return std::make_unique<SuiteRoom>(roomNumber);
    } else if (type == "Family") {
        return std::make_unique<FamilyRoom>(roomNumber);
    }
    return nullptr;
}
