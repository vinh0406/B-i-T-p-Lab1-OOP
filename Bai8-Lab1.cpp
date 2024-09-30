#include <bits/stdc++.h>
using namespace std;

// Cau truc luu thong tin mot chuyen bay
struct ChuyenBay {
    string maChuyenBay;
    string ngayBay;
    string gioBay;
    string noiDi;
    string noiDen;
};

// Ham kiem tra dinh dang ma chuyen bay
// Dau vao: chuoi ma chuyen bay
// Dau ra: true neu hop le, false neu khong hop le (khong duoc co khoang trang hay ky tu dac biet)
bool kiemTraMaChuyenBay(string ma) {
    if (ma.length() > 5) return false;
    for (char c : ma) {
        if (!isalnum(c)||isspace(c)) return false; // Chi cho phep chu va so
    }
    return true;
}

// Ham kiem tra dinh dang ngay bay
// Dau vao: chuoi ngay bay
// Dau ra: true neu hop le, false neu khong hop le
bool kiemTraNgay(string ngay) {
    if (ngay.length() != 10 || ngay[2] != '/' || ngay[5] != '/') return false;
    int ngayInt = stoi(ngay.substr(0, 2));
    int thangInt = stoi(ngay.substr(3, 2));
    int namInt = stoi(ngay.substr(6, 4));
    
    // Kiem tra gioi han ngay thang nam
    if (ngayInt < 1 || thangInt < 1 || thangInt > 12 || namInt < 1) return false;

    // Kiem tra ngay hop le theo thang
    int ngayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    // Nam nhuan
    if ((namInt % 4 == 0 && namInt % 100 != 0) || (namInt % 400 == 0)) ngayTrongThang[1] = 29;

    return ngayInt <= ngayTrongThang[thangInt - 1];
}

// Ham kiem tra dinh dang gio bay
// Dau vao: chuoi gio bay
// Dau ra: true neu hop le, false neu khong hop le
bool kiemTraGio(string gio) {
    if (gio.length() != 5 || gio[2] != ':') return false;
    int gioInt = stoi(gio.substr(0, 2));
    int phutInt = stoi(gio.substr(3, 2));
    return gioInt >= 0 && gioInt < 24 && phutInt >= 0 && phutInt < 60;
}

