#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
using ll = long long;
using P = pair<int, int>;

// https://atcoder.jp/contests/abc176/tasks/abc176_e

int h, w, m;
int main() {
  cin >> h >> w >> m;
  vector<int> hv(h), wv(w);
  int _h, _w;
  set<P> set;
  rep(i, 0, m) {
    cin >> _h >> _w;
    _h -= 1;
    _w -= 1;
    hv[_h] += 1;
    wv[_w] += 1;
    set.emplace(_h, _w);
  }
  int hmax = 0, wmax = 0;
  rep(i, 0, h) hmax = max(hmax, hv[i]);
  rep(i, 0, w) wmax = max(wmax, wv[i]);

  vector<int> hl, wl;
  rep(i, 0, h) if (hmax == hv[i]) hl.emplace_back(i);
  rep(i, 0, w) if (wmax == wv[i]) wl.emplace_back(i);

  int ans = hmax + wmax;
  for (int h : hl)
    for (int w : wl) {
      if (set.count(P(h, w))) continue;
      cout << ans << endl;
      return 0;
    }
  cout << ans - 1 << endl;
}