#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc230/tasks/abc230_d

int n, d;
int main() {
  using P = pair<int, int>;

  cin >> n >> d;
  vector<P> v;
  int l, r;
  rep(i, 0, n) {
    cin >> l >> r;
    v.push_back(make_pair(l,r));
  }
  sort(v.begin(), v.end(), [](P& a, P& b) { return a.second < b.second; });
  queue<P> queue;
  rep(i, 0, n) queue.push(v[i]);
  int cnt = 0;
  while (!queue.empty()) {
    r = queue.front().second;
    queue.pop();
    cnt += 1;
    while (queue.front().first < r + d && !queue.empty()) {
      queue.pop();
    }
  }
  cout << cnt << endl;
}