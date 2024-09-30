#include <bits/stdc++.h>
using namespace std;

// Kieu du lieu de bieu dien thong tin cua mot so tiet kiem
struct SoTietKiem {
    string maSo; // Ma so
    string loaiTietKiem; // Loai tiet kiem
    string hoTenKhachHang; // Ho ten khach hang
    string cmnd; // Chung minh nhan dan
    struct tm ngayMoSo; // Ngay mo so
    double soTienGui; // So tien gui

    // Tinh lai cho so tiet kiem
    // Dau vao: laiSuat (double) - Lai suat tinh theo %
    // Dau ra: Tien lai (double) - Tinh tien lai tu so tien gui va lai suat
     double tinhLai(double laiSuat, int soThang) {
        return soTienGui * laiSuat  * (soThang / 12.0);
    }

    // Tinh so thang gui tu ngay mo so den ngay hien tai
    // Dau ra: so thang gui tien tinh den hien tai
    int tinhSoThangGui() {
        time_t now = time(0);
        struct tm* currentTime = localtime(&now); // Lay thoi gian hien tai
        int soThang = (currentTime->tm_year - ngayMoSo.tm_year) * 12 + (currentTime->tm_mon - ngayMoSo.tm_mon);
        return soThang; // Tinh so thang gui
    }

    // Tinh so du sau khi tinh lai
    // Dau ra: so du sau khi cong lai
    double tinhSoDuSauKhiCoLai(double laiSuat) {
        int soThang = tinhSoThangGui(); 
        double tienLai = tinhLai(laiSuat, soThang); // Tinh tien lai
        return soTienGui + tienLai; // Cong tien lai vao so tien gui
    }

};

// Ham kiem tra ma so
// Dau vao: maSo (string) - Ma so can kiem tra
// Dau ra: true neu ma so hop le, false neu khong
bool kiemTraMaSo(const string& maSo) {
    return maSo.length() <= 5 && regex_match(maSo, regex("^[A-Za-z0-9]+$"));
}

// Ham kiem tra chung minh nhan dan
// Dau vao: cmnd (string) - CMND can kiem tra
// Dau ra: true neu CMND hop le, false neu khong
bool kiemTraCMND(const string& cmnd) {
    return (cmnd.length() == 9 || cmnd.length() == 12) && regex_match(cmnd, regex("^[0-9]+$"));
}

