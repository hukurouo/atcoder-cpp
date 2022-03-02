#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc228/tasks/abc228_d

int q;
long long A[1050000];
int main() {
  cin >> q;
  int n = pow(2, 20);
  int t;
  long long x;
  rep(i, 0, n + 1) A[i] = -1;
  set<int> set;
  rep(i, 0, n) set.insert(i);
  rep(i, 0, q) {
    cin >> t >> x;
    long long h = x;
    if (t == 1) {
      if (set.count(h % n)) {
        set.erase(h % n);
        A[h % n] = x;
      } else {
        auto it = set.lower_bound(h % n);
        if (*it >= h % n) {
          A[*it] = x;
          set.erase(*it);
        } else {
          A[*set.begin()] = x;
          set.erase(*set.begin());
        }
      }
    } else {
      cout << A[x % n] << endl;
    }
  }
}