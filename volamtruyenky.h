#pragma once
#include<iostream>
#include<vector>
#include<string> // Include the string header
using namespace std;

class NguHanh {
public:
    NguHanh() {}
    virtual ~NguHanh() {} // Make the destructor virtual
    virtual int phanloai() = 0;
    virtual double sinhkhac(NguHanh *x) = 0;
};

class Kim : public NguHanh {
public:
    int phanloai() override {
        return 1;
    }
    double sinhkhac(NguHanh *x) override {
        if (x->phanloai() == 3) {
            return 0.1;
        } else if (x->phanloai() == 4) {
            return -0.2;
        } else if (x->phanloai() == 2) {
            return 0.2;
        } else return 0;
    }
};

class Moc : public NguHanh {
public:
    int phanloai() override {
        return 2;
    }
    double sinhkhac(NguHanh *x) override {
        if (x->phanloai() == 4) {
            return 0.1;
        } else if (x->phanloai() == 5) {
            return 0.2;
        } else if (x->phanloai() == 1) {
            return -0.2;
        } else return 0;
    }
};

class Thuy : public NguHanh {
public:
    int phanloai() override {
        return 3;
    }
    double sinhkhac(NguHanh *x) override {
        if (x->phanloai() == 2) {
            return 0.1;
        } else if (x->phanloai() == 4) {
            return 0.2;
        } else if (x->phanloai() == 5) {
            return -0.2;
        } else return 0;
    }
};

class Hoa : public NguHanh {
public:
    int phanloai() override {
        return 4;
    }
    double sinhkhac(NguHanh *x) override {
        if (x->phanloai() == 5) {
            return 0.1;
        } else if (x->phanloai() == 1) {
            return 0.2;
        } else if (x->phanloai() == 3) {
            return -0.2;
        } else return 0;
    }
};

class Tho : public NguHanh {
public:
    int phanloai() override {
        return 5;
    }
    double sinhkhac(NguHanh *x) override {
        if (x->phanloai() == 1) {
            return 0.1;
        } else if (x->phanloai() == 3) {
            return 0.2;
        } else if (x->phanloai() == 2) {
            return -0.2;
        } else return 0;
    }
};

class Character {
protected:
    double level, dame;
    string name, tenmonphai, tenhe_str; // Changed the name of this string to avoid conflict with the NguHanh pointer
    NguHanh *tenhe;
public:
    Character() : level(0), dame(0), tenhe(nullptr) {} // Initialize variables properly
    virtual ~Character() {
        delete tenhe; // Ensure proper cleanup of dynamically allocated memory
    }
    virtual void Nhap() {
        cin.ignore(); // Added to ignore newline left in the buffer
        cout << "Nhap vao ten: ";
        getline(cin, name);
        cout << "Nhap vao level: ";
        cin >> level;
        cout << "1.Kim \n2.Moc \n3.Thuy \n4.Hoa \n5.Tho \n";
        cout << "Nhap vao he: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                tenhe = new Kim;
                tenhe_str = "Kim";
                cout<<"Chon ten mon phai.\n";
                cout<<"1.Thieu Lam \n2.Thien Vuong Bang \n";
                int t;cin>>t;
                if(t==1){
                    tenmonphai="Thieu Lam";
                }
                else if(t==2){
                    tenmonphai="Thien Vuong Bang";
                }
                else tenmonphai="";
                break;
            case 2:
                tenhe = new Moc;
                tenhe_str = "Moc";
                cout<<"Chon ten mon phai.\n";
                cout<<"1.Ngu Doc Giao \n2.Duong Mon \n";
                int t1;cin>>t1;
                if(t1==1){
                    tenmonphai="Ngu Doc Giao";
                }
                else if(t1==2){
                    tenmonphai="Duong Mon";
                }
                else tenmonphai="";
                break;
            case 3:
                tenhe = new Thuy;
                tenhe_str = "Thuy";
                cout<<"Chon ten mon phai.\n";
                cout<<"1.Nga My \n2.Thuy Yen Mon \n";
                int t2;cin>>t2;
                if(t2==1){
                    tenmonphai="Nga My";
                }
                else if(t2==2){
                    tenmonphai="Thuy Yen Mon";
                }
                else tenmonphai="";
                break;
            case 4:
                tenhe = new Hoa;
                tenhe_str = "Hoa";
                cout<<"Chon ten mon phai.\n";
                cout<<"1.Cai Bang \n2.Thien Nhan Giao \n";
                int t3;cin>>t3;
                if(t3==1){
                    tenmonphai="Cai Bang";
                }
                else if(t3==2){
                    tenmonphai="Thien Nhan Giao";
                }
                else tenmonphai="";
                break;
            case 5:
                tenhe = new Tho;
                tenhe_str = "Tho";
                cout<<"Chon ten mon phai.\n";
                cout<<"1.Con Lon \n2.Vo Dang \n";
                int t4;cin>>t4;
                if(t4==1){
                    tenmonphai="Con Lon";
                }
                else if(t4==2){
                    tenmonphai="Vo Dang";
                }
                else tenmonphai="";

                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                tenhe = nullptr;
                break;
        }
    }
    virtual void Xuat() {
        cout << "Ten nhan vat: " << name << endl;
        cout << "Level cua nhan vat: " << level << endl;
        cout << "Sat thuong cua nhan vat: " << mucsatthuong() <<endl;
        cout << "He cua nhan vat: " << tenhe_str << endl;
        cout << "Mon phai cua nhan vat: " << tenmonphai << endl;

    }
    virtual double mucsatthuong() {
        return 0;
    }
    NguHanh* getHe(){
        return tenhe;
    }
    double SucTanCong(Character *Temp){
        double satthuong = mucsatthuong();
        return satthuong+tenhe->sinhkhac(Temp->getHe());
    }
    string getName(){
        return name;


    }
};