// Ham kiem tra dinh dang ten dia diem (noi di/noi den)
// Dau vao: chuoi ten dia diem
// Dau ra: true neu hop le, false neu khong hop le (khong duoc co so hoac ky tu dac biet)
bool kiemTraDiaDiem(string diaDiem) {
    if (diaDiem.length() > 20) return false;
    for (char c : diaDiem) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

// Ham nhap thong tin chuyen bay
ChuyenBay nhapChuyenBay() {
    ChuyenBay cb;
    cout << "Nhap ma chuyen bay: ";
    while (true) {
        getline(cin, cb.maChuyenBay);
        if (kiemTraMaChuyenBay(cb.maChuyenBay)) break;
        else cout << "Ma chuyen bay khong hop le, vui long nhap lai: ";
    }
    cout << "Nhap ngay bay (dd/mm/yyyy): ";
    while (true) {
        cin >> cb.ngayBay;
        if (kiemTraNgay(cb.ngayBay)) break;
        else cout << "Ngay khong hop le, vui long nhap lai: ";
    }

    cout << "Nhap gio bay (hh:mm): ";
    while (true) {
        cin >> cb.gioBay;
        if (kiemTraGio(cb.gioBay)) break;
        else cout << "Gio khong hop le, vui long nhap lai: ";
    }

    cout << "Nhap noi di: ";
    cin.ignore();
    while (true) {        
        getline(cin, cb.noiDi);
        if (kiemTraDiaDiem(cb.noiDi)) break;
        else cout << "Noi di khong hop le, vui long nhap lai: ";
    }
    
    cout << "Nhap noi den: ";
    while (true) {
        getline(cin, cb.noiDen);
        if (kiemTraDiaDiem(cb.noiDen)) break;
        else cout << "Noi den khong hop le, vui long nhap lai: ";
    }

    return cb;
}

// Ham sap xep danh sach chuyen bay theo ngay va gio
// Dau vao: danh sach chuyen bay
// Dau ra: danh sach da duoc sap xep theo ngay gio tang dan
void sapXepChuyenBay(vector<ChuyenBay>& ds) {
    sort(ds.begin(), ds.end(), [](const ChuyenBay& a, const ChuyenBay& b) {
        // Tach ngay thang nam va gio phut de so sanh
        int ngayA = stoi(a.ngayBay.substr(0, 2)), thangA = stoi(a.ngayBay.substr(3, 2)), namA = stoi(a.ngayBay.substr(6, 4));
        int ngayB = stoi(b.ngayBay.substr(0, 2)), thangB = stoi(b.ngayBay.substr(3, 2)), namB = stoi(b.ngayBay.substr(6, 4));

        int gioA = stoi(a.gioBay.substr(0, 2)), phutA = stoi(a.gioBay.substr(3, 2));
        int gioB = stoi(b.gioBay.substr(0, 2)), phutB = stoi(b.gioBay.substr(3, 2));

        if (namA != namB) return namA < namB;
        if (thangA != thangB) return thangA < thangB;
        if (ngayA != ngayB) return ngayA < ngayB;
        if (gioA != gioB) return gioA < gioB;
        return phutA < phutB;
    });
}

// Ham tim kiem chuyen bay theo ma, noi di hoac noi den
// Dau vao: danh sach chuyen bay, thong tin can tim
// Dau ra: chuyen bay neu tim thay, khong in ra neu khong tim thay
void timKiemChuyenBay(const vector<ChuyenBay>& dsChuyenBay, string tuKhoa) {
    int dem = 0;
    for (const auto& cb : dsChuyenBay) {
        if (cb.maChuyenBay == tuKhoa || cb.noiDi == tuKhoa || cb.noiDen == tuKhoa) {
            cout << "Ma: " << cb.maChuyenBay << ", Ngay: " << cb.ngayBay << ", Gio: " << cb.gioBay << ", Noi di: " << cb.noiDi << ", Noi den: " << cb.noiDen << endl;
            dem++;
        }
    }
    if (dem == 0) cout << "Khong tim thay chuyen bay." << endl;
}

// Ham dem so luong chuyen bay tu noi di den noi den
// Dau vao: danh sach chuyen bay, chuoi noi di, chuoi noi den
// Dau ra: tra ve so luong chuyen bay phu hop
int demChuyenBay(const vector<ChuyenBay>& dsChuyenBay, string noiDi, string noiDen) {
    int dem = 0;
    for (const auto& cb : dsChuyenBay) {
        if (cb.noiDi == noiDi && cb.noiDen == noiDen) {
            dem++;
        }
    }
    return dem;
}

// Ham hien thi danh sach chuyen bay khoi hanh tu noi cu the vao ngay chi dinh
// Dau vao: danh sach chuyen bay, chuoi noi di, chuoi ngay bay
// Dau ra: in ra cac chuyen bay tu noi di va ngay bay do
void hienThiChuyenBayTheoNgay(const vector<ChuyenBay>& dsChuyenBay, string noiDi, string ngay) {
    int dem = 0;
    for (const auto& cb : dsChuyenBay) {
        if (cb.noiDi == noiDi && cb.ngayBay == ngay) {
            cout << "Ma: " << cb.maChuyenBay << ", Ngay: " << cb.ngayBay << ", Gio: " << cb.gioBay <<", Noi di: "<<cb.noiDi<< ", Noi den: " << cb.noiDen << endl;
            dem++;
        }
    }
    if (dem == 0) cout << "Khong co chuyen bay nao." << endl;
}

int main() {
    int n;
    cout << "Nhap so luong chuyen bay: ";
    cin >> n;
    cin.ignore();
    vector<ChuyenBay> dsChuyenBay;

    // Nhap thong tin chuyen bay
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin chuyen bay thu " << i + 1 << ":\n";
        dsChuyenBay.push_back(nhapChuyenBay());
    }

    // Sap xep danh sach chuyen bay theo ngay gio
    sapXepChuyenBay(dsChuyenBay);
    cout << "Danh sach chuyen bay da sap xep:\n";
    for (const auto& cb : dsChuyenBay) {
        cout << "Ma: " << cb.maChuyenBay << ", Ngay: " << cb.ngayBay << ", Gio: " << cb.gioBay << ", Noi di: " << cb.noiDi << ", Noi den: " << cb.noiDen << endl;
    }

    // Tim kiem chuyen bay theo ma, noi di, noi den
    string tuKhoa;
    cout << "\nNhap tu khoa tim kiem (ma chuyen bay, noi di, noi den): ";
    getline(cin, tuKhoa);
    timKiemChuyenBay(dsChuyenBay, tuKhoa);

    // Hien thi chuyen bay theo noi di va ngay
    string noiDi, ngay;
    cout << "\nNhap noi di va ngay de hien thi chuyen bay (dd/mm/yyyy): ";
    getline(cin, noiDi); 
    getline(cin, ngay);
    hienThiChuyenBayTheoNgay(dsChuyenBay, noiDi, ngay);

    // Dem so chuyen bay tu noi di den noi den cu the
    string noiDen;
    cout << "\nNhap noi di va noi den de dem so luong chuyen bay: ";
    getline(cin, noiDi);
    getline(cin, noiDen);
    int soLuong = demChuyenBay(dsChuyenBay, noiDi, noiDen);
    cout << "So luong chuyen bay tu " << noiDi << " den " << noiDen << " la: " << soLuong << endl;

    return 0;
}
