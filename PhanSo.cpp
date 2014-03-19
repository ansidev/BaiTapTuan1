#include "PhanSo.h"


//PhanSo::PhanSo(void)
//{
//}
//
//
//PhanSo::~PhanSo(void)
//{
//}

//Ham nhap phan so tu ban phim
void NhapPhanSo(PhanSo &psPhanSo, bool &bBienKiemTra)
{
    PhanSo psPhanSoTam;
    cout<<"Nhap tu so va mau so: ";

    //Nhap gia tri tu ban phim vao mot bien tam
    cin>>psPhanSoTam.iTuSo;
    cin>>psPhanSoTam.iMauSo;
    cin.clear();
    cin.sync();

    //Kiem tra tinh hop le cua cac gia tri nhap vao
    bBienKiemTra = KiemTraTinhHopLe(psPhanSoTam);
    
    //Neu gia tri nhap vao khong hop le thi xuat ra thong bao loi
    if(!bBienKiemTra)
    {
        cout<<"Loi: Mau so bang 0!"<<endl;
    }
    //Neu gia tri nhap vao hop le thi gan gia tri cho bien chinh
    else
    {
        psPhanSo = psPhanSoTam;
    }
}

//Ham kiem tra tinh hop le cua phan so nhap vao tu ban phim
bool KiemTraTinhHopLe(PhanSo psPhanSo)
{
    if(psPhanSo.iMauSo != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Ham xuat phan so ra man hinh
void XuatPhanSo(PhanSo psPhanSo)
{
    if(psPhanSo.iMauSo != 0)
    {
        cout<<psPhanSo.iTuSo<<"/"<<psPhanSo.iMauSo;
    }
}

//Ham rut gon mot phan so
PhanSo RutGonPhanSo(PhanSo psPhanSo)
{
    PhanSo psPhanSoToiGian = psPhanSo;
    //Bien tam de luu uoc chung lon nhat cua tu so va mau so cua mot phan so
    int iTemp = 1;
    //Tinh uoc chung lon nhat cua tu so va mau so
    iTemp = UCLN(psPhanSoToiGian.iTuSo, psPhanSoToiGian.iMauSo);

    if(iTemp == 1)
    {
        return psPhanSoToiGian;
    }
    else
    {
        //Rut gon phan so
        psPhanSoToiGian.iTuSo = psPhanSo.iTuSo / iTemp;
        psPhanSoToiGian.iMauSo = psPhanSo.iMauSo / iTemp;
        //Tra ve ket qua
        return psPhanSoToiGian;
    }
}

//Ham qui dong mau so cua hai phan so
void QuiDongPhanSo(PhanSo &psPhanSo1, PhanSo &psPhanSo2)
{
    //Rut gon 2 phan so truoc khi thuc hien qui dong mau so
    psPhanSo1 = RutGonPhanSo(psPhanSo1);
    psPhanSo2 = RutGonPhanSo(psPhanSo2);

    //Neu hai phan so toi gian khac mau so thi moi thuc hien qui dong
    if(psPhanSo1.iMauSo != psPhanSo2.iMauSo)
    {
        //Bien tam luu gia tri boi chung nho nhat cua hai mau so
        int iBCNN = 1;
        iBCNN = BCNN(psPhanSo1.iMauSo, psPhanSo2.iMauSo);
        psPhanSo1.iTuSo *= (iBCNN / psPhanSo1.iMauSo);
        psPhanSo1.iMauSo = iBCNN;
        psPhanSo2.iTuSo *= (iBCNN / psPhanSo2.iMauSo);
        psPhanSo2.iMauSo = iBCNN;
    }
}

//Ham so sanh hai phan so
void SoSanhPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    PhanSo psPhanSo3, psPhanSo4;
    psPhanSo3 = psPhanSo1;
    psPhanSo4 = psPhanSo2;
    QuiDongPhanSo(psPhanSo3, psPhanSo4);
    int iTemp = psPhanSo3.iTuSo - psPhanSo4.iTuSo;

    if(iTemp > 0)
    {
        XuatPhanSo(psPhanSo1);
        cout<<" > ";
        XuatPhanSo(psPhanSo2);
        cout<<endl;
    }

    if(iTemp == 0)
    {
        XuatPhanSo(psPhanSo1);
        cout<<" = ";
        XuatPhanSo(psPhanSo2);
        cout<<endl;
    }
    if(iTemp < 0)
    {
        XuatPhanSo(psPhanSo1);
        cout<<" < ";
        XuatPhanSo(psPhanSo2);
        cout<<endl;
    }
}

//Ham tim phan so lon nhat trong hai phan so
PhanSo TimPhanSoLonNhat(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    PhanSo psPhanSo3, psPhanSo4;
    psPhanSo3 = psPhanSo1;
    psPhanSo4 = psPhanSo2;
    QuiDongPhanSo(psPhanSo3, psPhanSo4);
    int iTemp = psPhanSo3.iTuSo - psPhanSo4.iTuSo;

    if(iTemp >= 0)
    {
        return psPhanSo1;
    }
    else
    {
        return psPhanSo2;
    }
}

//Ham tim phan so doi cua mot phan so
PhanSo TimPhanSoDoi(PhanSo psPhanSo)
{
    PhanSo psPhanSo1;
    if(psPhanSo.iMauSo > 0)
    {
        psPhanSo1.iTuSo = -1 * psPhanSo.iTuSo;
        psPhanSo1.iMauSo = psPhanSo.iMauSo;
    }
    if(psPhanSo.iMauSo < 0)
    {
        psPhanSo1.iTuSo = psPhanSo.iTuSo;
        psPhanSo1.iMauSo = -1 * psPhanSo.iMauSo;
    }
    return psPhanSo1;

}

//Ham nghich dao mot phan so
PhanSo NghichDaoPhanSo(PhanSo psPhanSo)
{
    PhanSo psPhanSo1;
    if(psPhanSo.iTuSo != 0)
    {
        if(psPhanSo.iTuSo < 0)
        {
            psPhanSo1.iTuSo = -1 * psPhanSo.iMauSo;
            psPhanSo.iMauSo = -1 * psPhanSo.iTuSo;
        }

        if(psPhanSo.iTuSo > 0)
        {
            psPhanSo1.iTuSo = psPhanSo.iMauSo;
            psPhanSo1.iMauSo = psPhanSo.iTuSo;
        }
    }
    return psPhanSo1;
}

//Ham tinh tong hai phan so
PhanSo TinhTongHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    PhanSo psPhanSo3, psPhanSo4;
    PhanSo psTong;
    psPhanSo3 = psPhanSo1;
    psPhanSo4 = psPhanSo2;
    QuiDongPhanSo(psPhanSo3, psPhanSo4);
    psTong.iTuSo = psPhanSo3.iTuSo + psPhanSo4.iTuSo;
    psTong.iMauSo = psPhanSo3.iMauSo;
    psTong = RutGonPhanSo(psTong);
    return psTong;
}

