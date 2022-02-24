#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc221/tasks/abc221_d

int main() {
  int n, a, b;
  cin >> n;
  using pa = pair<int, bool>;
  priority_queue<pa, vector<pa>, greater<pa>> pq;
  rep(i, 0, n) {
    cin >> a >> b;
    pq.push(make_pair(a, true));
    pq.push(make_pair(a + b, false));
  }

  int k = 0;
  int idx = 0;
  int ans[n + 1];
  rep(i, 0, n + 1) ans[i] = 0;
  while (!pq.empty()) {
    a = pq.top().first;
    ans[k] += a - idx;
    while (a == pq.top().first && !pq.empty()) {
      bool is_login = pq.top().second;
      if (is_login) {
        k += 1;
      } else {
        k -= 1;
      }
      pq.pop();
    }
    idx = a;
  }
  rep(i, 1, n) { cout << ans[i] << " "; }
  cout << ans[n] << endl;
}