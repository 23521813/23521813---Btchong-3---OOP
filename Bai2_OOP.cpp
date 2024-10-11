/**
 *    author:  longvu
 *    created: 10/11/24 23:07:28
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

class arrPhanSo {
private:
	vector<pair<int, int>> a;
	int n;
public:
	void Nhap() {
		cout << "Nhap so phan tu: ";
		cout.flush();
		cin >> n;
		a.resize(n);
		cout << "Nhap day phan so: ";
		cout.flush();
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first >> a[i].second;
		}
	}

	void Xuat() {
		cout << "Day phan so la: ";
		cout.flush();
		for (int i = 0; i < n; ++i) {
			cout << a[i].first << '/' << a[i].second << ' ';
		}
		cout << '\n';
	}

	// Tim phan so lon nhat
	void Max() {
		pair<int, int> res = {0, 1};
		for (int i = 0; i < n; ++i) {
			if (a[i].first * res.second > res.first * a[i].second) {
				res = a[i];
			}
		}
		cout << "Phan so lon nhat la: " << res.first << '/' << res.second << '\n';
		cout.flush();
	}

	bool ktNguyenTo(int x) {
		if (x < 2) return false;
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) return false;
		}
		return true;
	}

	// Dem co bao nhieu phan so co tu so la so nguyen to
	void Dem() {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (ktNguyenTo(abs(a[i].first))) {
				++cnt;
			}
		}
		cout << "So phan so co tu so la so nguyen to la: " << cnt << '\n';
		cout.flush();
	}

	// Sap xep day phan so theo thu tu tang dan
	void SapXep() {
		sort(all(a), [&](pair<int, int> x, pair<int, int> y) {
			return x.first * y.second < x.second * y.first;
		});
	}
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    arrPhanSo a;
    a.Nhap();
    a.Xuat();
    a.Max();
    a.Dem();
    a.SapXep();
    a.Xuat();
    return 0;
}