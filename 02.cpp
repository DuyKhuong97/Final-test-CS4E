#include <iostream>
#include <string>
using namespace std;

class Vemaybay {
    string tenchuyen;
    string ngaybay;
    double giave;

public:
    Vemaybay() {
        tenchuyen = "";
        ngaybay = "";
        giave = 0.0;
    }

    double getgiave() {
        return giave;
    }

    void Nhap() {
        cout << "Nhap ten chuyen: ";
        getline(cin, tenchuyen);
        cout << "Nhap ngay bay: ";
        getline(cin, ngaybay);
        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    void Xuat() {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }
};

class Nguoi {
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi() {
        hoten = "";
        gioitinh = "";
        tuoi = 0;
    }

    void Nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class Hanhkhach : public Nguoi {
    Vemaybay* ve;
    int soluong;

public:
    Hanhkhach() {
        ve = nullptr;
        soluong = 0;
    }

    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;

        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; i++) {
            cout << "Nhap thong tin ve thu " << i + 1 << endl;
            ve[i].Nhap();
        }
    }

    void Xuat() {
        Nguoi::Xuat();
        cout << "Danh sach ve:" << endl;
        for (int i = 0; i < soluong; i++) {
            cout << "Thong tin ve thu " << i + 1 << endl;
            ve[i].Xuat();
        }
    }

    double tongtien() {
        double sum = 0.0;
        for (int i = 0; i < soluong; i++) {
            sum += ve[i].getgiave();
        }
        return sum;
    }
};

int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    cin.ignore();

    Hanhkhach* danhSachHanhKhach = new Hanhkhach[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hanh khach thu " << i + 1 << endl;
        danhSachHanhKhach[i].Nhap();
    }

    cout << "Danh sach hanh khach va so tien phai tra tuong ung:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Hanh khach thu " << i + 1 << endl;
        danhSachHanhKhach[i].Xuat();
        cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (danhSachHanhKhach[i].tongtien() < danhSachHanhKhach[j].tongtien()) {
                Hanhkhach temp = danhSachHanhKhach[i];
                danhSachHanhKhach[i] = danhSachHanhKhach[j];
                danhSachHanhKhach[j] = temp;
            }
        }
    }

    cout << "Danh sach hanh khach sau khi sap xep theo chieu giam dan cua Tong tien:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Hanh khach thu " << i + 1 << endl;
        danhSachHanhKhach[i].Xuat();
        cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
        cout << endl;
    }

    delete[] danhSachHanhKhach;

    return 0;
}