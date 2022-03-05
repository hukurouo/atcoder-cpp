#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc230/tasks/abc230_e

long long n;
int main() {
  cin >> n;
  long long l = 1;
  long long r = n;
  long long t = n / l;
  vector<long long> v;
  v.emplace_back(0);
  while (l != r) {
    while (r-l > 1) {
      long long mid = (l + r) / 2;
      if (t != (n / mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    v.emplace_back(l);
    r = n;
    l += 1;
    t = n / l;
  }

  long long ans = 0;
  rep(i, 0, v.size()-1) {
    ans += (v[i+1] - v[i]) * (n / v[i+1]);
  }
  cout << ans + 1 << endl;
}