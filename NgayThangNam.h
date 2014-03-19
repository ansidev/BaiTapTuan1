#pragma region Khai bao thu vien
//Header

//Thu vien chuan
#include <iostream>
//#include <ctime>
using namespace std;
#pragma endregion

//#pragma once
//class NgayThangNam
//{
//public:
//    NgayThangNam(void);
//    ~NgayThangNam(void);
//};

#pragma region Dinh nghia struct NgayThangNam
struct NgayThangNam
{
    //Du lieu
    int iNgay;          //Ngay
    int iThang;         //Thang
    int iNam;           //Nam
    bool bNamNhuan;     //Cho biet nam nhuan hay khong

    //Khoi tao
    //NgayThangNam()
    //{
    //    iNgay = 1;
    //    iThang = 1;
    //    iNam = 2014;
    //    bNamNhuan = false;
    //}
};
#pragma endregion

#pragma region Khai bao Prototypes
void NhapNgayThangNam(NgayThangNam &ntnNgayThangNam, bool &bBienKiemTra);   //Ham nhap ngay thang nam tu ban phim
void XuatNgayThangNam(NgayThangNam ntnNgayThangNam);                        //Ham xuat ngay thang nam ra man hinh
bool KiemTraTinhHopLe(NgayThangNam &ntnNgayThangNam);                       //Ham xuat phan so ra man hinh
bool KiemTraNamNhuan(int iNam);                                             //Ham kiem tra mot nam co phai la nam nhuan hay khong
NgayThangNam TimNgayKeTiep(NgayThangNam ntnNgayThangNam);                   //Ham tim ngay ke tiep cua mot ngay
#pragma endregion