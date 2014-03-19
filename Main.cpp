#pragma region Thong tin tac gia
/////////////////////////////////////
//Tac gia: Le Minh Tri
//MSSV: 11520710
//Email: 11520710@gm.uit.edu.vn
//       ansidev@gmail.com
//Ngay cap nhat: 15/03/2014
/////////////////////////////////////
#pragma endregion

//#pragma region #include
//Headers
#include "PhanSo.h"
#include "NgayThangNam.h"
#include "HocSinh.h"

//Thu vien chuan
#include "system.h"
#include <iostream>
using namespace std;
//#pragma endregion

#pragma region MENU CHINH
//Ham cho phep lua chon bai tap
int LuaChonBaiTap()
{
    int iTongSoBaiTap = 5;
    int iLuaChon;
    //system("cls");
    cout<<"DANH SACH LUA CHON"<<endl;
    cout<<"0: Thoat chuong trinh."<<endl;
    for(int i = 1; i <= iTongSoBaiTap; i++)
    {
        cout<<i<<": Bai tap "<<i<<"."<<endl;
    }
    cout<<"Nhap so tuong ung voi lua chon."<<endl;
    cout<<"Lua chon: ";
    cin>>iLuaChon;
    cin.clear();
    cin.sync();
    return iLuaChon;
}
#pragma endregion

