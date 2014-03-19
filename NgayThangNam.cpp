#include "NgayThangNam.h"


//NgayThangNam::NgayThangNam(void)
//{
//}
//
//
//NgayThangNam::~NgayThangNam(void)
//{
//}

//Ham nhap ngay thang nam tu ban phim
void NhapNgayThangNam(NgayThangNam &ntnNgayThangNam, bool &bBienKiemTra)
{
    //Bien tam de luu gia tri ngay thang nam
    NgayThangNam ntnNgayThangNamTam;
    cout<<"Chi chap nhan nam co gia tri >= 1."<<endl;
    cout<<"Nhap ngay thang nam: ";
    cin>>ntnNgayThangNamTam.iNgay;
    cin>>ntnNgayThangNamTam.iThang;
    cin>>ntnNgayThangNamTam.iNam;
    cin.clear();
    cin.sync();
    bBienKiemTra = KiemTraTinhHopLe(ntnNgayThangNamTam);
    if(bBienKiemTra)
    {
        ntnNgayThangNam = ntnNgayThangNamTam;
    }
    else
    {
        cout<<"Gia tri nhap vao khong hop le!"<<endl;
    }
}

//Ham xuat ngay thang nam ra man hinh
//Bien string cDauPhanCach dung de dinh kieu dau phan cach giua ngay thang nam
void XuatNgayThangNam(NgayThangNam ntnNgayThangNam)
{
    char cDauPhanCach = '/';
    cout<<ntnNgayThangNam.iNgay<<cDauPhanCach<<ntnNgayThangNam.iThang<<cDauPhanCach<<ntnNgayThangNam.iNam;
}

//Ham kiem tra mot nam co phai la nam nhuan hay khong
bool KiemTraNamNhuan(int iNam)
{
    //Kiem tra nam nhuan
    //Nam nhuan la nam:
    //      Chia het cho 4 va khong chia het cho 100
    //      hoac
    //      Chia het cho 400
    if((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Ham kiem tra tinh hop le cua ngay thang nam nhap vao
bool KiemTraTinhHopLe(NgayThangNam &ntnNgayThangNam)
{
    bool bBienKiemTra;
    //Kiem tra khoang gia tri cua ngay, thang, nam nhap vao
    //Ngay nam trong khoang [1, 31].
    //Thang nam trong khoang [1, 12].
    //Nam phai lon hoac bang 1.

    //Tinh hop le cua thang va nam duoc kiem tra trong lenh nay
    if(ntnNgayThangNam.iNam >= 1 && (ntnNgayThangNam.iThang >= 1 && ntnNgayThangNam.iThang <= 12) && (ntnNgayThangNam.iNgay >= 1 && ntnNgayThangNam.iNgay <= 31))
    {
        ntnNgayThangNam.bNamNhuan = KiemTraNamNhuan(ntnNgayThangNam.iNam);

        //Mang chua so ngay toi da cua cac thang trong nam
        int arrSoNgayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        //Neu la thang 2 cua mot nam nhuan thi cap nhat so ngay trong thang 2 la 29 ngay
        if(ntnNgayThangNam.iThang == 2 && ntnNgayThangNam.bNamNhuan == true)
        {
            arrSoNgayTrongThang[2] = 29;
        }
        
        //Kiem tra tinh hop le cua ngay
        //Kiem tra ngay nhap vao co vuot qua so ngay toi da trong thang khong
        if(ntnNgayThangNam.iNgay >= 1 && ntnNgayThangNam.iNgay <= arrSoNgayTrongThang[ntnNgayThangNam.iThang])
        {
            bBienKiemTra = true;
        }
        else
        {
            bBienKiemTra = false;
        }

    }
    else
    {
        bBienKiemTra = false;
    }
    return bBienKiemTra;
}

//Ham tim ngay ke tiep cua mot ngay
NgayThangNam TimNgayKeTiep(NgayThangNam ntnNgayThangNam)
{
    //Mang chua so ngay toi da cua cac thang trong nam
    int arrSoNgayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //Bien chua ngay ke tiep cua ngay da khai bao
    NgayThangNam ntnNgayKeTiep = ntnNgayThangNam;

    //Neu la thang 2 cua mot nam nhuan thi cap nhat so ngay trong thang 2 la 29 ngay
    if(ntnNgayThangNam.iThang == 2 && ntnNgayThangNam.bNamNhuan == true)
    {
        arrSoNgayTrongThang[2] = 29;
    }
    //Tim ngay ke tiep
    //Neu la ngay cuoi cung trong thang thi ngay ke tiep la ngay 1 cua thang ke tiep
    if (ntnNgayKeTiep.iNgay == arrSoNgayTrongThang[ntnNgayKeTiep.iThang])
    {
        ntnNgayKeTiep.iNgay = 1;
        //Neu la ngay 31/12 thi thang ke tiep la thang 1 cua nam sau
        //Ngay da duoc thay doi trong cau lenh phia tren
        if(ntnNgayKeTiep.iThang == 12)
        {
            ntnNgayKeTiep.iThang = 1;
            ntnNgayKeTiep.iNam += 1;
            ntnNgayKeTiep.bNamNhuan = KiemTraNamNhuan(ntnNgayKeTiep.iNam);
        }
        else
        {
            //Neu khong phai la ngay 31/12
            //thi chi can tang gia tri thang len mot don vi
            ntnNgayKeTiep.iThang += 1;
        }
    }
    else
    {
        //Neu khong phai la ngay cuoi cung trong thang
        //thi chi can tang ngay them 1 don vi
        ntnNgayKeTiep.iNgay += 1;
    }
    return ntnNgayKeTiep;
}