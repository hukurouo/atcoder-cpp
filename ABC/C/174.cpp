#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc174/tasks/abc174_c

int k;
int main() {
  cin >> k;
  int max = 1000000;
  long long d[max];
  d[0] = 0;
  rep(i, 1, max) {
    d[i] = (10 * d[i - 1] + 7) % k;
    if (d[i] == 0) {
      cout << i << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
}