#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
using ll = long long;
using P = pair<int, int>;

// https://atcoder.jp/contests/abc054/tasks/abc054_c

bool is_find(vector<int> v, int x) {
  bool is_find = false;
  rep(i, 0, v.size()) {
    if (v[i] == x) is_find = true;
  }
  return is_find;
}

int n, m;
int main() {
  cin >> n >> m;
  int a, b;
  vector<vector<int>> g(n);
  rep(i, 0, m) {
    cin >> a >> b;
    a--;
    b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  using Pv = pair<vector<int>, int>;
  queue<Pv> queue;
  vector<int> v;
  set<vector<int>> set;
  v.emplace_back(0);
  queue.push(make_pair(v, 0));
  while (!queue.empty()) {
    Pv top = queue.front();
    queue.pop();
    if (top.first.size() == n) {
      set.insert(top.first);
    }
    
    for (auto to : g[top.second]) {
      if (!is_find(top.first, to)) {
        vector<int> tv = top.first;
        tv.emplace_back(to);
        queue.push(make_pair(tv, to));
      }
    };
  }
  cout << set.size() << endl;
}