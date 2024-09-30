#include <bits/stdc++.h>
using namespace std;

// Ham tinh giai thua
// Dau vao: so nguyen n
// Dau ra: n!
long long factorial(int n) {
    long long result = 1;
    // Lap qua cac so tu 2 den n de tinh giai thua
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result; 
}

// Ham tinh sin(x) theo chuoi Taylor voi do chinh xac 0.00001
// Dau vao: x la gia tri goc (radian) ma ban muon tinh sin(x)
// Dau ra: gia tri gan dung cua sin(x) duoc tinh bang chuoi Taylor
double sinTaylor(double x) { 
    double term;         // Biến lưu trữ từng hạng tử của chuỗi Taylor
    double sin_xTaylor = 0;    // Biến lưu trữ giá trị của sin(x)
    int n = 0;           // Bắt đầu với hạng tử thứ nhất
    // Chuẩn hóa x để nằm trong khoảng -pi đến pi
    x = fmod(x + M_PI, 2 * M_PI) - M_PI;
    
    // Vòng lặp tính các hạng tử tiếp theo cho đến khi độ chính xác đạt yêu cầu
    while (abs(term) > 0.00001){ // Kiểm tra độ chính xác
        term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1); // Tính hạng tử theo công thức
        sin_xTaylor += term;   // Cộng hạng tử vào tổng sin(x)
        n++;             
    } 

    return sin_xTaylor; 
}

int main() {
    double x;
    // Nhap gia tri x tu ban phim (don vi radian)
    cout << "Nhap gia tri x (tinh bang radian): ";
    cin >> x;

    // Tinh sin(x) su dung chuoi Taylor
    double result = sinTaylor(x);

    // In ket qua tinh bang chuoi Taylor
    cout << "Gia tri sin(" << x << ") = " << result << endl;

    return 0;
}
