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

//Thời khóa biểu
class ThoiKhoaBieu {
private:
    string tenBuoi;
    string monHoc;
    string gioHoc;

public:
    ThoiKhoaBieu() {
        tenBuoi = "";
        monHoc = "";
        gioHoc = "";
    }

    ThoiKhoaBieu(string tb, string mh, string gh) {
        tenBuoi = tb;
        monHoc = mh;
        gioHoc = gh;
    }

    // Nhập
    void Nhap() {
        cin.ignore();
        cout << "Nhap ten buoi (Sang/Chieu/Toi): ";
        getline(cin, tenBuoi);

        cout << "Nhap mon hoc: ";
        getline(cin, monHoc);

        cout << "Nhap gio hoc (vd: 7h-9h): ";
        getline(cin, gioHoc);
    }

    // Xuất
    void Xuat() const {
        cout << "Buoi: " << tenBuoi << endl;
        cout << "Mon hoc: " << monHoc << endl;
        cout << "Gio hoc: " << gioHoc << endl;
    }

    // Getter & Setter
    string getTenBuoi() const { return tenBuoi; }
    string getMonHoc() const { return monHoc; }
    string getGioHoc() const { return gioHoc; }

    void setTenBuoi(string tb) { tenBuoi = tb; }
    void setMonHoc(string mh) { monHoc = mh; }
    void setGioHoc(string gh) { gioHoc = gh; }
};


// 1. Nhập danh sách
void NhapDS(ThoiKhoaBieu ds[], int &n) {
    cout << "Nhap so buoi hoc: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap buoi thu " << i + 1 << " ---\n";
        ds[i].Nhap();
    }
}

// 2. Xuất danh sách
void XuatDS(ThoiKhoaBieu ds[], int n) {
    cout << "\n===== THOI KHOA BIEU =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\nBuoi thu " << i + 1 << ":\n";
        ds[i].Xuat();
    }
}

// 3. Tìm kiếm tuyến tính theo tên buổi
int LinearSearch(ThoiKhoaBieu ds[], int n, string tenBuoi) {
    for (int i = 0; i < n; i++) {
        if (ds[i].getTenBuoi() == tenBuoi)
            return i;
    }
    return -1;
}
// 4. Sắp xếp theo tên buổi
void SortByTenBuoi(ThoiKhoaBieu ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getTenBuoi() > ds[j].getTenBuoi()) {
                ThoiKhoaBieu temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    cout << "\n=> Da sap xep theo ten buoi!\n";
}

// 5. Xóa buổi theo tên
void DeleteByTenBuoi(ThoiKhoaBieu ds[], int &n, string tenBuoi) {
    int vt = LinearSearch(ds, n, tenBuoi);
    if (vt == -1) {
        cout << "\nKhong tim thay buoi de xoa!\n";
        return;
    }

    for (int i = vt; i < n - 1; i++)
        ds[i] = ds[i + 1];

    n--;
    cout << "\n=> Da xoa thanh cong!\n";
}

int main() {

    return 0;

}

