#include <iostream>
#include <string>
using namespace std;
// Cấu trúc dữ liệu cho tên hs và điểm toánn, văn
struct HocSinh{
    string ten;
    float toan, van;
};
/*
 - Chức năng: Kiem tra ten hop le
 - Input: Chuoi s (ten)
 - Output: true neu hop le, false neu co ky tu la hoac rong
 */
bool hopLeTen(string s){
    // Neu chuoi rong thi tra ve sai luon
    if (s.length() == 0){ 
        return false;
    }
    // Dung vong lap for binh thuong voi bien chay i
    for (int i = 0; i < (int)s.length(); i++){
        // Lay ky tu tai vi tri i ra de kiem tra
        char c = s[i]; 
        // Kiem tra: Neu c khong phai chu cai va cung khong phai khoang trang
        if (!(isalpha(c) || isspace(c))) {
            return false; // Gap ky tu la la loai ngay
        }
    }
    // Neu kiem tra het ca chuoi ma moi thu deu on thi tra ve dung
    return true;
}
/*
 Chưc năng: Thực hiện nhập tên từ bàn phím và ép buộc người dùng nhập đúng định dạng.
 Output: Một chuỗi tên hợp lệ.
 */
string nhapTen(){
    string s;
    while (true){
        cout << "Nhap ho ten: ";
        // ws dung đẻe xử lýdòng thừa còn sót lại trong bộ đệm
        getline(cin >> ws, s); 
        if (hopLeTen(s)) return s;
        cout << "Ten khong hop le (chi duoc chu va khoang trang)!\n";
    }
}
/*
 Chức năng: Nhập điểm số và kiểm tra điều kiện điểm phải nằm trong khoảng [0, 10].
 msg: Chuỗi thông báo hiển thị
 Một số thực có giá trị từ 0 đến 10.
 */
float nhapDiem(string msg) {
    float x;
    while (true) {
        cout << msg;
        // Kiểm tra nếu nhập không phải là số (cin >> x thất bại) hoặc số ngoài khoảng 0-10
        if (cin >> x && x >= 0 && x <= 10) {
            return x;
        } else {
            cout << "Loi! Diem phai > 0 && < 10\n";
            cin.clear(); // Xóa trạng thái lỗi của cin
            cin.ignore(1000, '\n'); // Xóa toàn bộ ký tự sai trong buffer
        }
    }
}
/*
 Chức năng: Tính toán điểm trung bình cộng của hai môn học.
 hs: Một biến kiểu cấu trúc HocSinh.
 Giá trị trung bình theo công thức: (Toan + Van) / 2.
 */
float diemTB(HocSinh hs){
    return (hs.toan + hs.van) / 2;
}
/*
 Hàm main: chua cac ham nhap va print
 Chức năng: Nhập dữ liệu -> Xử lý tính toán -> Xuất kết quả
 */
int main(){
    HocSinh hs;
    hs.ten = nhapTen();
    hs.toan = nhapDiem("Nhap diem Toan: ");
    hs.van  = nhapDiem("Nhap diem Van: ");
    cout << "\nThong tin hoc sinh:" << endl;
    cout << "Ten hoc sinh: " << hs.ten << endl;
    cout << "Diem Toan: " << hs.toan << " | Van: " << hs.van << endl;
    cout << "Diem Trung Binh: " << diemTB(hs) << endl;
    return 0;
}
