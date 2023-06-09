#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "Do_Hoa.h"
#include <algorithm>
#include <time.h> // dung de lay thoi gian hien tai 
using namespace std;
class People {
protected:
    string CMND;
    string fullName;
    string Que;
    string birthDate;
    string email;
    string sdt;
    string matkhau; 
    friend istream& operator >> (istream& is, People& people);
public:   
    string getCMND() const {
        return CMND;
    }
    string getFullName() const {
        return fullName;
    }
    string getQue() const {
        return Que;
    }
    string getBirthDate() const {
        return birthDate;
    }
    string getEmail() const {
        return email;
    }
    string getSDT() const {
        return sdt;
    }
    string getMatKhau() const
    {
        return matkhau;
    }
    void setCMND(const string& cmnd) {
        CMND = cmnd;
    }
    void setFullName(const string& name) {
        fullName = name;
    }
    void setQue(const string& que) {
        Que = que;
    }
    void setBirthDate(const string& date) {
        birthDate = date;
    }
    void setEmail(const string& email) {
        this->email = email;
    }
    void setSDT(const string& sdt) {
        this->sdt = sdt;
    }
    void setMatKhau(const string& matkhau)
    {
        this->matkhau = matkhau;
    }
    People() {
        CMND = "";fullName = ""; Que = ""; birthDate = ""; email = "";sdt = "";matkhau = "";                
    }
    People(string CMND, string fullName, string Que, string birthDate, string email, string sdt, string matkhau) {
        this->CMND = CMND;
        this->fullName = fullName;
        this->Que = Que;
        this->birthDate = birthDate;
        this->email = email;
        this->sdt = sdt;
        this->matkhau = matkhau;
    }
    void showInfo() {
        cout << setw(15) << left << CMND << setw(16) << left << fullName << setw(15) << left << Que
            << setw(15) << left << birthDate << setw(25) << left << email
            << setw(15) << left << sdt << setw(15) << left << matkhau << "\n";
    }
};

People TaoDoiTuongPeopleFromString(string input) {
    vector<string> data;
    stringstream ss(input);
    string s2;
    const char daucach = ';'; // kí tự phân tách
    while (getline(ss, s2, daucach)) {
        data.push_back(s2);
    }

    if (data.size() >= 7) { // xem vector có đủ thông tin để tạo 1 đối tượng People hay không
        return People(data[0], data[1], data[2], data[3], data[4], data[5], data[6]);
    }
    return People("", "", "", "", "", "", ""); // Trả về một đối tượng rỗng nếu dữ liệu không hợp lệ
}

