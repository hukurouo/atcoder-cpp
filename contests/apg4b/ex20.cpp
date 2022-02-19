#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)

// https://atcoder.jp/contests/apg4b/tasks/APG4b_cc

int n;
vector<int> v;

int f(int i, vector<vector<int>> &v) {
  int n = v[i].size();
  if (n == 0) {
    return 1;
  }
  int sum = 0;
  rep(j, 0, n) {
    sum += f(v[i][j], v);
  }
  return sum + 1;
}

int main() {
  cin >> n;
  vector<vector<int>> vec(n+1,v);
  rep(i, 1, n) {
    int t;
    cin >> t;
    vec[t].push_back(i);
  }
  rep(i, 0, n) { 
    cout << f(i, vec) << endl;
  }
}

// 再帰関数