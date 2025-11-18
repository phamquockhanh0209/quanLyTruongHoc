#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ====================== CLASS NGUOI ======================
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

    virtual void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);

        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);

        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    virtual void Xuat() const {
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

    virtual ~Nguoi() {}
};

// ====================== CLASS GIAO VIEN ======================
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

    void Nhap() override {
        cout << "\n=== Nhap thong tin giao vien ===\n";
        Nguoi::Nhap();

        cout << "Nhap ma giao vien: ";
        getline(cin, maGV);

        cout << "Nhap mon day: ";
        getline(cin, monDay);

        cout << "Nhap luong: ";
        cin >> luong;
        cin.ignore();
    }

    void Xuat() const override {
        cout << "\n=== Thong tin giao vien ===\n";
        Nguoi::Xuat();
        cout << "Ma GV   : " << maGV << endl;
        cout << "Mon day : " << monDay << endl;
        cout << "Luong   : " << luong << endl;
    }

    string getMaGV() const { return maGV; }
    string getMonDay() const { return monDay; }
    double getLuong() const { return luong; }

    void setMaGV(string mgv) { maGV = mgv; }
    void setMonDay(string md) { monDay = md; }
    void setLuong(double l) { luong = l; }

    bool operator < (const GiaoVien& other) const {
        return this->getHoTen() < other.getHoTen();
    }

    static void SapXepTheoTen(vector<GiaoVien>& ds) {
        sort(ds.begin(), ds.end());
    }
};

// ====================== CLASS STUDENT ======================
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

// ====================== CLASSROOM + DSA ======================
class Classroom {
private:
    vector<Student> ds;

public:
    void addStudent() {
        Student s;
        s.Nhap();
        ds.push_back(s);
    }

    void showAll() {
        for (auto &s : ds) {
            s.Xuat();
            cout << "---------------------\n";
        }
    }

    void searchByName(string name) {
        for (auto &s : ds)
            if (s.getHoTen() == name) {
                cout << "==> TIM THAY!\n";
                s.Xuat();
                return;
            }
        cout << "Khong tim thay!\n";
    }

    void searchByID_Linear(string id) {
        for (auto &s : ds)
            if (s.getID() == id) {
                cout << "==> TIM THAY!\n";
                s.Xuat();
                return;
            }
        cout << "Khong tim thay!\n";
    }

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

    void bubbleSort_GPA() {
        int n = ds.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (ds[j].getGPA() > ds[j + 1].getGPA())
                    swap(ds[j], ds[j + 1]);
    }

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

// ====================== THOI KHOA BIEU ======================
class ThoiKhoaBieu {
private:
    string tenBuoi;
    string monHoc;
    string gioHoc;

public:
    ThoiKhoaBieu() {}

    void Nhap() {
        cin.ignore();
        cout << "Nhap ten buoi: ";
        getline(cin, tenBuoi);

        cout << "Nhap mon hoc: ";
        getline(cin, monHoc);

        cout << "Nhap gio hoc: ";
        getline(cin, gioHoc);
    }

    void Xuat() const {
        cout << "Buoi: " << tenBuoi << endl;
        cout << "Mon hoc: " << monHoc << endl;
        cout << "Gio hoc: " << gioHoc << endl;
    }

    string getTenBuoi() const { return tenBuoi; }
};

// ====================== TKB FUNCTIONS ======================
void NhapDS(ThoiKhoaBieu ds[], int &n) {
    cout << "Nhap so buoi hoc: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap buoi thu " << i + 1 << " ---\n";
        ds[i].Nhap();
    }
}

void XuatDS(ThoiKhoaBieu ds[], int n) {
    cout << "\n===== THOI KHOA BIEU =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\nBuoi thu " << i + 1 << ":\n";
        ds[i].Xuat();
    }
}

int LinearSearch(ThoiKhoaBieu ds[], int n, string tenBuoi) {
    for (int i = 0; i < n; i++)
        if (ds[i].getTenBuoi() == tenBuoi)
            return i;
    return -1;
}

// ========================= MAIN MENU =========================
int main() {
    Classroom lop;
    vector<GiaoVien> dsGV;
    ThoiKhoaBieu tkb[100];
    int nTKB = 0;

    int choice;

    do {
        cout << "\n========== MENU CHINH ==========\n";
        cout << "1. Quan ly giao vien\n";
        cout << "2. Quan ly sinh vien\n";
        cout << "3. Quan ly thoi khoa bieu\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        if (choice == 1) {
            int c;
            do {
                cout << "\n--- MENU GIAO VIEN ---\n";
                cout << "1. Them giao vien\n";
                cout << "2. Xuat danh sach\n";
                cout << "3. Sap xep theo ten\n";
                cout << "0. Quay lai\n";
                cin >> c;

                if (c == 1) {
                    GiaoVien gv;
                    gv.Nhap();
                    dsGV.push_back(gv);
                }
                else if (c == 2) {
                    for (auto &x : dsGV) x.Xuat();
                }
                else if (c == 3) {
                    GiaoVien::SapXepTheoTen(dsGV);
                    cout << "=> Da sap xep!\n";
                }

            } while (c != 0);
        }

        else if (choice == 2) {
            int c;
            do {
                cout << "\n--- MENU SINH VIEN / DSA ---\n";
                cout << "1. Them sinh vien\n";
                cout << "2. Xuat danh sach\n";
                cout << "3. Tim theo ten\n";
                cout << "4. Tim theo ID (Linear)\n";
                cout << "5. Sap xep GPA (Bubble)\n";
                cout << "6. Sap xep theo ten (Quick Sort)\n";
                cout << "7. Xoa theo ID\n";
                cout << "0. Quay lai\n";
                cin >> c;

                if (c == 1) lop.addStudent();
                else if (c == 2) lop.showAll();
                else if (c == 3) {
                    string ten; cin.ignore(); getline(cin, ten);
                    lop.searchByName(ten);
                }
                else if (c == 4) {
                    string id; cin.ignore(); getline(cin, id);
                    lop.searchByID_Linear(id);
                }
                else if (c == 5) {
                    lop.bubbleSort_GPA();
                    cout << "=> Da sap xep\n";
                }
                else if (c == 6) {
                    lop.quickSort_Name(0, 0); // placeholder
                }
                else if (c == 7) {
                    string id; cin.ignore(); getline(cin, id);
                    lop.deleteByID(id);
                }

            } while (c != 0);
        }

        else if (choice == 3) {
            int c;
            do {
                cout << "\n--- MENU TKB ---\n";
                cout << "1. Nhap TKB\n";
                cout << "2. Xuat TKB\n";
                cout << "3. Tim buoi\n";
                cout << "0. Quay lai\n";
                cin >> c;

                if (c == 1) NhapDS(tkb, nTKB);
                else if (c == 2) XuatDS(tkb, nTKB);
                else if (c == 3) {
                    cin.ignore();
                    string buoi;
                    cout << "Nhap ten buoi: ";
                    getline(cin, buoi);
                    int k = LinearSearch(tkb, nTKB, buoi);
                    if (k != -1) tkb[k].Xuat();
                    else cout << "Khong tim thay!\n";
                }

            } while (c != 0);
        }

    } while (choice != 0);

    return 0;
}
