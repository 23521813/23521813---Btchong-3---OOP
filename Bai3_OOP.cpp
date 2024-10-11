/**
 *    author:  longvu
 *    created: 10/11/24 23:13:21
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

class DonThuc {
private:
	// P(x) = a * x^b
	int a, b;
public:
	// Tao lap don thuc
	DonThuc(int a = 0, int b = 0) : a(a), b(b) {}

	// Nhap don thuc
	void Nhap() {
		cout << "Nhap he so a: ";
		cout.flush();
		cin >> a;
		cout << "Nhap so mu b: ";
		cout.flush();
		cin >> b;
	}

	// Xuat don thuc
	void Xuat() {
		cout << a << " * x^" << b << '\n';
		cout.flush();
	}

	// Tinh gia tri don thuc khi biet x
	int Tinh(int x) {
		return a * pow(x, b);
	}

	// Tinh dao ham
	DonThuc DaoHam() {
		return DonThuc(a * b, b - 1);
	}

	// Tinh tong 2 don thuc cung bac
	DonThuc operator+(const DonThuc& other) {
		if (b != other.b) {
			cout << "Khong cung bac\n";
			cout.flush();
			return DonThuc();
		}
		return DonThuc(a + other.a, b);
	}
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    DonThuc P, Q, K;
    P.Nhap();
    Q.Nhap();
    K = P + Q;
    K.Xuat();
    return 0;
}