#include <bits/stdc++.h>
using namespace std;
#define Max 100

struct HangHoa{
	char MaHang[10];
	char TenHang[20];
	char DVTinh[10];
	float DonGia;
	int SoLuong;
};

struct List{
	int count;
	HangHoa a[100];
};

void Create(List &L)
{
	L.count = -1;
}

int Full(List &L)
{
	return L.count == Max - 1;
}

int Empty(List L)
{
	return L.count == -1;
}

int Add(List &L, HangHoa x)
{
	if(Full(L))
		return 0;
	else
	{
		L.count++;
		L.a[L.count] = x;
		return 1;
	}
}

void Nhap(HangHoa &hh)
{
	cout << "Nhap ma hang: ";				fflush(stdin);				gets(hh.MaHang);
	cout << "Nhap ten hang: ";				fflush(stdin);				gets(hh.TenHang);
	cout << "Nhap don vi tinh: ";			fflush(stdin);				gets(hh.DVTinh);
	cout << "Nhap don gia: ";											cin >> hh.DonGia;
	cout << "Nhap so luong: ";											cin >> hh.SoLuong;
}

void Nhapds(List &L)
{
	Create(L);  // if list rong thi tao danh sach moi, neu khong thi chen them danh sach vao cuoi
	HangHoa x;
	int i = 1;
	do
	{
		cout << "Nhap thong tin ma hang thu " << i << endl;
		Nhap(x);
		if(strcmp(x.MaHang, "***") == 0)
		return;
		if (!Add(L, x))
		return;
		i++;
	}
	while(1);
}

void Xuat(List &L)
{
	cout << "Bang danh sach hang hoa" << endl;
	cout << setw(5) << "STT" << setw(15) << "Ma Hang" << setw(15) << "Ten Hang" << setw(15) << "DV Tinh" << setw(15) << "Don Gia" << setw(15) << "So Luong" << setw(15) << "Thanh Tien" << endl;
	for(int i = 0; i <= L.count; i++)
	{
		cout << setw(5) << i+1 << setw(15) << L.a[i].MaHang << setw(15) << L.a[i].TenHang << setw(15)
		<< L.a[i].DVTinh << setw(15) << L.a[i].DonGia << setw(15) << L.a[i].SoLuong << setw(15) << L.a[i].DonGia * L.a[i].SoLuong << endl;
	}
}

void timkiem(List L)
{
	if(Empty(L))
	{
		cout << "Danh sach rong, khong the tim kiem \n";
		return;
	}
	
	int SLmax = L.a[0].SoLuong, SLmin = L.a[0].SoLuong;
	int iMax = 0, iMin = 0;
	for(int i = 0; i <= L.count; i++)
	{
		if(L.a[i].SoLuong > SLmax)
		{
			SLmax = L.a[i].SoLuong;
			iMax = i;
		}
		if(L.a[i].SoLuong < SLmin)
		{
			SLmin = L.a[i].SoLuong;
			iMin = i;
		}
	}
	cout << "Mat hang co so luong lon nhat la " << L.a[iMax].TenHang << " = " << SLmax << endl;
	cout << "Mat hang co so luong nho nhat la " << L.a[iMin].TenHang <<  " = " << SLmin << endl;
}

void ThayTen(List &L)
{
	if(Empty(L))
	{
		cout << "Danh sach rong, không the thay doi";
		return;
	}
	char TenCu[20], TenMoi[20];
	bool TimThay = false;
	cout << "Nhap ten mat hang can thay the: ";			fflush(stdin);			gets(TenCu);
	for(int i = 0; i <= L.count; i++)
	{
		if(strcmp(L.a[i].TenHang, TenCu) == 0)
		{
			cout << "Nhap ten hang moi: ";				fflush(stdin);			gets(TenMoi);
			strcpy(L.a[i].TenHang, TenMoi);
			cout << "Cap nhat ten hang thanh cong";
			TimThay = true;
		}
	}
	if(!TimThay)
		cout << "Khong tim thay ten hang trong danh sach" << endl;
}	

void Dem(List L)
{
	int Giamax = L.a[0].DonGia;
	int dem = 0;
	for(int i = 0; i <= L.count; i++)
	{
		if(L.a[i].DonGia > Giamax)
			Giamax = L.a[i].DonGia;
	}
	for(int i = 0; i <= L.count; i++)
	{
		if(L.a[i].DonGia == Giamax)
			dem++;
	}
	cout << "So mat hang co don gia cao nhat = " << Giamax << " la: " << dem << endl;
}

void Xoa(List &L, int k)
{
	if(k <= L.count && k >= 0)
	{
		for(int i = k; i < L.count; i++)
			L.a[i] = L.a[i+1];
		L.count--;
	}
	else
		cout << "Khong xoa duoc" << endl;
}

void Xoamax(List &L)
{
	if(Empty(L))
	{
		cout << "Danh sach rong" << endl;
		return ;
	}
	int iMax = 0;
	for(int i = 0; i <= L.count; i++)
	{
		if(L.a[i].SoLuong > L.a[iMax].SoLuong)
			iMax = i;
	}
	Xoa(L, iMax);
}

