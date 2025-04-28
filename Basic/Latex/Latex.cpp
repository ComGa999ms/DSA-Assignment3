#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define sz(v) (int)(v).size()
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;

void solve(void) {
    string s;
    getline(cin, s);
    int n = sz(s);

    stack<char> st;
    rep(i, 0, n - 1) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                cout << 0;
                return;
            }
            char op = st.top();
            if ((c == ')' && op != '(') || (c == ']' && op != '[') || (c == '}' && op != '{')) {
                cout << 0;
                return;
            }
            st.pop();
        }
    }
    if (st.size()) cout << 0;
    else cout << 1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
