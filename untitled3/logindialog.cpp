#include "logindialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QPainterPath>

// Hàm vẽ Icon Vector cao cấp cho các ô nhập liệu và danh sách tính năng
QIcon LoginDialog::createVectorIcon(const QString& type, const QColor& color) {
    QPixmap pixmap(32, 32);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(color, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.setBrush(Qt::NoBrush);

    if (type == "user") {
        painter.drawEllipse(11, 5, 10, 10);
        QPainterPath path;
        path.moveTo(5, 27);
        path.arcTo(5, 17, 22, 20, 180, -180);
        painter.drawPath(path);
    }
    else if (type == "lock") {
        painter.drawRoundedRect(7, 13, 18, 14, 2, 2);
        painter.drawArc(10, 5, 12, 16, 0, 180 * 16);
    }
    else if (type == "eye") {
        QPainterPath path;
        path.moveTo(3, 16);
        path.quadTo(16, 5, 29, 16);
        path.quadTo(16, 27, 3, 16);
        painter.drawPath(path);
        painter.setBrush(color);
        painter.drawEllipse(13, 13, 6, 6);
    }
    else if (type == "eye-off") {
        QPainterPath path;
        path.moveTo(3, 16);
        path.quadTo(16, 5, 29, 16);
        path.quadTo(16, 27, 3, 16);
        painter.drawPath(path);
        painter.setBrush(color);
        painter.drawEllipse(13, 13, 6, 6);
        painter.setBrush(Qt::NoBrush);
        painter.drawLine(6, 6, 26, 26);
    }
    // Dấu check hình tròn xịn cho danh sách tính năng bên trái
    else if (type == "feature-check") {
        painter.setPen(QPen(QColor("#38BDF8"), 2)); // Màu xanh bầu trời sáng
        painter.drawEllipse(4, 4, 24, 24);

        QPainterPath path;
        path.moveTo(10, 16);
        path.lineTo(14, 20);
        path.lineTo(22, 11);
        painter.drawPath(path);
    }

    painter.end();
    return QIcon(pixmap);
}

// HÀM KHỞI TẠO CỦA CỬA SỔ ĐĂNG NHẬP
LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent), isPasswordHidden(true)
{
    this->setWindowTitle("Grand Hotel PMS");
    this->resize(1000, 650);
    this->setMinimumSize(950, 600);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // ==================== PANEL BÊN TRÁI (THIẾT KẾ ĐỘC QUYỀN MỚI) ====================
    QWidget *leftPanel = new QWidget(this);
    leftPanel->setObjectName("leftPanel");

    QVBoxLayout *leftLayout = new QVBoxLayout(leftPanel);
    leftLayout->setContentsMargins(40, 50, 40, 50);
    leftLayout->setSpacing(0);
    leftLayout->setAlignment(Qt::AlignCenter); // Căn giữa toàn bộ block theo chiều dọc

    leftLayout->addStretch(1);

    // Khu vực Logo nổi bật (Bo tròn, tạo khối nền nhẹ nâng cấp thị giác)
    QWidget *logoContainer = new QWidget(leftPanel);
    logoContainer->setObjectName("logoContainer");
    logoContainer->setFixedSize(110, 110);

    QVBoxLayout *logoContainerLayout = new QVBoxLayout(logoContainer);
    logoContainerLayout->setContentsMargins(0, 0, 0, 0);
    logoContainerLayout->setAlignment(Qt::AlignCenter);

    // ĐÃ CẬP NHẬT: Gọi chuẩn file logo mới của bạn qua đường dẫn tài nguyên
    QLabel *logoLabel = new QLabel(logoContainer);
    QPixmap hotelPixmap(":/hotel2.png");
    if(!hotelPixmap.isNull()) {
        logoLabel->setPixmap(hotelPixmap.scaled(75, 75, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        logoLabel->setText("🏨");
        logoLabel->setStyleSheet("font-size: 50px;");
    }
    logoLabel->setAlignment(Qt::AlignCenter);
    logoContainerLayout->addWidget(logoLabel);

    leftLayout->addWidget(logoContainer, 0, Qt::AlignHCenter);
    leftLayout->addSpacing(20);

    // Tên thương hiệu
    QLabel *hotelName = new QLabel("Grand Hotel", leftPanel);
    hotelName->setObjectName("hotelName");
    hotelName->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(hotelName);
    leftLayout->addSpacing(6);

    // Slogan hệ thống
    QLabel *hotelSub = new QLabel("MANAGEMENT SYSTEM", leftPanel);
    hotelSub->setObjectName("hotelSub");
    hotelSub->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(hotelSub);

    leftLayout->addSpacing(45); // Khoảng cách tới danh sách tính năng

    // Khối danh sách tính năng với Icon Vector Xịn
    QVBoxLayout *featuresLayout = new QVBoxLayout();
    featuresLayout->setSpacing(16);
    featuresLayout->setAlignment(Qt::AlignLeft);

    QStringList features = {"Bảo mật hệ thống tối cao", "Tự động lưu trữ JSON dữ liệu", "Phân quyền đa cấp chuyên nghiệp"};
    for (const QString& text : features) {
        QHBoxLayout *row = new QHBoxLayout();
        row->setSpacing(12);

        QLabel *iconLabel = new QLabel(leftPanel);
        iconLabel->setPixmap(createVectorIcon("feature-check", QColor("#38BDF8")).pixmap(22, 22));

        QLabel *txtLabel = new QLabel(text, leftPanel);
        txtLabel->setObjectName("leftPureText");

        row->addWidget(iconLabel);
        row->addWidget(txtLabel);
        row->addStretch();

        featuresLayout->addLayout(row);
    }

    // Gói danh sách tính năng vào một widget căn giữa
    QWidget *featuresContainer = new QWidget(leftPanel);
    featuresContainer->setLayout(featuresLayout);
    leftLayout->addWidget(featuresContainer, 0, Qt::AlignHCenter);

    leftLayout->addStretch(1);


    // ==================== PANEL BÊN PHẢI (GIỮ NGUYÊN & ĐỒNG BỘ NÚT) ====================
    QWidget *rightPanel = new QWidget(this);
    rightPanel->setObjectName("rightPanel");
    QVBoxLayout *rightLayout = new QVBoxLayout(rightPanel);
    rightLayout->setContentsMargins(60, 35, 60, 35);
    rightLayout->setSpacing(10);

    QLabel *titleLabel = new QLabel("Đăng nhập", rightPanel);
    titleLabel->setObjectName("titleLabel");

    QLabel *descLabel = new QLabel("Nhập tài khoản để tiếp tục làm việc", rightPanel);
    descLabel->setObjectName("descLabel");

    rightLayout->addWidget(titleLabel);
    rightLayout->addWidget(descLabel);
    rightLayout->addSpacing(5);

    // Vùng nhập Email
    QVBoxLayout *emailBox = new QVBoxLayout();
    emailBox->setSpacing(5);
    QLabel *lblEmail = new QLabel("EMAIL", rightPanel);
    lblEmail->setObjectName("fieldLabel");
    emailEdit = new QLineEdit(rightPanel);
    emailEdit->setFixedHeight(45);
    emailEdit->setPlaceholderText("Nhập email hoặc tên đăng nhập");
    emailEdit->addAction(createVectorIcon("user", QColor("#94A3B8")), QLineEdit::LeadingPosition);
    emailBox->addWidget(lblEmail);
    emailBox->addWidget(emailEdit);
    rightLayout->addLayout(emailBox);

    // Vùng nhập Password
    QVBoxLayout *passBox = new QVBoxLayout();
    passBox->setSpacing(5);
    QLabel *lblPass = new QLabel("PASSWORD", rightPanel);
    lblPass->setObjectName("fieldLabel");
    passwordEdit = new QLineEdit(rightPanel);
    passwordEdit->setFixedHeight(45);
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setPlaceholderText("Nhập mật khẩu");
    passwordEdit->addAction(createVectorIcon("lock", QColor("#94A3B8")), QLineEdit::LeadingPosition);
    eyeAction = passwordEdit->addAction(createVectorIcon("eye", QColor("#94A3B8")), QLineEdit::TrailingPosition);
    connect(eyeAction, &QAction::triggered, this, &LoginDialog::togglePasswordVisibility);
    passBox->addWidget(lblPass);
    passBox->addWidget(passwordEdit);
    rightLayout->addLayout(passBox);

    // Vùng chọn Vai trò
    QVBoxLayout *roleBox = new QVBoxLayout();
    roleBox->setSpacing(5);
    QLabel *lblRole = new QLabel("VAI TRÒ TRUY CẬP", rightPanel);
    lblRole->setObjectName("fieldLabel");

    roleComboBox = new QComboBox(rightPanel);
    roleComboBox->addItems({"Quản lý", "Nhân viên", "Khách hàng"});
    roleComboBox->setFixedHeight(45);
    roleComboBox->setCurrentIndex(1);

    roleBox->addWidget(lblRole);
    roleBox->addWidget(roleComboBox);
    rightLayout->addLayout(roleBox);

    // VÙNG TIỆN ÍCH
    QHBoxLayout *utilBox = new QHBoxLayout();
    rememberMeCheck = new QCheckBox("Ghi nhớ đăng nhập", rightPanel);
    rememberMeCheck->setObjectName("rememberMeCheck");
    QPushButton *forgotBtn = new QPushButton("Quên mật khẩu?", rightPanel);
    forgotBtn->setObjectName("forgotBtn");
    utilBox->addWidget(rememberMeCheck);
    utilBox->addStretch();
    utilBox->addWidget(forgotBtn);
    rightLayout->addLayout(utilBox);

    // NHÃN BÁO LỖI CỐ ĐỊNH
    errorLabel = new QLabel("", rightPanel);
    errorLabel->setObjectName("errorLabel");
    errorLabel->setFixedHeight(25);
    errorLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    rightLayout->addWidget(errorLabel);

    // Nút đăng nhập chính
    loginButton = new QPushButton("Đăng nhập", rightPanel);
    loginButton->setObjectName("loginButton");
    loginButton->setFixedHeight(50);
    rightLayout->addWidget(loginButton);
    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::handleLogin);

    QLabel *divLabel = new QLabel("hoặc sử dụng một trong các lựa chọn này", rightPanel);
    divLabel->setObjectName("dividerLabel");
    divLabel->setAlignment(Qt::AlignCenter);
    rightLayout->addWidget(divLabel);

    // Nút MXH đồng bộ kích thước bằng nhau tăm tắp
    QHBoxLayout *socialBox = new QHBoxLayout();
    socialBox->setSpacing(12);

    QPushButton *gBtn = new QPushButton(" Google", rightPanel);
    gBtn->setObjectName("socialGoogleBtn");
    gBtn->setFixedHeight(45);
    QIcon googleIcon(":/google1.png");
    if(!googleIcon.isNull()) {
        gBtn->setIcon(googleIcon);
        gBtn->setIconSize(QSize(22, 22));
    }

    QPushButton *fBtn = new QPushButton(" Facebook", rightPanel);
    fBtn->setObjectName("socialFbBtn");
    fBtn->setFixedHeight(45);
    QIcon fbIcon(":/facebook2.jpg");
    if(!fbIcon.isNull()) {
        fBtn->setIcon(fbIcon);
        fBtn->setIconSize(QSize(22, 22));
    }

    socialBox->addWidget(gBtn);
    socialBox->addWidget(fBtn);
    rightLayout->addLayout(socialBox);

    // Thẻ chứa tài khoản demo mẫu
    QWidget *infoCard = new QWidget(rightPanel);
    infoCard->setObjectName("infoCard");
    QVBoxLayout *infoCardLayout = new QVBoxLayout(infoCard);
    QLabel *infoText = new QLabel("<b>Demo Accounts:</b><br>"
                                  "• Manager: admin / admin123<br>"
                                  "• Employee: employee / employee123<br>"
                                  "• Customer: customer / customer123", infoCard);
    infoText->setObjectName("infoText");
    infoCardLayout->addWidget(infoText);
    rightLayout->addWidget(infoCard);

    mainLayout->addWidget(leftPanel, 38);
    mainLayout->addWidget(rightPanel, 62);

    // ==================== TOÀN BỘ STYLE SHEET ĐÃ ĐƯỢC LÀM MỚI HIỆN ĐẠI ====================
    this->setStyleSheet(R"(
        QDialog {
            background-color: #FFFFFF;
        }
        QWidget#leftPanel {
            background-color: #0F172A; /* Màu xanh đen Slate chuẩn quốc tế cao cấp */
            border-top-left-radius: 12px;
            border-bottom-left-radius: 12px;
        }

        /* Đập khối vòng rực sáng tinh tế ôm lấy logo làm điểm nhấn thương hiệu */
        QWidget#logoContainer {
            background-color: rgba(255, 255, 255, 0.07);
            border: 1px solid rgba(255, 255, 255, 0.15);
            border-radius: 55px;
        }

        QLabel#hotelName {
            color: #FFFFFF;
            font-size: 28px;
            font-weight: 800;
            font-family: 'Segoe UI', Arial;
            letter-spacing: 0.5px;
        }
        QLabel#hotelSub {
            color: #38BDF8; /* Màu xanh bầu trời sáng công nghệ */
            font-size: 11px;
            font-weight: bold;
            letter-spacing: 3px;
        }
        QLabel#leftPureText {
            color: #E2E8F0;
            font-size: 14px;
            font-weight: 500;
            font-family: 'Segoe UI';
        }
        QWidget#rightPanel {
            background-color: #FFFFFF;
            border-top-right-radius: 12px;
            border-bottom-right-radius: 12px;
        }
        QLabel#titleLabel {
            color: #0F172A;
            font-size: 28px;
            font-weight: bold;
        }
        QLabel#descLabel {
            color: #64748B;
            font-size: 14px;
        }
        QLabel#fieldLabel {
            color: #475569;
            font-size: 11px;
            font-weight: bold;
        }
        QLineEdit {
            background-color: #FFFFFF;
            border: 1px solid #CBD5E1;
            border-radius: 6px;
            padding-left: 36px;
            padding-right: 36px;
            color: #334155;
            font-size: 14px;
        }
        QLineEdit:focus {
            border: 2px solid #2563EB;
        }
        QComboBox {
            background-color: #FFFFFF;
            border: 1px solid #CBD5E1;
            border-radius: 6px;
            padding-left: 12px;
            color: #334155;
            font-size: 14px;
        }
        QComboBox:focus {
            border: 2px solid #2563EB;
        }
        QComboBox::drop-down {
            border: none;
            subcontrol-origin: padding;
            subcontrol-position: top right;
            width: 30px;
        }
        QComboBox QListView {
            background-color: #FFFFFF;
            border: 1px solid #CBD5E1;
            color: #334155;
            selection-background-color: #2563EB;
            selection-color: #FFFFFF;
        }
        QCheckBox#rememberMeCheck {
            color: #475569 !important;
            font-size: 13px;
            font-family: 'Segoe UI';
        }
        QCheckBox#rememberMeCheck::indicator {
            width: 18px;
            height: 18px;
        }
        QPushButton#loginButton {
            background-color: #2563EB;
            color: #FFFFFF;
            border-radius: 6px;
            font-size: 16px;
            font-weight: bold;
        }
        QPushButton#loginButton:hover {
            background-color: #1D4ED8;
        }
        QPushButton#forgotBtn {
            background-color: transparent;
            color: #2563EB;
            border: none;
            font-size: 13px;
            font-weight: bold;
        }
        QPushButton#forgotBtn:hover {
            color: #1D4ED8;
            text-decoration: underline;
        }
        QLabel#dividerLabel {
            color: #94A3B8;
            font-size: 12px;
        }
        QPushButton#socialGoogleBtn, QPushButton#socialFbBtn {
            background-color: #FFFFFF;
            border: 1px solid #E2E8F0;
            border-radius: 6px;
            color: #475569;
            font-size: 14px;
            font-weight: 500;
            min-width: 160px;
            max-width: 160px;
            height: 40px;
        }
        QPushButton#socialGoogleBtn:hover, QPushButton#socialFbBtn:hover {
            background-color: #F8FAFC;
            border-color: #CBD5E1;
        }
        QWidget#infoCard {
            background-color: #EFF6FF;
            border: 1px solid #BFDBFE;
            border-radius: 6px;
        }
        QLabel#infoText {
            color: #1E40AF;
            font-size: 13px;
        }
        QLabel#errorLabel {
            color: #EF4444;
            font-family: 'Segoe UI';
            font-size: 10pt;
            font-weight: 500;
        }
    )");
}

void LoginDialog::togglePasswordVisibility() {
    if (isPasswordHidden) {
        passwordEdit->setEchoMode(QLineEdit::Normal);
        eyeAction->setIcon(createVectorIcon("eye-off", QColor("#94A3B8")));
    } else {
        passwordEdit->setEchoMode(QLineEdit::Password);
        eyeAction->setIcon(createVectorIcon("eye", QColor("#94A3B8")));
    }
    isPasswordHidden = !isPasswordHidden;
}

void LoginDialog::handleLogin() {
    QString user = emailEdit->text();
    QString pass = passwordEdit->text();
    int role = roleComboBox->currentIndex();

    bool success = false;
    if (role == 1 && user == "employee" && pass == "employee123") success = true;
    else if (role == 0 && user == "admin" && pass == "admin123") success = true;
    else if (role == 2 && user == "customer" && pass == "customer123") success = true;

    if (success) {
        errorLabel->setText("");
        this->accept();
    } else {
        errorLabel->setText("⚠ Thông tin đăng nhập không chính xác!");
    }
}

int LoginDialog::getSelectedRoleIndex() const { return roleComboBox->currentIndex(); }
QString LoginDialog::getUsername() const { return emailEdit->text(); }
LoginDialog::~LoginDialog() {}