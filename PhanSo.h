#pragma region Khai bao thu vien
//Headers
#include "SoHoc.h"                      //Chua ham tim uoc so chung lon nhat
//Thu vien chuan
#include <iostream>
using namespace std;
#pragma endregion
//#pragma once
//class PhanSo
//{
//public:
//    PhanSo(void);
//    ~PhanSo(void);
//};

#pragma region Dinh nghia struct PhanSo
struct PhanSo
{
    //Du lieu
    int iTuSo;  //Tu so
    int iMauSo; //Mau so

    //Khoi tao
    //PhanSo()
    //{
    //    iTuSo = 0;
    //    iMauSo = 1;
    //}
};
#pragma endregion

#pragma region Khai bao Prototypes
void NhapPhanSo(PhanSo &psPhanSo, bool &bBienKiemTra);          //Ham nhap phan so tu ban phim
bool KiemTraTinhHopLe(PhanSo psPhanSo);                        //Ham kiem tra tinh hop le cua phan so nhap vao
void XuatPhanSo(PhanSo psPhanSo);                               //Ham xuat phan so ra man hinh
PhanSo RutGonPhanSo(PhanSo psPhanSo);                           //Ham rut gon mot phan so
PhanSo TimPhanSoDoi(PhanSo psPhanSo);                           //Ham tim phan so doi cua mot phan so
PhanSo NghichDaoPhanSo(PhanSo psPhanSo);                        //Ham tim phan so nghich dao cua mot phan so
void QuiDongPhanSo(PhanSo &psPhanSo1, PhanSo &psPhanSo2);       //Ham qui dong mau so cua hai phan so
void SoSanhPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2);          //Ham so sanh hai phan so 
PhanSo TimPhanSoLonNhat(PhanSo psPhanSo1, PhanSo psPhanSo2);    //Ham tim phan so lon nhat trong hai phan so 
PhanSo TinhTongHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2);   //Ham tinh tong hai phan so
PhanSo TinhHieuHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2);   //Ham tinh hieu hai phan so
PhanSo TinhTichHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2);   //Ham tinh tich hai phan so
PhanSo TinhThuongHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2); //Ham tinh thuong hai phan so
#pragma endregion


