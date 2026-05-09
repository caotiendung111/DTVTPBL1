# ✈️ DTVTPBL1 - Hệ Thống Quản Lý Tour Du Lịch Trong Nước

<div align="center">

[![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://cplusplus.com/)
[![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat-square&logo=windows&logoColor=white)](#)
[![File-Based](https://img.shields.io/badge/Storage-File%20Based-orange?style=flat-square)](#)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=flat-square)](#)

**Ứng Dụng Quản Lý & Đặt Tour Du Lịch Trong Nước Toàn Diện**

[Tính Năng](#-tính-năng-chính) • [Hướng Dẫn](#-hướng-dẫn-sử-dụng) • [Cấu Trúc](#-cấu-trúc-dự-án)

</div>

---

## 📖 Giới Thiệu

**DTVTPBL1** là một ứng dụng quản lý tour du lịch trong nước được viết bằng **C++** chạy trên **Windows Console**. Hệ thống cho phép:

- 👥 **Khách Hàng** có thể đăng ký, đăng nhập, tìm kiếm tour, đặt tour, xem hóa đơn
- 👔 **Quản Lý** quản lý khách hàng, tour, giá cả, và xem các tour đã bán

Toàn bộ dữ liệu được lưu trữ vào **file .txt** (Người.txt, ThongTinTour.txt, v.v.)

---

## 🚀 Tính Năng Chính

### 👤 Chức Năng Khách Hàng

| Tính Năng | Mô Tả |
|-----------|-------|
| 📝 **Đăng Ký Tài Khoản** | Tạo tài khoản mới với CMND, họ tên, email, số điện thoại |
| 🔐 **Đăng Nhập** | Đăng nhập bằng CMND và mật khẩu |
| 🔍 **Tìm Kiếm Tour** | Tìm tour theo tên, giá tiền, số ngày, v.v. |
| 📊 **Xem Tour Có Sẵn** | Hiển thị tất cả tour du lịch với đầy đủ thông tin |
| 💰 **Xem Top Tour** | Xem tour có giá cao nhất & thấp nhất |
| 📋 **Sắp Xếp Tour** | Sắp xếp tour theo giá tiền (tăng/giảm) |
| 🎫 **Đặt Tour** | Chọn tour, cập nhật info tour nếu cần, xuất hóa đơn |
| 📄 **Xem Hóa Đơn** | Xem danh sách hóa đơn tour đã đặt |
| ❌ **Hủy Tour** | Hủy tour nếu không muốn (xóa hóa đơn) |
| ⚙️ **Cập Nhật Tài Khoản** | Thay đổi CMND, họ tên, email, mật khẩu, v.v. |
| 🔑 **Đổi Mật Khẩu** | Thay đổi mật khẩu hiện tại |

### 👔 Chức Năng Quản Lý

| Tính Năng | Mô Tả |
|-----------|-------|
| 👥 **Thêm Khách Hàng** | Tạo hồ sơ khách hàng mới |
| 🗑️ **Xóa Khách Hàng** | Xóa khách hàng theo CMND |
| 📋 **Xem Danh Sách Khách** | Hiển thị tất cả khách hàng |
| 🎫 **Thêm Tour Mới** | Thêm tour mới vào hệ thống |
| 🗑️ **Xóa Tour** | Xóa tour theo mã tour |
| 📊 **Xem Danh Sách Tour** | Hiển thị tất cả tour trong hệ thống |
| 🔍 **Tìm Kiếm Tour** | Tìm tour theo mã, tên, giá, v.v. |
| 💰 **Tour Cao Nhất/Thấp Nhất** | Xem top tour có giá cao/thấp nhất |
| 📊 **Sắp Xếp Tour** | Sắp xếp theo giá tiền, số ngày |
| 📝 **Cập Nhật Thông Tin Tour** | Chỉnh sửa thông tin chi tiết tour |
| 📝 **Cập Nhật Khách Hàng** | Chỉnh sửa thông tin khách hàng |
| 🧑 **Sắp Xếp Khách Theo Tuổi** | Xắp xếp khách hàng theo năm sinh |
| 📋 **Xem Tour Đã Bán** | Xem danh sách tour đã bán được |

---

## 🛠️ Công Nghệ & Công Cụ Sử Dụng

```
🔧 Ngôn Ngữ & Framework
├── C++ (97.6%)
├── C (2.4%) - Code hỗ trợ
└── Windows API - GUI console

📦 Thư Viện Chính
├── iostream - Input/Output
├── fstream - File handling
├── vector - Dynamic arrays
├── string - String manipulation
├── algorithm - Sorting & searching
├── sstream - String streaming
└── windows.h - Console graphics

💾 Lưu Trữ Dữ Liệu
├── Người.txt - Thông tin khách hàng
├── ThongTinTour.txt - Danh sách tour
├── billKhachHang.txt - Hóa đơn khách
└── billQuanLi.txt - Tập hợp tất cả hóa đơn
```

---

## 📁 Cấu Trúc Dự Án

```
DTVTPBL1/
├── MainDulich2HDH2.cpp        # Main program - tất cả logic chính
├── Do_Hoa.h                   # Header file - các hàm graphics/UI
├── Nguoi.txt                  # Data: Thông tin khách hàng
├── ThongTinTour.txt           # Data: Thông tin tour
├── BillKhachHang.txt          # Data: Hóa đơn của từng khách
├── billQuanLi.txt             # Data: Tập hợp tất cả hóa đơn
├── README.md                  # Tài liệu này
└── [Các file .txt khác]
```

---

## 🏗️ Kiến Trúc Chương Trình

### Class Chính

#### 1️⃣ **People Class** - Lớp Khách Hàng
```cpp
class People {
    string CMND;          // Chứng Minh Nhân Dân
    string fullName;      // Họ và tên
    string Que;           // Quê quán
    string birthDate;     // Ngày sinh (DD/MM/YYYY)
    string email;         // Email
    string sdt;           // Số điện thoại
    string matkhau;       // Mật khẩu
};
```

**Các Phương Thức Chính:**
- Getter/Setter cho tất cả các attribute
- `showInfo()` - Hiển thị thông tin khách hàng

#### 2️⃣ **Tourists Class** - Lớp Tour (Kế Thừa People)
```cpp
class Tourists : public People {
    string Matour;                // Mã tour
    string TenTour;               // Tên tour
    string NgayXuatPhat;          // Ngày khởi hành
    int SoNgayDi;                 // Số ngày du lịch
    string HuongDanVien;          // Tên hướng dẫn viên
    string MayBay;                // Hãng máy bay
    string KhachSan;              // Tên khách sạn
    int GiaTien;                  // Giá tiền (VND)
    string phuongthucgiaodich;    // Phương thức giao dịch (cash/card/bank)
};
```

**Các Phương Thức Chính:**
- Getter/Setter cho tất cả các attribute
- `showifTour()` - Hiển thị thông tin tour

#### 3️⃣ **Bill Class** - Lớp Hóa Đơn (Kế Thừa Tourists)
```cpp
class Bill : public Tourists {
    string noidung;       // Nội dung hóa đơn
    void xuat_bill();     // Xuất hóa đơn ra màn hình
};
```

---

## 💻 Các Hàm Chính

### Quản Lý Dữ Liệu

| Hàm | Mô Tả |
|-----|-------|
| `DocDuLieuTuFileNguoi()` | Đọc dữ liệu khách từ file |
| `DocDuLieuTuFileTour()` | Đọc dữ liệu tour từ file |
| `GhiDuLieuVaoFileNguoi1()` | Ghi khách hàng vào file |
| `GhiDuLieuVaoFileTour()` | Ghi tour vào file |

### Tìm Kiếm & Sắp Xếp

| Hàm | Mô Tả |
|-----|-------|
| `TimKiemKhachHang()` | Tìm kiếm khách hàng |
| `timkiemTour()` | Tìm kiếm tour |
| `SapXepTheoNam()` | Sắp xếp khách theo năm sinh |
| `SapXepTheoSoTienGiamDan()` | Sắp xếp tour giảm dần theo giá |
| `SapXepTheoSoTienTangDan()` | Sắp xếp tour tăng dần theo giá |
| `SapXepTheoSoNgayDi()` | Sắp xếp tour theo số ngày |

### Đặc Biệt

| Hàm | Mô Tả |
|-----|-------|
| `timkiemTourCaoNhat()` | Tìm tour có giá cao nhất |
| `timkiemTourThapNhat()` | Tìm tour có giá thấp nhất |
| `xuattourDuLich()` | Xuất hóa đơn chi tiết |
| `KTDangNhap()` | Xác thực đăng nhập |

---

## 🚀 Hướng Dẫn Sử Dụng

### 1️⃣ Yêu Cầu & Chuẩn Bị

**Yêu Cầu:**
- Windows OS (do sử dụng `windows.h` và `conio.h`)
- C++ Compiler (Visual Studio, Dev-C++, Code::Blocks, v.v.)

**File Dữ Liệu (phải có sẵn):**
```
Người.txt               → Danh sách khách hàng
ThongTinTour.txt       → Danh sách tour
billQuanLi.txt         → Hóa đơn quản lý
billKhachHang.txt      → Hóa đơn khách hàng
```

### 2️⃣ Biên Dịch & Chạy

```bash
# Biên dịch với g++
g++ -o DTVTPBL1 MainDulich2HDH2.cpp

# Chạy chương trình
./DTVTPBL1
```

**Hoặc trong Visual Studio:**
1. Tạo project C++ Console mới
2. Thêm 2 file: `MainDulich2HDH2.cpp` và `Do_Hoa.h`
3. Build & Run

### 3️⃣ Hướng Dẫn Sử Dụng Ứng Dụng

#### **Màn Hình Chính**
```
Chọn 1 - Quản Lý (dành cho admin/quản lý tour)
Chọn 2 - Khách Hàng (dành cho khách du lịch)
Chọn 0 - Thoát
```

#### **Mode Quản Lý:**
```
1.  Thêm khách hàng
2.  Xóa khách hàng
3.  Hiển thị danh sách khách
4.  Hiển thị danh sách tour
5.  Tìm kiếm khách hàng
6.  Tìm kiếm tour
7.  Sắp xếp khách theo tuổi
8.  Sắp xếp tour theo giá tiền
9.  Sắp xếp theo số ngày du lịch
10. Cập nhật thông tin khách
11. Cập nhật thông tin tour
12. Xem tour có giá cao nhất
13. Xem tour có giá thấp nhất
14. Thêm tour mới
15. Xóa tour
16. Xem tour đã bán được
17. Quay lại menu chính
```

#### **Mode Khách Hàng:**
```
ĐĂNG KÝ / ĐĂNG NHẬP
↓
1.  Hiển thị tour có sẵn
2.  Tìm kiếm tour
3.  Đổi mật khẩu
4.  Xem tour giá cao nhất
5.  Xem tour giá thấp nhất
6.  Sắp xếp tour theo giá
7.  Cập nhật thông tin cá nhân
8.  ĐẶT TOUR
    ├─ Cập nhật thông tin tour (ngày, số ngày, phương thức)
    └─ Xuất hóa đơn
9.  Xem hóa đơn tour đã đặt (có thể hủy)
10. Quay lại
```

---

## 📊 Định Dạng File Dữ Liệu

### 📄 Người.txt (Khách Hàng)
```
CMND;FullName;Que;BirthDate;Email;Phone;Password
123456789;Cao Tiến Dũng;Da Nang;01/01/2000;dung@email.com;0123456789;pass123
987654321;Nguyen Van A;Ha Noi;15/05/1998;vana@email.com;0987654321;abc123
```

**Format:** CMND ; Họ Tên ; Quê Quán ; Ngày Sinh ; Email ; SDT ; Mật Khẩu

### 🎫 ThongTinTour.txt (Tour)
```
T001;Ha Noi - Phong Nha;01/12/2024;3;Mr. Tuan;Vietnam Airlines;Saigon Hotel;5000000;Transfer Bank
T002;Sa Pa - Fansipan;15/12/2024;2;Ms. Lan;Vietjet Air;Topas Hotel;3000000;Cash
```

**Format:** MaTour ; TenTour ; NgayXP ; SoNgayDi ; HuongDanVien ; MayBay ; KhachSan ; Gia ; PTGD

### 📋 billKhachHang.txt / billQuanLi.txt
```
                HOA DON TOUR DU LICH CUA QUY KHACH - CAM ON DA UNG HO.
        
                Da Nang, Ngay : 08 / 12 / 2024
                Thoi Gian     : 14:30:45 PM
        
        *****************************************
        *Khach hang        : Cao Tiến Dũng
        *Que Quan          : Da Nang
        *So Dien Thoai     : 0123456789
        *****************************************
        *Ma Tour           : T001
        *Ten Tour          : Ha Noi - Phong Nha
        *Ngay xuat phat    : 01/12/2024
        *So Ngay Di        : 3 ngay
        *Huong Dan Vien    : Mr. Tuan
        *May Bay           : Vietnam Airlines
        *Khach San         : Saigon Hotel
        *Gia Tien          : 5000000 vnd
        *Giao Dich         : Transfer Bank
        Tour Du Lich Dung Nhat CAM ON QUY KHACH.
```

---

## 🎨 Giao Diện & UI

### Màu Sắc Console
```cpp
0   = Black          (Đen)
1   = Blue           (Xanh đậm)
2   = Green          (Xanh lá)
3   = Cyan           (Xanh nước biển)
4   = Red            (Đỏ)
5   = Magenta        (Tím)
6   = Brown          (Nâu)
7   = Light Gray     (Xám nhạt)
8   = Dark Gray      (Xám đậm)
9   = Light Blue     (Xanh nhạt)
10  = Light Green    (Xanh lá nhạt)
11  = Light Cyan     (Xanh nước biển nhạt) - THÔNG TIN
12  = Light Red      (Đỏ nhạt) - CẢNH BÁO
13  = Light Magenta  (Tím nhạt)
14  = Yellow         (Vàng) - TIÊU ĐỀ
15  = White          (Trắng)
```

### Các Hàm Graphics (Do_Hoa.h)
```cpp
textcolor(x)              // Đổi màu chữ
gotoxy(x, y)              // Di chuyển cursor tới vị trí (x,y)
XoaManHinh()              // Xóa màn hình
resizeConsole(w, h)       // Resize cửa sổ console
ShowCur(visibility)       // Ẩn/hiện con trỏ
ToMau(x, y, text, color)  // Viết text tại vị trí với màu
```

---

## ⚙️ Một Số Lưu Ý Kỹ Thuật

### 1. Xác Thực Đăng Nhập
```cpp
bool KTDangNhap(const vector<People> person, 
                const string cmnddn, 
                const string mkdn)
{
    for (const People& p : person) {
        if (p.getCMND() == cmnddn && p.getMatKhau() == mkdn)
            return true;
    }
    return false;
}
```

### 2. Tìm Kiếm (Case-Insensitive)
- Chuyển tất cả string về chữ thường trước so sánh
- Hỗ trợ tìm kiếm theo: CMND, Tên, Email, SDT, Quê quán, Năm sinh

### 3. Sắp Xếp Bubble Sort
- Sắp xếp theo năm sinh (từ trẻ → già)
- Sắp xếp tour theo giá (tăng/giảm)
- Sắp xếp theo số ngày du lịch

### 4. Lưu Trữ Dữ Liệu
- Dùng `;` (semicolon) làm ký tự phân tách
- Format: `field1;field2;field3\n`
- Sử dụng `stringstream` + `getline()` để parse dữ liệu

### 5. Xuất Hóa Đơn
- Sử dụng `stringstream` để tạo hóa đơn
- Ghi vào 2 file: khách hàng + quản lý
- Có timestamp tự động (ngày/giờ hiện tại)

---

## 🐛 Các Vấn Đề Đã Biết & Hạn Chế

| Vấn Đề | Mô Tả | Giải Pháp |
|--------|-------|----------|
| 📦 **Không có Database** | Dùng file text thay vì database | Có thể nâng cấp lên SQLite/MySQL |
| 🔐 **Bảo Mật** | Mật khẩu lưu dạng plain text | Nên hash mật khẩu (MD5/SHA256) |
| 🪟 **Chỉ Windows** | Dùng API Windows | Port sang Linux/Mac bằng ncurses |
| 📱 **Console chạy chậm** | Quá nhiều `system("cls")` | Dùng `XoaManHinh()` hoặc optimize |
| 🔄 **Đôi khi input bị lỗi** | `cin.ignore()` không đủ | Cần xử lý input buffer tốt hơn |

---

## 🔮 Nâng Cấp Trong Tương Lai

- [ ] Migrate sang **SQLite / MySQL Database**
- [ ] Thêm **GUI** (Qt/WinForms thay vì console)
- [ ] Hỗ trợ **Linux / Mac**
- [ ] Thêm **hash password** (MD5/SHA256)
- [ ] Thêm **system backup/restore**
- [ ] Thêm **statistics & reports** (thống kê doanh số, v.v.)
- [ ] Tích hợp **API thanh toán** (Momo, Zalopay, v.v.)
- [ ] Phát triển **web version** (PHP/Python/Node.js)

---

## 📚 Tài Liệu Tham Khảo

- [C++ Reference](https://cplusplus.com/)
- [Windows Console API](https://learn.microsoft.com/en-us/windows/console/)
- [File I/O in C++](https://www.cplusplus.com/reference/fstream/)
- [Vector & STL](https://cplusplus.com/reference/vector/)

---

## 📝 Định Dạng Code

- **Coding Style**: Google C++ Style Guide
- **Naming Convention**: camelCase cho biến, PascalCase cho class
- **Indentation**: 4 spaces (hoặc 1 tab)
- **Comments**: Tiếng Việt/Tiếng Anh

---

## 📞 Thông Tin Tác Giả

### 👨‍💻 Nhà Phát Triển
**Cao Tiến Dũng** (Dung Harry)

### 🏫 Bối Cảnh
- **Loại Dự Án**: Dự Án Thực Tập Phần PBL (Project-Based Learning - Học tập qua dự án)
- **Môn Học**: Lập Trình Hướng Đối Tượng (OOP)
- **Năm Học**: 2022-2023

### 🤝 Liên Hệ
- 🐙 GitHub: [@caotiendung111](https://github.com/caotiendung111)
- 📧 Email: caotiendung111@email.com
- 📘 Facebook: [Dung Harry](https://facebook.com/dungh)

---

## 📜 Giấy Phép

Dự án này được cấp phép dưới **MIT License** - xem file [LICENSE](LICENSE) để biết chi tiết.

---

## 🙏 Lời Cảm Ơn

- 👨‍🏫 Cảm ơn thầy cô hướng dẫn và giáo viên trường
- 👥 Cảm ơn các bạn cùng lớp đã hỗ trợ
- 💻 Cảm ơn cộng đồng lập trình C++ vì những tài liệu tuyệt vời

---

<div align="center">

### ⭐ Nếu thấy dự án này hữu ích, hãy ⭐ Star cho mình!

**Made with ❤️ by Cao Tiến Dũng**

```
   ✈️  Tour Du Lich DungNhat  ✈️
   HEN GAP LAI QUY KHACH
```

</div>