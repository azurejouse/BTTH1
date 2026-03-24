#include <iostream>
using namespace std;
/*
Struct Date
Chức năng: lưu ngày (d), tháng (m), năm (y)
*/
struct Date{
    int d, m, y;
};
/*
Hàm nhapInt
Input: thông báo
Output: số nguyên hợp lệ
Chức năng: kiểm tra nhập sai (ký tự, chữ)
*/
int nhapInt(string msg){
    int x;
    cout << msg;
    while (!(cin >> x)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap sai! Nhap lai: ";
    }
    return x;
}
/*
Hàm namNhuan
Input: năm y
Output: true nếu là năm nhuận, ngược lại false
Chức năng:
- Năm chia hết cho 400 hoặc chia hết cho 4 nhưng không chia hết cho 100
*/
bool namNhuan(int y){
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}
/*
Hàm soNgay
Input: tháng m, năm y
Output: số ngày của tháng đó
Chức năng: xác định số ngày trong tháng (có xét năm nhuận)
*/
int soNgay(int m, int y){
    switch (m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return namNhuan(y) ? 29 : 28;
    }
    return 0;
}
/*
Hàm nhapDate
Input: biến Date
Output: ngày hợp lệ
Chức năng:
- Nhập ngày, tháng, năm
- Kiểm tra hợp lệ (tháng 1-12, ngày đúng theo tháng)
- Nếu sai thì nhập lại
*/
void nhapDate(Date &a){
    do{
        a.d = nhapInt("Nhap ngay: ");
        a.m = nhapInt("Nhap thang: ");
        a.y = nhapInt("Nhap nam: ");
        if (a.m < 1 || a.m > 12 || a.d < 1 || a.d > soNgay(a.m, a.y))
            cout << "Ngay khong hop le! Nhap lai.\n";
        else break;
    } while (true);
}
/*
Hàm nextDate
Input: 1 ngày
Output: ngày kế tiếp
Chức năng:
- Tăng ngày lên 1
- Nếu vượt số ngày tháng → sang tháng mới
- Nếu vượt tháng 12 → sang năm mới
*/
Date nextDate(Date a){
    a.d++;
    if (a.d > soNgay(a.m, a.y)){
        a.d = 1;
        a.m++;
        if (a.m > 12){
            a.m = 1;
            a.y++;
        }
    }
    return a;
}
/*
Hàm main
Chức năng:
- Nhập ngày
- Tính ngày kế tiếp
- Xuất kết quả
*/
int main(){
    Date a;
    nhapDate(a);
    Date b = nextDate(a);
    cout << "Ngay ke tiep: " << b.d << "/" << b.m << "/" << b.y;
    return 0;
}