#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc223/tasks/abc223_d

int n, m;
int main() {
  cin >> n >> m;
  int M[n];
  rep(i, 0, n) M[i] = 0;
  vector<vector<int>> vec(n);
  int a, b;
  rep(i, 0, m) {
    cin >> a >> b;
    a--;
    b--;
    M[b] += 1;
    vec[a].push_back(b);
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  rep(i, 0, n) {
    if (M[i] == 0) {
      pq.push(i);
    }
  }

  vector<int> ans;
  while (!pq.empty()) {
    int t = pq.top();
    pq.pop();
    ans.push_back(t + 1);
    for (int x : vec[t]) {
      M[x] -= 1;
      if (M[x] == 0) {
        pq.push(x);
      }
    }
  }
  if (ans.size() == n) {
    rep(i, 0, n - 1) cout << ans[i] << " ";
    cout << ans[n - 1] << endl;
  } else {
    cout << -1 << endl;
  }
}

// 辞書順最小は前から貪欲
// トポロジカルソートでも可
// https://atcoder.jp/contests/abc223/editorial/2777