void main()
{
    //Khai bao bien
    PhanSo psPhanSo1, psPhanSo2, psPhanSo3, psPhanSo4, psPhanSo5;
    PhanSo psPhanSoToiGian;
    PhanSo psPhanSoLonNhat;
    PhanSo psTong, psHieu, psTich, psThuong;

    bool bBienKiemTra;
    
    NgayThangNam ntnNgayThangNam;
    NgayThangNam ntnNgayKeTiep;

    HocSinh hsHocSinh;
    float fDiemTrungBinh;

    int iLuaChon = 0; //Dung de lua chon bai tap

    do
    {
         iLuaChon = LuaChonBaiTap();
        switch(iLuaChon)
        {
            case 1:
                {
                    system("cls");
                    cout<<"================================================="<<endl;
                    cout<<"| BAI TAP 1: RUT GON PHAN SO                    |"<<endl;
                    cout<<"| 1. Viet chuong trinh:                         |"<<endl;
	                cout<<"|    1.1. Nhap vao mot phan so.                 |"<<endl;
	                cout<<"|    1.2. Rut gon phan so va xuat ket qua.      |"<<endl;
                    cout<<"================================================="<<endl;
                    cout<<endl;

                    // Chuong trinh rut gon phan so
                    NhapPhanSo(psPhanSo1, bBienKiemTra);
                    
                    //Neu phan so hop le thi moi thuc hien xuat gia tri ra man hinh
                    if(bBienKiemTra == true)
                    {
                        cout<<"Phan so vua nhap: ";
                        XuatPhanSo(psPhanSo1);
                        cout<<endl;
                        psPhanSoToiGian = RutGonPhanSo(psPhanSo1);
                        cout<<"Phan so sau khi rut gon: ";
                        XuatPhanSo(psPhanSoToiGian);
                        cout<<endl;
                        cout<<"Bai tap da duoc giai xong!"<<endl;
                    }

                    cout<<"================================================="<<endl;
                    cout<<endl;
                    cin.clear();
                    cin.sync();
                    break;
                }

            case 2:
                {
                    system("cls");
                    cout<<"================================================="<<endl;
                    cout<<"| BAI TAP 2: TIM PHAN SO LON NHAT               |"<<endl;
                    cout<<"| 2. Viet chuong trinh:                         |"<<endl;
	                cout<<"|    2.1. Nhap vao hai phan so.                 |"<<endl;
	                cout<<"|    2.2. Tim phan so lon nhat va xuat ket qua. |"<<endl;
                    cout<<"================================================="<<endl;
                    cout<<endl;

                    // Chuong trinh tim phan so lon nhat trong hai phan so
                    cout<<"Phan so thu nhat"<<endl;
                    NhapPhanSo(psPhanSo2, bBienKiemTra);

                    //Neu phan so hop le thi moi thuc hien xuat gia tri ra man hinh
                    if(bBienKiemTra == true)
                    {
                        cout<<"Phan so thu hai"<<endl;
                        NhapPhanSo(psPhanSo3, bBienKiemTra);

                        //Neu phan so hop le thi moi thuc hien xuat gia tri ra man hinh
                        if(bBienKiemTra == true)
                        {
                            psPhanSoLonNhat = TimPhanSoLonNhat(psPhanSo2, psPhanSo3);
                            cout<<"Phan so lon nhat:"<<endl;
                            XuatPhanSo(psPhanSoLonNhat);
                            cout<<endl;
                            cout<<"Bai tap da duoc giai xong!"<<endl;
                        }
                    }

                    cout<<"================================================="<<endl;
                    cout<<endl;
                    cin.clear();
                    cin.sync();
                    break;
                }

            case 3:
                {
                    system("cls");
                    cout<<"================================================="<<endl;
                    cout<<"| BAI TAP 3:                                    |"<<endl; 
                    cout<<"| TINH TONG, HIEU, TICH, THUONG CUA 2 PHAN SO   |"<<endl;
                    cout<<"| 3. Viet chuong trinh:                         |"<<endl;
	                cout<<"|    3.1. Nhap vao hai phan so.                 |"<<endl;
	                cout<<"|    3.2. Tinh tong, hieu, tich, thuong         |"<<endl;
                    cout<<"|         giua chung va xuat ket qua.           |"<<endl;
                    cout<<"================================================="<<endl;
                    cout<<endl;

                    // Chuong trinh tinh tong, hieu, tich, thuong cua hai phan so
                    cout<<"Phan so thu nhat"<<endl;
                    NhapPhanSo(psPhanSo4, bBienKiemTra);

                    //Neu phan so hop le thi moi thuc hien xuat gia tri ra man hinh
                    if(bBienKiemTra == true)
                    {
                        cout<<"Phan so thu hai"<<endl;
                        NhapPhanSo(psPhanSo5, bBienKiemTra);

                        //Neu phan so hop le thi moi thuc hien xuat gia tri ra man hinh
                        if(bBienKiemTra == true)
                        {
                            psTong = TinhTongHaiPhanSo(psPhanSo4, psPhanSo5);
                            psHieu = TinhHieuHaiPhanSo(psPhanSo4, psPhanSo5);
                            psTich = TinhTichHaiPhanSo(psPhanSo4, psPhanSo5);
                            psThuong = TinhThuongHaiPhanSo(psPhanSo4, psPhanSo5);
                            cout<<"Ket qua:"<<endl;
                            cout<<"Tong = ";
                            XuatPhanSo(psTong);
                            cout<<endl;
                            cout<<"Hieu = ";
                            XuatPhanSo(psHieu);
                            cout<<endl;
                            cout<<"Tich = ";
                            XuatPhanSo(psTich);
                            cout<<endl;
                            cout<<"Thuong = ";
                            XuatPhanSo(psThuong);
                            cout<<endl;
                            cout<<endl;
                            cout<<"Bai tap da duoc giai xong!"<<endl;
                        }
                    }

                    cout<<"================================================="<<endl;
                    cout<<endl;
                    cin.clear();
                    cin.sync();
                    break;
                }

            case 4:
                {
                    system("cls");
                    cout<<"================================================="<<endl;
                    cout<<"| BAI TAP 4:                                    |"<<endl; 
                    cout<<"| TIM NGAY KE TIEP                              |"<<endl;
                    cout<<"| 4. Viet chuong trinh:                         |"<<endl;
	                cout<<"|    4.1. Nhap vao mot ngay.                    |"<<endl;
	                cout<<"|    4.2. Tim ngay ke tiep va xuat ket qua.     |"<<endl;
                    cout<<"================================================="<<endl;
                    cout<<endl;

                    // Chuong trinh tim ngay ke tiep cua mot ngay
                    NhapNgayThangNam(ntnNgayThangNam, bBienKiemTra);

                    if(bBienKiemTra == true)
                    {
                        //Nhap ngay thang nam
                        cout<<"Ngay thang nam vua nhap: ";
                        XuatNgayThangNam(ntnNgayThangNam);
                        cout<<endl;
                        //Tim ngay ke tiep
                        ntnNgayKeTiep = TimNgayKeTiep(ntnNgayThangNam);
                        cout<<"Ngay ke tiep cua ngay vua nhap: ";
                        XuatNgayThangNam(ntnNgayKeTiep);
                        cout<<endl;
                        cout<<"Bai tap da duoc giai xong!"<<endl;
                    }

                    cout<<"================================================="<<endl;
                    cout<<endl;
                    cin.clear();
                    cin.sync();
                    break;
                }

            case 5:
                {
                    system("cls");
                    cout<<"================================================="<<endl;
                    cout<<"| BAI TAP 5:                                    |"<<endl; 
                    cout<<"| TINH DIEM TRUNG BINH                          |"<<endl;
                    cout<<"| 5. Viet chuong trinh:                         |"<<endl;
	                cout<<"|    5.1. Nhap ho ten,                          |"<<endl;
                    cout<<"|         diem Toan va Van cua mot hoc sinh.    |"<<endl;
	                cout<<"|    5.2. Tinh diem trung binh va xuat ket qua. |"<<endl;
                    cout<<"================================================="<<endl;
                    cout<<endl;

                    // Chuong trinh tinh diem trung binh cua hoc sinh
                    //Nhap ho va ten, diem Toan va diem Van
                    NhapTongHop(hsHocSinh, bBienKiemTra);

                    //Neu diem hop le thi moi thuc hien tinh diem trung binh
                    //va xuat ket qua ra man hinh
                    if(bBienKiemTra == true)
                    {
                        //Xuat diem toan va diem Van cua hoc sinh ra man hinh
                        cout<<"Diem Toan va diem Van cua hoc sinh ";
                        XuatHoVaTen(hsHocSinh);
                        cout<<endl;
                        cout<<"Diem Toan: ";
                        XuatDiem(hsHocSinh.fDiemToan);
                        cout<<endl;
                        cout<<"Diem Van: ";
                        XuatDiem(hsHocSinh.fDiemVan);
                        cout<<endl;
                        //Tinh diem trung binh cua hoc sinh
                        fDiemTrungBinh = TinhDiemTrungBinh(hsHocSinh);
                        cout<<"Diem trung binh cua hoc sinh ";
                        XuatHoVaTen(hsHocSinh);
                        cout<<": ";
                        XuatDiem(hsHocSinh.fDiemTrungBinh);
                        cout<<endl;
                        cout<<"Bai tap da duoc giai xong!"<<endl;
                    }

                    cout<<"================================================="<<endl;
                    cout<<endl;
                    cin.clear();
                    cin.sync();
                    break;
                }

            //case -1:
            //    {
            //        system("cls");
            //        cout<<"================================================="<<endl;
            //        cout<<"| SO SANH HAI PHAN SO                           |"<<endl;
            //        cout<<"| 2. Viet chuong trinh:                         |"<<endl;
            //        cout<<"|    2.1. Nhap vao hai phan so.                 |"<<endl;
            //        cout<<"|    2.2. So sanh hai phan so va xuat ket qua.  |"<<endl;
            //        cout<<"================================================="<<endl;
            //        cout<<endl;

            //        // Chuong trinh tim phan so lon nhat trong hai phan so
            //        cout<<"Phan so thu nhat"<<endl;
            //        NhapPhanSo(psPhanSo2);
            //        cout<<"Phan so thu hai"<<endl;
            //        NhapPhanSo(psPhanSo3);
            //        SoSanhPhanSo(psPhanSo2, psPhanSo3);
            //        cout<<endl;
            //        cout<<"Bai tap da duoc giai xong!"<<endl;
            //        cout<<"================================================="<<endl;
            //        cout<<endl;
            //        cin.clear();
            //        cin.sync();
            //        break;
            //    }

            case 0:
                {
                    system("cls");
                    cout<<"Dang thoat chuong trinh..."<<endl;
                    cin.clear();
                    cin.sync();
                    break;
                }
            default:
                {
                    cin.clear();
                    cin.sync();
                    break;
                }
        }
    }
    while(iLuaChon != 0);
    //while(iLuaChon == 1 || iLuaChon == 2 || iLuaChon == 3 || iLuaChon == 4 || iLuaChon == 5);
    system("pause");
}
