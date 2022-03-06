#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc233/tasks/abc233_e

int main() {
  string s;
  getline(cin, s);
  int n = s.length();
  int dp[n + 1];
  int t = 0;
  vector<int> v;
  rep(i, 0, n) {
    dp[i] = int(s[i] - '0');
    t += dp[i];
  }
  int mu = 0;
  rep(i, 0, n-1) {
    v.emplace_back((t+mu) % 10);
    mu = (t + mu) / 10;
    t -= dp[n-i-1];
  }
  cout << t + mu;
  rep(i, 1, n) cout << v[n-i-1];
  cout << endl;
}