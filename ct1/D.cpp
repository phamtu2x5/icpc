#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int N, ST, EN, u, d;

int main() {
    fastIO
    cin >> N >> ST >> EN >> u >> d;

    if (ST == EN) {
        cout << 0;
        return 0;
    }

    vector<int> visited(N + 1, -1);
    queue<pair<int, int>> q;
    q.push({ST, 0});
    visited[ST] = 0;

    while (!q.empty()) {
        int current = q.front().first;
        int presses = q.front().second;
        q.pop();

        if (current + u <= N && visited[current + u] == -1) {
            visited[current + u] = presses + 1;
            q.push({current + u, presses + 1});
            if (current + u == EN) {
                cout << presses + 1;
                return 0;
            }
        }

        if (current - d >= 1 && visited[current - d] == -1) {
            visited[current - d] = presses + 1;
            q.push({current - d, presses + 1});
            if (current - d == EN) {
                cout << presses + 1;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}
