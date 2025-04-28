#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define int long long
#define fi first
#define se second
#define pii pair <int,int>
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())

using namespace std;

const int N = 1e6 + 5;

int n, q;
pii a[N], temp[N];

bool cmp(pii ai, pii bi) {
    return ai.fi <= bi.fi;
}

void merge1(int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r) {
        if (cmp(a[i], a[j])) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    rep(i, l, r) a[i] = temp[i];
}

void mergeSort(int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge1(l, mid, r);
    }
}

void solve(void) {
    cin >> n >> q;
    rep(i, 1, n) cin >> a[i].fi, a[i].se = i;

    mergeSort(1, n);

    while (q-- ) {
        string _; int op, x;
        cin >> _ >> op >> x;

        if (op == 1) {
            int L = 1, R = n, res = -1;
            while (L <= R) {
                int mid = (L + R) >> 1;

                if (a[mid].fi >= x) {
                    if (a[mid].fi == x) res = a[mid].se;
                    R = mid - 1;
                } else L = mid + 1;
            }

            cout << res << endl;
        } else {
            int L = 1, R = n, res = -1;
            while (L <= R) {
                int mid = (L + R) >> 1;

                if (a[mid].fi <= x) {
                    if (a[mid].fi == x) res = a[mid].se;
                    L = mid + 1;
                } else R = mid - 1;
            }

            cout << res << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