void Xoamin(List &L)
{
	if(Empty(L))
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	int iMin = 0;
	for(int i = 0; i <= L.count; i++)
	{
		if(L.a[i].SoLuong < L.a[iMin].SoLuong)
			iMin = i;
	}
	Xoa(L, iMin);
}

void chen(List &L, int p){
	if(p <= L.count+1 && p >0){
		L.count++;
		for(int i = L.count; i >= p-1; i--)
			L.a[i] = L.a[i-1];
		cout << "Nhap ma hang hoa: ";				fflush(stdin);			gets(L.a[p-1].MaHang);
		cout << "Nhap ten hang: ";					fflush(stdin);			gets(L.a[p-1].TenHang);
		cout << "Nhap dv tinh: ";					fflush(stdin);			gets(L.a[p-1].DVTinh);
		cout << "Nhap don gia: ";											cin >> L.a[p-1].DonGia;
		cout << "Nhap so luong: ";											cin >> L.a[p-1].SoLuong;
	}
	else
		cout<<"Khong chen duoc!"<<endl;
}

void chenViTriThu3(List &L) 
{
    if (Full(L)) 
	{
        cout << "Danh sach day, khong the chen them!" << endl;
        return;
    }
    
    if (L.count >= 2) { 
        for(int i = L.count; i >= 2; i--) 
		{
            L.a[i] = L.a[i-1];
        }
        L.count++;
        cout << "Nhap ma hang hoa: "; 			fflush(stdin); 			gets(L.a[2].MaHang);
        cout << "Nhap ten hang: "; 				fflush(stdin); 			gets(L.a[2].TenHang);
        cout << "Nhap dv tinh: "; 				fflush(stdin); 			gets(L.a[2].DVTinh);
        cout << "Nhap don gia: "; 										cin >> L.a[2].DonGia;
        cout << "Nhap so luong: "; 										cin >> L.a[2].SoLuong;
    } 
	else 
        cout << "Khong du phan tu de chen vao vi tri thu 3!" << endl;
}

void chenDau(List &L) {
    if(Full(L)) 
	{
        cout << "Danh sach day, khong the chen them!" << endl;
        return;
    }
    for(int i = L.count; i >= 0; i--) {
        L.a[i] = L.a[i-1];
    }
    L.count++;
    cout << "Nhap ma hang hoa: "; 				fflush(stdin); 			gets(L.a[0].MaHang);
    cout << "Nhap ten hang: "; 					fflush(stdin); 			gets(L.a[0].TenHang);
    cout << "Nhap dv tinh: "; 					fflush(stdin); 			gets(L.a[0].DVTinh);
    cout << "Nhap don gia: "; 											cin >> L.a[0].DonGia;
    cout << "Nhap so luong: "; 											cin >> L.a[0].SoLuong;
}

void chenCuoi(List &L) {
    if(Full(L)) 
	{
        cout << "Danh sach day, khong the chen them!" << endl;
        return;
    }
	L.count++;
    cout << "Nhap ma hang hoa: ";         		fflush(stdin); 			gets(L.a[L.count].MaHang);
    cout << "Nhap ten hang: "; 					fflush(stdin); 			gets(L.a[L.count].TenHang);
    cout << "Nhap dv tinh: "; 					fflush(stdin); 			gets(L.a[L.count].DVTinh);
    cout << "Nhap don gia: "; 											cin >> L.a[L.count].DonGia;
    cout << "Nhap so luong: "; 											cin >> L.a[L.count].SoLuong;

}

void chenSauMaxSoLuong(List &L) {
    if(Full(L))
	{
        cout << "Danh sach day, khong the chen them!" << endl;
        return;
    }
    if(Empty(L)) 
	{
        cout << "Danh sach rong, khong the chen!" << endl;
        return;
    }
    int maxSL = L.a[0].SoLuong;
    int iMax = 0;
    for (int i = 1; i < L.count; i++) 
	{
        if (L.a[i].SoLuong > maxSL) 
		{
            maxSL = L.a[i].SoLuong;
            iMax = i;
        }
    }
    for (int i = L.count; i > iMax + 1; i--) 
	{
        L.a[i] = L.a[i-1];
    }
    L.count++;
    cout << "Nhap ma hang hoa: "; 				fflush(stdin); 			gets(L.a[iMax+1].MaHang);
    cout << "Nhap ten hang: "; 					fflush(stdin); 			gets(L.a[iMax+1].TenHang);
    cout << "Nhap dv tinh: "; 					fflush(stdin); 			gets(L.a[iMax+1].DVTinh);
    cout << "Nhap don gia: "; 											cin >> L.a[iMax+1].DonGia;
    cout << "Nhap so luong: "; 											cin >> L.a[iMax+1].SoLuong;
}

