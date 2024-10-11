/**
 *    author:  longvu
 *    created: 11/28/22 15:57:32
**/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int nax = (int)(200001);
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

int a[nax], pre[nax];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = a[i] + pre[i - 1];
    }
    while (m--) {
        int k;
        cin >> k;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] <= k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l--;
        cout << k * l - pre[l] + (pre[n] - pre[l]) - (n - l) * k << '\n';
    }
    return 0;
}