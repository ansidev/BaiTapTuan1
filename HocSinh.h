#pragma region Khai bao thu vien
//Header

//Thu vien chuan
#include <iostream>
#include <string>
using namespace std;
#pragma endregion

//#pragma once
//class HocSinh
//{
//public:
//    HocSinh(void);
//    ~HocSinh(void);
//};
//

#pragma region Dinh nghia struct HocSinh
struct HocSinh
{
    std::string sHo;        //Ho
    std::string sTenDem;    //Ten dem
    std::string sTen;       //Ten
    float fDiemToan;        //Diem Toan
    float fDiemVan;         //Diem Van
    float fDiemTrungBinh;   //Diem trung binh
};
#pragma endregion

#pragma region Khai bao Prototype
void NhapTongHop(HocSinh &hsHocSinh, bool &bBienKiemTra);       //Ham nhap ho va ten, diem trung binh cua hoc sinh
void NhapHoTen(HocSinh &hsHocSinh);                             //Ham nhap ho va ten cua hoc sinh
void NhapDiem(HocSinh &hsHocSinh, bool &bBienKiemTra);          //Ham nhap diem cua mot hoc sinh
void XuatHoVaTen(HocSinh hsHocSinh);                            //Ham xuat ho ten cua mot hoc sinh ra man hinh
void XuatDiem(float fDiem);                                     //Ham xuat diem cua mot hoc sinh ra man hinh
bool KiemTraTinhHopLeCuaDiem(float fDiemToan);                  //Ham kiem tra tinh hop le cua diem
float TinhDiemTrungBinh(HocSinh &hsHocSinh);                    //Ham tinh diem trung binh cua hoc sinh
#pragma endregion