#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc216/tasks/abc216_e

int n, k, A[200200];

int main() {
  cin >> n >> k;
  rep(i, 0, n) cin >> A[i];
  sort(A, A + n, greater<long long>());

  long long ans = 0;
  long long cnt = 1;
  long long pt = A[0];
  long long nt;

  rep(i, 0, n) {
    pt = A[i];
    nt = A[i + 1];
    if ((pt - nt) * cnt > k) {
      int div = k / cnt;
      int rem = k % cnt;
      ans += cnt * (pt + (pt - div + 1)) * (div) / 2;
      ans += rem * (pt - div);
      break;
    } else {
      ans += cnt * (pt + (nt + 1)) * (pt - nt) / 2;
      k -= (pt - nt) * cnt;
      cnt += 1;
    }
  }
  cout << ans << endl;
}