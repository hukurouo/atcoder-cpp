#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc218/tasks/abc218_c

int n;

int main() {
  cin >> n;
  set<pair<int, int>> s, t;
  char c;
  rep(i, 0, n) rep(j, 0, n) {
    cin >> c;
    if (c == '#') s.insert(make_pair(i, j));
  }
  rep(i, 0, n) rep(j, 0, n) {
    cin >> c;
    if (c == '#') t.insert(make_pair(i, j));
  }

  rep(i, 0, 4) {
    pair<int, int> mins = *begin(s);
    pair<int, int> mint = *begin(t);
    set<pair<int, int>> ds, dt, tt;
    for (auto v : s) {  // 平行移動; 最左上の座標を(0,0)に移動する
      ds.insert(make_pair(v.first - mins.first, v.second - mins.second));
    }
    vector<pair<int, int>> memo;
    for (auto v : t) {
      memo.push_back(v);
      dt.insert(make_pair(v.first - mint.first, v.second - mint.second));
    }
    if (ds == dt) {
      cout << "Yes" << endl;
      exit(0);
    }
    for (auto v : memo) {
      t.erase(v);
    }
    for (auto v : dt) {  // 回転
      t.insert(make_pair(v.second, v.first * (-1)));
    }
  }
  cout << "No" << endl;
}

// グリッドの回転・平行移動
// setを使うと楽