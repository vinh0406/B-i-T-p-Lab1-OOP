#include <bits/stdc++.h>
using namespace std;

// bieu dien phan so
struct PhanSo {
    int tu;   // tu so
    int mau;  // mau so
};

// Ham nhap phan so tu ban phim
PhanSo nhapPhanSo() {
    PhanSo ps;
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    cout << "Nhap mau so: ";
    cin >> ps.mau;
    return ps;
}

// Ham so sanh hai phan so
// Dau vao: hai phan so ps1 va ps2
// Dau ra: phan so lon hon trong hai phan so
PhanSo soSanhPhanSo(PhanSo ps1, PhanSo ps2) {
    // So sanh bang cach quy dong mau so, so sanh tu so
    int tu1 = ps1.tu * ps2.mau;
    int tu2 = ps2.tu * ps1.mau;
    
    if (tu1 > tu2)
        return ps1;
    else
        return ps2;
}

// Ham rut gon phan so
PhanSo rutGon(PhanSo ps) {
        int ucln = __gcd(ps.tu, ps.mau); 
        ps.tu /= ucln;
        ps.mau /= ucln;
        if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
        return ps;
}

// Ham xuat phan so ra man hinh
void xuatPhanSo(PhanSo ps) {
    if (ps.mau==1) cout<<ps.tu;
    else if (ps.tu==0) cout<<0;
    else
    cout << ps.tu << "/" << ps.mau << endl;
}

int main() {
    // Nhap hai phan so tu nguoi dung
    cout << "Nhap phan so thu nhat:\n";
    PhanSo ps1 = nhapPhanSo();
    if (ps1.mau==0) {
        cout<<"Khong xac dinh";
        return 0;
    }
    ps1 = rutGon(ps1);

    cout << "Nhap phan so thu hai:\n";
    PhanSo ps2 = nhapPhanSo();
    if (ps2.mau==0) {
        cout<<"Khong xac dinh";
        return 0;
    }
    ps2 = rutGon(ps2);
    
    // So sanh hai phan so va tim phan so lon nhat
    PhanSo maxPhanSo = soSanhPhanSo(ps1, ps2);
    
    // Xuat ket qua phan so lon nhat
    cout << "Phan so lon nhat la: ";
    xuatPhanSo(maxPhanSo);
    
    return 0;
}
