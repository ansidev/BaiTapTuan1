#include "HocSinh.h"

//HocSinh::HocSinh(void)
//{
//}
//
//
//HocSinh::~HocSinh(void)
//{
//}

//Ham nhap ho va ten, diem trung binh cua hoc sinh
void NhapTongHop(HocSinh &hsHocSinh, bool &bBienKiemTra)
{
    NhapHoTen(hsHocSinh);
    NhapDiem(hsHocSinh, bBienKiemTra);
}

//Ham nhap ho va ten cua hoc sinh
void NhapHoTen(HocSinh &hsHocSinh)
{
    cout<<"Nhap ho va ten cua hoc sinh"<<endl;
    cout<<"Ho: ";
    cin>>hsHocSinh.sHo;
    cin.clear();
    cin.sync();
    cout<<"Ten dem: ";
    getline(cin, hsHocSinh.sTenDem, '\n');
    cout<<"Ten: ";
    cin>>hsHocSinh.sTen;
    cin.clear();
    cin.sync();
}

//Ham nhap diem cua mot hoc sinh
void NhapDiem(HocSinh &hsHocSinh, bool &bBienKiemTra)
{
    //Bien tam de luu diem
    float fDiemToanTam, fDiemVanTam;

    //Nhap diem Toan
    cout<<"Nhap diem"<<endl;
    cout<<"Diem Toan: ";
    cin>>fDiemToanTam;
    cin.clear();
    cin.sync();
    //Kiem tra tinh hop le cua diem Toan
    bBienKiemTra = KiemTraTinhHopLeCuaDiem(fDiemToanTam);

    //Neu diem Toan khong hop le thi xuat thong bao loi ra man hinh va ket thuc
    //Neu diem Toan hop le thi tiep tuc nhap diem Van
    if(!bBienKiemTra)
    {
        cout<<"Diem nhap vao khong hop le!"<<endl;
    }
    else
    {
        //Nhap diem Van
        cout<<"Diem Van: ";
        cin>>fDiemVanTam;
        cin.clear();
        cin.sync();

        //Kiem tra tinh hop le cua diem Van
        bBienKiemTra = bBienKiemTra && KiemTraTinhHopLeCuaDiem(fDiemVanTam);
        
        //Neu diem Van khong hop le thi xuat thong bao loi ra man hinh va ket thuc
        //Neu diem Van hop le thi moi chinh thuc nhap diem cho hoc sinh
        if(!bBienKiemTra)
        {
            cout<<"Diem nhap vao khong hop le!"<<endl;
        }
        else
        {
            hsHocSinh.fDiemToan = fDiemToanTam;
            hsHocSinh.fDiemVan  = fDiemVanTam;
        }
    }
}

//Ham xuat ho ten cua mot hoc sinh ra man hinh
void XuatHoVaTen(HocSinh hsHocSinh)
{
    cout<<hsHocSinh.sHo<<" "<<hsHocSinh.sTenDem<<" "<<hsHocSinh.sTen;
}

//Ham xuat diem cua mot hoc sinh ra man hinh
void XuatDiem(float fDiem)
{
    cout<<fDiem;
}

//Ham kiem tra tinh hop le cua diem
bool KiemTraTinhHopLeCuaDiem(float fDiem)
{
    //Neu diem lon hon hoac bang 0 va be hon hoac bang 10 thi tra ve gia tri true
    //Nguoc lai, tra ve gia tri false
    bool bBienKiemTra = (fDiem >= 0 && fDiem <= 10) ? true:false;
    return bBienKiemTra;
}

//Ham tinh diem trung binh cua hoc sinh
float TinhDiemTrungBinh(HocSinh &hsHocSinh)
{
    float fDiemTrungBinhLamTron;
    hsHocSinh.fDiemTrungBinh = (hsHocSinh.fDiemToan + hsHocSinh.fDiemVan) / 2;
    fDiemTrungBinhLamTron = static_cast<long int> (hsHocSinh.fDiemTrungBinh * 10 + 0.5) / 10.0;
    hsHocSinh.fDiemTrungBinh = fDiemTrungBinhLamTron;
    return fDiemTrungBinhLamTron;
}