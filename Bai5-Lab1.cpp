#include <bits/stdc++.h>
using namespace std;

// Ham kiem tra xem nam nhuan hay khong
// Dau vao: nam n
// Dau ra: true neu nam nhuan, false neu khong
bool isLeapYear(int year) {
    // Nam nhuan neu chia het cho 4 va khong chia het cho 100,
    // hoac chia het cho 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Ham tim ngay tiep theo
// Dau vao: ngay, thang, nam
// Dau ra: ngay tiep theo
void nextDay(int day, int month, int year) {
    // So ngay trong tung thang
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiem tra nam nhuan va dieu chinh thang 2
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    // Tang ngay
    day++;
    // Neu ngay vuot qua so ngay cua thang, reset ngay va tang thang
    if (day > daysInMonth[month - 1]) {
        day = 1;
        month++;
        // Neu thang vuot qua 12, reset thang va tang nam
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    cout << "Ngay ke tiep: " << day << "/" << month << "/" << year << endl;
}

// Ham tim ngay truoc do
// Dau vao: ngay, thang, nam
// Dau ra: ngay truoc do
void previousDay(int day, int month, int year) {
    // So ngay trong tung thang
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiem tra nam nhuan va dieu chinh thang 2
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    // Giam ngay
    day--;
    // Neu ngay nho hon 1, reset ngay va giam thang
    if (day < 1) {
        month--;
        // Neu thang nho hon 1, reset thang va giam nam
        if (month < 1) {
            month = 12;
            year--;
        }
        // Cap nhat lai ngay theo so ngay cua thang vua giam
        day = daysInMonth[month - 1];
    }
    cout << "Ngay truoc do: " << day << "/" << month << "/" << year << endl;
}

// Ham tinh so ngay trong nam
// Dau vao: ngay, thang, nam
// Dau ra: so ngay da qua trong nam
int dayOfYear(int day, int month, int year) {
    int totalDays = 0;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiem tra nam nhuan va dieu chinh thang 2
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    // Số ngày trong từng tháng trước tháng hiện tại
    for (int i = 0; i < month - 1; ++i) {
        totalDays += daysInMonth[i];
    }
    totalDays += day; // Cộng thêm số ngày hiện tại
    return totalDays;
}

int main() {
    int day, month, year;

    // Nhap ngay, thang, nam tu nguoi dung
    cout << "Nhap ngay: ";
    cin >> day;
    cout << "Nhap thang: ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;

    // Tim va xuat ngay ke tiep
    nextDay(day, month, year);

    // Tim va xuat ngay truoc do
    previousDay(day, month, year);

    // Tinh va xuat so ngay da qua trong nam
    int totalDays = dayOfYear(day, month, year);
    cout << "Ngay " << day << "/" << month << "/" << year << " la ngay thu " << totalDays << " trong nam." << endl;

    return 0;
}
