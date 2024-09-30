#include <bits/stdc++.h>
using namespace std;

// Dinh nghia struct PhanSo de bieu dien mot phan so
struct PhanSo {
    int tu;  // Tu so
    int mau; // Mau so

    // Ham nhap phan so tu nguoi dung
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
    }

    // Ham rut gon phan so
    // Dau vao: phan so ban dau
    // Dau ra: phan so da duoc rut gon
    void rutGon() {
        int ucln = __gcd(tu, mau); 
        tu /= ucln;
        mau /= ucln;
        // Dam bao mau so luon duong
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    // Ham xuat phan so ra man hinh
    void xuat() const {
        if (mau == 1) {
            cout << "Phan so: " << tu << endl; 
        } else {
            cout << "Phan so: " << tu << "/" << mau << endl;
        }
    }
};

int main() {
    PhanSo ps;
    // Nhap phan so tu nguoi dung
    ps.nhap();
    // Kiem tra mau khac 0
    if (ps.mau==0) {
        cout<<"khong xac dinh";
        return 0;
    }
    // Rut gon phan so
    ps.rutGon();
    // Xuat ket qua
    ps.xuat();
    return 0;
}
