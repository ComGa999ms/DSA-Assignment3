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

int n, m;
int pre[N], nxt[N];

void solve(void) {
    cin >> n >> m;

    int First = 1, Last = n;

    nxt[1] = 2;
    pre[n] = n - 1;

    rep(i, 2, n) {
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }

    rep(i, 1, m) {
        int x; cin >> x;

        if (x != First) {
            int preX = pre[x];
            int nxtX = nxt[x];

            if (preX) nxt[preX] = nxtX;
            if (nxtX) pre[nxtX] = preX;

            if (x == Last) Last = preX;

            pre[x] = 0;
            nxt[x] = First;

            pre[First] = x;
            First = x;
        }
    }

    int cur = First;
    while (cur >= 0 && cur <= n) {
        cout << cur << ' ';
        cur = nxt[cur];
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
