#include <iostream>
using namespace std;
/*
Struct PhanSo
Chức năng: lưu tử số (tu) và mẫu số (mau) của một phân số
*/
struct PhanSo{
    int tu, mau;
};
/*
Hàm nhapPhanSo
Input: không
Output: phân số hợp lệ (mẫu ≠ 0, đúng định dạng số nguyên)
Chức năng:
- Nhập tử và mẫu
- Kiểm tra lỗi nhập (nhập chữ/ký tự)
- Kiểm tra mẫu khác 0
- Nếu sai thì yêu cầu nhập lại
*/
void nhapPhanSo(PhanSo &ps) {
    do{
        // nhập tử
        cout << "Nhap tu so: ";
        while (!(cin >> ps.tu)){ 
            cin.clear();                  // xóa trạng thái lỗi của cin
            cin.ignore(1000, '\n');       // xóa dữ liệu sai trong buffer
            cout << "Nhap sai! Nhap lai tu so: ";
        }
        // nhập mẫu
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
Input: 2 số nguyên a, b
Output: ước chung lớn nhất của a và b
Chức năng:
- Sử dụng thuật toán Euclid (dạng lặp)
- Dùng để rút gọn phân số
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
Input: phân số ps
Output: phân số đã rút gọn
Chức năng:
- Chia cả tử và mẫu cho UCLN để đưa về dạng tối giản
*/
void rutGon(PhanSo &ps){
    int g = gcd(ps.tu, ps.mau);
    ps.tu /= g;
    ps.mau /= g;
}
/*
Hàm xuatPhanSo
Input: phân số ps
Output: in ra phân số theo dạng đẹp:
- tu = 0 → in 0
- tu = mau → in 1
- mau = 1 → in tu
- còn lại → in tu/mau
Chức năng: chuẩn hóa cách hiển thị kết quả
*/
void xuatPhanSo(PhanSo ps){
    // đưa dấu âm về tử
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
- Nhập phân số
- Rút gọn phân số
- Xuất kết quả theo dạng chuẩn
*/
int main(){
    PhanSo ps;
    nhapPhanSo(ps);   // nhập dữ liệu
    rutGon(ps);       // rút gọn
    cout << "Phan so sau rut gon: ";
    xuatPhanSo(ps);   // xuất kết quả
    return 0;
}