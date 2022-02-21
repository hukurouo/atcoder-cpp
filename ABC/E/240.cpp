#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc240/tasks/abc240_e

int n;
vector<int> g[200200];
int L[200200], R[200200];
int t = 1;

void dfs(int u, int parent) {
  L[u] = t;
  bool f = false;
  for (auto to : g[u]) {
    if (to == parent) continue;
    if (f) t++;
    dfs(to, u);
    f = true;
  }
  R[u] = t;
}

int main() {
  cin >> n;
  int u, v;
  rep(i, 0, n-1) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1,-1);
  rep(i, 0, n) {
    cout << L[i+1] << " " << R[i+1] << endl;
  }
}

// オイラーツアー