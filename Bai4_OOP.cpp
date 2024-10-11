/**
 *    author:  longvu
 *    created: 10/11/24 23:19:04
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
    int a, b;
public:
    friend class DaThuc;
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
        cout << a << "*x^" << b;
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
        return DonThuc(a + other.a, b);
    }

    DonThuc operator-(const DonThuc& other) {
        return DonThuc(a - other.a, b);
    }
};

class DaThuc {
private:
    vector<DonThuc> a;
public:
    // Khoi tao 1 da thuc voi bac bang 0 hoac bang n
    DaThuc(int n = 0) {
        a.resize(n + 1);
    }

    // Tinh gia tri cua da thuc khi biet x
    int TinhGiaTri(int x) {
        int res = 0;
        for (int i = 0; i < sz(a); ++i) {
            res += a[i].Tinh(x);
        }
        return res;
    }

    void Nhap() {
        cout << "Nhap so bac cua da thuc: ";
        cout.flush();
        int n;
        cin >> n;
        a.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            cout << "Nhap he so thu " << i << ":\n";
            cout.flush();
            int x;
            cin >> x;
            a[i] = DonThuc(x, i);
        }
    }

    void Xuat() {
        cout << "Da thuc la: ";
        for (int i = 0; i < sz(a); ++i) {
            a[i].Xuat();
            if (i != sz(a) - 1) {
                cout << "+";
            }
        }
        cout << '\n';
        cout.flush();
    }

    // Tong 2 da thuc
    DaThuc operator+(const DaThuc& other) {
        int n = max(sz(a), sz(other.a));
        DaThuc res(n);
        for (int i = 0; i <= n; ++i) {
            res.a[i] = a[i] + other.a[i];
        }
        return res;
    }

    // Tru 2 da thuc
    DaThuc operator-(const DaThuc& other) {
        int n = max(sz(a), sz(other.a));
        DaThuc res(n);
        for (int i = 0; i <= n; ++i) {
            res.a[i] = a[i] - other.a[i];
        }
        return res;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    DaThuc a, b;
    a.Nhap();
    a.Xuat();
    b.Nhap();
    b.Xuat();
    DaThuc c = a + b;
    cout << "Tong 2 da thuc la: " << '\n';
    c.Xuat();
    return 0;
}