//Ham tinh hieu hai phan so
PhanSo TinhHieuHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    //Tinh hieu cua hai phan so bang cach
    //tinh tong cua phan so thu nhat va phan so doi cua phan so thu hai
    return TinhTongHaiPhanSo(psPhanSo1, TimPhanSoDoi(psPhanSo2));
}

//Ham tinh tich hai phan so
PhanSo TinhTichHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    PhanSo psPhanSo3, psPhanSo4;
    PhanSo psTich;
    psPhanSo3 = RutGonPhanSo(psPhanSo1);
    psPhanSo4 = RutGonPhanSo(psPhanSo2);
    psTich.iTuSo = psPhanSo3.iTuSo * psPhanSo4.iTuSo;
    psTich.iMauSo = psPhanSo3.iMauSo * psPhanSo4.iMauSo;
    psTich = RutGonPhanSo(psTich);
    return psTich;
}

//Ham tinh thuong hai phan so
PhanSo TinhThuongHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    PhanSo psThuong;
    if(psPhanSo2.iTuSo != 0)
    {
        //Tinh thuong cua hai phan so bang cach
        //tinh tich cua phan so thu nhat va phan so nghich dao cua phan so thu hai
        psThuong = TinhTichHaiPhanSo(psPhanSo1, NghichDaoPhanSo(psPhanSo2));
    }
    return psThuong;
}