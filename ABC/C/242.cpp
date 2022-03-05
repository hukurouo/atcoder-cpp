#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc242/tasks/abc242_c

int n;
int main() {
  cin >> n;
  int MOD = 998244353;
  long long memo[9];
  rep(i, 0, 9) memo[i] = 1;
  rep(i, 0, n-1) {
    long long t[9];
    t[0] = memo[0] + memo[1];
    rep(i, 1, 8) t[i] = memo[i-1] + memo[i] + memo[i+1];
    t[8] = memo[8] + memo[7];
    rep(i, 0, 9) memo[i] = t[i] % MOD;
  }
  long long ans = 0;
  rep(i, 0, 9) ans += memo[i];
  cout << ans % MOD << endl;
}