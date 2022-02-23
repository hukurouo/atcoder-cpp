#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc217/tasks/abc217_d

int L, Q;

int main() {
  cin >> L >> Q;
  set<int> set;
  set.insert(0);
  set.insert(L);

  int c, q;
  rep(i, 0, Q) {
    cin >> c >> q;
    if (c == 1) {
      set.insert(q);
    } else {
      auto it = set.lower_bound(q);
      cout << *it - *prev(it) << endl;
    }
  }
}

// 順序付き集合