class NhanVat : public Character {
public:
    double mucsatthuong() override {
        return level * 5;
    }
};

class QuaiThuong : public Character {
public:
    double mucsatthuong() override {
        return level * 3;
    }
};

class QuaiDauLinh : public Character {
public:
    double mucsatthuong() override {
        return level * 7;
    }
};

class DanhSach {
protected:
    vector<Character*> DS;
public:
    void Nhap() {
        cout << "==========================" << endl;
        cout << "Nhap so luong Nhan Vat va Quai Vat: ";
        int SoLuong;cin>>SoLuong;
        for (int i = 0; i < SoLuong; i++) {
            Character *charac;
            cout << "==========================" << endl;
            cout << "Nhap vao thong tin phan tu thu "<<i+1<<endl;
            cout << "1.Nhan Vat \n2.Quai Thuong \n3.Quai Dau Linh \n";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    charac = new NhanVat;
                    break;
                case 2:
                    charac = new QuaiThuong;
                    break;
                case 3:
                    charac = new QuaiDauLinh;
                    break;
                default:
                    cout << "Lua chon khong hop le!" << endl;
                    continue;
            }
            charac->Nhap();
            DS.push_back(charac);
        }
    }

     void Xuat() {
        cout << "==========================" << endl;
        cout << "DANH SÁCH NHÂN VẬT VÀ QUÁI VẬT" << endl;
        for(const auto& t : DS) {
            cout << "------------------------------" << endl;
            t->Xuat();
            cout << "------------------------------" << endl;
        }
        cout << "==========================" << endl;
    }
    void SoSanhMucSatThuong(){
    bool check = true;
    do {
        int t1, t2;

        cout << "Nhap vao vi tri can so sanh: "; cin >> t1;
        cout << "Nhap vao vi tri can so sanh: "; cin >> t2;

        if (t1 < 0 || t2 < 0 || t1 >= DS.size() || t2 >= DS.size()) {
            cout << "Nhap vao khong hop le";
            check = false;
        } else {
            double x = DS[t1]->SucTanCong(DS[t2]) - DS[t2]->SucTanCong(DS[t1]);
            cout << "Muc sat thuong phan tu " << t1 << " gay cho phan tu " << t2 << " la: " << DS[t1]->SucTanCong(DS[t2]) << endl;
            cout << "Muc sat thuong phan tu " << t2 << " gay cho phan tu " << t1 << " la: " << DS[t2]->SucTanCong(DS[t1]) << endl;
            if (x > 0) {
                cout << DS[t1]->getName() << " CHIEN THANG " << DS[t2]->getName();
            } else if (x < 0) {
                cout << DS[t2]->getName() << " CHIEN THANG " << DS[t1]->getName();
            } else {
                cout << "HOA NHAU\n";
            }
            break;
        }
    } while (!check);
}

    void MAXDAME(){
        Character *temp=nullptr;
        double maxdame=0;
        for(const auto&charac:DS){
            if(charac->mucsatthuong()>maxdame){
                temp = charac;
                maxdame=charac->mucsatthuong();
            }
        }
        cout<<"Thong tin phan tu co muc sat thuong cao nhat: \n";
        temp->Xuat();
    }
    ~DanhSach() {
        for(const auto &charac:DS){
                delete charac;

        }
    }
};
