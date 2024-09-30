#include <bits/stdc++.h>
using namespace std;

// Khai bao struct PhanSo de luu tru tu so va mau so
struct PhanSo {
    int tuSo;
    int mauSo;
};

// Ham nhap du lieu cho phan so tu ban phim
// Dau vao: tuSo va mauSo duoc nguoi dung nhap vao
void nhap(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tuSo;
    cout << "Nhap mau so: ";
    cin >> ps.mauSo;
}

// Ham xuat phan so ra man hinh
// Dau ra: In ra phan so da nhap
void xuat(const PhanSo &ps) {
    if (ps.mauSo == 1) {
        cout << ps.tuSo;
    } 
    else {
        cout << ps.tuSo << "/" << ps.mauSo;
    }
}

// Ham rut gon phan so bang cach chia tu va mau cho UCLN
// Dau vao: phan so goc
// Dau ra: phan so da rut gon
void rutGon(PhanSo &ps) {
    int uc = __gcd(ps.tuSo, ps.mauSo);
    ps.tuSo /= uc;
    ps.mauSo /= uc;
    if (ps.mauSo < 0) {
        ps.tuSo = -ps.tuSo;
        ps.mauSo = -ps.mauSo;
    }
}

// Ham tinh tong hai phan so
// Dau vao: phan so thu nhat va phan so thu hai
// Dau ra: phan so tong cua hai phan so
PhanSo Tong(const PhanSo &ps1, const PhanSo &ps2) {
    PhanSo tong;
    tong.tuSo = ps1.tuSo * ps2.mauSo + ps1.mauSo * ps2.tuSo;
    tong.mauSo = ps1.mauSo * ps2.mauSo;
    rutGon(tong);
    return tong;
}

// Ham tinh hieu hai phan so
// Dau vao: phan so thu nhat va phan so thu hai
// Dau ra: phan so hieu cua hai phan so
PhanSo Hieu(const PhanSo &ps1, const PhanSo &ps2) {
    PhanSo hieu;
    hieu.tuSo = ps1.tuSo * ps2.mauSo - ps1.mauSo * ps2.tuSo;
    hieu.mauSo = ps1.mauSo * ps2.mauSo;
    rutGon(hieu);
    return hieu;
}

// Ham tinh tich hai phan so
// Dau vao: phan so thu nhat va phan so thu hai
// Dau ra: phan so tich cua hai phan so
PhanSo Tich(const PhanSo &ps1, const PhanSo &ps2) {
    PhanSo tich;
    tich.tuSo = ps1.tuSo * ps2.tuSo;
    tich.mauSo = ps1.mauSo * ps2.mauSo;
    rutGon(tich);
    return tich;
}

// Ham tinh thuong hai phan so
// Dau vao: phan so thu nhat va phan so thu hai
// Dau ra: phan so thuong cua hai phan so
PhanSo Thuong(const PhanSo &ps1, const PhanSo &ps2) {
    PhanSo thuong;
    if (ps2.tuSo == 0) {
        thuong.mauSo = 0; 
    } else {
    thuong.tuSo = ps1.tuSo * ps2.mauSo;
    thuong.mauSo = ps1.mauSo * ps2.tuSo;
    rutGon(thuong);
    }
    return thuong;
}

int main() {
    PhanSo ps1,ps2;

    // Nhap vao hai phan so tu ban phim
    cout << "Nhap phan so thu nhat:\n";
    nhap(ps1);
    cout << "Nhap phan so thu hai:\n";
    nhap(ps2);
    if (ps1.mauSo==0 || ps2.mauSo==0) {
        cout<<"khong xac dinh";
        return 0;
    }

    // Tinh toan va xuat ket qua
    PhanSo tong = Tong(ps1, ps2);
    PhanSo hieu = Hieu(ps1, ps2);
    PhanSo tich = Tich(ps1, ps2);
    PhanSo thuong = Thuong(ps1, ps2);

    // Xuat ket qua cua cac phep tinh
    cout << "\nTong hai phan so: ";
    xuat(tong);
    cout << "\nHieu hai phan so: ";
    xuat(hieu);
    cout << "\nTich hai phan so: ";
    xuat(tich);
    cout << "\nThuong hai phan so: ";
    if (thuong.mauSo==0) cout<<"Khong xac dinh";
    else xuat(thuong);

    return 0;
}
