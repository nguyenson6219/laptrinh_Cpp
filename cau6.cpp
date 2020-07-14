//#include<iostream>
//#include<iomanip>
//#include<vector>
//#include<string>
//#include<fstream>
//using namespace std;
//
//class NhanVien{
//protected:
//	string hoTen;
//	string Loai;
//public:
//	virtual void Nhap(){
//		cin.ignore();
//		cout << "\nnhap ho ten:";
//		getline(cin, hoTen);
//		cout << "nhap loai:";
//		getline(cin, Loai);
//	}
//	virtual void Xuat(){
//		cout << setw(20) << hoTen << setw(20) << Loai;
//	}
//	virtual int LuongThang(){
//		return 0;
//	}
//	string gethoten(){
//		return hoTen;
//	}
//	string getloai(){
//		return Loai;
//	}
//	friend istream& operator >>(istream& is, NhanVien &_nv){
//		_nv.Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, NhanVien &_nv){
//		_nv.Xuat();
//		return os;
//	}
//	virtual void xuatfile(ofstream &file){
//		file << hoTen << "\t" << Loai;
//	}
//};
//class VanPhong :public NhanVien{
//private:
//	int heSo;
//public:
//	VanPhong(string hoten, string loai){
//		hoTen = hoten;
//		Loai = loai;
//	}
//	void Nhap(){
//		cout << "nhap he so chuc vu:";
//		cin >> heSo;
//	}
//	void Xuat(){
//		NhanVien::Xuat();
//		cout << setw(20) << heSo << setw(60) << LuongThang() << setw(20);
//	}
//	int LuongThang(){
//		return 1000000 * heSo;
//	}
//	friend istream& operator >>(istream& is, VanPhong *vp){
//		vp->Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, VanPhong *vp){
//		vp->Xuat();
//		return os;
//	}
//	void xuatfile(ofstream &file){
//		NhanVien::xuatfile(file);
//		file << "\t" << heSo << "\t\t\t" << LuongThang();
//	}
//};
//class LapTrinhVien :public NhanVien{
//private:
//	int phanMem;
//public:
//	LapTrinhVien(string hoten, string loai){
//		hoTen = hoten;
//		Loai = loai;
//	}
//	void Nhap(){
//		cout << "nhap so phan mem viet duoc:";
//		cin >> phanMem;
//	}
//	void Xuat(){
//		NhanVien::Xuat();
//		cout << setw(40) << phanMem << setw(40) << LuongThang() << setw(20);
//	}
//	int LuongThang(){
//		return 5000000 * phanMem;
//	}
//	friend istream& operator >>(istream& is, LapTrinhVien *ltv){
//		ltv->Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, LapTrinhVien *ltv){
//		ltv->Xuat();
//		return os;
//	}
//	void xuatfile(ofstream &file){
//		NhanVien::xuatfile(file);
//		file << "\t\t" << phanMem << "\t\t" << LuongThang();
//	}
//};
//class PhucVu :public NhanVien{
//private:
//	int Thuong;
//public:
//	PhucVu(string hoten, string loai){
//		hoTen = hoten;
//		Loai = loai;
//	}
//	void Nhap(){
//		cout << "nhap so tien thuong:";
//		cin >> Thuong;
//	}
//	void Xuat(){
//		NhanVien::Xuat();
//		cout << setw(60) << Thuong << setw(20) << LuongThang() << setw(20);
//	}
//	int LuongThang(){
//		return 3000000 + Thuong;
//	}
//	friend istream& operator >>(istream& is, PhucVu *pv){
//		pv->Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, PhucVu *pv){
//		pv->Xuat();
//		return os;
//	}
//	void xuatfile(ofstream &file){
//		NhanVien::xuatfile(file);
//		file << "\t\t\t" << Thuong << "\t" << LuongThang();
//	}
//};
//class QuanLy{
//private:
//	vector<NhanVien*> dsnv;
//	int n;
//public:
//	void Nhap(){
//		cout << "\nnhap so luong nhan vien:";
//		cin >> n;
//		dsnv.resize(n);
//		for (int i = 0; i < dsnv.size(); i++){
//			NhanVien nv;
//			cin >> nv;
//			if (nv.getloai() == "vphong"){
//				VanPhong *VP = new VanPhong(nv.gethoten(), nv.getloai());
//				cin >> VP;
//				dsnv[i] = VP;
//			}
//			else if (nv.getloai() == "ltv"){
//				LapTrinhVien *LTV = new LapTrinhVien(nv.gethoten(), nv.getloai());
//				cin >> LTV;
//				dsnv[i] = LTV;
//			}
//			else{
//				PhucVu *PV = new PhucVu(nv.gethoten(), nv.getloai());
//				cin >> PV;
//				dsnv[i] = PV;
//			}
//		}
//	}
//	void Xuat(){
//		cout << "\n\n\n\t\t\t\t\t=============DANH SACH NHAN VIEN=============\n\n";
//		cout << setw(20) << "Ho Ten" << setw(20) << "Loai" << setw(20) << "He So" << setw(20) << "So phan mem" << setw(20) << "Thuong" << setw(20) << "Luong Thang" << setw(20) << "\n";
//		for (int i = 0; i < dsnv.size(); i++){
//			cout << *dsnv[i];
//			cout << "\n\n";
//		}
//		cout << "\n\n\n";
//		system("pause");
//	}
//	void Chen(){
//		int pos;
//		cout << "\nnhap vi tri muon chen:";
//		cin >> pos;
//		NhanVien nv;
//		cin >> nv;
//		if (nv.getloai() == "vphong"){
//			VanPhong *VP = new VanPhong(nv.gethoten(), nv.getloai());
//			cin >> VP;
//			dsnv.insert(dsnv.begin() + pos, VP);
//		}
//		else if (nv.getloai() == "ltv"){
//			LapTrinhVien *LTV = new LapTrinhVien(nv.gethoten(), nv.getloai());
//			cin >> LTV;
//			dsnv.insert(dsnv.begin() + pos, LTV);
//		}
//		else{
//			PhucVu *PV = new PhucVu(nv.gethoten(), nv.getloai());
//			cin >> PV;
//			dsnv.insert(dsnv.begin() + pos, PV);
//		}
//	}
//	void Xoa(){
//		string name;
//		cin.ignore();
//		cout << "\nnhap ten nhan vien muon xoa:";
//		getline(cin, name);
//		for (int i = 0; i < dsnv.size(); i++){
//			if (dsnv[i]->gethoten() == name){
//				dsnv.erase(dsnv.begin() + i);
//			}
//		}
//		
//	}
//	void TimKiem(){
//		int max = dsnv[0]->LuongThang();
//		for (int i = 0; i < dsnv.size(); i++){
//			if (dsnv[i]->LuongThang()>max)
//				max = dsnv[i]->LuongThang();
//		}
//		cout << "\n\n\n\t\t\t\t============DANH SACH NHAN VIEN CO LUONG CAO NHAT============\n\n";
//		cout << setw(20) << "Ho Ten" << setw(20) << "Loai" << setw(20) << "He So" << setw(20) << "So phan mem" << setw(20) << "Thuong" << setw(20) << "Luong Thang" << setw(20) << "\n";
//		for (int i = 0; i < dsnv.size(); i++){
//			if (dsnv[i]->LuongThang() == max)
//				cout << *dsnv[i] << "\n";
//		}
//		cout << "\n\n\n";
//		system("pause");
//	}
//	void LietKe(){
//		int sum = 0;
//		for (int i = 0; i < dsnv.size(); i++){
//			sum = sum + dsnv[i]->LuongThang();
//		}
//		float tb = sum / dsnv.size();
//		cout << "\n\n\n\t\t\t============DANH SACH NHAN VIEN CO LUONG THAP HON MUC TRUNG BINH============\n\n";
//		cout << setw(20) << "Ho Ten" << setw(20) << "Loai" << setw(20) << "He So" << setw(20) << "So phan mem" << setw(20) << "Thuong" << setw(20) << "Luong Thang" << setw(20) << "\n";
//		for (int i = 0; i < dsnv.size(); i++){
//			if (dsnv[i]->LuongThang() < tb)
//				cout << *dsnv[i] << "\n";
//		}
//		cout << "\n\n\n";
//		system("pause");
//	}
//	void SapXep(){
//		for (int i = 0; i < dsnv.size()-1; i++){
//			for (int j = i + 1; j < dsnv.size(); j++){
//				if (dsnv[i]->LuongThang() < dsnv[j]->LuongThang()){
//					NhanVien *temp = dsnv[i];
//					dsnv[i] = dsnv[j];
//					dsnv[j] = temp;
//				}
//			}
//		}
//	}
//	void GhiFile(){
//		ofstream file;
//		file.open("D://danhsach6.txt");
//		if (file.is_open()){
//			file << dsnv.size() << "\n";
//			file << "Ho Ten" << "\t" << "Loai" << "\t" << "He So" << "\t" << "Phan Mem" << "\t" << "Thuong" << "\t" << "Luong\n";
//			for (int i = 0; i < dsnv.size(); i++){
//				dsnv[i]->xuatfile(file);
//				file << "\n";
//			}
//			file.close();
//		}
//		else cout << "khong mo duoc file!";
//	}
//	void menu(){
//		int chon;
//		do{
//			system("cls");
//			cout << "1-nhap danh sach nhan vien\n";
//			cout << "2-xuat danh sach nhan vien\n";
//			cout << "3-chen nhan vien vao danh sach\n";
//			cout << "4-xoa nhan vien khoi danh sach\n";
//			cout << "5-tim kiem nhan vien luong cao nhat\n";
//			cout << "6-liet ke nhan vien luong thap hon muc trung binh\n";
//			cout << "7-sap xep danh sach nhan vien luong giam dan\n";
//			cout << "8-ghi danh sach vao file .txt\n";
//			cout << "lua chon chuc nang muon thuc hien:";
//			cin >> chon;
//			switch (chon){
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
//void main(){
//	QuanLy *qlnv = new QuanLy;
//	qlnv->menu();
//	delete qlnv;
//}
