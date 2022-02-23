#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

// https://atcoder.jp/contests/abc219/tasks/abc219_d

int N, X, Y, A[310], B[310];
int dp[301][301][301];
int main() {
  cin >> N >> X >> Y;
  rep(i, 0, N) cin >> A[i] >> B[i];
  int inf = 10000;
  rep(i, 0, N + 1) rep(j, 0, 301) rep(k, 0, 301) dp[i][j][k] = inf;
  dp[0][0][0] = 0;
  rep(i, 0, N) rep(j, 0, 301) rep(k, 0, 301) {
    if (dp[i][j][k] < inf) {
      chmin(dp[i + 1][min(j + A[i], X)][min(k + B[i], Y)], dp[i][j][k] + 1);
      chmin(dp[i + 1][j][k], dp[i][j][k]);
    }
  }
  int ans = dp[N][X][Y] < inf ? dp[N][X][Y] : -1;
  cout << ans << endl;
}

// dp