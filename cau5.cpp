//#include<iostream>
//#include<iomanip>
//#include<vector>
//#include<fstream>
//#include<string>
//using namespace std;
//
//class DocGia{
//protected:
//	string HoTen;
//	string Loai;
//public:
//	virtual void Nhap(){
//		cin.ignore();
//		cout << "\nnhap ho ten:";
//		getline(cin, HoTen);
//		cout << "nhap loai:";
//		getline(cin, Loai);
//	}
//	virtual void Xuat(){
//		cout << setw(20) << HoTen << setw(20) << Loai;
//	}
//	virtual int TongTien(){
//		return 0;
//	}
//	string gethoten(){
//		return HoTen;
//	}
//	string getloai(){
//		return Loai;
//	}
//	virtual void xuatfile(ofstream &file){
//		file << "\n" << HoTen << "\t" << Loai;
//	}
//	friend istream& operator >>(istream& is, DocGia &_dg){
//		_dg.Nhap();
//		return is;
//	}
//	friend ostream& operator<<(ostream& os, DocGia &_dg){
//		_dg.Xuat();
//		return os;
//	}
//};
//class NguoiLon:public DocGia{
//private:
//	int soThang;
//public:
//	NguoiLon(string hoten, string loai){
//		HoTen = hoten;
//		Loai = loai;
//	}
//	void Nhap(){
//		cout << "nhap so thang dang ky:";
//		cin >> soThang;
//	}
//	void Xuat(){
//		DocGia::Xuat();
//		cout << setw(20) << soThang << setw(40) << TongTien() << setw(20);
//	}
//	int TongTien(){
//		return 100000 * soThang;
//	}
//	void xuatfile(ofstream &file){
//		DocGia::xuatfile(file);
//		file << "\t" << soThang << "\t\t" << TongTien();
//	}
//	friend istream& operator >>(istream& is, NguoiLon *_nl){
//		_nl->Nhap();
//		return is;
//	}
//	friend ostream& operator<<(ostream& os, NguoiLon *_nl){
//		_nl->Xuat();
//		return os;
//	}
//};
//class TreEm :public DocGia{
//private:
//	int soTuoi;
//public:
//	TreEm(string hoten, string loai){
//		HoTen = hoten;
//		Loai = loai;
//	}
//	void Nhap(){
//		cout << "nhap so tuoi:";
//		cin >> soTuoi;
//	}
//	void Xuat(){
//		DocGia::Xuat();
//		cout << setw(40) << soTuoi << setw(20) << TongTien() << setw(20);
//	}
//	int TongTien(){
//		return 20000 * soTuoi;
//	}
//	void xuatfile(ofstream &file){
//		DocGia::xuatfile(file);
//		file << "\t\t" << soTuoi << "\t" << TongTien();
//	}
//	friend istream& operator >>(istream& is, TreEm *_te){
//		_te->Nhap();
//		return is;
//	}
//	friend ostream& operator<<(ostream& os, TreEm *_te){
//		_te->Xuat();
//		return os;
//	}
//};
//class NguoiGia:public DocGia{
//private:
//public:
//	NguoiGia(string hoten, string loai){
//		HoTen = hoten;
//		Loai = loai;
//	}
//	void Xuat(){
//		DocGia::Xuat();
//		cout << setw(60) << TongTien() << setw(20);
//	}
//	int TongTien(){
//		return 0;
//	}
//	void xuatfile(ofstream &file){
//		DocGia::xuatfile(file);
//		file << "\t\t\t" <<TongTien();
//	}
//	friend istream& operator >>(istream& is, NguoiGia *_ng){
//		_ng->Nhap();
//		return is;
//	}
//	friend ostream& operator<<(ostream& os, NguoiGia *_ng){
//		_ng->Xuat();
//		return os;
//	}
//};
//class QuanLy{
//private:
//	vector<DocGia*> dsdg;
//	int n;
//public:
//	void Nhap(){
//		cout << "\nnhap tong so doc gia:";
//		cin >> n;
//		dsdg.resize(n);
//		for (int i = 0; i < dsdg.size(); i++){
//			DocGia dg;
//			cin >> dg;
//			if (dg.getloai() == "nglon"){
//				NguoiLon *NL = new NguoiLon(dg.gethoten(), dg.getloai());
//				cin >> NL;
//				dsdg[i] = NL;
//			}
//			else if(dg.getloai() == "tree"){
//				TreEm *TE = new TreEm(dg.gethoten(), dg.getloai());
//				cin >> TE;
//				dsdg[i] = TE;
//			}
//			else{
//				NguoiGia *NG = new NguoiGia(dg.gethoten(), dg.getloai());
//				dsdg[i] = NG;
//			}
//		}
//	}
//	void Xuat(){
//		cout << "\n\n\t\t\t\t===============DANH SACH DOC GIA===============\n\n";
//		cout << setw(20) << "Ho Ten" << setw(20) << "Loai" << setw(20) << "So Thang" << setw(20) << "So Tuoi" << setw(20) << "Tong Tien" << setw(20) << "\n\n";
//		for (int i = 0; i < dsdg.size(); i++){
//			cout << *dsdg[i];
//			cout << "\n\n";
//		}
//		cout << "\n\n\n";
//		system("pause");
//	}
//	void Chen(){
//		int pos;
//		cout << "\nnhap vi tri muon chen:";
//		cin >> pos;
//		DocGia dg;
//		cin >> dg;
//		if (dg.getloai() == "nglon"){
//			NguoiLon *NL = new NguoiLon(dg.gethoten(), dg.getloai());
//			cin >> NL;
//			dsdg.insert(dsdg.begin() + pos, NL);
//		}
//		else if (dg.getloai() == "tree"){
//			TreEm *TE = new TreEm(dg.gethoten(), dg.getloai());
//			cin >> TE;
//			dsdg.insert(dsdg.begin() + pos, TE);
//		}
//		else{
//			NguoiGia *NG = new NguoiGia(dg.gethoten(), dg.getloai());
//			dsdg.insert(dsdg.begin() + pos, NG);
//		}
//	}
//	void Xoa(){
//		string name;
//		cin.ignore();
//		cout << "\nnhap ten doc gia muon xoa:";
//		getline(cin, name);
//		for (int i = 0; i < dsdg.size(); i++){
//			if (dsdg[i]->gethoten() == name)
//				dsdg.erase(dsdg.begin() + i);
//		}
//	}
//	void TimKiem(){
//		int max = dsdg[0]->TongTien();
//		for (int i = 0; i < dsdg.size(); i++){
//			if (dsdg[i]->TongTien()>max){
//				max = dsdg[i]->TongTien();
//			}
//		}
//		cout << "\n\n\t\t\t===============DANH SACH DOC GIA DONG TIEN NHIEU NHAT===============\n\n";
//		cout << setw(20) << "Ho Ten" << setw(20) << "Loai" << setw(20) << "So Thang" << setw(20) << "So Tuoi" << setw(20) << "Tong Tien" << setw(20) << "\n\n";
//		for (int i = 0; i < dsdg.size(); i++){
//			if (dsdg[i]->TongTien() == max){
//				cout << *dsdg[i];
//				cout << "\n\n";
//			}
//		}
//		cout << "\n\n\n";
//		system("pause");
//	}
//	void LietKe(){
//		int sum=0;
//		for (int i = 0; i < dsdg.size(); i++){
//			sum = sum + dsdg[i]->TongTien();
//		}
//		float tb = sum / dsdg.size();
//		cout << "\n\n\t\t\t===============DANH SACH DOC GIA DONG PHI CAO HON MUC TB===============\n\n";
//		cout << setw(20) << "Ho Ten" << setw(20) << "Loai" << setw(20) << "So Thang" << setw(20) << "So Tuoi" << setw(20) << "Tong Tien" << setw(20) << "\n\n";
//		for (int i = 0; i < dsdg.size(); i++){
//			if (dsdg[i]->TongTien()>tb){
//				cout << *dsdg[i];
//				cout << "\n\n";
//			}
//		}
//		cout << "\n\n\n";
//		system("pause");
//	}
//	void SapXep(){
//		for (int i = 0; i < dsdg.size() - 1; i++){
//			for (int j = i + 1; j < dsdg.size(); j++){
//				if (dsdg[i]->TongTien()>dsdg[j]->TongTien()){
//					DocGia *temp = dsdg[i];
//					dsdg[i] = dsdg[j];
//					dsdg[j] = temp;
//				}
//			}
//		}
//	}
//	void GhiFile(){
//		ofstream file;
//		file.open("D://danhsach_5.txt");
//		if (file.is_open()){
//			file << dsdg.size() << "\n";
//			file << "Ho Ten" << "\t" << "Loai" << "\t" << "So Thang" << "\t" << "So Tuoi" << "\t" << "Tong Tien" << "\t";
//			for (int i = 0; i < dsdg.size(); i++){
//				dsdg[i]->xuatfile(file);
//			}
//			file.close();
//		}
//		else cout << "khong mo duoc file!";
//	}
//	void menu(){
//		int chon;
//		do
//		{
//			system("cls");
//			cout << "1-nhap danh sach doc gia\n";
//			cout << "2-xuat danh sach doc gia\n";
//			cout << "3-chen thong tin doc gia\n";
//			cout << "4-xoa thong tin doc gia\n";
//			cout << "5-tim doc gia dong tien nhieu nhat\n";
//			cout << "6-liet ke doc gia dong phi cao hon muc trung binh\n";
//			cout << "7-sap xep danh sach\n";
//			cout << "8-ghi danh sach vao file .txt\n";
//			cout << "lua chon chuc nang muon thuc hien:";
//			cin >> chon;
//			switch (chon)
//			{
//			case 1:Nhap(); break;
//			case 2:Xuat(); break;
//			case 3:Chen(); break;
//			case 4:Xoa(); break;
//			case 5:TimKiem(); break;
//			case 6:LietKe(); break;
//			case 7:SapXep(); break;
//			case 8:GhiFile(); break;
//			}
//		} while (chon != 9);
//	}
//};
//
//
//void main(){
//	QuanLy *ql = new QuanLy;
//	ql->menu();
//	delete ql;
//}