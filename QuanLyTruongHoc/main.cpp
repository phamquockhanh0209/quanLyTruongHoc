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
// gv
class GiaoVien : public Nguoi {
private:
    string maGV;
    string monDay;
    double luong;

public:
    GiaoVien() : Nguoi() {
        maGV = "";
        monDay = "";
        luong = 0;
    }

    GiaoVien(string ht, string ns, string dc, string mgv, string md, double l)
        : Nguoi(ht, ns, dc)
    {
        maGV = mgv;
        monDay = md;
        luong = l;
    }

    void Nhap() {
        cout << "\nNhap thong tin giao vien\n";

        Nguoi::Nhap();

        cout << "Nhap ma giao vien: ";
        getline(cin, maGV);

        cout << "Nhap mon day: ";
        getline(cin, monDay);

        cout << "Nhap luong: ";
        cin >> luong;
        cin.ignore();
    }

    void Xuat() const {
        cout << "\nThong tin giao vien\n";
        Nguoi::Xuat();
        cout << "Ma GV   : " << maGV << endl;
        cout << "Mon day : " << monDay << endl;
        cout << "Luong   : " << luong << endl;
    }

    void XuatNgan() const {
        cout << maGV << " | "
             << getHoTen() << " | "
             << monDay << " | "
             << luong << endl;
    }

    string getMaGV() const { return maGV; }
    string getMonDay() const { return monDay; }
    double getLuong() const { return luong; }

    void setMaGV(string mgv) { maGV = mgv; }
    void setMonDay(string md) { monDay = md; }
    void setLuong(double l) { luong = l; }

    void SuaThongTin() {
        cout << "\nSua thong tin giao vien\n";

        cout << "Sua ho ten (cu: " << getHoTen() << "): ";
        string tenMoi; getline(cin, tenMoi);
        if (!tenMoi.empty()) setHoTen(tenMoi);

        cout << "Sua ngay sinh (cu: " << getNgaySinh() << "): ";
        string nsMoi; getline(cin, nsMoi);
        if (!nsMoi.empty()) setNgaySinh(nsMoi);

        cout << "Sua dia chi (cu: " << getDiaChi() << "): ";
        string dcMoi; getline(cin, dcMoi);
        if (!dcMoi.empty()) setDiaChi(dcMoi);

        cout << "Sua ma GV (cu: " << maGV << "): ";
        string mgvMoi; getline(cin, mgvMoi);
        if (!mgvMoi.empty()) maGV = mgvMoi;

        cout << "Sua mon day (cu: " << monDay << "): ";
        string mdMoi; getline(cin, mdMoi);
        if (!mdMoi.empty()) monDay = mdMoi;

        cout << "Sua luong (cu: " << luong << "): ";
        string temp; getline(cin, temp);
        if (!temp.empty()) luong = stod(temp);

        cout << "\nDa cap nhat thong tin giao vien!\n";
    }

    bool operator < (const GiaoVien& other) const {
        return this->getHoTen() < other.getHoTen();
    }

    GiaoVien* TimTheoMaGV(vector<GiaoVien>& ds, string ma) {
        for (auto &gv : ds)
            if (gv.maGV == ma)
                return &gv;
        return nullptr;
    }

    void TimTheoMonDay(vector<GiaoVien>& ds, string mon) {
        bool found = false;
        for (auto &gv : ds)
            if (gv.monDay == mon) {
                gv.Xuat();
                found = true;
            }
        if (!found)
            cout << "Khong tim thay giao vien day mon nay!\n";
    }

    void SapXepTheoMa(vector<GiaoVien>& ds) {
        sort(ds.begin(), ds.end(),
            [](const GiaoVien &a, const GiaoVien &b) {
                return a.maGV < b.maGV;
            }
        );
    }

    void SapXepTheoTen(vector<GiaoVien>& ds) {
        sort(ds.begin(), ds.end());
    }

    void SapXepTheoLuong(vector<GiaoVien>& ds) {
        sort(ds.begin(), ds.end(),
            [](const GiaoVien &a, const GiaoVien &b) {
                return a.luong < b.luong;
            }
        );
    }
};

// CLASS Student ke thua nguoi
class Student : public Nguoi {
private:
    string studentID;
    double GPA;
    string major;

public:
    Student() {}

    void Nhap() override {
        Nguoi::Nhap();
        cout << "Nhap Student ID: ";
        getline(cin, studentID);

        cout << "Nhap GPA: ";
        cin >> GPA;
        cin.ignore();

        cout << "Nhap chuyen nganh: ";
        getline(cin, major);
    }

    void Xuat() const override {
        Nguoi::Xuat();
        cout << "Student ID : " << studentID << endl;
        cout << "GPA        : " << GPA << endl;
        cout << "Major      : " << major << endl;
    }

    string getID() const { return studentID; }
    double getGPA() const { return GPA; }
};
class Classroom {
private:
    vector<Student> ds;

public:
    // Them sinh vien
    void addStudent() {
        Student s;
        s.Nhap();
        ds.push_back(s);
    }

    // Xuat toan bo
    void showAll() {
        for (auto &s : ds) {
            s.Xuat();
            cout << "---------------------\n";
        }
    }

    //Linear Search theo Name
    void searchByName(string name) {
        for (auto &s : ds)
            if (s.getHoTen() == name) {
                cout << "==> TIM THAY!\n";
                s.Xuat();
                return;
            }
        cout << "Khong tim thay!\n";
    }

    //Linear Search theo ID
    void searchByID_Linear(string id) {
        for (auto &s : ds)
            if (s.getID() == id) {
                cout << "==> TIM THAY!\n";
                s.Xuat();
                return;
            }
        cout << "Khong tim thay!\n";
    }

    // Binary Search theo ID
    int binarySearchID(string id) {
        int l = 0, r = ds.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ds[mid].getID() == id) return mid;
            if (ds[mid].getID() < id) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
    //Bubble Sort – theo GPA
    void bubbleSort_GPA() {
        int n = ds.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (ds[j].getGPA() > ds[j + 1].getGPA())
                    swap(ds[j], ds[j + 1]);
    }
    //Quick Sort – theo Name
    int partitionQS(int low, int high) {
        string pivot = ds[high].getHoTen();
        int i = low - 1;

        for (int j = low; j < high; j++)
            if (ds[j].getHoTen() < pivot) {
                i++;
                swap(ds[i], ds[j]);
            }

        swap(ds[i + 1], ds[high]);
        return i + 1;
    }

    void quickSort_Name(int low, int high) {
        if (low < high) {
            int pi = partitionQS(low, high);
            quickSort_Name(low, pi - 1);
            quickSort_Name(pi + 1, high);
        }
    }
    //Selection Sort – theo ID
    void selectionSort_ID() {
        int n = ds.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
                if (ds[j].getID() < ds[minIndex].getID())
                    minIndex = j;
            swap(ds[i], ds[minIndex]);
        }
    }
    // Delete theo ID
    void deleteByID(string id) {
        for (int i = 0; i < ds.size(); i++) {
            if (ds[i].getID() == id) {
                ds.erase(ds.begin() + i);
                cout << "==> Da xoa thanh cong.\n";
                return;
            }
        }
        cout << "Khong tim thay ID.\n";
    }
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





