#include <iostream>
#include <string>
using namespace std;
// Cấu trúc dữ liệu
struct HocSinh{
    string ten;
    float toan, van;
};
/*
 Tính năng: Kiểm tra tính hợp lệ của tên người dùng nhập vào.
 s: Chuỗi (string) tên cần kiểm tra.
 true: Nếu tên chỉ chứa chữ cái (a-z, A-Z) và khoảng trắng.
 false: Nếu tên trống hoặc chứa ký tự đặc biệt/số.
 */
/**
 * Tinh nang: Kiem tra ten hop le (chi chua chu cai va khoang trang)
 * Dau vao: Chuoi s (ten nguoi dung nhap)
 * Dau ra: true neu hop le, false neu co ky tu la hoac rong
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
        // Kiem tra: Neu c KHONG phai chu cai VA cung KHONG phai khoang trang
        if (!(isalpha(c) || isspace(c))) {
            return false; // Gap ky tu la (so, dau cham,...) la loai ngay
        }
    }
    // Neu kiem tra het ca chuoi ma moi thu deu on thi tra ve dung
    return true;
}
/*
 Chưc năng: Thực hiện nhập tên từ bàn phím và ép buộc người dùng nhập đúng định dạng.
 Một chuỗi tên đã được kiểm tra tính hợp lệ.
 */
string nhapTen(){
    string s;
    while (true){
        cout << "Nhap ho ten: ";
        // ưs dung đẻe xử lýdòng thừa còn sót lại trong bộ đệm
        getline(cin >> ws, s); 
        if (hopLeTen(s)) return s;
        cout << "Ten khong hop le (chi duoc chu va khoang trang)!\n";
    }
}
/*
 Tính năng: Nhập điểm số và kiểm tra điều kiện điểm phải nằm trong khoảng [0, 10].
 msg: Chuỗi thông báo hiển thị cho người dùng (ví dụ: "Nhap diem Toan: ").
 Một số thực (float) có giá trị từ 0 đến 10.
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
 hs: Một biến kiểu cấu trúc HocSinh (chứa điểm toán và văn).
 Giá trị trung bình (float) theo công thức: (Toan + Van) / 2.
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