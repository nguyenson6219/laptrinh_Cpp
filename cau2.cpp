//#include<iostream>
//#include<string>
//#include<vector>
//#include<iomanip>
//#include<cstdlib>
//#include<fstream>
//using namespace std;
//class SinhVien
//{
//private:
//protected:
//	int MSSV;
//	string HoTen;
//	string He;
//	float laptrinhC;
//public:
//	virtual void Nhap()
//	{
//		cout << "nhap ma so sinh vien:";
//		cin >> MSSV;
//		cin.ignore();
//		cout << "nhap ho ten:";
//		getline(cin, HoTen);
//		cout << "nhap he:";
//		cin >> He;
//		cout << "nhap diem lap trinh C:";
//		cin >> laptrinhC;
//	}
//	virtual void Xuat()
//	{
//		cout <<"\n" << setw(15) << MSSV << setw(15) << HoTen << setw(15) << He << setw(15) << laptrinhC;
//	}
//	virtual float Tinh_dtb()
//	{
//		return 0;
//	}
//	virtual void xuatfile(ofstream &file)
//	{
//		file << "\n" << MSSV << "\t" << HoTen << "\t" << He << "\t" << laptrinhC << "\t";
//	}
//	string gethoten(){
//		return HoTen;
//	}
//	float getltc(){
//		return laptrinhC;
//	}
//	string getHe(){
//		return He;
//	}
//	int getMSSV(){
//		return MSSV;
//	}
//	friend istream& operator >>(istream& is, SinhVien &_sv)
//	{
//		_sv.Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, SinhVien &_sv)
//	{
//		_sv.Xuat();
//		return os;
//	}
//};
//class SinhVien_CQ :public SinhVien
//{
//private:
//	float nmkt;
//public:
//	SinhVien_CQ(int mssv, string hoten, string he, float ltc){
//		MSSV = mssv;
//		HoTen = hoten;
//		He = he;
//		laptrinhC = ltc;
//	}
//	void Nhap(){
//		cout << "nhap diem nhap mon ki thuat:";
//		cin >> nmkt;
//	}
//	void Xuat(){
//		SinhVien::Xuat();
//		cout << setw(30) << nmkt << setw(15) <<setprecision(2)<< Tinh_dtb() << setw(15);
//	}
//	float Tinh_dtb(){
//		return (3 * laptrinhC + 2 * nmkt) / 5;
//	}
//	void  xuatfile(ofstream &file){
//		SinhVien::xuatfile(file);
//		file << nmkt << "\t\t" << Tinh_dtb() << "\t";
//	}
//	friend istream& operator >>(istream& is, SinhVien_CQ *_svcq)
//	{
//		_svcq->Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, SinhVien_CQ *_svcq)
//	{
//		_svcq->Xuat();
//		return os;
//	}
//};
//class SinhVien_CLC :public SinhVien
//{
//private:
//	float dtcb;
//public:
//	SinhVien_CLC(int mssv, string hoten, string he, float ltc){
//		MSSV = mssv;
//		HoTen = hoten;
//		He = he;
//		laptrinhC = ltc;
//	}
//	void Nhap(){
//		cout << "nhap diem dien tu co ban:";
//		cin >> dtcb;
//	}
//	void Xuat(){
//		SinhVien::Xuat();
//		cout << setw(15) << dtcb << setw(30) <<setprecision(2)<< Tinh_dtb() << setw(15);
//	}
//	float Tinh_dtb()
//	{
//		return (2 * laptrinhC + dtcb) / 3;
//	}
//	void  xuatfile(ofstream &file)
//	{
//		SinhVien::xuatfile(file);
//		file <<"\t"<< dtcb << "\t"<<Tinh_dtb();
//	}
//	friend istream& operator >>(istream& is, SinhVien_CLC *_svclc)
//	{
//		_svclc->Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, SinhVien_CLC *_svclc)
//	{
//		_svclc->Xuat();
//		return os;
//	}
//};
//class Menu
//{
//private:
//	vector<SinhVien *> dssv;
//	int n;
//public:
//	void Nhap()
//	{
//		cout << "\nnhap so luong sinh vien:";
//		cin >> n;
//		dssv.resize(n);
//		for (int i = 0; i < dssv.size(); i++){
//			SinhVien sv;
//			cin >> sv;
//			if (sv.getHe() == "cq"){
//				SinhVien_CQ  *CQ = new SinhVien_CQ(sv.getMSSV(), sv.gethoten(), sv.getHe(), sv.getltc());
//				cin >> CQ;
//				dssv[i] = CQ;
//			}
//			else{
//				SinhVien_CLC *CLC = new SinhVien_CLC(sv.getMSSV(), sv.gethoten(), sv.getHe(), sv.getltc());
//				cin >> CLC;
//				dssv[i] = CLC;
//			}
//		}
//	}
//	void Xuat()
//	{
//		cout << "\n\t\t\t\t\t\t====DANH SACH SINH VIEN====\n";
//		cout << "\n" << setw(15) << "MSSV" << setw(15) << "Ho va Ten" << setw(15) << "He" << setw(15) << "LTC" << setw(15) << "DTCB" << setw(15) << "NMKT" << setw(15) << "DTB" << setw(15);
//		for (int i = 0; i < dssv.size(); i++)
//		{
//			cout << *dssv[i];
//		}
//		cout << "\n\n";
//		system("pause");
//	}
//	void Tim_dtb()
//	{
//		float max;
//		max=dssv[0]->Tinh_dtb();
//		for (int i = 0; i < dssv.size(); i++)
//		{
//			if (dssv[i]->Tinh_dtb()>max){
//				max = dssv[i]->Tinh_dtb();
//			}
//		}
//		cout << "\nSinh vien co diem trung binh cao nhat la:";
//		cout << "\n" << setw(15) << "MSSV" << setw(15) << "Ho va Ten" << setw(15) << "He" << setw(15) << "LTC" << setw(15) << "DTCB" << setw(15) << "NMKT" << setw(15) << "DTB" << setw(15);
//		for (int i = 0; i < dssv.size(); i++)
//		{
//			if (max == dssv[i]->Tinh_dtb())
//			{
//				cout << *dssv[i];
//			}
//		}
//		cout << "\n";
//		system("pause");
//	}
//	void Sap_xep()
//	{
//		for (int i = 0; i < dssv.size() - 1; i++)
//		{
//			for (int j = i + 1; j < dssv.size(); j++)
//			{
//				if (dssv[i]->Tinh_dtb()>dssv[j]->Tinh_dtb())
//				{
//					SinhVien *temp = dssv[i];
//					dssv[i] = dssv[j];
//					dssv[j] = temp;
//				}
//			}
//		}
//		cout << "Sap xep xong!!\n";
//		system("pause");
//	}
//	void Xoa_sv()
//	{
//		int c;
//		cout << "Nhap ma so sinh vien can xoa:";
//		cin >> c;
//		for (int i = 0; i < dssv.size(); i++)
//		{
//			if (dssv[i]->getMSSV() == c)
//				dssv.erase(dssv.begin() + i);
//		}
//		cout << "Da xoa xong!!\n";
//		system("pause");
//	}
//	void Chen_sv()
//	{
//		int pos;
//		cout << "nhap vi tri muon chen:";
//		cin >> pos;
//		SinhVien sv;
//		cin >> sv;
//		if (sv.getHe() == "cq"){
//			SinhVien_CQ *CQ = new SinhVien_CQ(sv.getMSSV(), sv.gethoten(), sv.getHe(), sv.getltc());
//			cin >> CQ;
//			dssv.insert(dssv.begin() + pos, CQ);
//		}
//		else{
//			SinhVien_CLC *CLC = new SinhVien_CLC(sv.getMSSV(), sv.gethoten(), sv.getHe(), sv.getltc());
//			cin >> CLC;
//			dssv.insert(dssv.begin() + pos, CLC);
//		}
//	}
//	void Ghifile()
//	{
//		ofstream file;
//		file.open("D://danhsach_2.txt");
//		if (file.is_open())
//		{
//			file << dssv.size() << "\n";
//			file << "MSSV" << "\t" << "Ho Ten" << "\t" << "He" << "\t" << "LTC" << "\t" << "NMKT" << "\t" << "DTCB" << "\t" << "DTB";
//			for (int i = 0; i < dssv.size(); i++)
//			{
//				dssv[i]->xuatfile(file);
//			}
//			file.close();
//		}
//		else
//			cout << "khong mo dc file";
//	}
//	void inmenu()
//	{
//		int chon;
//		do
//		{
//			system("cls");
//			cout << "1-nhap danh sach sinh vien\n";
//			cout << "2-xuat danh sach sinh vien\n";
//			cout << "4-tim sinh vien co dtb cao nhat\n";
//			cout << "5-sap xep sinh vien theo diem trung binh tang dan\n";
//			cout << "6-Xoa sinh vien\n";
//			cout << "7-Chen sinh vien\n";
//			cout << "8-Ghi file danh sach\n";
//			cout << "3-thoat\n";
//			cout << "lua chon chuc nang muon thuc hien:";
//			cin >> chon;
//			switch (chon)
//			{
//			case 1:Nhap(); break;
//			case 2:Xuat(); break;
//			case 4:Tim_dtb(); break;
//			case 5:Sap_xep(); break;
//			case 6:Xoa_sv(); break;
//			case 7:Chen_sv(); break;
//			case 8:Ghifile(); break;
//			}
//		} while (chon != 3);
//	}
//};
//void main()
//{
//	Menu *ds_sv = new Menu;
//	ds_sv->inmenu();
//	delete ds_sv;
//}
