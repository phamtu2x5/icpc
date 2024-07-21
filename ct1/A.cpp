#include <bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;

string solve(string s, int q, vector<int>& a) {
    int n = s.length();
    vector<int> dif(n + 1, 0);
    for (int qi : a) {
        dif[qi]++;
        if ((n - qi + 1) <= n) {
            dif[n - qi + 1]--;
        }
    }
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + dif[i];
    }
    int i = 0, j = n - 1;
    while (i < j) {
        if (pre[i + 1] % 2 != 0) {
            swap(s[i], s[j]);
        }
        ++i;
        --j;
    }
    return s;
}

signed main() {
    string s;
    int q;
    cin >> s>>q;
    vector<int>a(q);
    for (int i = 0; i < q; ++i)
        cin >> a[i];
    string ans = solve(s, q,a);
    cout << ans << endl;
    return 0;
}