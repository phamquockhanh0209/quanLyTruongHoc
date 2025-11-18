#include <iostream>
#include <string>
using namespace std;

class Nguoi {
private:
    string hoTen;
    string ngaySinh;
    string diaChi;

public:
    Nguoi() {
        hoTen = "";
        ngaySinh = "";
        diaChi = "";
    }

    Nguoi(string ht, string ns, string dc) {
        hoTen = ht;
        ngaySinh = ns;
        diaChi = dc;
    }

    void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();                 
        getline(cin, hoTen);

        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);

        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    void Xuat() const {
        cout << "Ho ten   : " << hoTen << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
        cout << "Dia chi  : " << diaChi << endl;
    }

    string getHoTen() const { return hoTen; }
    string getNgaySinh() const { return ngaySinh; }
    string getDiaChi() const { return diaChi; }

    void setHoTen(string ht) { hoTen = ht; }
    void setNgaySinh(string ns) { ngaySinh = ns; }
    void setDiaChi(string dc) { diaChi = dc; }

    ~Nguoi() {}
};

int main() {

    return 0;
}