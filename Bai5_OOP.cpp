/**
 *    author:  longvu
 *    created: 10/11/24 23:39:57
**/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int nax = (int)(100001);
const int mod = 1e9 + 7;

template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}

class cBook {
private:
	string ten;
	string tacGia;
	int namXuatBan, tongSoTrang;
public:
	friend class cListBook;
	// Thiet lap thong tin sach
	cBook(string ten = "", string tacGia = "", int namXuatBan = 0, int tongSoTrang = 0) : ten(ten), tacGia(tacGia), namXuatBan(namXuatBan), tongSoTrang(tongSoTrang) {}

	void Nhap() {
		cout << "Nhap ten sach: " << endl;
		cin.ignore();
		getline(cin, ten);
		cout << "Nhap ten tac gia: " << endl;
		getline(cin, tacGia);
		cout << "Nhap nam xuat ban: " << endl;
		cin >> namXuatBan;
		cout << "Nhap tong so trang: " << endl;
		cin >> tongSoTrang;

	}

	void Xuat() {
		cout << "Ten sach: " << ten << endl;
		cout << "Ten tac gia: " << tacGia << endl;
		cout << "Nam xuat ban: " << namXuatBan << endl;
		cout << "Tong so trang: " << tongSoTrang << endl;
	}

	// Cap nhat thong tin sach
	void CapNhat() {
		cout << "Nhap ten sach: " << endl;
		cin.ignore();
		getline(cin, ten);
		cout << "Nhap ten tac gia: " << endl;
		getline(cin, tacGia);
		cout << "Nhap nam xuat ban: " << endl;
		cin >> namXuatBan;
		cout << "Nhap tong so trang: " << endl;
		cin >> tongSoTrang;

	}
};

class cListBook {
private:
	vector<cBook> a;
public:
	// Them sach vao danh sach
	void ThemSach() {
		cBook temp;
		temp.Nhap();
		a.push_back(temp);
	}

	// Xuat danh sach sach
	void Xuat() {
		for (int i = 0; i < sz(a); ++i) {
			a[i].Xuat();
		}
	}

	// Tim Sach suat ban gan day nhat
	void TimSach() {
		int res = 0;
		for (int i = 0; i < sz(a); ++i) {
			if (a[i].namXuatBan > a[res].namXuatBan) {
				res = i;
			}
		}
		cout << "Sach xuat ban gan day nhat la: " << endl;
		a[res].Xuat();
	}
};



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cListBook a;
    int n;
    cout << "Nhap so sach: " << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
		a.ThemSach();
	}
	a.Xuat();
	a.TimSach();
    return 0;
}