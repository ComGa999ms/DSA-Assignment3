#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define fi first
#define se second
#define pii pair <int,int>
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())

using namespace std;

const int N = 1e6 + 5;

int n, m, q;
vector <string> a;
vector <string> X;

void solve(void) {
    cin >> n >> m >> q;
    a.resize(n + 1);

    rep(i, 1, n) {
        string x; cin >> x;
        a[i] = " " + x;
    }

    rep(i, 1, n) rep(j, 1, m) {
        string s;
        rep(k, j, min(j + 9, m)) {
            s += a[i][k];
            if (sz(s) >= 2) X.push_back(s);
        }
    }

    rep(j, 1, m) rep(i, 1, n) {
        string si;
        rep(k, i, min(i + 9, n)) {
            si += a[k][j];
            if (sz(si) >= 2) X.push_back(si);
        }
    }

    sort(all(X));
    X.erase(unique(all(X)), X.end());

    while (q-- ) {
        string x; cin >> x;
        cout << (binary_search(all(X), x) == 0 ? 0 : 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