void DocDuLieuTuFileNguoi(string fileName, vector<People>& person) {
    ifstream ifs(fileName);
    if (ifs) {
        string line;
        while (getline(ifs, line)) {
            People People1 = TaoDoiTuongPeopleFromString(line);
            person.push_back(People1);
        }
    }
    ifs.close();
}
void showPeople(const vector<People>& person) {
    textcolor(14); cout << "==> THONG TIN KHACH HANG: \n";  textcolor(11);
    cout << setw(15) << left << "Chung Minh" << setw(16) << left << "FULL NAME" << setw(15) << left << "Que"
        << setw(15) << left << "Ngay Sinh" << setw(25) << left
        << "Email" << setw(15) << left << "Phone" << setw(15) << left << "PASSWORD" << "\n";

    for (People s : person) { // for each
        s.showInfo();
    } textcolor(9); 
}
void GhiDuLieuVaoFileNguoi1(const string& fileName, const vector<People>& person) {
    ofstream ofs(fileName);
    if (ofs) {
        for (const auto& people1 : person) {
            ofs << people1.getCMND() << ';' << people1.getFullName() << ';' << people1.getQue() << ";" << people1.getBirthDate() << ';'
                << people1.getEmail() << ';' << people1.getSDT() << ";" << people1.getMatKhau() << '\n';
        }
        cout << "\t\t\t\t Ghi du lieu vao file thanh cong.\n";
    }
    else {
        cout << "\t\t\t\t Khong the mo file de ghi du lieu.\n";
    }
    ofs.close();
}
bool SoSanhThongTinDeTimKiemKhachHang(const People& person, const string& keyword) {
    string lowerKeyword = keyword;
    string lowerStudentID = person.getCMND();
    string lowerPhone = person.getSDT();
    string lowerEmail = person.getEmail();
    string lowerQueQuan = person.getQue();
    string lowerBirthdate = person.getBirthDate();
    string lowerFullName = person.getFullName();
    transform(lowerStudentID.begin(), lowerStudentID.end(), lowerStudentID.begin(), tolower);
    transform(lowerPhone.begin(), lowerPhone.end(), lowerPhone.begin(), tolower);
    transform(lowerEmail.begin(), lowerEmail.end(), lowerEmail.begin(), tolower);
    transform(lowerFullName.begin(), lowerFullName.end(), lowerFullName.begin(), tolower);
    transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), tolower);
    transform(lowerBirthdate.begin(), lowerBirthdate.end(), lowerBirthdate.begin(), tolower);
    transform(lowerQueQuan.begin(), lowerQueQuan.end(), lowerQueQuan.begin(), tolower);
    return lowerStudentID == lowerKeyword || lowerPhone == lowerKeyword || lowerEmail == lowerKeyword
        || lowerQueQuan == lowerKeyword || lowerFullName == lowerKeyword || lowerBirthdate == lowerKeyword;
}
void TimKiemKhachHang(const vector<People>& person, const string& keyword) {
    bool found = false;
    int count = 0;
    for (auto people1 : person) {
        if (SoSanhThongTinDeTimKiemKhachHang(people1, keyword)) {
            if (count == 0) {            
                textcolor(11); cout << setw(15) << left << "Chung Minh" << setw(16) << left << "FULL NAME" << setw(15) << left << "Que"
                    << setw(15) << left << "Ngay Sinh" << setw(25) << left << "Email"
                    << setw(15) << left << "Phone" << setw(15) << left << "PassWord " << "\n";
                count = 1; textcolor(9);             
            }       
            textcolor(14);   people1.showInfo(); textcolor(9);         
            found = true;
        }
    }
    if (found == false) {
        cout << "\t\t\t\tKhong tim thay khach du lich co thong tin: " << keyword << endl;
    }
}
istream& operator >> (istream& is, People& person)
{
    string cmndd, hoten, quequan, ngaysinh, email, sdt, password;
    cout << "\t\t\t\t Nhap CMND : ";
    getline(is, cmndd);    
    person.setCMND(cmndd);
    cout << "\t\t\t\t Nhap Ho Va Ten : ";
    getline(is, hoten);
    person.setFullName(hoten);
    cout << "\t\t\t\t Nhap Que Quan :";
    getline(is, quequan);
    person.setQue(quequan);
    cout << "\t\t\t\t Nhap Ngay Sinh : ";
    getline(is, ngaysinh);
    person.setBirthDate(ngaysinh);
    cout << "\t\t\t\t Nhap Email : ";
    getline(is, email);
    person.setEmail(email);
    cout << "\t\t\t\t Nhap SDT : ";
    getline(is, sdt);
    person.setSDT(sdt);
    cout << "\t\t\t\t Nhap PassWord : ";
    getline(is, password);
    person.setMatKhau(password);
    return is;
}
bool SoSanhTuNamSinh(const People& person1, const People& person2)
{
    if (person1.getBirthDate().length() < 10 || person2.getBirthDate().length() < 10) {

        return false;
    }
    int year1, year2;
    stringstream(person1.getBirthDate().substr(6, 4)) >> year1;
    stringstream(person2.getBirthDate().substr(6, 4)) >> year2;
    return year1 < year2; // so tuoi tu be den lon 
}
void SapXepTheoNam(vector<People>& person)
{
    int n = person.size();
    bool swapped = false;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (SoSanhTuNamSinh(person[j], person[j + 1])) {
                People temp = person[j];
                person[j] = person[j + 1];
                person[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
class Tourists : public People
{
private:
    string Matour;
    string TenTour;
    string NgayXuatPhat;
    int SoNgayDi;
    string HuongDanVien;
    string MayBay;
    string KhachSan;
    int GiaTien;
    string phuongthucgiaodich;
public:
    Tourists() { SoNgayDi = 0; GiaTien = 0; }
    Tourists(string Matour, string TenTour, string NgayXuatPhat, int SoNgayDi, string HuongDanVien, string MayBay, string KhachSan, int GiaTien, string phuongthucgiaodich)
    {
        this->Matour = Matour;
        this->TenTour = TenTour;
        this->NgayXuatPhat = NgayXuatPhat;
        this->SoNgayDi = SoNgayDi;
        this->HuongDanVien = HuongDanVien;
        this->MayBay = MayBay;
        this->KhachSan = KhachSan;
        this->GiaTien = GiaTien;
        this->phuongthucgiaodich = phuongthucgiaodich;
    }
    void showifTour()
    {
        cout << setw(10) << left << Matour << setw(28) << left << TenTour << setw(17) << left << NgayXuatPhat
            << setw(12) << left << SoNgayDi << setw(18) << left << HuongDanVien << setw(30) << left << MayBay << setw(17) << left << KhachSan << setw(12) << left
            << size_t(GiaTien) << setw(15) << left << phuongthucgiaodich << "\n";
    }
    void setMatour(string Matour)
    {
        this->Matour = Matour;
    }
    void setTenTour(string TenTour)
    {
        this->TenTour = TenTour;
    }
    void setNgayXuatPhat(string NgayXuatPhat)
    {
        this->NgayXuatPhat = NgayXuatPhat;
    }
    void setSoNgayDi(int SoNgayDi)
    {
        this->SoNgayDi = SoNgayDi;
    }
    void setHuongDanVien(string HuongDanVien)
    {
        this->HuongDanVien = HuongDanVien;
    }
    void setMayBay(string MayBay)
    {
        this->MayBay = MayBay;
    }
    void setKhachSan(string KhachSan)
    {
        this->KhachSan = KhachSan;
    }
    void setGiaTien(int GiaTien)
    {
        this->GiaTien = GiaTien;
    }
    void setPhuongThucGiaoDich(string phuongthucgiaodich)
    {
        this->phuongthucgiaodich = phuongthucgiaodich;
    }
    string getMatour()
    {
        return Matour;
    }
    string getTenTour()
    {
        return TenTour;
    }
    string getNgayXuatPhat()
    {
        return NgayXuatPhat;
    }
    int getSoNgayDi()
    {
        return SoNgayDi;
    }
    string getHuongDanVien()
    {
        return HuongDanVien;
    }
    string getMayBay()
    {
        return MayBay;
    }
    string getKhachSan()
    {
        return KhachSan;
    }
    int getGiaTien()
    {
        return GiaTien;
    }
    string getPhuongThucGiaoDich()
    {
        return phuongthucgiaodich;
    }
};
Tourists TaoDoiTuongKhachHangFromString(string input) {
    vector<string> data;
    stringstream ss(input);
    string s2;
    const char delim = ';'; // kí tự phân tách
    while (getline(ss, s2, delim)) {
        data.push_back(s2);
    }
    if (data.size() >= 9) { // xem vector có đủ thông tin để tạo 1 đối tượng student hay không
        return Tourists(data[0], data[1], data[2], stof(data[3]), data[4], data[5], data[6], stof(data[7]), data[8]);
    }
    return Tourists("", "", " ", 0.0f, "", "", "", 0.0f, "");
}
void DocDuLieuTuFileTour(string fileName, vector<Tourists>& tourist) {
    ifstream ifs(fileName);
    if (ifs) {
        string line;
        while (getline(ifs, line)) {
            Tourists tour1 = TaoDoiTuongKhachHangFromString(line);
            tourist.push_back(tour1);
        }
    }
    ifs.close();
}
void showTourist(const vector<Tourists>& tourist) {
    textcolor(14);
    cout << "==> THONG TIN TOUR DU LICH: \n";
    textcolor(9);
    textcolor(11);
    cout << setw(10) << left << "Ma Tour" << setw(28) << left << "Ten Tour" << setw(17) << left << "Ngay Xuat Phat"
        << setw(12) << left << "So Ngay Di" << setw(18) << left << "Huong Dan Vien" << setw(30) << left << "May Bay" << setw(17) << left << "Khach San" << setw(12) << left
        << "Gia Tien" << setw(15) << left << "PT GD" << "\n";
    for (auto s : tourist) {
        s.showifTour();
    }
    textcolor(9);
}
void GhiDuLieuVaoFileTour(const vector<Tourists>& tourist, const string& fileName)
{
    ofstream file(fileName);
    if (file.is_open())
    {
        for (Tourists tourist : tourist)
        {
            file << tourist.getMatour() << ";"
                << tourist.getTenTour() << ";"
                << tourist.getNgayXuatPhat() << ";"
                << tourist.getSoNgayDi() << ";"
                << tourist.getHuongDanVien() << ";"
                << tourist.getMayBay() << ";"
                << tourist.getKhachSan() << ";"
                << tourist.getGiaTien() << ";"
                << tourist.getPhuongThucGiaoDich() << "\n";
        }
        file.close();
    }
    else
    {
        cout << "Khong the mo file " << fileName << " de ghi du lieu." << endl;
    }
}
istream& operator >> (istream& is, Tourists& tourist)
{
    string Matour, TenTour, NgayXuatPhat, HuongDanVien, MayBay, KhachSan, phuongthucgiaodich;
    int SoNgayDi, GiaTien;
    cout << "\t\t\t\t Nhap Ma Tour: ";
    getline(is, Matour);
    tourist.setMatour(Matour);
    cout << "\t\t\t\t Nhap Ten Tour: ";
    getline(is, TenTour);
    tourist.setTenTour(TenTour);
    cout << "\t\t\t\t Nhap Ngay Xuat Phat: ";
    getline(is, NgayXuatPhat);
    tourist.setNgayXuatPhat(NgayXuatPhat);
    cout << "\t\t\t\t Nhap So Ngay Di: ";
    is >> SoNgayDi;
    tourist.setSoNgayDi(SoNgayDi);
    cin.ignore();
    cout << "\t\t\t\t Nhap Huong Dan Vien: ";
    getline(is, HuongDanVien);
    tourist.setHuongDanVien(HuongDanVien);
    cout << "\t\t\t\t Nhap May Bay: ";
    getline(is, MayBay);
    tourist.setMayBay(MayBay);
    cout << "\t\t\t\t Nhap Khach San: ";
    getline(is, KhachSan);
    tourist.setKhachSan(KhachSan);
    cout << "\t\t\t\t Nhap Gia Tien: ";
    is >> GiaTien;
    tourist.setGiaTien(GiaTien);
    cin.ignore();
    cout << "\t\t\t\t Nhap Phuong Thuc Giao Dich: ";
    getline(is, phuongthucgiaodich);
    tourist.setPhuongThucGiaoDich(phuongthucgiaodich);
    return is;
}
bool TimKiemSoTienDeSapXepGiamDan(Tourists tourists1, Tourists tourists2)
{
    size_t(tien1) = tourists1.getGiaTien();
    size_t(tien2) = tourists2.getGiaTien();
    return tien1 < tien2;
}
void SapXepTheoSoTienGiamDan(vector<Tourists>& tourist)
{
    int n = tourist.size();
    bool swapped = false;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (TimKiemSoTienDeSapXepGiamDan(tourist[j], tourist[j + 1])) {
                Tourists temp = tourist[j];
                tourist[j] = tourist[j + 1];
                tourist[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
bool TimKiemSoTienDeSapXepTangDan(Tourists tourists1, Tourists tourists2)
{
    size_t(tien1) = tourists1.getGiaTien();
    size_t(tien2) = tourists2.getGiaTien();
    return tien1 > tien2;
}
void SapXepTheoSoTienTangDan(vector<Tourists>& tourist)
{
    int n = tourist.size();
    bool swapped = false;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (TimKiemSoTienDeSapXepTangDan(tourist[j], tourist[j + 1])) {
                Tourists temp = tourist[j];
                tourist[j] = tourist[j + 1];
                tourist[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
bool TimKiemDeSapXepSoNgayDi(Tourists tourists1, Tourists tourists2)
{
    int SoNgayDi1 = tourists1.getSoNgayDi();
    int SoNgayDi2 = tourists2.getSoNgayDi();
    return SoNgayDi1 > SoNgayDi2;
}
void SapXepTheoSoNgayDi(vector<Tourists>& tourist)
{
    int n = tourist.size();
    bool swapped = false;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (TimKiemDeSapXepSoNgayDi(tourist[j], tourist[j + 1])) {
                Tourists temp = tourist[j];
                tourist[j] = tourist[j + 1];
                tourist[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
vector<Tourists> timkiemTourCaoNhat(vector<Tourists>& tourists) {   
    SapXepTheoSoTienGiamDan(tourists);
    int highestGiaTien = tourists[0].getGiaTien();//gia tri lon nhat 
    // Lưu các tour có giá tiền cao nhất vào vector highestMoney
    vector<Tourists> highestMoney;
    for (auto& tour : tourists) {
        if (tour.getGiaTien() == highestGiaTien) {
            highestMoney.push_back(tour);
        }
        else {
            break;
        }
    }
    return highestMoney;
}
void inHanhKhachCaoNhat(const vector<Tourists>& highestMoney) {
    if (highestMoney.empty()) {
        cout << "KHONG CO TOUR NAO." << endl;
        return;
    }
    textcolor(14);  cout << "TOUR CAO NHAT TRONG HE THONG:" << endl;
    textcolor(11); cout << setw(10) << left << "Ma Tour" << setw(28) << left << "Ten Tour" << setw(17) << left << "Ngay Xuat Phat"
        << setw(12) << left << "So Ngay Di" << setw(18) << left << "Huong Dan Vien" << setw(30) << left << "May Bay" << setw(17) << left << "Khach San" << setw(12) << left
        << "Gia Tien" << setw(15) << left << "PT GD" << "\n";
    for (auto tourist : highestMoney) {
        tourist.showifTour();
    }textcolor(9);
}
vector<Tourists> timkiemTourThapNhat(vector<Tourists>& tourists) {
    SapXepTheoSoTienTangDan(tourists);
    int shortestGiaTien = tourists[0].getGiaTien();//gia tri lon nhat 
    // Lưu các tour có giá tiền cao nhất vào vector highestMoney
    vector<Tourists> highestMoney;
    for (auto& tour : tourists) {
        if (tour.getGiaTien() == shortestGiaTien) {
            highestMoney.push_back(tour);
        }
        else {
            break;
        }
    }
    return highestMoney;
}
void inHanhKhachThapNhat(const vector<Tourists>& shortestMoney) {
    if (shortestMoney.empty()) {
        cout << "\t\t\t\tKHONG CO TOUR NAO." << endl;
        return;
    }
    textcolor(14);  cout << "\t\t\t\tTOUR THAP NHAT TRONG HE THONG:" << endl;
    textcolor(11); cout << setw(10) << left << "Ma Tour" << setw(28) << left << "Ten Tour" << setw(17) << left << "Ngay Xuat Phat"
        << setw(12) << left << "So Ngay Di" << setw(18) << left << "Huong Dan Vien" << setw(30) << left << "May Bay" << setw(17) << left << "Khach San" << setw(12) << left
        << "Gia Tien" << setw(15) << left << "PT GD" << "\n";
    for (auto tourist : shortestMoney) {//for each
        tourist.showifTour();
    }textcolor(9);
}

bool SoSanhThongTinDeTimKiemTour(Tourists& tourist1, string& keyword) {
    string lowerKeyword = keyword;  string lowerMaTour = tourist1.getMatour(); string lowerTenTour = tourist1.getTenTour();
    string lowerNgayKhoiHanh = tourist1.getNgayXuatPhat();   string lowerHDV = tourist1.getHuongDanVien();  string lowerMayBay = tourist1.getMayBay();
    string lowerKhachSan = tourist1.getKhachSan();  string lowerPTGD = tourist1.getPhuongThucGiaoDich();
    transform(lowerMaTour.begin(), lowerMaTour.end(), lowerMaTour.begin(), tolower);
    transform(lowerTenTour.begin(), lowerTenTour.end(), lowerTenTour.begin(), tolower);
    transform(lowerNgayKhoiHanh.begin(), lowerNgayKhoiHanh.end(), lowerNgayKhoiHanh.begin(), tolower);
    transform(lowerHDV.begin(), lowerHDV.end(), lowerHDV.begin(), tolower);
    transform(lowerMayBay.begin(), lowerMayBay.end(), lowerMayBay.begin(), tolower);
    transform(lowerKhachSan.begin(), lowerKhachSan.end(), lowerKhachSan.begin(), tolower);
    transform(lowerPTGD.begin(), lowerPTGD.end(), lowerPTGD.begin(), tolower);
    transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), tolower);
    return lowerMaTour == lowerKeyword || lowerTenTour == lowerKeyword || lowerNgayKhoiHanh == lowerKeyword
        || lowerHDV == lowerKeyword || lowerMayBay == lowerKeyword || lowerKhachSan == lowerKeyword
        || lowerPTGD == lowerKeyword;
}
void timkiemTour(const vector<Tourists>& person, string& keyword) {
    bool found = false; int count = 0; // biến đếm = 0 để chỉ in ra 1 dòng Ma Tour Ten Tour thôi 
    for (auto people1 : person) {
        if (SoSanhThongTinDeTimKiemTour(people1, keyword) || keyword == to_string(people1.getSoNgayDi())
            || keyword == to_string(people1.getGiaTien())) {
            if (count == 0) {      
                textcolor(11);
                cout << setw(10) << left << "Ma Tour" << setw(28) << left << "Ten Tour" << setw(17) << left << "Ngay Xuat Phat"
                    << setw(12) << left << "So Ngay Di" << setw(18) << left << "Huong Dan Vien" << setw(30) << left << "May Bay" << setw(17) << left << "Khach San" << setw(12) << left
                    << "Gia Tien" << setw(15) << left << "PT GD" << "\n";
                count = 1;
                textcolor(9);
            }
            textcolor(14);
            people1.showifTour();
            textcolor(9);
            found = true;
        }
    }
    if (!found) {
        textcolor(11); cout << "\t\t\t\tKhong tim thay Tour Du Lich co thong tin: " << keyword << endl; textcolor(9);
    }
}
void deleteTour(vector<Tourists>& tour, const string& MaTourDelete) {
    bool tourFound = false;
    for (auto it = tour.begin(); it != tour.end(); ++it) {
        if (it->getMatour() == MaTourDelete) {
            tourFound = true;
            tour.erase(it);
            break;
        }
    }
    if (tourFound) {
        cout << "\t\t\t\tDa xoa Tour co ma tour : " << MaTourDelete << endl;
        GhiDuLieuVaoFileTour(tour, "ThongTinTour1.txt");
    }
    else {
        cout << "\t\t\t\tKhong tim thay tour co ma tour : " << MaTourDelete << endl;
    }
}
void deletePerson(vector<People>& person, const string& CMNDToDelete) {
    bool personFound = false;
    for (auto it = person.begin(); it != person.end(); ++it) {
        if (it->getCMND() == CMNDToDelete) {
            personFound = true;
            person.erase(it);
            break;
        }
    }
    if (personFound) {
        cout << "\t\t\t\tDa Xoa Khach Hang Co CMND : " << CMNDToDelete << endl;
        GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
    }
    else {
        cout << "\t\t\t\tKhong tim thay khach hang co CMND : " << CMNDToDelete << endl;
    }
}
bool KTDangNhap(const vector<People> person, const string cmnddn, const string mkdn)
{
    for (const People& p : person)
    {
        if (p.getCMND() == cmnddn && p.getMatKhau() == mkdn)
        {
            return true;
        }
    }
    return false;
}
class Bill : public Tourists
{
private:
    string noidung;
public:
    Bill(const string noidung)
    {
        this->noidung = noidung;
    }
    void xuat_bill()
    {
        cout << noidung;
    } 
    ~Bill() {};
};
void xuattourDuLich(vector<Tourists> tourist,vector<People> person, string matourdat,string Cmnd, const string& billKH,const string& Billql, vector<Bill>& billkhachhang)
{
    ofstream ofs(billKH);
    ofstream ofs2(Billql, ios::app);
    if (ofs.is_open() && ofs2.is_open())
    {
        stringstream tam;
        for (auto tour1 : tourist)
        {
            if (SoSanhThongTinDeTimKiemTour(tour1, matourdat))
            {
                textcolor(11); tam << "\t\t\t\t HOA DON TOUR DU LICH CUA QUY KHACH - CAM ON DA UNG HO.\n"; textcolor(9);
                time_t baygio = time(0);
                tm* ltm = localtime(&baygio);
                tam << "\n\t\t\t\t Da Nang, Ngay : " << ltm->tm_mday << " / " << 1 + ltm->tm_mon << " / " << 1900 + ltm->tm_year;
                if (0 <= ltm->tm_hour && ltm->tm_hour < 12) {
                    tam << "\n\t\t\t\t Thoi Gian     : " << ltm->tm_hour << ":";
                    tam << 1 + ltm->tm_min << ":";
                    tam << 1 + ltm->tm_sec << " AM " << endl;
                }
                else if (ltm->tm_hour >= 12 && ltm->tm_hour < 24) {
                    int gio = (ltm->tm_hour > 12) ? ltm->tm_hour - 12 : ltm->tm_hour; // toán tử ba ngôi 
                    tam << "\n\t\t\t\t Thoi Gian     : " << gio << ":";
                    tam << 1 + ltm->tm_min << ":";
                    tam << 1 + ltm->tm_sec << " PM " << endl;
                }
                for (auto people : person)
                {
                    if (people.getCMND() == Cmnd)
                    {
                        tam << "\n\t\t\t\t *****************************************\n";
                        tam << "\n\t\t\t\t *Khach hang        : "; textcolor(14); tam << people.getFullName(); textcolor(9);
                        tam << "\n\t\t\t\t *Que Quan          : "; textcolor(14); tam << people.getQue(); textcolor(9);
                        tam << "\n\t\t\t\t *So Dien Thoai     : "; textcolor(14); tam << people.getSDT(); textcolor(9);
                    }
                }
                tam << "\n\t\t\t\t *****************************************\n";
                tam << "\n\t\t\t\t *Ma Tour           : "; textcolor(14);   tam << tour1.getMatour(); textcolor(9);                                          
                tam << "\n\t\t\t\t *Ten Tour          : "; textcolor(14);   tam << tour1.getTenTour(); textcolor(9);
                tam << "\n\t\t\t\t *Ngay xuat phat    : "; textcolor(14);   tam << tour1.getNgayXuatPhat(); textcolor(9);
                tam << "\n\t\t\t\t *So Ngay Di        : "; textcolor(14);   tam << tour1.getSoNgayDi() << " ngay "; textcolor(9);
                tam << "\n\t\t\t\t *Huong Dan Vien    : "; textcolor(14);   tam << tour1.getHuongDanVien(); textcolor(9);
                tam << "\n\t\t\t\t *May Bay           : "; textcolor(14);   tam << tour1.getMayBay(); textcolor(9);
                tam << "\n\t\t\t\t *Khach San         : "; textcolor(14);   tam << tour1.getKhachSan(); textcolor(9);
                tam << "\n\t\t\t\t *Gia Tien          : "; textcolor(14);   tam << tour1.getGiaTien() << " vnd "; textcolor(9);
                tam << "\n\t\t\t\t *Giao Dich         : "; textcolor(14);   tam << tour1.getPhuongThucGiaoDich(); textcolor(9);
                textcolor(11); tam << "\n\t\t\t\t Tour Du Lich Dung Nhat CAM ON QUY KHACH.\n\n"; textcolor(9);
                Bill bill(tam.str());                                                   
                billkhachhang.push_back(bill);
                bill.xuat_bill();                             
                ofs << tam.str();
                ofs2 << tam.str(); // str() chuyen doi stringstream thanh chuoi
                break;
            }
        }
        ofs2.close();
        ofs.close();
    }  
}
void ThoatManHinh()
{
    system("cls"); gotoxy(25, 7);    cout << "\n\n" << endl << endl; cout << "\n";
    cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * **\n";
    cout << "\t\t\t\t *";  textcolor(12);
    cout << "                    Tour Du Lich  ";
    textcolor(9);   cout << "                *\n";
    cout << "\t\t\t\t *--------------------------------------------------*\n";
    cout << "\t\t\t\t *                                                  *" << endl;
    cout << "\t\t\t\t *                                                  *" << endl;
    cout << "\t\t\t\t *              HEN GAP LAI QUY KHACH               *" << endl;
    cout << "\t\t\t\t *                                                  *" << endl;
    cout << "\t\t\t\t *                                                  *" << endl;
    cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
}
int main()
{
    ShowCur(0);
    vector<People> person;
    string fileName = "Nguoi1.txt";
    string fileTour = "ThongTinTour1.txt";
    string billKH = "billKhachHang.txt";
    string billQL = "billQuanLi.txt";
    vector<Tourists> tourist;
    vector<Bill> billKhachHang;
    vector<Bill> billQuanli;
    DocDuLieuTuFileNguoi(fileName, person);
    DocDuLieuTuFileTour(fileTour, tourist);
    int choice = 0;
Back:
    system("cls");
    textcolor(11);
    cout << "\n\t\t\t\t *--------------------------------------------------*\n";
    cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * **\n";
    cout << "\t\t\t\t *                                                  *" << endl;
    cout << "\t\t\t\t *          [1] Quan Li    ||  [2] Khach hang       *" << endl;
    cout << "\t\t\t\t *                                                  *" << endl;
    cout << "\t\t\t\t *                [0] THOAT UNG DUNG                *" << endl;
    cout << "\t\t\t\t *                                                  *" << endl;
    cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
    cout << " \n\n\t\t\t\t\t   * * * * * * * * * * * * * * * * *  ";  textcolor(12); 
    cout << " \n\n\t\t\t\t\t   [VUI LONG CHON] : ";
    int choiice = 0;
    cin >> choiice;   textcolor(9);
    switch (choiice)
    {
    case 0: {
        ThoatManHinh();
        (void)_getch();
        return 0;
    }
          break;
    case 1:
    {
        system("cls");
        int choiiQuanLy = 0;
        showTourist(tourist);
        showPeople(person);
        do
        {                    
            textcolor(14); cout << "\t\t\t\tCHAO MUNG BAN: ";
            cout << "DICH VU QUAN LI TOUR DU LICH TRONG NUOC." << endl;  textcolor(9);
            cout << "\t\t\t\t===========================================================\n";
            cout << "\t\t\t\t==                                                       ==\n";
            cout << "\t\t\t\t==      0.  Thoat chuong trinh                           ==\n";
            cout << "\t\t\t\t==      1.  Them 1 hanh khach                            ==\n";
            cout << "\t\t\t\t==      2.  Xoa  1 hanh khach                            ==\n";
            cout << "\t\t\t\t==      3.  Hien thi hanh khach                          ==\n";
            cout << "\t\t\t\t==      4.  Hien thi Tour dang co                        ==\n";
            cout << "\t\t\t\t==      5.  Tim Kiem Hanh Khach Theo Thong Tin           ==\n";
            cout << "\t\t\t\t==      6.  Tim Kiem Tour Theo Thong Tin                 ==\n";
            cout << "\t\t\t\t==      7.  Sap Xep Hanh Khach Theo Nam Sinh             ==\n";
            cout << "\t\t\t\t==      8.  Sap xep Tour theo so tien                    ==\n";
            cout << "\t\t\t\t==      9.  Sap xep theo so ngay di                      ==\n";
            cout << "\t\t\t\t==      10. Cap Nhat Lai Thong Tin Khach Hang            ==\n";
            cout << "\t\t\t\t==      11. Cap nhat lai thong tin tour                  ==\n";
            cout << "\t\t\t\t==      12. Tour cao nhat trong web                      ==\n";
            cout << "\t\t\t\t==      13. Tour thap nhat trong web                     ==\n";               
            cout << "\t\t\t\t==      14. Them 1 Tour                                  ==\n";
            cout << "\t\t\t\t==      15. Xoa 1 Tour                                   ==\n";
            cout << "\t\t\t\t==      16. Hien Tour Da Ban Duoc                        ==\n";
            cout << "\t\t\t\t==      17. Quay Lai                                     ==\n";
            cout << "\t\t\t\t===========================================================\n";
            cout << "\n\t\t\t\tVui long chon case : ";
            cin >> choiiQuanLy;
            switch (choiiQuanLy)
            {
            case 16 :
            {
                ifstream ifs("billQuanLi.txt");
                if (ifs.is_open())
                {
                    if (ifs.peek() != EOF)
                    {
                        string tam;
                        while (getline(ifs, tam))
                        {
                            textcolor(11); cout << tam << endl; textcolor(9);
                        }
                    }
                    else
                    {
                        textcolor(11);  cout << "\t\t\t\t Khong Ban Duoc Tour Nao\n"; textcolor(9);
                    }
                }
            }
            break;
            case 14 :
            {
                cin.ignore();
                Tourists newTourists("", "", " ", 0.0f, "", "", "", 0.0f, "");             
                textcolor(14);    cout << "\t\t\t\tNhap Thong Tin Tour\n";    textcolor(9);
                cin >> newTourists;
                tourist.push_back(newTourists);
                GhiDuLieuVaoFileTour(tourist, fileTour);
                cout << "\t\t\t\tTour moi duoc them vao thanh cong.\n";
            }
            break;
            case 15:
            {
                string MaTourDelete;
                cin.ignore();
                cout << "\t\t\t\tNhap Ma Tour can xoa: ";
                getline(cin, MaTourDelete);
                deleteTour(tourist, MaTourDelete);
            }
            break;
            case 0:
            {
                ThoatManHinh();
                (void)_getch();
                return 0;
                break;
            }
            case 1:
            {
                People newPeople("", "", "", "", "", "", "");               
                cin.ignore();
                cout << "\t\t\t\tNhap Thong Tin Khach Hang\n";
                cin >> newPeople;                              
                person.push_back(newPeople);            
                GhiDuLieuVaoFileNguoi1(fileName, person);         
                cout << "\t\t\t\tHanh Khach moi duoc them vao thanh cong.\n";
                break;
            }
            case 2: {
                string PeopleCMNDToDelete;            
                cin.ignore();
                cout << "\t\t\t\tNhap CMND Hanh Khach can xoa: ";
                getline(cin, PeopleCMNDToDelete);              
                deletePerson(person, PeopleCMNDToDelete);
                break;
            }
            case 3: {
                showPeople(person);
                break;
            }
            case 4:
            {
                showTourist(tourist);
                break;
            }
            case 5: {
                string keyword;
                cout << "\t\t\t\tNhap vao thong tin can tim kiem: ";
                cin.ignore();
                getline(cin, keyword);
                TimKiemKhachHang(person, keyword);
            }
                  break;
            case 6:
            {
                string keyword1;
                cout << "\n\t\t\t\tNhap vao thong tin can tim kiem: ";
                cin.ignore();
                getline(cin, keyword1);
                timkiemTour(tourist, keyword1);
                break;
            }
            case 7: {            
                SapXepTheoNam(person);
                cout << "\n\t\t\t\tSap Xep Hanh Khach Theo Nam Sinh:\n";
                showPeople(person);

            }
                  break;
            case 8:
            {
                SapXepTheoSoTienGiamDan(tourist);
                cout << "\n\t\t\t\t\tSap Xep Tour Theo So Tien:\n";
                showTourist(tourist);
                break;
            }
            case 9:
            {             
                SapXepTheoSoNgayDi(tourist);
                cout << "\n\t\t\t\t\tSap Xep Hanh Khach Theo So Ngay Di:\n";
                showTourist(tourist);
                break;
            }
            case 10:
            {
                string PeoPleCMNDToUpdate;
                cout << "\n\t\t\t\tNhap CMND cua khach hang can cap nhat: ";
                cin.ignore();
                getline(cin, PeoPleCMNDToUpdate);
                auto it = person.begin();
                bool kt = false;
                for (it = person.begin(); it != person.end(); ++it)
                {
                    if (it->getCMND() == PeoPleCMNDToUpdate)
                    {
                        kt = true;
                        int updateChoice;
                        TimKiemKhachHang(person, PeoPleCMNDToUpdate);               
                        textcolor(11);   cout << "\t\t\t\t THONG TIN CAN CAP NHAT." << endl;
                        cout << "\t\t\t\t==============================\n";
                        cout << "\t\t\t\t==                          ==\n";
                        cout << "\t\t\t\t== 1. Chung Minh Cong Dan   ==\n";
                        cout << "\t\t\t\t== 2. Ho Ten                ==\n";
                        cout << "\t\t\t\t== 3. Que Quan              ==\n";
                        cout << "\t\t\t\t== 4. Nam Sinh              ==\n";
                        cout << "\t\t\t\t== 5. Email                 ==\n";
                        cout << "\t\t\t\t== 6. So Dien Thoai         ==\n";
                        cout << "\t\t\t\t== 7. Mat Khau              ==\n";     
                        cout << "\t\t\t\t==============================\n";  textcolor(9);                   
                        cout << "\n\t\t\t\tEnter your choice: ";
                        cin >> updateChoice;
                        switch (updateChoice)
                        {
                        case 1:
                        {
                            string newCMND;
                            cout << "\n\t\t\t\t Nhap CMND moi: ";
                            cin.ignore();
                            getline(cin, newCMND);
                            it->setCMND(newCMND);
                            GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                            cout << "\n\t\t\t\tDa cap nhat thong tin khach hang co CMND : ";  textcolor(11);
                            cout << PeoPleCMNDToUpdate << " -> " << newCMND << endl; textcolor(9);
                            break;
                        }
                        case 2: {
                            string newFullName;
                            cout << "\n\t\t\t\tNhap ten moi: ";
                            cin.ignore();
                            getline(cin, newFullName);
                            string TenCu = it->getFullName();
                            it->setFullName(newFullName);
                            GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                            cout << "\t\t\t\tDa cap nhat thong tin khach hang co CMND : "; textcolor(11);  cout << PeoPleCMNDToUpdate; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << TenCu << " -> " << newFullName << endl; textcolor(9);
                            break;
                        }
                        case 3: {
                            string QueQuanMoi;
                            cout << "\t\t\t\tNhap que quan moi: ";
                            cin.ignore();
                            getline(cin, QueQuanMoi);
                            string QueCu = it->getQue();
                            it->setQue(QueQuanMoi);
                            GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                            cout << "\t\t\t\tDa cap nhat thong tin khach hang co CMND : "; textcolor(11);  cout << PeoPleCMNDToUpdate; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << QueCu << " -> " << QueQuanMoi << endl; textcolor(9);
                            break;
                        }
                        case 4: {
                            string NamSinhMoi;
                            cout << "Nhap nam sinh moi: ";
                            cin.ignore();
                            getline(cin, NamSinhMoi);
                            string NamSinhCu = it->getBirthDate();
                            it->setBirthDate(NamSinhMoi);
                            GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                            cout << "\t\t\t\tDa cap nhat thong tin khach hang co CMND : "; textcolor(11);  cout << PeoPleCMNDToUpdate; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << NamSinhCu << " -> " << NamSinhMoi << endl; textcolor(9);
                            break;
                        }
                        case 5: {
                            string EmailNew;
                            cout << "\t\t\t\tNhap email moi: ";
                            cin.ignore();
                            getline(cin, EmailNew);
                            string EmailCu = it->getEmail();
                            it->setEmail(EmailNew);
                            GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                            cout << "\t\t\t\tDa cap nhat thong tin khach hang co CMND : "; textcolor(11);  cout << PeoPleCMNDToUpdate; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << EmailCu << " -> " << EmailNew << endl; textcolor(9);
                            break;
                        }
                        case 6: {
                            string PhoneNew;
                            cout << "\t\t\t\tNhap phone moi: ";
                            cin.ignore();
                            getline(cin, PhoneNew);
                            string phoneCu = it->getSDT();
                            it->setSDT(PhoneNew);
                            GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                            cout << "\t\t\t\tDa cap nhat thong tin khach hang co CMND : "; textcolor(11);  cout << PeoPleCMNDToUpdate; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << phoneCu << " -> " << PhoneNew << endl; textcolor(9);
                            break;
                        }
                        case 7: {
                            string passwordNew;
                            cout << "\t\t\t\tNhap pass word moi: ";
                            cin.ignore();
                            getline(cin, passwordNew);
                            string passwordCu = it->getMatKhau();
                            it->setMatKhau(passwordNew);
                            GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                            cout << "\t\t\t\tDa cap nhat thong tin khach hang co CMND : "; textcolor(11);  cout << PeoPleCMNDToUpdate; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << passwordCu << " -> " << passwordNew << endl; textcolor(9);
                            break;
                        }
                        default:
                            cout << "\t\t\t\tLua chon khong hop le.\n";
                            break;

                        }
                    }
                }
                if (/*it == person.end()*/kt == false )
                {
                    textcolor(11);  cout << "\t\t\t\tKhong tim thay khach hang co CMND : " << PeoPleCMNDToUpdate << endl; textcolor(9);
                }
                break;
            }
            case 11:
            {
                string MaTourCapNhat;
                cout << "\t\t\t\tNhap Ma Tour Can Cap Nhat : ";
                cin.ignore();
                getline(cin, MaTourCapNhat);
                auto it = tourist.begin();
                bool ktTour = false;
                for (it = tourist.begin(); it != tourist.end(); ++it)
                {
                    if (it->getMatour() == MaTourCapNhat)
                    {
                        ktTour = true;
                        int updateChoice;
                        timkiemTour(tourist, MaTourCapNhat);                
        textcolor(11);  cout << "\t\t\t\tChon Thong Tin Can Cap Nhat." << endl;
                        cout << "\t\t\t\t======================================\n";
                        cout << "\t\t\t\t==                                  ==\n";
                        cout << "\t\t\t\t==      1. Ma Tour                  ==\n";
                        cout << "\t\t\t\t==      2. Ten Tour                 ==\n";
                        cout << "\t\t\t\t==      3. Ngay Xuat Phat           ==\n";
                        cout << "\t\t\t\t==      4. So Ngay Di               ==\n";
                        cout << "\t\t\t\t==      5. Huong Dan Vien Du Lich   ==\n";
                        cout << "\t\t\t\t==      6. Hang May Bay             ==\n";
                        cout << "\t\t\t\t==      7. Khach San                ==\n";
                        cout << "\t\t\t\t==      8. Gia Tien Tour            ==\n";
                        cout << "\t\t\t\t==      9. Phuong Thuc Giao Dich    ==\n";
                        cout << "\t\t\t\t======================================\n";
                        cout << "\t\t\t\tEnter your choice: "; textcolor(9);                    
                        cin >> updateChoice;
                        switch (updateChoice)
                        {
                        case 1:
                        {
                            string newMaTour;
                            cout << "\t\t\t\tNhap Ma Tour moi: ";
                            cin.ignore();
                            getline(cin, newMaTour);
                            it->setMatour(newMaTour);
                            GhiDuLieuVaoFileTour(tourist, fileTour);
                            cout << "\t\t\t\tDa cap nhat thong tin Tour co Ma Tour "; 
                            textcolor(11);  cout << "\t\t\t\t Cap Nhat  : CMND " << MaTourCapNhat << " -> CMND " << newMaTour << endl; textcolor(9);
                            break;
                        }
                        case 2: {
                            string newTenTour;
                            cout << "\t\t\t\tNhap ten Tour moi: ";
                            cin.ignore();
                            getline(cin, newTenTour);
                            string TenTourCu = it->getTenTour();
                            it->setTenTour(newTenTour);
                            GhiDuLieuVaoFileTour(tourist, fileTour);
                            cout << "\t\t\t\tDa cap nhat thong tin Tour co Ma Tour : "; textcolor(11);  cout << MaTourCapNhat; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << TenTourCu << " -> " << newTenTour << endl; textcolor(9);
                            break;
                        }
                        case 3: {
                            string newNgayXuatPhat;
                            cout << "\t\t\t\tNhap ngay xuat phat moi: ";
                            cin.ignore();
                            getline(cin, newNgayXuatPhat);
                            string NgayXuatPhatCu = it->getNgayXuatPhat();
                            it->setNgayXuatPhat(newNgayXuatPhat);
                            GhiDuLieuVaoFileTour(tourist, fileTour);
                            cout << "\t\t\t\tDa cap nhat thong tin Tour co Ma Tour : "; textcolor(11);  cout << MaTourCapNhat; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << NgayXuatPhatCu << " -> " << newNgayXuatPhat << endl; textcolor(9);
                            break;
                        }
                        case 4: {
                            int newSoNgayDi;
                            cout << "\t\t\t\tNhap so ngay di moi: ";
                            cin >> newSoNgayDi;
                            int SoNgayDiCu = it->getSoNgayDi();
                            it->setSoNgayDi(newSoNgayDi);
                            GhiDuLieuVaoFileTour(tourist, fileTour);
                            cout << "\t\t\t\tDa cap nhat thong tin Tour co Ma Tour : "; textcolor(11);  cout << MaTourCapNhat; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << SoNgayDiCu << " -> " << newSoNgayDi << endl; textcolor(9);                            
                            break;
                        }
                        case 5: {
                            string newHuongDanVien;
                            cout << "\t\t\t\tNhap huong dan vien moi: ";
                            cin.ignore();
                            getline(cin, newHuongDanVien);
                            string HuongDanVienCu = it->getHuongDanVien();
                            it->setHuongDanVien(newHuongDanVien);
                            GhiDuLieuVaoFileTour(tourist, fileTour);
                            cout << "\t\t\t\tDa cap nhat thong tin Tour co Ma Tour : "; textcolor(11);  cout << MaTourCapNhat; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << HuongDanVienCu << " -> " << newHuongDanVien << endl; textcolor(9);
                            break;
                        }
                        case 6: {
                            string newHangMayBay;
                            cout << "\t\t\t\tNhap hang may bay moi: ";
                            cin.ignore();
                            getline(cin, newHangMayBay);
                            string MayBayCu = it->getMayBay();
                            it->setMayBay(newHangMayBay);
                            GhiDuLieuVaoFileTour(tourist, fileTour);
                            cout << "\t\t\t\tDa cap nhat thong tin Tour co Ma Tour : "; textcolor(11);  cout << MaTourCapNhat; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << MayBayCu << " -> " <<  newHangMayBay << endl; textcolor(9);
                            break;
                        }
                        case 7: {
                            string newKhachSan;
                            cout << "\t\t\t\tNhap khach san moi: ";
                            cin.ignore();
                            getline(cin, newKhachSan);
                            string KhachSanCu = it->getKhachSan();
                            it->setKhachSan(newKhachSan);
                            GhiDuLieuVaoFileTour(tourist, fileTour);
                            cout << "\t\t\t\tDa cap nhat thong tin Tour co Ma Tour : "; textcolor(11);  cout << MaTourCapNhat; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << KhachSanCu << " -> " << newKhachSan << endl; textcolor(9);
                            break;
                        }
                        case 8: {
                            int newGiaTour;
                            cout << "Nhap Gia Tour moi: ";
                            cin >> newGiaTour;
                            int GiaTienCu = it->getGiaTien();
                            it->setGiaTien(newGiaTour);
                            GhiDuLieuVaoFileTour(tourist, fileTour);
                            cout << "\t\t\t\tDa cap nhat thong tin Tour co Ma Tour : "; textcolor(11);  cout << MaTourCapNhat; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << GiaTienCu << " -> " << newGiaTour << endl; textcolor(9);
                            break;
                        }
                        case 9: {
                            string newPTGD;
                            cout << "\t\t\t\tNhap PTGD moi: ";
                            cin.ignore();
                            getline(cin, newPTGD);
                            string ptgdCu = it->getPhuongThucGiaoDich();
                            it->setPhuongThucGiaoDich(newPTGD);
                            GhiDuLieuVaoFileTour(tourist, fileTour);
                            cout << "\t\t\t\tDa cap nhat thong tin Tour co Ma Tour : "; textcolor(11);  cout << MaTourCapNhat; textcolor(9);
                            textcolor(11);  cout << "\n\t\t\t\t" << ptgdCu << " -> " << newPTGD << endl; textcolor(9);
                            break;
                        }
                        default:
                            cout << "\t\t\t\tLua chon khong hop le.\n";
                            break;
                        }
                    }
                }
                if (/*it == tourist.end()*/ktTour == false)
                {
                    textcolor(11);  cout << "\t\t\t\tKhong tim thay Ma Tour : " << MaTourCapNhat << endl; textcolor(9);
                }
                break;
            }
            case 12:
            {
                vector<Tourists> highestMoney = timkiemTourCaoNhat(tourist);
                inHanhKhachCaoNhat(highestMoney);
                break;
            }
            case 13:
            {
                vector<Tourists> shortMoney = timkiemTourThapNhat(tourist);
                inHanhKhachThapNhat(shortMoney);
                break;
            }     
            case 17:
            {
                goto Back;
                break;
            }
            default:
                cout << "\t\t\t\tLua Chon Khong Hop Le - Vui Long Thu Lai.\n";
                break;
            }
        } while (choiiQuanLy != 0);
    }
    break;
    case 2:
    {
    back1:
        system("cls");
        textcolor(11); cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * **\n";
        cout << "\t\t\t\t *";
        textcolor(12); cout << "   Tour Du Lich DungNhat - XIN CHAO QUY KHACH ";  textcolor(11);
        cout << "    *";
        cout << "\n\t\t\t\t *--------------------------------------------------*\n";
        cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * **\n";
        cout << "\t\t\t\t *                                                  *" << endl;
        cout << "\t\t\t\t *     [1] D A N G K I    ||  [2] D A N G N H A P   *" << endl;
        cout << "\t\t\t\t *                                                  *" << endl;
        cout << "\t\t\t\t *                [0] THOAT UNG DUNG                *" << endl;
        cout << "\t\t\t\t *                [3] Quay Lai                      *" << endl;
        cout << "\t\t\t\t *                                                  *" << endl;
        cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
        cout << " \n\n\t\t\t\t\t   * * * * * * * * * * * * * * * * *  ";
        int choice = 0;
        do
        {      
            textcolor(11);  cout << " \n\t\t\t\t\t       [VUI LONG CHON] : ";
            cin >> choice;       textcolor(9);    
            switch (choice)
            {
            case 1:
            {
                textcolor(11);   cout << "\t\t\t\t           Ban Chon Dang Ky Thong Tin Tai Khoan.\n"; textcolor(9);
                People newPeople1("", "", "", "", "", "", "");           
                cin.ignore();            
                cout << "\t\t\t\t Nhap Thong Tin Khach Hang\n";
                bool cmndTrung = false;
                do {
                    cin >> newPeople1;
                    cmndTrung = false;
                    for (auto it = person.begin(); it != person.end(); ++it)
                    {
                        if (it->getCMND() == newPeople1.getCMND())
                        {
                            textcolor(12);
                            cout << "\t\t\t\t CMND Da Ton Tai. Vui long nhap lai thong tin.\n"; textcolor(9);
                            cmndTrung = true;
                            break;
                        }
                    }
                } while (cmndTrung);
                person.push_back(newPeople1);         
                GhiDuLieuVaoFileNguoi1(fileName, person);             
                cout << "\t\t\t\tTao Thong Tin Thanh Cong.\n";
                break;
            }
            case 2:
            {
                string cmndDN = "";   string mkdn = "";             
                cin.ignore();
                textcolor(11);  cout << "\t\t\t\t             Ban Chon Dang Nhap Tai Khoan.\n"; textcolor(9);
                cout << "\t\t\t\t Vui Long Nhap Chung Minh Cong Dan : ";
                getline(cin, cmndDN);
                cout << "\t\t\t\t Vui Long Nhap Mat Khau : ";
                getline(cin, mkdn);
                if (KTDangNhap(person, cmndDN, mkdn))
                {
                    system("cls");
                    textcolor(14); cout << "\n\t\t\t\t         ========== Dang Nhap Thanh Cong ==========\n\n"; textcolor(9);
                    int choiDN = 0;                                     
                    do
                    {
                    back2:
                        cout << "\n\t\t\t\tCHAO MUNG BAN: ";
                        cout << "DICH VU CHAM SOC KHACH HANG DU LICH TRONG NUOC." << endl;
                        textcolor(9);
                        cout << "\t\t\t\t===========================================================\n";
                        cout << "\t\t\t\t==                                                       ==\n";
                        cout << "\t\t\t\t==      0.  Thoat                                        ==\n";
                        cout << "\t\t\t\t==      1.  Hien thi Tour dang co                        ==\n";
                        cout << "\t\t\t\t==      2.  Tim Kiem Tour Theo Thong Tin                 ==\n";
                        cout << "\t\t\t\t==      3.  Doi Mat Khau                                 ==\n";
                        cout << "\t\t\t\t==      4.  Tour co so tien cao nhat                     ==\n";
                        cout << "\t\t\t\t==      5.  Tour co so tien thap nhat                    ==\n";
                        cout << "\t\t\t\t==      6.  Sap xep Tour theo so tien                    ==\n";
                        cout << "\t\t\t\t==      7.  Cap Nhat Lai Thong Tin Ca Nhan               ==\n";
                        cout << "\t\t\t\t==      8.  Dat Tour                                     ==\n";
                        cout << "\t\t\t\t==      9.  Tour Da Dat                                  ==\n";
                        cout << "\t\t\t\t==      10. Quay Lai                                     ==\n";
                        cout << "\t\t\t\t===========================================================\n";
                        textcolor(12);
                        cout << " \n\t\t\t\t\t   [VUI LONG CHON] : ";
                        cin >> choiDN;
                        textcolor(9);
                        switch (choiDN)
                        {
                        case 10:
                        {
                            goto back1;
                            break;
                        }
                        case 1 :
                        {
                            showTourist(tourist);
                            break;
                        }
                        case 2 :
                        {
                            string keyword1;
                            cout << "\t\t\t\tNhap vao thong tin can tim kiem: ";
                            cin.ignore();
                            getline(cin, keyword1);
                            timkiemTour(tourist, keyword1);
                            break;
                        }
                        case 3 :
                        {
                        
                            for (auto it = person.begin(); it != person.end(); ++it)
                            {
                                if (it->getMatKhau() == mkdn)
                                {
                                    string passwordNew;
                                    cout << "\t\t\t\tNhap pass word moi: ";
                                    cin.ignore();
                                    getline(cin, passwordNew);
                                    mkdn = passwordNew;
                                    string mkcu = it->getMatKhau();
                                    it->setMatKhau(passwordNew);                                 
                                    GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                                    cout << "\t\t\t\tDa cap nhat password moi cho khach hang.\n";
                                    textcolor(11);  cout << "\t\t\t\t" << mkcu << " -> " << passwordNew << endl; textcolor(9);
                                }
                            }               
                        }
                        break;
                        case 4 :
                        {
                            vector<Tourists> highestMoney = timkiemTourCaoNhat(tourist);
                            inHanhKhachCaoNhat(highestMoney);
                            break;
                        }            
                        case 5 :
                        {
                            vector<Tourists> shortestMoney = timkiemTourThapNhat(tourist);
                            inHanhKhachThapNhat(shortestMoney);
                            break;
                        }
                        case 6 :
                        {
                            SapXepTheoSoTienGiamDan(tourist);
                            cout << "\n\t\t\t\tSap Xep Hanh Khach Theo So Tien:\n";
                            showTourist(tourist);
                            break;
                        }
                        case 7 :
                        {
                            for (auto it = person.begin(); it != person.end(); ++it)
                            {
                                if (it->getCMND() == cmndDN)
                                {
                                    int updateChoice; textcolor(11);                                  
                                    cout << "\t\t\t\t THONG TIN CAN CAP NHAT." << endl;
                                    cout << "\t\t\t\t==============================\n";
                                    cout << "\t\t\t\t==                          ==\n";
                                    cout << "\t\t\t\t== 1. Chung Minh Cong Dan   ==\n";
                                    cout << "\t\t\t\t== 2. Ho Ten                ==\n";
                                    cout << "\t\t\t\t== 3. Que Quan              ==\n";
                                    cout << "\t\t\t\t== 4. Nam Sinh              ==\n";
                                    cout << "\t\t\t\t== 5. Email                 ==\n";
                                    cout << "\t\t\t\t== 6. So Dien Thoai         ==\n";
                                    cout << "\t\t\t\t== 7. Mat Khau              ==\n";
                                    cout << "\t\t\t\t==============================\n"; textcolor(9);
                                    cout << "\t\t\t\tEnter your choice: ";
                                    cin >> updateChoice;
                                    switch (updateChoice)
                                    {
                                    case 1:
                                    {
                                        string newCMND;
                                        cout << "\t\t\t\tNhap CMND moi: ";
                                        cin.ignore();
                                        getline(cin, newCMND);
                                        string cmndcu = it->getCMND();
                                        it->setCMND(newCMND);
                                        cmndDN = newCMND;
                                        GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                                        textcolor(11);  cout << "\t\t\t\tCap Nhat : CMND " << cmndcu << " -> CMND " << newCMND << endl; textcolor(9);
                                        break;
                                    }
                                    case 2: {
                                        string newFullName;
                                        cout << "\t\t\t\tNhap ten moi: ";
                                        cin.ignore();
                                        getline(cin, newFullName);
                                        string TenCu = it->getFullName();
                                        it->setFullName(newFullName);
                                        GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                                        textcolor(11);  cout << "\t\t\t\tCap Nhat : Khach Hang " << TenCu << " -> Khach Hang " << newFullName << endl; textcolor(9);
                                        break;
                                    }
                                    case 3: {
                                        string QueQuanMoi;
                                        cout << "\t\t\t\tNhap que quan moi: ";
                                        cin.ignore();
                                        getline(cin, QueQuanMoi);
                                        string QueCu = it->getQue();
                                        it->setQue(QueQuanMoi);
                                        GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                                        textcolor(11);  cout << "\t\t\t\tCap Nhat : Que " << QueCu << " -> Que " << QueQuanMoi << endl; textcolor(9);
                                        break;
                                    }
                                    case 4: {
                                        string NamSinhMoi;
                                        cout << "\t\t\t\tNhap nam sinh moi: ";
                                        cin.ignore();
                                        getline(cin, NamSinhMoi);
                                        string namsinhcu = it->getBirthDate();
                                        it->setBirthDate(NamSinhMoi);
                                        GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                                        textcolor(11);  cout << "\t\t\t\tCap Nhat : Nam Sinh " << namsinhcu << " -> Nam Sinh " << NamSinhMoi << endl; textcolor(9);
                                        break;
                                    }
                                    case 5: {
                                        string EmailNew;
                                        cout << "\t\t\t\tNhap email moi: ";
                                        cin.ignore();
                                        getline(cin, EmailNew);
                                        string emailcu = it->getEmail();
                                        it->setEmail(EmailNew);
                                        GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                                        textcolor(11);  cout << "\t\t\t\tCap Nhat : Email " << emailcu << " -> Email " << EmailNew << endl; textcolor(9);
                                        break;
                                    }
                                    case 6: {
                                        string PhoneNew;
                                        cout << "\t\t\t\tNhap phone moi: ";
                                        cin.ignore();
                                        getline(cin, PhoneNew);
                                        string sdtcu = it->getSDT();
                                        it->setSDT(PhoneNew);
                                        GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                                        textcolor(11);  cout << "\t\t\t\tCap Nhat : Phone " << sdtcu << " -> Phone " << PhoneNew << endl; textcolor(9);
                                        break;
                                    }
                                    case 7: {
                                        string passwordNew;
                                        cout << "\t\t\t\tNhap pass word moi: ";
                                        cin.ignore();
                                        string pworkcu = it->getMatKhau();
                                        getline(cin, passwordNew);
                                        it->setMatKhau(passwordNew);
                                        GhiDuLieuVaoFileNguoi1("Nguoi1.txt", person);
                                        textcolor(11);  cout << "\t\t\t\tCap Nhat : Mat Khau " << pworkcu << " -> Mat Khau " << passwordNew << endl; textcolor(9);
                                        break;
                                    }
                                    default:
                                        cout << "\t\t\t\tLua chon khong hop le.\n";
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                        case 8:
                        {   quaylaineukhong:
                            cin.ignore();                
                            string matourdat="";
                            showTourist(tourist);                                            
                            bool kt = false;
                            do
                            {                       
                                cout << "\t\t\t\tBan chon tour nao ? : ";                         
                                getline(cin, matourdat);
                                for (auto tour : tourist)
                                {
                                    if (tour.getMatour() == matourdat)
                                    {                                                     
                                        kt = true;
                                        timkiemTour(tourist, matourdat);
                                        break;
                                    }
                                }
                            } while ( kt != true);
                            k:
                            cout << "\t\t\t\tBan co chac chan chon tour nay khong?(1 co - 2 khong) : ";
                            int chacchantour = 0;
                            cin >> chacchantour;
                            switch (chacchantour)
                            {
                            case 1:
                            {                                                                                 
                                int choiycgk = 0;
                                do
                                {
                                xy:                                    
                     textcolor(11); cout << "\n\t\t\t\tBan Co Yeu Cau Gi Khong?" << endl; textcolor(9);
                                    cout << "\t\t\t\t===========================================================\n";
                                    cout << "\t\t\t\t==                                                       ==\n";
                                    cout << "\t\t\t\t==      0.  Quay Lai                                     ==\n";
                                    cout << "\t\t\t\t==      1.  Cap Nhat Lai Thong Tin Tour Theo Muc Dich    ==\n";
                                    cout << "\t\t\t\t==      2.  Xuat Tour                                    ==\n";
                                    cout << "\t\t\t\t==      3.  Thoat                                        ==\n";
                                    cout << "\t\t\t\t===========================================================\n";                                   
                                    textcolor(14);  cout << "\n\t\t\t\t\t   [VUI LONG CHON] : ";
                                    cin >> choiycgk; textcolor(9);
                                    switch (choiycgk)
                                    {
                                    case 0 :
                                    {
                                        system("cls");
                                        goto back2;
                                        break;
                                    }
                                    case 1 :
                                    {
                                        // cap nhat tour
                                        for (auto it = tourist.begin(); it != tourist.end(); ++it)
                                        {
                                            if (it->getMatour() == matourdat)
                                            {
                                                int updateChoice;
                                                timkiemTour(tourist,matourdat);                                           
                                 textcolor(11); cout << "\t\t\t\tChon Thong Tin Can Cap Nhat." << endl;
                                                cout << "\t\t\t\t======================================\n";                                                                                                                        
                                                cout << "\t\t\t\t==      1. Ngay Xuat Phat           ==\n";
                                                cout << "\t\t\t\t==      2. So Ngay Di               ==\n";
                                                cout << "\t\t\t\t==      3. Phuong Thuc Giao Dich    ==\n";
                                                cout << "\t\t\t\t======================================\n";
                                                cout << "\t\t\t\tEnter your choice: "; textcolor(9);
                                                cin >> updateChoice;
                                                switch (updateChoice)
                                                {                                                                                          
                                                case 1: {
                                                    string newNgayXuatPhatt;
                                                    cout << "\t\t\t\tNhap ngay xuat phat moi: ";
                                                    cin.ignore();
                                                    getline(cin, newNgayXuatPhatt);
                                                    string NgayXpCu = it->getNgayXuatPhat();
                                                    it->setNgayXuatPhat(newNgayXuatPhatt); 
                                                    textcolor(11);  cout << "\n\t\t\t\tCap Nhat : " << NgayXpCu << " -> " << newNgayXuatPhatt << endl; textcolor(9);
                                                    break;
                                                }
                                                case 2: {
                                                    int newSoNgayDii;
                                                    cout << "\t\t\t\tNhap so ngay di moi: ";
                                                    cin >> newSoNgayDii;
                                                    int SoNgayDicu = it->getSoNgayDi();
                                                    it->setSoNgayDi(newSoNgayDii);                                                           
                                                    textcolor(11);  cout << "\n\t\t\t\tCap Nhat : " << SoNgayDicu << " Ngay -> " << newSoNgayDii << " Ngay " << endl; textcolor(9);
                                                    break;
                                                }                                                                                                                                       
                                                case 3: {
                                                    string newPTGD;
                                                    cout << "\t\t\t\tNhap PTGD moi: ";
                                                    cin.ignore();
                                                    string Ptgdcu = it->getPhuongThucGiaoDich();
                                                    getline(cin, newPTGD);
                                                    it->setPhuongThucGiaoDich(newPTGD);    
                                                    textcolor(11);  cout << "\n\t\t\t\tCap Nhat : Ngan Hang " << Ptgdcu << " -> Ngan Hang " << newPTGD << endl; textcolor(9);
                                                    break;
                                                }
                                                default:
                                                    cout << "\t\t\t\tLua chon khong hop le.\n";
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    break;
                                    case 2:
                                    {               
                                        system("cls");                                    
                                        xuattourDuLich(tourist,person, matourdat,cmndDN,billKH,billQL,billKhachHang);                                      
                                        Thoatweb:                                  
                                        textcolor(11);  cout << "\n\t\t\t\t\t [Thoat Web ] [1] ";  
                                        cout << "\n\t\t\t\t\t [Quay  Lai ] [2] ";    textcolor(9);
                                        int thoatweb = 0;
                                        cout << "\n\t\t\t\t\t Vui Long An : "; 
                                        cin >> thoatweb;
                                        if (thoatweb == 1)
                                        {
                                            ThoatManHinh();
                                            textcolor(11); cout << "\n\t\t\t\t       ------------------------------------          " << endl;
                                                           cout << "\t\t\t\t       Cam On Thay Co Va Cac Ban Da Lang Nghe      " << endl;
                                                           cout << "\t\t\t\t         PB1 : Dung 22DT2 with Nhat 22DT1          " << endl; textcolor(9);
                                            (void)_getch();
                                            return 0;
                                        }
                                        else if (thoatweb == 2)
                                        {
                                            goto back2;
                                        }                                       
                                        else
                                        {
                                            goto Thoatweb;
                                        }
                                        break;
                                    }
                                    case 3:
                                    {
                                        ThoatManHinh();
                                        (void)_getch();
                                        return 0;
                                    }
                                    break;
                                    default:
                                        goto xy;
                                        break;
                                    }
                                } while (choiycgk != 3);
                            }
                            break;
                            case 2:
                                goto quaylaineukhong;
                                break;
                            default:
                                goto k;
                                break;
                            }
                        }
                        break;
                        case 9 :
                        {
                            ifstream ifs("billKhachHang.txt");
                            if (ifs.is_open())
                            {
                                if (ifs.peek() != EOF)
                                {
                                    string tam;
                                    while (getline(ifs, tam))
                                    {
                                        cout << tam << endl;
                                    }
                                    int choicee = 0;
                                    do
                                    {
                                        textcolor(14); cout << "\t\t\t\t Ban muon lam gi ?." << endl;
                                        cout << "\t\t\t\t **************************\n";
                                        cout << "\t\t\t\t **      [1] Huy Tour     *\n";
                                        cout << "\t\t\t\t **      [2] OK           *\n";
                                        cout << "\t\t\t\t **************************\n"; textcolor(9);
                                        cout << "\t\t\t\t Enter your choice: ";
                                        cin >> choicee;
                                        switch (choicee)
                                        {
                                        case 1:
                                        {
                                            ofstream ofs("billKhachHang.txt", ios::out);
                                            textcolor(11); cout << "\n\t\t\t\t Da huy tour thanh cong\n"; textcolor(9);
                                        }
                                        break;
                                        default:
                                            break;
                                        }
                                    } while (choicee != 2);
                                }      
                                else
                                {
                                    cout << "\t\t\t\tFile Rong Vui Long Thu Lai";
                                }
                                ifs.close();
                            }
                            else
                            {
                                cout << "\n\t\t\t\t Khong the mo file" << endl;
                            }
                        }
                        break;
                        case 0:                      
                            {
                            ThoatManHinh();  (void)_getch(); return 0;                                                   
                            }
                            break;                      
                        default:
                            goto back2;  break;                       
                        }
                    } while (choiDN != 0);
                }
                else
                {
                    textcolor(12);  cout << "\n\t\t\t\t    ======== CMND hoac Mat Khau khong dung ========"; textcolor(9);
                }
            }
            break;
            case 3:
            {
                goto Back; break;            
            }    
            case 0:
            {
                ThoatManHinh();  (void)_getch(); return 0;           
                
            }
            break;
            default:
                goto back1; break;          
            }
        } while (choice != 0);
    }
    break;
    default:
        goto Back;
        break;
    }
    return 0;
}