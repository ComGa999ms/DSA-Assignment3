#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define int long long
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())

using namespace std;

int n;

bool cmp1(string a, string b) {
    if (sz(a) != sz(b)) return sz(a) < sz(b);
    return a < b;
}

void merge1(vector<string> &v, int l, int mid, int r) {
    vector<string> temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (cmp1(v[i], v[j])) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }
    while (i <= mid) temp[k++] = v[i++];
    while (j <= r) temp[k++] = v[j++];

    rep(i, 0, k - 1) v[l + i] = temp[i];
}

void mergeSort1(vector<string> &v, int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        mergeSort1(v, l, mid);
        mergeSort1(v, mid + 1, r);
        merge1(v, l, mid, r);
    }
}

bool cmp2(const pair<int, string> &a, const pair<int, string> &b) {
    if (a.fi != b.fi) return a.fi > b.fi;
    if (sz(a.se) != sz(b.se)) return sz(a.se) < sz(b.se);
    return a.se < b.se;
}

void merge2(vector<pair<int, string>> &v, int l, int mid, int r) {
    vector<pair<int, string>> temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (cmp2(v[i], v[j])) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }
    while (i <= mid) temp[k++] = v[i++];
    while (j <= r) temp[k++] = v[j++];

    rep(i, 0, k - 1) v[l + i] = temp[i];
}

void mergeSort2(vector<pair<int, string>> &v, int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        mergeSort2(v, l, mid);
        mergeSort2(v, mid + 1, r);
        merge2(v, l, mid, r);
    }
}

void solve(void) {
    cin >> n;

    vector<string> a(n);
    for (auto &x : a) cin >> x;

    mergeSort1(a, 0, n - 1);

    vector<pair<int, string>> candidates;
    rep(i, 0, n - 1) {
        int j = i, cnt = 0;
        while (j < n && a[i] == a[j]) j++, cnt++;

        candidates.push_back(make_pair(cnt, a[i]));
        i = j - 1;
    }

    mergeSort2(candidates, 0, sz(candidates) - 1);

    for (auto &T : candidates) cout << T.se << " " << T.fi << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
