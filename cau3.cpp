//#include<iostream>
//#include<iomanip>
//#include<string>
//#include<fstream>
//#include<vector>
//using namespace std;
//class phongKS{
//private:
//public:
//	int maPhong;
//	string tenPhong;
//	int giaTien;
//	int soLuong;
//	void Nhap(){
//		cout << "nhap ma phong:";
//		cin >> maPhong;
//		cin.ignore();
//		cout << "nhap ten phong:";
//		getline(cin, tenPhong);
//		cout << "nhap gia tien:";
//		cin >> giaTien;
//		cout << "nhap so luong:";
//		cin >> soLuong;
//	}
//	void Xuat(){
//		cout << setw(20) << maPhong << setw(20) << tenPhong << setw(20) << giaTien << setw(20) << soLuong << setw(20);
//	}
//	void xuatfile(ofstream &file){
//		file << "\n" << maPhong << "\t" << tenPhong << "\t" << giaTien << "\t" << soLuong;
//	}
//	friend istream& operator >>(istream& is, phongKS &input){
//		input.Nhap();
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, phongKS &output){
//		output.Xuat();
//		return os;
//	}
//};
//class dangKy:public phongKS{
//private:
//	int soDem;
//public:
//	dangKy(int maphong, string tenphong, int giatien, int soluong, int sodem){
//		maPhong = maphong;
//		tenPhong = tenphong;
//		giaTien = giatien;
//		soLuong = soluong;
//		soDem = sodem;
//	}
//	void Xuat(){
//		cout << setw(20) << maPhong << setw(20) << tenPhong << setw(20) << giaTien << setw(20) << soLuong << setw(20) << soDem << setw(20);
//	}
//	int tinhTien(){
//		return giaTien*soLuong*soDem;
//	}
//	friend ostream& operator <<(ostream& os, dangKy &output){
//		output.Xuat();
//		return os;
//	}
//};
//class quanLy{
//private:
//	vector<phongKS> pks;
//	vector<dangKy> dk;
//	int n;
//public:
//	void Nhap()
//	{
//		cout << "\nnhap tong so loai phong:";
//		cin >> n;
//		pks.resize(n);
//		for (int i = 0; i < pks.size(); i++)
//		{
//			phongKS ks;
//			cin >> ks;
//			pks[i] = ks;
//		}
//	}
//	void Xuat(){
//		cout << "\n\n\t\t\t\t=============DANH SACH PHONG CON TRONG=============\t\t\n";
//		cout << setw(20) << "Ma phong" << setw(20) << "Ten phong" << setw(20) << "Gia tien/dem" << setw(20) << "So luong" << setw(20) << "\n";
//		for (int i = 0; i < pks.size(); i++){
//			if (pks[i].soLuong == 0)
//				pks.erase(pks.begin() + i);
//		}
//		for (int i = 0; i < pks.size(); i++)
//		{
//			cout << pks[i];
//			cout << "\n";
//		}
//		system("pause");
//	}
//	void Dangky(){
//		int d,s,e;
//		cout << "\nnhap ma phong can dang ki:";
//		cin >> d;
//		cout << "\nnhap so luong:";
//		cin >> e;
//		cout << "\nnhap so dem:";
//		cin >> s;
//		for (int i = 0; i < pks.size(); i++){
//			if (pks[i].maPhong == d){
//				if (pks[i].soLuong >= e){
//					pks[i].soLuong = pks[i].soLuong - e;
//					dangKy _dk(pks[i].maPhong, pks[i].tenPhong, pks[i].giaTien,e,s);
//					dk.push_back(_dk);	
//				}
//				else cout << "so luong k du!";
//			}
//		}
//		system("pause");
//	}
//	void Xuatdk(){
//		cout << "\n\n\t\t\t\t=============DANH SACH PHONG DANG KY=============\t\t\n";
//		cout << "\n" << setw(20) << "Ma phong" << setw(20) << "Ten phong" << setw(20) << "Gia tien/dem" << setw(20) << "So luong" << setw(20) << "So dem" << setw(20);
//		for (int i = 0; i < dk.size(); i++){
//			cout << "\n";
//			cout << dk[i];
//			cout << "\n";
//		}
//		system("pause");
//	}
//	void TinhTien(){
//		int tien = 0;
//		for (int i = 0; i < dk.size(); i++){
//			tien = tien + dk[i].tinhTien();
//		}
//		cout << "\n\nTong tien phong:" << tien << "\n\n";
//		system("pause");
//	}
//	void SapXep(){
//		for (int i = 0; i < pks.size() ; i++){
//			for (int j = i + 1; j < pks.size(); j++){
//				if (pks[i].giaTien>pks[j].giaTien){
//					phongKS temp = pks[i];
//					pks[i] = pks[j];
//					pks[j] = temp;
//				}
//			}
//		}
//		cout << "\n\nSap xep xong!!!\n\n";
//		system("pause");
//	}
//	void GhiFile(){
//		ofstream file;
//		file.open("D://danhsachtrong.txt");
//		if (file.is_open()){
//			file << pks.size() << "\n";
//			file << "Ma phong" << "\t" << "Ten phong" << "\t" << "Gia tien" << "\t" << "So luong" << "\n";
//			for (int i = 0; i < pks.size(); i++){
//				pks[i].xuatfile(file);
//			}
//			file.close();
//		}
//		else  cout << "khong mo duoc file!!";
//	}
//	void Menu(){
//		int chon;
//		do{
//			system("cls");
//			cout << "1-nhap danh sach phong";
//			cout << "\n2-xuat danh sach phong con trong";
//			cout << "\n4-dang ky phong";
//			cout << "\n5-xuat danh sach phong da dang ky";
//			cout << "\n6-tinh tong tien phai tra";
//			cout << "\n7-sap xep danh sach phong";
//			cout << "\n8-ghi danh sach phong trong vao file";
//			cout << "\n3-thoat";
//			cout << "\nlua chon:";
//			cin >> chon;
//			switch (chon){
//			case 1:Nhap(); break;
//			case 2:Xuat(); break;
//			case 4:Dangky(); break;
//			case 5:Xuatdk(); break;
//			case 6:TinhTien(); break;
//			case 7:SapXep(); break;
//			case 8:GhiFile(); break;
//			}
//		} while (chon != 3);
//	}
//};
//
//
//void main(){
//	quanLy *dsp=new quanLy;
//	dsp->Menu();
//	delete dsp;
//}