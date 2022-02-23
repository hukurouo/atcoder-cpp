#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc217/tasks/abc217_d

int L, Q;

int main() {
  cin >> L >> Q;
  vector<int> a;
  a.push_back(0);
  a.push_back(L);

  int c, q;
  rep(i, 0, Q) {
    cin >> c >> q;
    if (c == 1) {
      int idx = lower_bound(a.begin(), a.end(), q) - a.begin();
      a.insert(a.begin() + idx, q);
    } else {
      int idx = lower_bound(a.begin(), a.end(), q) - a.begin();
      cout << a[idx] - a[idx - 1] << endl;
    }
  }
}

// 二分探索