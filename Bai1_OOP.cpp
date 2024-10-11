/**
 *    author:  longvu
 *    created: 10/11/24 22:13:06
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

class cArray {
private:
    vector<int> a;
    int n;
public:
    void Nhap() {
        cout << "Nhap so phan tu: ";
        cout.flush();
        cin >> n;
        a.resize(n);
        cout << "Nhap day so: ";
        cout.flush();
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
    }

    void Xuat() {
        cout << "Day so la: ";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        cout.flush();
    }

    // Tao mang ngau nhien
    void TaoDay(int n) {
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            a[i] = rand() % 100;
        }
    }

    // Dem so lan xuat hien cua x
    void Dem(int x) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                ++cnt;
            }
        }
        cout << "So lan xuat hien cua " << x << " la ";
        cout << cnt << '\n';
        cout.flush();
    }

    // Kiem tra day so o tang dan hay khong
    bool KiemTraTang() {
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // Tim so nho nhat trong day
    int Min() {
        int res = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] < res) {
                res = a[i];
            }
        }
        return res;
    }

    // Sap xep day tang dan
    void SapXep() {
        sort(all(a));
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cArray a;
    a.Nhap();
    a.Xuat();
    a.TaoDay(10);
    a.Xuat();
    a.Dem(5);
    cout << "Day so tang dan: ";
    cout.flush();
    cout << a.KiemTraTang() << '\n';
    cout << "So nho nhat trong day: ";
    cout.flush();
    cout << a.Min() << '\n';
    a.SapXep();
    a.Xuat();
    return 0;
}