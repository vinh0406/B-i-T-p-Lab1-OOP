#include <bits/stdc++.h>
using namespace std;

// Cau truc luu tru thong tin cua mot hoc sinh
struct HocSinh {
    string hoTen;
    float diemToan;
    float diemVan;
    float diemNgoaiNgu;
    float diemTrungBinh;
};

// Ham kiem tra dinh dang ten
// Dau vao: chuoi hoTen
// Dau ra: true neu hop le (khong chua ky tu so), false neu khong hop le
bool kiemTraTen(string hoTen) {
    for (char c : hoTen) {
        if (isdigit(c)) return false;
    }
    return true;
}

// Ham nhap diem cua mot mon
float nhapDiem() {
    float diem;
    while (true) {
        cin >> diem;
        if (diem >= 0 && diem <= 10) return diem;
        cout << "Diem khong hop le, vui long nhap lai (0 <= diem <= 10): ";
    }
}

// Ham tinh diem trung binh
// Dau vao: diemToan, diemVan, diemNgoaiNgu
// Dau ra: tra ve diem trung binh
float tinhDiemTrungBinh(float diemToan, float diemVan, float diemNgoaiNgu) {
    return (2 * diemToan + diemVan + diemNgoaiNgu) / 4;
}

// Ham phan loai hoc sinh dua tren diem trung binh
// Dau vao: diemTrungBinh
// Dau ra: tra ve chuoi phan loai hoc sinh
string phanLoaiHocSinh(float diemTrungBinh) {
    if (diemTrungBinh >= 9) return "Xuat sac";
    if (diemTrungBinh >= 8) return "Gioi";
    if (diemTrungBinh >= 6.5) return "Kha";
    if (diemTrungBinh >= 5) return "Trung binh";
    return "Yeu";
}

// Ham nhap thong tin hoc sinh
HocSinh nhapHocSinh() {
    HocSinh hs;
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hs.hoTen);
    while (!kiemTraTen(hs.hoTen)) {
        cout << "Ten khong hop le, vui long nhap lai: ";
        getline(cin, hs.hoTen);
    }
    cout << "Nhap diem Toan: ";
    hs.diemToan = nhapDiem();
    cout << "Nhap diem Van: ";
    hs.diemVan = nhapDiem();
    cout << "Nhap diem Ngoai ngu: ";
    hs.diemNgoaiNgu = nhapDiem();

    // Tinh diem trung binh
    hs.diemTrungBinh = tinhDiemTrungBinh(hs.diemToan, hs.diemVan, hs.diemNgoaiNgu);
    return hs;
}

// Ham tim hoc sinh co diem trung binh cao nhat
// Dau vao: vector danh sach hoc sinh
// Dau ra: tra ve danh sach hoc sinh co diem trung binh cao nhat
vector<HocSinh> timHocSinhCaoNhat(const vector<HocSinh>& danhSach) {
    float diemCaoNhat = max_element(danhSach.begin(), danhSach.end(), [](HocSinh a, HocSinh b) {
        return a.diemTrungBinh < b.diemTrungBinh;
    })->diemTrungBinh;

    vector<HocSinh> ketQua;
    for (const auto& hs : danhSach) {
        if (hs.diemTrungBinh == diemCaoNhat) {
            ketQua.push_back(hs);
        }
    }
    return ketQua;
}

// Ham tim kiem hoc sinh theo ten
// Dau vao: vector danh sach hoc sinh, chuoi tuKhoa tim kiem
// Dau ra: in ra cac hoc sinh khop voi tu khoa
void timKiemHocSinhTheoTen(const vector<HocSinh>& danhSach, string tuKhoa) {
    int check = 0;
    transform(tuKhoa.begin(), tuKhoa.end(), tuKhoa.begin(), ::tolower); // Chuyen tu khoa ve chu thuong
    for (const auto& hs : danhSach) {
        string ten = hs.hoTen;
        transform(ten.begin(), ten.end(), ten.begin(), ::tolower);
        if (ten.find(tuKhoa) != string::npos) {
            check = 1;
            cout << "Ho ten: " << hs.hoTen << ", Diem TB: " << hs.diemTrungBinh << ", Phan loai: " << phanLoaiHocSinh(hs.diemTrungBinh) << endl;
        }
    }
    if (check == 0) cout << "khong tim thay ten. ";
}

// Ham xuat danh sach hoc sinh co diem toan thap nhat
// Dau vao: vector danh sach hoc sinh
// Dau ra: in ra cac hoc sinh co diem toan thap nhat
void xuatHocSinhDiemToanThapNhat(const vector<HocSinh>& danhSach) {
    float diemThapNhat = min_element(danhSach.begin(), danhSach.end(), [](HocSinh a, HocSinh b) {
        return a.diemToan < b.diemToan;
    })->diemToan;

    cout << "Hoc sinh co diem Toan thap nhat:\n";
    for (const auto& hs : danhSach) {
        if (hs.diemToan == diemThapNhat) {
            cout << "Ho ten: " << hs.hoTen << ", Diem Toan: " << hs.diemToan << endl;
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    vector<HocSinh> danhSach;

    // Nhap thong tin hoc sinh
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        danhSach.push_back(nhapHocSinh());
        cout << "-------------------------\n";
    }

    // Xuat thong tin hoc sinh
    for (const auto& hs : danhSach) {
        cout << "-------------------------\n";
        cout << "Ho ten: " << hs.hoTen << ", Diem TB: " << hs.diemTrungBinh
             << ", Phan loai: " << phanLoaiHocSinh(hs.diemTrungBinh) << endl;
    }

    // Tim va in danh sach hoc sinh co diem TB cao nhat
    vector<HocSinh> hsCaoNhat = timHocSinhCaoNhat(danhSach);
    cout << "-------------------------\n";
    cout << "Hoc sinh co diem TB cao nhat:\n";
    for (const auto& hs : hsCaoNhat) {
        cout << "Ho ten: " << hs.hoTen << ", Diem TB: " << hs.diemTrungBinh << endl;
    }

    // Tim kiem hoc sinh theo ten
    string tuKhoa;
    cout << "-------------------------\n";
    cout << "Nhap tu khoa tim kiem theo ten: ";
    cin >> tuKhoa;
    timKiemHocSinhTheoTen(danhSach, tuKhoa);

    // Xuat danh sach hoc sinh co diem Toan thap nhat
    cout << "-------------------------\n";
    xuatHocSinhDiemToanThapNhat(danhSach);
    cout << "-------------------------\n";
    return 0;
}
