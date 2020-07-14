//#include<iostream>
//#include<vector>
//#include<iomanip>
//#include<fstream>
//#include<string>
//using namespace std;
//class Khoa{
//protected:
//	string hoTen;
//	string He;
//	int hocPhi;
//public:
//	virtual void Nhap(){
//		cin.ignore();
//		cout << "nhap ho ten:";
//		getline(cin, hoTen);
//		cout << "nhap he:";
//		cin >> He;
//	}
//	virtual void Xuat(){
//		cout << "\n\n\nHo ten:" << hoTen;
//		cout << "\nHe:" << He;
//	}
//	virtual int HocPhi(){
//		return 0;
//	}
//	string gethoten(){
//		return hoTen;
//	}
//	string gethe(){
//		return He;
//	}
//	virtual void xuatfile(ofstream &file){
//		file << hoTen << "\n";
//		file << He << "\n";
//	}
//	friend istream& operator >>(istream& is, Khoa &_sv){
//		_sv.Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, Khoa &_sv){
//		_sv.Xuat();
//		return os;
//	}
//};
//class ChinhQuy:public Khoa{
//protected:
//	int LT;
//	int TH;
//	int TongTC(){
//		return (LT * 2) + (TH * 3);
//	}
//public:
//	ChinhQuy(string hoten, string he){
//		hoTen = hoten;
//		He = he;
//	}
//	void Nhap(){
//		cout << "nhap tin chi ly thuyet:";
//		cin >> LT;
//		cout << "nhap tin chi thuc hanh:";
//		cin >> TH;
//	}
//	void Xuat(){
//		Khoa::Xuat();
//		cout << "\nTC LT:" << LT;
//		cout << "\nTC TH:" << TH;
//		cout << "\nTong TC:" << TongTC();
//		cout << "\nHoc Phi:" << HocPhi();
//	}
//	int HocPhi(){
//		return TongTC() * 200000;
//	}
//	void xuatfile(ofstream &file){
//		Khoa::xuatfile(file);
//		file << LT << "\n";
//		file << TH << "\n";
//		file << TongTC() << "\n";
//		file << HocPhi() << "\n";
//	}
//	friend istream& operator >>(istream& is, ChinhQuy* _cq){
//		_cq->Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, ChinhQuy* _cq){
//		_cq->Xuat();
//		return os;
//	}
//};
//class ChatLuongCao :public Khoa{
//protected:
//	int HK;
//public:
//	ChatLuongCao(string hoten, string he){
//		hoTen = hoten;
//		He = he;
//	}
//	void Nhap(){
//		cout << "nhap hoc ky dang hoc:";
//		cin >> HK;
//	}
//	void Xuat(){
//		Khoa::Xuat();
//		cout << "\nHK(1-8):" << HK;
//		cout << "\nHoc Phi:" << HocPhi();
//	}
//	int HocPhi(){
//		int HP = 20000000;
//		for (int i = 2; i <= HK; i++){
//			HP = HP + (HP * 10) / 100;
//		}
//		return HP;
//	}
//	void xuatfile(ofstream &file){
//		Khoa::xuatfile(file);
//		file << HK << "\n";
//		file << HocPhi() << "\n";
//	}
//	friend istream& operator >>(istream& is, ChatLuongCao* _clc){
//		_clc->Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, ChatLuongCao* _clc){
//		_clc->Xuat();
//		return os;
//	}
//};
//class QuanLy{
//private:
//	vector<Khoa *> dssv;
//public:
//	void Nhap()
//	{
//		int n;
//		cout << "nhap tong so sinh vien:";
//		cin >> n;
//		dssv.resize(n);
//		for (int i = 0; i < dssv.size(); i++){
//			Khoa sv;
//			cin >> sv;
//			if (sv.gethe() == "cq"){
//				ChinhQuy* CQ = new ChinhQuy(sv.gethoten(), sv.gethe());
//				cin >> CQ;
//				dssv[i] = CQ;
//			}
//			else{
//				ChatLuongCao* CLC = new ChatLuongCao(sv.gethoten(), sv.gethe());
//				cin >> CLC;
//				dssv[i] = CLC;
//			}
//		}
//	}
//	void Xuat(){
//		for (int i = 0; i < dssv.size(); i++)
//		{
//			cout << *dssv[i];
//		}
//		cout << "\n\n";
//		system("pause");
//	}
//	void Chen(){
//		int pos;
//		cout << "\nnhap vi tri muon chen:";
//		cin >> pos;
//		Khoa sv;
//		cin >> sv;
//		if (sv.gethe() == "cq"){
//			ChinhQuy *CQ = new ChinhQuy(sv.gethoten(), sv.gethe());
//			cin >> CQ;
//			dssv.insert(dssv.begin() + pos, CQ);
//		}
//		else{
//			ChatLuongCao *CLC = new ChatLuongCao(sv.gethoten(), sv.gethe());
//			cin >> CLC;
//			dssv.insert(dssv.begin() + pos, CLC);
//		}
//	}
//	void Xoa(){
//		string name;
//		cin.ignore();
//		cout << "\nnhap ten sinh vien muon xoa:";
//		getline(cin, name);
//		for (int i = 0; i < dssv.size(); i++){
//			if (dssv[i]->gethoten() == name)
//				dssv.erase(dssv.begin() + i);
//		}
//	}
//	void SapXep(){
//		for (int i = 0; i < dssv.size()-1; i++){
//			for (int j = i + 1; j < dssv.size(); j++){
//				if (dssv[i]->HocPhi()>dssv[j]->HocPhi()){
//					Khoa *temp = dssv[i];
//					dssv[i] = dssv[j];
//					dssv[j] = temp;
//				}
//			}
//		}
//	}
//	void LietKe(){
//		float tb,sum=0;
//		for (int i = 0; i < dssv.size(); i++){
//			sum = sum + dssv[i]->HocPhi();
//		}
//		tb = sum / dssv.size();
//		for (int i = 0; i < dssv.size(); i++){
//			if (dssv[i]->HocPhi()>tb){
//				cout << *dssv[i];
//			}
//		}
//		cout << "\n\n\n\n";
//		system("pause");
//	}
//	void Ghifile(){
//		ofstream file;
//		file.open("D://danhsach4.txt");
//		if (file.is_open()){
//			file << dssv.size() << "\n";
//			for (int i = 0; i < dssv.size(); i++){
//				dssv[i]->xuatfile(file);
//			}
//			file.close();
//		}
//		else
//			cout << "ko mo dc file";
//	}
//	void menu(){
//		int chon;
//		do
//		{
//			system("cls");
//			cout << "1-nhap danh sach sinh vien\n";
//			cout << "2-xuat danh sach sinh vien\n";
//			cout << "3-chen thong tin sinh vien\n";
//			cout << "4-xoa sinh vien\n";
//			cout << "5-sap xep danh sach theo hoc phi\n";
//			cout << "6-Liet ke\n";
//			cout << "7-ghi danh sach vào file .txt\n";
//			cout << "8-thoat\n\n";
//			cout << "lua chon chuc nang muon thuc hien:";
//			cin >> chon;
//			switch (chon)
//			{
//			case 1:Nhap(); break;
//			case 2:Xuat(); break;
//			case 3:Chen(); break;
//			case 4:Xoa(); break;
//			case 5:SapXep(); break;
//			case 6:LietKe(); break;
//			case 7:Ghifile(); break;
//			}
//		} while (chon != 8);
//	}
//};
//
//void main(){
//	QuanLy *_dssv = new QuanLy;
//	_dssv->menu();
//	delete _dssv;
//}