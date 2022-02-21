#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc240/tasks/abc240_b

int main() {
  int n;
  cin >> n;
  set<int> s;
  int t;
  rep(i, 0, n) {
    cin >> t;
    s.insert(t);
  }
  cout << s.size() << endl;
}