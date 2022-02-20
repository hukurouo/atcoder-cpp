#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc239/tasks/abc239_e

int N, Q, X[100100];
vector<int> Memo[100100];

vector<int> dfs(int u, int parent, vector<vector<int>>&g) {
  vector<int> list;
  for (int to : g[u]) {
    if (to == parent) {
      continue;
    }
    vector<int> d = dfs(to, u, g);
    list.insert(list.end(), d.begin(), d.end());
  }
  list.push_back(X[u - 1]);
  sort(list.begin(), list.end());
  reverse(list.begin(), list.end());
  if (list.size() > 20) { list.resize(20); }
  Memo[u] = list;
  return list;
}

int main() {
  cin >> N >> Q;
  rep(i, 0, N) { cin >> X[i]; }

  int a, b;
  vector<vector<int>> g(N + 1);
  rep(i, 0, N - 1) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  dfs(1, 0, g);

  int v, k;
  rep(i, 0, Q) { 
    cin >> v >> k; 
    cout << Memo[v][k-1] << endl;
  }
}