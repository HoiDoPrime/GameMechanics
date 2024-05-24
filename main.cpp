
#include "volamtruyenky.h"
#include<iostream>
using namespace std;

int main()
{
    DanhSach T;
    T.Nhap();
    cout << "==========================" << endl;
    cout<<"Nhap vao so thao tac: \n";
    int t;cin>>t;
    while(t){
    cout << "==========================" << endl;
    cout<<"NHAP VAO LUA CHON THAO TAC\n";
    cout<<"1.Thoat chuong trinh \n";
    cout<<"2.In ra thong tin danh sach \n";
    cout<<"3.Tim phan tu co muc sat thuong cao nhat \n";
    cout<<"4.Chon 2 phan tu de so sanh muc sat thuong \n";
    int t ; cin>>t;
    switch(t){
    case 1:
        return 0;
        break;

    case 2:
        T.Xuat();
        break;
    case 3:
        T.MAXDAME();
        break;
    case 4:
        T.SoSanhMucSatThuong();
        break;
    default:
        cout<<"Nhap vao khong hop le";
        break;

    }
    t--;
    }

    return 0;
}
