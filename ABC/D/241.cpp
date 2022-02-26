#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc241/tasks/abc241_d

int n;
int main() {
  cin >> n;
  int q, k;
  long long x;
  set<long long> set;
  map<long long, int> map;

  // multiset という便利なやつあり
  // https://atcoder.jp/contests/abc241/editorial/3453

  rep(i, 0, n) {
    cin >> q;
    if (q == 1) {
      cin >> x;
      set.insert(x);
      map[x] += 1;
    } else if (q == 2) {
      cin >> x >> k;
      auto it = set.upper_bound(x);
      if (it == set.begin()) {
        cout << -1 << endl;
        continue;
      }
      --it;
      int t = 0;
      t += map[*it];
      while (t < k && it != set.begin()) {
        --it;
        t += map[*it];
      }
      if (t >= k) {
        cout << *it << endl;
      } else {
        cout << -1 << endl;
      }
    } else {
      cin >> x >> k;
      auto it = set.lower_bound(x);
      int t = 0;
      t += map[*it];
      while (t < k && it != set.end()) {
        ++it;
        t += map[*it];
      }
      if (t >= k) {
        cout << *it << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
}