// Ham kiem tra ngay hop le
// Dau vao: day (int) - Ngay, month (int) - Thang, year (int) - Nam
// Dau ra: true neu ngay hop le, false neu khong
bool kiemTraNgay(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1 || year < 0) return false;
    const int daysInMonth[] = {31, (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return day <= daysInMonth[month - 1];
}

// Ham kiem tra ho ten khach hang
// Dau vao: hoTen (string) - Ho ten khach hang can kiem tra
// Dau ra: true neu ho ten hop le, false neu khong
bool kiemTraHoTen(const string& hoTen) {
    return hoTen.length() <= 30 && regex_match(hoTen, regex("^[A-Za-z ]+$"));
}

// Ham kiem tra so tien gui
// Dau vao: soTien (double) - So tien gui can kiem tra
// Dau ra: true neu so tien gui hop le (so duong), false neu khong
bool kiemTraSoTienGui(double soTien) {
    return soTien > 0;
}

// Ham nhap du lieu cho so tiet kiem
// Dau vao: stk (SoTietKiem&) - Tham chieu den so tiet kiem can nhap
// Khong co dau ra, hoan thanh viec nhap du lieu cho stk
void nhapSoTietKiem(SoTietKiem& stk) {
    cout << "Nhap ma so: ";
    while (true) {
        getline(cin, stk.maSo);
        if (kiemTraMaSo(stk.maSo)) break; // Kiem tra ma so hop le
        else cout << "Ma so khong hop le. Vui long nhap lai: ";
    }

    cout << "Nhap loai tiet kiem: ";
    getline(cin, stk.loaiTietKiem); // Nhap loai tiet kiem

    cout << "Nhap ho ten khach hang: ";
    while (true) {
        getline(cin, stk.hoTenKhachHang);
        if (kiemTraHoTen(stk.hoTenKhachHang)) break; // Kiem tra ho ten hop le
        else cout << "Ho ten khach hang khong hop le. Vui long nhap lai: ";
    }

    cout << "Nhap CMND: ";
    while (true) {
        getline(cin, stk.cmnd);
        if (kiemTraCMND(stk.cmnd)) break; // Kiem tra CMND hop le
        else cout << "CMND khong hop le. Vui long nhap lai: ";
    }

    cout << "Nhap ngay mo so (dd mm yyyy): ";
    while (true) {
        int day, month, year;
        cin >> day >> month >> year;
        if (kiemTraNgay(day, month, year)) {
            stk.ngayMoSo.tm_mday = day;
            stk.ngayMoSo.tm_mon = month - 1; // tm_mon bat dau tu 0
            stk.ngayMoSo.tm_year = year - 1900; // tm_year tinh tu 1900
            break;
        } else {    
            cout << "Ngay mo so khong hop le. Vui long nhap lai: ";
        }
    }
    cin.ignore(); 

    cout << "Nhap so tien gui: ";
    while (true) {
        cin >> stk.soTienGui;
        if (kiemTraSoTienGui(stk.soTienGui)) break; // Kiem tra so tien gui phai la so duong
        else cout << "So tien gui phai la so duong. Vui long nhap lai: ";
    }
    cin.ignore(); 
}

// Ham xuat du lieu so tiet kiem
// Dau vao: stk (const SoTietKiem&) - Tham chieu den so tiet kiem can xuat
// Khong co dau ra, xuat thong tin so tiet kiem ra man hinh
void xuatSoTietKiem(const SoTietKiem& stk) {
    cout << "Ma so: " << stk.maSo << endl;
    cout << "Loai tiet kiem: " << stk.loaiTietKiem << endl;
    cout << "Ho ten khach hang: " << stk.hoTenKhachHang << endl;
    cout << "CMND: " << stk.cmnd << endl;
    cout << "Ngay mo so: " << stk.ngayMoSo.tm_mday << "/" << (stk.ngayMoSo.tm_mon + 1) << "/" << (stk.ngayMoSo.tm_year + 1900) << endl;
    cout << "So tien gui: " << fixed << setprecision(2) << stk.soTienGui << " VND" << endl;
}

// Ham cap nhat lai suat cho so tiet kiem
// Dau vao: stk (SoTietKiem&) - Tham chieu den so tiet kiem, laiSuat (double) - Lai suat
// Dau ra: Tien lai (double) - Tinh tien lai tu so tien gui va lai suat
double capNhatLaiSuat(SoTietKiem& stk, double laiSuat) {
        return stk.tinhLai(laiSuat, stk.tinhSoThangGui()); 
}

// Ham rut tien tu so tiet kiem
// Dau vao: stk (SoTietKiem&) - Tham chieu den so tiet kiem, soTienRut (double) - So tien muon rut
// Khong co dau ra, rut tien tu stk va in ra thong tin so du con lai
void rutTien(SoTietKiem& stk, double soTienRut, double laiSuat) {
    // Tinh so du sau khi co lãi
    double soDuHienTai = stk.tinhSoDuSauKhiCoLai(laiSuat); // Tinh so du hien tai
    // Kiem tra so thang gui
    int soThang = stk.tinhSoThangGui();
    double laiSuatThapHon = 0.05; // Lai suat thap hon neu rut truoc han
    if (soThang < 6 && stk.loaiTietKiem == "dai han") {
        cout << "Rut truoc han. Lai suat se bi giam xuong " << laiSuatThapHon*100 << "%." << endl;
        soDuHienTai = stk.tinhSoDuSauKhiCoLai(laiSuatThapHon);
    }
    
    // Kiem tra so tien rut
    if (soTienRut > soDuHienTai) {
        cout << "Khong du tien de rut. So du hien tai: " << fixed << setprecision(2) << soDuHienTai << " VND" << endl;
        return;
    }
    
    // Cap nhat so du
    soDuHienTai -= soTienRut; // Rut tien
    stk.soTienGui = soDuHienTai; // Cap nhat so du
    cout << "Rut thanh cong " << soTienRut << " VND. So du hien tai: " << fixed << setprecision(2) << soDuHienTai << " VND" << endl;
}

// Ham tim kiem so tiet kiem
// Dau vao: tu khoa can tim
// Dau ra: Thong tin so tiet kiem can tim
void timKiemSoTietKiem(const vector<SoTietKiem>& danhSach, const string& tuKhoa) {
    cout << "Ket qua tim kiem:" << endl;
    for (const auto& stk : danhSach) {
        if (stk.cmnd == tuKhoa || stk.maSo == tuKhoa) {
            xuatSoTietKiem(stk); // Xuat thong tin so tiet kiem
        }
    }
}

// Ham so sanh ngay, thang, nam
bool isDateInRange(const tm& date, const tm& startDate, const tm& endDate) {
    // So sanh nam truoc
    if (date.tm_year < startDate.tm_year || date.tm_year > endDate.tm_year) {
        return false;
    }

    // Neu nam nam trong khoang, kiem tra thang
    if (date.tm_year == startDate.tm_year && date.tm_mon < startDate.tm_mon) {
        return false;
    }
    if (date.tm_year == endDate.tm_year && date.tm_mon > endDate.tm_mon) {
        return false;
    }

    // Neu nam va thang hop le, kiem tra ngay
    if (date.tm_year == startDate.tm_year && date.tm_mon == startDate.tm_mon && date.tm_mday < startDate.tm_mday) {
        return false;
    }
    if (date.tm_year == endDate.tm_year && date.tm_mon == endDate.tm_mon && date.tm_mday > endDate.tm_mday) {
        return false;
    }

    return true; 
}


// Ham liet ke cac so tiet kiem mo trong 1 khoang thoi gian
// Dau vao: Khoang thoi gian
// Dau ra: Thong tin cac so tiet kiem phu hop
void lietKeSoTietKiemTrongKhoangThoiGian(const vector<SoTietKiem>& danhSach, const tm& startDate, const tm& endDate) {
    cout << "Danh sach so tiet kiem mo trong khoang thoi gian:" << endl;
    
     for (const auto& stk : danhSach) {
        if (isDateInRange(stk.ngayMoSo, startDate, endDate)) {
            xuatSoTietKiem(stk); 
        }
    }
}

// Ham so sanh so tiet kiem theo so tien gui
bool soSanhTheoSoTienGui(const SoTietKiem& a, const SoTietKiem& b) {
    return a.soTienGui > b.soTienGui; // So sanh theo so tien gui giam dan
}

// Ham so sanh so tiet kiem theo ngay mo so
bool soSanhTheoNgayMoSo(const SoTietKiem& a, const SoTietKiem& b) {
    return mktime((tm*)&a.ngayMoSo) < mktime((tm*)&b.ngayMoSo); // So sanh theo ngay mo so tang dan
}

// Ham sap xep danh sach so tiet kiem
// Dau vao: Danh sach so tiet kiem
// Dau ra: Danh sach so tiet kiem da sap xep
void sapXepDanhSachSoTietKiem(vector<SoTietKiem>& danhSach, bool sapXepTheoSoTienGui) {
    if (sapXepTheoSoTienGui) {
        sort(danhSach.begin(), danhSach.end(), soSanhTheoSoTienGui); // Sap xep giam dan theo so tien gui
        for (auto &ps:danhSach) 
        xuatSoTietKiem(ps);
    } else {
        sort(danhSach.begin(), danhSach.end(), soSanhTheoNgayMoSo); // Sap xep tang dan theo ngay mo so
        for (auto &ps:danhSach)
        xuatSoTietKiem(ps);
    }
}

int main() {
    vector<SoTietKiem> danhSachSoTietKiem; // Danh sach so tiet kiem
    int n;
    cout << "Nhap so luong so tiet kiem: ";
    cin>>n;
    cin.ignore();
    for (int i=0;i<n;i++) {
        cout << "Nhap thong tin so tiet kiem thu "<<i+1<<":\n";
        
        SoTietKiem stk;
        nhapSoTietKiem(stk); // Nhap so tiet kiem
        danhSachSoTietKiem.push_back(stk); // Them vao danh sach
    }
               
    // Xuat danh sach so tiet kiem   
    cout << "--------------------------------------\n"; 
    cout << "Xuat danh sach: \n";       
    for (const auto& stk : danhSachSoTietKiem) {
        xuatSoTietKiem(stk); 
    }

    // Cap nhat lai suat
    double laiSuat;
    cout << "--------------------------------------\n";
    cout << "Nhap lai suat: ";
    cin >> laiSuat;
    for (auto& stk : danhSachSoTietKiem) {
        double tienLai = capNhatLaiSuat(stk, laiSuat); 
            cout << "Tien lai cho so " << stk.maSo << ": " << tienLai << " VND" << endl;
        }
    
    // Rut tien
    string maSo;
    double soTienRut;
    cout << "--------------------------------------\n";
    cout << "Nhap ma so de rut tien: ";
    cin.ignore();
    getline(cin, maSo);
    cout << "Nhap so tien muon rut: ";
    cin >> soTienRut;
    for (auto& stk : danhSachSoTietKiem) {
        if (stk.maSo == maSo) {
            rutTien(stk, soTienRut, laiSuat); 
            break;
            }
        }              
    
    // Tim kiem so tiet kiem
    string tuKhoa;
    cin.ignore();
    cout << "--------------------------------------\n";
    cout << "Nhap CMND hoac ma so de tim kiem: ";
    getline(cin, tuKhoa);
    timKiemSoTietKiem(danhSachSoTietKiem, tuKhoa); 

    // Liet ke cac so tiet kiem mo trong mot khoang thoi gian
    cout << "--------------------------------------\n";
    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
    cout << "Nhap ngay bat dau (dd mm yyyy): ";
    cin >> startDay >> startMonth >> startYear;
    cout << "Nhap ngay ket thuc (dd mm yyyy): ";
    cin >> endDay >> endMonth >> endYear;

    tm startDate = {0};
    startDate.tm_mday = startDay;
    startDate.tm_mon = startMonth - 1;
    startDate.tm_year = startYear - 1900;

    tm endDate = {0};
    endDate.tm_mday = endDay;
    endDate.tm_mon = endMonth - 1;
    endDate.tm_year = endYear - 1900;
    
    lietKeSoTietKiemTrongKhoangThoiGian(danhSachSoTietKiem, startDate, endDate); 
    
    cout << "--------------------------------------\n";
    cout << "Sap xep theo so tien gui:\n";
    sapXepDanhSachSoTietKiem(danhSachSoTietKiem, true); // Sap xep theo so tien gui
    cout << "--------------------------------------\n";
    cout << "Sap xep theo ngay mo so:\n";
    sapXepDanhSachSoTietKiem(danhSachSoTietKiem, false); // Sap xep theo ngay mo so

    return 0;
}
