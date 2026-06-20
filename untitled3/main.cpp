#include "mainwindow.h"
#include <QApplication>
#include <iostream>

// Kết nối các file quản lý logic của bạn vào main
#include "Account.h"
#include "RoomFactory.h"
#include "DatabaseManager.h"

// THÊM FILE ĐĂNG NHẬP VÀO ĐÂY
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // -------------------------------------------------------------
    // KHU VỰC CHẠY THỬ LOGIC HỆ THỐNG (In ra tab Application Output)
    std::cout << "=== HE THONG QUAN LY KHACH SAN GRAND HOTEL ===" << std::endl;

    // 1. Thử nghiệm phân quyền tài khoản
    Account managerAcc("admin", "admin123", Role::Manager);
    if (managerAcc.login("admin", "admin123")) {
        std::cout << "-> Dang nhap thanh cong! User: " << managerAcc.getUsername()
        << " | Quyen: " << managerAcc.getRoleString() << std::endl;
    }

    // 2. Thử nghiệm Factory Pattern tạo phòng tự động
    auto testRoom = RoomFactory::createRoom("Standard", 101);
    if (testRoom) {
        std::cout << "-> Factory tao phong thanh cong! So phong: " << testRoom->getRoomNumber()
        << " | Loai: " << testRoom->getRoomType() << std::endl;
    }

    // 3. Đọc dữ liệu từ file JSON bằng Singleton
    DatabaseManager::getInstance().loadRoomsFromJSON(DatabaseManager::getInstance().getRoomsVectorPlaceholder());
    // -------------------------------------------------------------

    // KHU VỰC ĐIỀU KHIỂN GIAO DIỆN CHẠY ĐĂNG NHẬP TRƯỚC
    LoginDialog login;

    // Nếu người dùng nhập đúng tài khoản demo và bấm "Đăng nhập"
    if (login.exec() == QDialog::Accepted) {
        MainWindow w;
        w.show();         // Mở cửa sổ chính MainWindow
        return a.exec();  // Chạy vòng lặp ứng dụng
    }

    return 0; // Nếu tắt bảng đăng nhập hoặc đăng nhập thất bại thì thoát chương trình luôn
}