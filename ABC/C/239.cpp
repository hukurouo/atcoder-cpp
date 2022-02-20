#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc239/tasks/abc239_c

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  map<pair<int, int>, bool> map;
  vector<int> d = {-2, -1, 1, 2};
  for (int dx : d) {
    for (int dy : d) {
      if (abs(dx) == abs(dy)) {
        continue;
      }
      pair<int, int> pair = make_pair(x1 + dx, y1 + dy);
      map[pair] = true;
    }
  }
  for (int dx : d) {
    for (int dy : d) {
      if (abs(dx) == abs(dy)) {
        continue;
      }
      pair<int, int> pair = make_pair(x2 + dx, y2 + dy);
      if (map[pair]) {
        cout << "Yes" << endl;
        exit(0);
      }
    }
  }
  cout << "No" << endl;
}