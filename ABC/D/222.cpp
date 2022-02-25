#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc222/tasks/abc222_d

int n, a, b;
long long dp[3001][3001];

int main() {
  cin >> n;
  int A[n], B[n];
  rep(i, 0, n) cin >> A[i];
  rep(i, 0, n) cin >> B[i];

  long long mod = 998244353;
  rep(i, 0, 3001) rep(j, 0, 3001) dp[i][j] = 0;
  rep(i, A[0], B[0] + 1) dp[1][i] = 1;
  rep(i, 1, n) {
    a = A[i];
    b = B[i];
    long long t = 0;
    rep(j, 0, b + 1) {
      if (dp[i][j] != 0) {
        t += dp[i][j];
      }
      if (j < a) {
        continue;
      }
      t = t % mod;
      dp[i + 1][j] += t;
      dp[i + 1][j] = dp[i + 1][j] % mod;
      //cout << dp[i+1][j] << endl;
    }
  }
  long long ans = 0;
  rep(i, 0, 3001) {
    ans += dp[n][i];
    ans = ans % mod;
  }
  cout << ans << endl;
}