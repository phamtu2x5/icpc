#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define N 1000005
using namespace std;
int cnt[N];
int t,n;
signed main() {
    fastIO
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n+5);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        fill(cnt, cnt + N, 0);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        for (int i = N - 1; i >= 1; i--) {
            int tmp = 0;
            for (int j = i; j < N; j += i) {
                tmp += cnt[j];
            }
            if (tmp > 1) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
