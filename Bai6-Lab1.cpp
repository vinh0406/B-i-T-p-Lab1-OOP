#include <bits/stdc++.h>
using namespace std;

// Ham xay dung mang prefix (partial match table)
// Dau vao: mang A
// Dau ra: mang prefix cho biet do dai cua phan khop dai nhat tai moi vi tri
vector<int> buildPrefixTable(const vector<int>& A) {
    int m = A.size();
    vector<int> prefix(m, 0); // Khoi tao mang prefix co cung kich thuoc voi A

    int j = 0; // Chieu dai cua prefix match truoc do
    for (int i = 1; i < m; i++) {
        while (j > 0 && A[i] != A[j]) {
            j = prefix[j - 1]; // Di chuyen ve vi tri prefix truoc do
        }
        if (A[i] == A[j]) {
            j++; // Neu khop thi tang j
        }
        prefix[i] = j; // Luu gia tri j vao bang prefix
    }
    return prefix;
}

// Ham su dung KMP de tim so lan xuat hien cua A trong B
// Dau vao: mang A, B
// Dau ra: vi tri bat dau cua cac lan xuat hien
vector<int> KMPSearch(const vector<int>& A, const vector<int>& B) {
    vector<int> positions; // Luu vi tri bat dau cua cac lan xuat hien
    int n = B.size();
    int m = A.size();

    // Xay dung bang prefix tu mang A
    vector<int> prefix = buildPrefixTable(A);

    int j = 0; // Chi so cho mang A
    for (int i = 0; i < n; i++) { // Duyet qua mang B
        while (j > 0 && B[i] != A[j]) {
            j = prefix[j - 1]; // Di chuyen j ve theo bang prefix neu khong khop
        }
        if (B[i] == A[j]) {
            j++; // Neu khop thi tang j
        }
        if (j == m) { // Khi tim duoc ca mang A trong B
            positions.push_back(i - m + 1); // Luu vi tri bat dau
            j = prefix[j - 1]; // Tiep tuc tim kiem cho cac vi tri sau
        }
    }

    return positions;
}

int main() {
    int sizeA, sizeB;
    cout << "Nhap so phan tu cua mang A: ";
    cin >> sizeA;

    cout << "Nhap so phan tu cua mang B: ";
    cin >> sizeB;

    vector<int> A(sizeA), B(sizeB);
    cout << "Nhap cac phan tu cua mang A: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }

    cout << "Nhap cac phan tu cua mang B: ";
    for (int i = 0; i < sizeB; i++) {
        cin >> B[i];
    }

    // Tim vi tri bat dau cua cac lan xuat hien cua A trong B
    vector<int> positions = KMPSearch(A, B);

    // Xuat ket qua
    cout << "So lan mang A xuat hien trong mang B: " << positions.size() << endl;
    if (!positions.empty()) {
        cout << "Cac vi tri bat dau: ";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}
