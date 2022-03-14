#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
using ll = long long;
using P = pair<int, int>;

// https://atcoder.jp/contests/abc174/tasks/abc174_e

ll n, k;
int main() {
  cin >> n >> k;
  ll A[n];
  rep(i, 0, n) cin >> A[i];
  ll l = 0;
  ll r = pow(10, 10);
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    ll cnt = 0;
    rep(i, 0, n) {
      if (A[i] == mid || A[i] / mid == 0) {
      } else {
        cnt += A[i] / mid;
        if (A[i] % mid == 0) {
          cnt -= 1;
        }
      }
    }
    if (cnt <= k) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;
}

// 答えで二分探索