void chenSauMinSoLuong(List &L) {
    if(Full(L)) 
	{
        cout << "Danh sach day, khong the chen them!" << endl;
        return;
    }
    
    if(Empty(L))
    {
        cout << "Danh sach rong, khong the chen!" << endl;
        return;
    }
    int minSL = L.a[0].SoLuong;
    int iMin = 0;
    for (int i = 1; i < L.count; i++) {
        if (L.a[i].SoLuong < minSL) {
            minSL = L.a[i].SoLuong;
            iMin = i;
        }
    }
    for (int i = L.count; i > iMin + 1; i--) {
        L.a[i] = L.a[i-1];
    }
    L.count++;
    cout << "Nhap ma hang hoa: "; 			fflush(stdin); 			gets(L.a[iMin+1].MaHang);
    cout << "Nhap ten hang: "; 				fflush(stdin); 			gets(L.a[iMin+1].TenHang);
    cout << "Nhap dv tinh: "; 				fflush(stdin); 			gets(L.a[iMin+1].DVTinh);
    cout << "Nhap don gia: "; 										cin >> L.a[iMin+1].DonGia;
    cout << "Nhap so luong: "; 										cin >> L.a[iMin+1].SoLuong;
}

void sapXepChontang(List &L)
{    
	for(int i = 0; i < L.count; i++)
	{
		int m = i;
		for(int j = i+1; j < L.count+1; j++)
		if(L.a[j].DonGia*L.a[j].SoLuong < L.a[m].DonGia*L.a[m].SoLuong) 
			m = j;
		swap(L.a[i], L.a[m]);
	}
}

void sapXepChongiam(List &L)
{    
	for(int i = 0; i < L.count; i++)
	{
		int m = i;
		for(int j = i+1; j < L.count+1; j++)
		if(L.a[j].DonGia*L.a[j].SoLuong > L.a[m].DonGia*L.a[m].SoLuong) 
			m = j;
		swap(L.a[i], L.a[m]);
	}
}

void sapXepNoiBottang(List &L) {
    for(int i = 0; i <= L.count; i++) 
	{
        for (int j = 0; j < L.count - i; j++) 
		{
            float thanhTien1 = L.a[j].DonGia * L.a[j].SoLuong;
            float thanhTien2 = L.a[j + 1].DonGia * L.a[j + 1].SoLuong;
            
            if (thanhTien1 > thanhTien2) 
			{
                swap(L.a[j], L.a[j + 1]);
            }
        }
    }
}

void sapXepNoiBotgiam(List &L) {
    for(int i = 0; i <= L.count; i++) 
	{
        for (int j = 0; j < L.count - i; j++) 
		{
            float thanhTien1 = L.a[j].DonGia * L.a[j].SoLuong;
            float thanhTien2 = L.a[j + 1].DonGia * L.a[j + 1].SoLuong;
            
            if (thanhTien1 < thanhTien2) 
			{
                swap(L.a[j], L.a[j + 1]);
            }
        }
    }
}

void sapXepChentang(List &L) 
{
    for (int i = 1; i <= L.count; i++) 
	{
        HangHoa key = L.a[i];
        float thanhTienKey = key.DonGia * key.SoLuong;
        int j = i - 1;
        while (j >= 0 && (L.a[j].DonGia * L.a[j].SoLuong) > thanhTienKey) 
		{
            L.a[j + 1] = L.a[j];
            j--;
        }
        L.a[j + 1] = key;
    }
}

void sapXepChengiam(List &L) 
{
    for (int i = 1; i <= L.count; i++) 
	{
        HangHoa key = L.a[i];
        float thanhTienKey = key.DonGia * key.SoLuong;
        int j = i - 1;
        while (j >= 0 && (L.a[j].DonGia * L.a[j].SoLuong) < thanhTienKey) 
		{
            L.a[j + 1] = L.a[j];
            j--;
        }
        L.a[j + 1] = key;
    }
}

int main()
{
	List L;
	HangHoa x[100];
	Nhapds(L);
	cout << "================ Danh sach hang hoa vua nhap la =================== \n";
	Xuat(L);
//	timkiem(L);
//	ThayTen(L);
//	cout << "==================== Bang sau khi thay ten hang =====================" << endl;
//	Xuat(L);
//	Dem(L);
//	Xoamax(L);
//	cout << "============== Bang sau khi xoa phan tu co so luong lon nhat ============== " << endl;
//	Xuat(L);
//	Xoamin(L);
//	cout << "================= Bang sau khi xoa phan tu co so luong nho nhat ============== " << endl;
//	Xuat(L);
//	chenViTriThu3(L);
//	chenDau(L);
//	chenCuoi(L);
//	chenSauMaxSoLuong(L);
//	chenSauMinSoLuong(L);
//	cout << "==================== Bang sau khi chen them phan tu ================== " << endl;
//	Xuat(L); 
//	sapXepChontang(L);
//	sapXepNoiBottang(L);
	sapXepChentang(L);
	cout << "======================= Bang sau khi sap xep don gia tang dan ===========" << endl;
	Xuat(L);
//	sapXepChongiam(L);
//	sapXepNoiBotgiam(L);
//	sapXepChengiam(L);
//	cout << "======================= Bang sau khi sap xep don gia giam dan ===========" << endl;
//	Xuat(L);
	return 0;
}
