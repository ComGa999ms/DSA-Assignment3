#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, l, r) for (int i = l; i >= r; --i)
#define fi first
#define se second
#define pii pair <int,int>
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())

using namespace std;

const int N = 1e6 + 5;

int n;
vector <int> res;

void solve(void) {
    cin >> n;
    while (n) {
        int t = n % 2;
        res.push_back(t);
        n /= 2;
    }

    repd(i, sz(res) - 1, 0) cout << res[i];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
