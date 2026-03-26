#include <iostream>
using namespace std;
/*
Struct PhanSo
Chức năng: lưu tử số và mẫu số của phân số
*/
struct PhanSo{
    int tu, mau;
};
/*
Hàm nhapPhanSo
Input: không
Output: phân số hợp lệ (mẫu ≠ 0, đúng định dạng)
Chức năng:
- Nhập tử và mẫu
- Kiểm tra lỗi nhập
- Bắt nhập lại nếu sai
*/
void nhapPhanSo(PhanSo &ps){
    do{
        cout << "Nhap tu so: ";
        while (!(cin >> ps.tu)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nhap sai! Nhap lai tu so: ";
        }
        cout << "Nhap mau so (khac 0): ";
        while (!(cin >> ps.mau)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nhap sai! Nhap lai mau so: ";
        }
        if (ps.mau == 0)
            cout << "Nhap lai phan so!\n";
    }while (ps.mau == 0);
}
/*
Hàm gcd
Input: 2 số nguyên
Output: UCLN
Chức năng: rút gọn theo euclid
*/
int gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    while (b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
/*
Hàm rutGon
Input: phân số
Output: phân số tối giản
*/
void rutGon(PhanSo &ps){
    int g = gcd(ps.tu, ps.mau);
    ps.tu /= g;
    ps.mau /= g;
}
/*
Hàm lonHon
Input: 2 phân số a, b
Output: true nếu a > b
Chức năng:
- So sánh bằng cách nhân chéo
- Tránh chia để không bị sai số
*/
bool lonHon(PhanSo a, PhanSo b){
    return a.tu * b.mau > b.tu * a.mau;
}
/*
Hàm xuatPhanSo
Input: phân số
Output: in ra dạng đẹp:
- 0
- 1
- số nguyên
- hoặc a/b
*/
void xuatPhanSo(PhanSo ps){
    if (ps.mau < 0){
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    if (ps.tu == 0){
        cout << 0;
    }
    else if (ps.tu == ps.mau){
        cout << 1;
    }
    else if (ps.mau == 1){
        cout << ps.tu;
    }
    else{
        cout << ps.tu << "/" << ps.mau;
    }
}
/*
Hàm main
Chức năng:
- Nhập 2 phân số
- Rút gọn
- So sánh và in phân số lớn hơn
*/
int main(){
    PhanSo a, b;
    cout << "Nhap phan so thu nhat:\n";
    nhapPhanSo(a);
    cout << "Nhap phan so thu hai:\n";
    nhapPhanSo(b);
    rutGon(a);
    rutGon(b);
    cout << "Phan so lon nhat: ";
    if (lonHon(a, b))
        xuatPhanSo(a);
    else
        xuatPhanSo(b);
    return 0;
}
