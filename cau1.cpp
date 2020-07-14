//#include<iostream>
//#include<iomanip>
//#include<cstdlib>
//#include<vector>
//#include<string>
//#include<fstream>
//using namespace std;
//
//class SanPham
//{
//private:
//	
//	string TenHang;
//	
//public:
//	long GiaTien;
//	int MaHang;
//	int SoLuong;
//	void Nhap()
//	{
//		cout << "nhap ma hang:";
//		cin >> MaHang;
//		cout << "nhap ten hang:";
//		cin.ignore(); 
//		getline(cin, TenHang);
//		cout << "nhap gia tien:";
//		cin >> GiaTien;
//		cout << "nhap so luong:";
//		cin >> SoLuong;
//	}
//	void Xuat()
//	{
//		cout<< setw(20) << MaHang << setw(20) <<TenHang << setw(20) << GiaTien << setw(20) <<SoLuong<<setw(20);
//	}
//	void xuatfile(ofstream &file)
//	{
//		file << "\n" << MaHang << "\t" << TenHang << "\t" << GiaTien << "\t" << SoLuong << "\t";
//	}
//	friend istream& operator >>(istream& is, SanPham &_sp)
//	{
//		_sp.Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, SanPham &_sp)
//	{
//		_sp.Xuat();
//		return os;
//	}
//};
//class Menu
//{
//private:
//	int n,w=0;
//	vector<SanPham> sp;
//	vector<SanPham> sp1;
//	vector<SanPham> mua;
//public:
//	void Nhap()
//	{
//		cout << "nhap so san pham:";
//		cin >> n;
//		sp.resize(n);	
//		for (int i = 0; i < sp.size(); i++)
//		{
//			SanPham sanPham;
//			cin >> sanPham;
//			sp[i] = sanPham;
//		}
//	}
//	void Xuat()
//	{
//		cout << "\n\t\t\t============DANH SACH SAN PHAM============\n";
//		cout <<"\n"<< setw(20) << "Ma Hang" << setw(20) << "Ten Hang" << setw(20) << "Gia Tien" << setw(20) << "So Luong"<<setw(20)<<"\n";
//		for (int i = 0; i < sp.size(); i++)
//		{
//			cout << sp[i];
//			cout << "\n";
//		}
//		system("pause");
//	}
//	void chensl()
//	{
//		int n,e;
//		cout << "nhap ma hang can them:";
//		cin >> n;
//		cout << "nhap so luong can them:";
//		cin >> e;
//		for (int i = 0; i < sp.size(); i++)
//		{
//			if (sp[i].MaHang == n)
//				sp[i].SoLuong = sp[i].SoLuong + e;
//		}
//	}
//	void Muahang()
//	{
//			int d, e;
//			cout << "nhap ma hang can mua:";
//			cin >> d;
//			cout << "nhap so luong:";
//			cin >> e;
//			for (int j = 0; j < sp.size(); j++)
//			{
//				if (sp[j].MaHang == d)
//				{
//					if (sp[j].SoLuong >= e)
//					{
//						sp[j].SoLuong = sp[j].SoLuong - e;
//						mua.push_back(sp[j]);
//						mua[w].SoLuong = e;
//						w++;
//					}
//					else
//						cout << "so luong k du";
//				}
//			}
//		cout <<"\n"<<setw(65)<< "========*so san pham da mua*========";
//		cout << "\n" << setw(20) << "Ma Hang" << setw(20) << "Ten Hang" << setw(20) << "Gia Tien" << setw(20) << "So Luong" << setw(20) << "\n";
//		for (int i = 0; i < mua.size(); i++)
//		{
//			cout << mua[i];
//			cout << "\n";
//		}
//		system("pause");
//		
//	}
//	void Tinh()
//	{
//		int s = 0;
//		long m = 0;
//		for (int i = 0; i < mua.size(); i++)
//		{
//			s = s + mua[i].SoLuong;
//			m = m + mua[i].GiaTien*mua[i].SoLuong;
//		}
//		cout << "\ntong luong hang:" << s;
//		cout << "\ntong gia tien:" << m<<'\n';
//		system("pause");
//	}
//	void GhiFile()
//	{
//		ofstream file;
//		file.open("D:\\danhsach.txt");
//		if (file.is_open())
//		{
//			file << sp.size() << "\n";
//			file << "Ma Hang" << "\t" << "Ten Hang" << "\t" << "Gia Tien" << "\t" << "So Luong";
//			for (int i = 0; i < sp.size(); i++)
//			{
//				sp[i].xuatfile(file);
//			}
//			file.close();
//		}
//		else
//			cout << "khong mo dc file";
//	}
//	void Inmenu()
//	{
//		int chon;
//		do
//		{
//			system("cls");
//			cout << "1-nhap danh sach san pham\n";
//			cout << "2-xuat danh sach san pham con trong kho\n";
//			cout << "3-thoat\n";
//			cout << "4-mua danh sach san pham\n";
//			cout << "5-tinh tong so luong va tong tien mua hang\n";
//			cout << "6-chen so luong san pham\n";
//			cout << "7-ghi danh sach san pham ton kho vao file\n";
//			cout << "lua chon chuc nang muon thuc hien:";
//			cin >> chon;
//			switch (chon)
//			{
//			case 1:Nhap(); break;
//			case 2:Xuat(); break;
//			case 4:Muahang(); break;
//			case 5:Tinh(); break;
//			case 6:chensl(); break;
//			case 7:GhiFile(); break;
//			}
//		} while (chon != 3);
//
//	}
//};
//void main()
//{
//	Menu ds_sp;
//	ds_sp.Inmenu();
//	
//}
