#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
using ll = long long;
using P = pair<int, int>;

// https://atcoder.jp/contests/abc089/tasks/abc089_d

int h, w, d, q;
int main() {
  cin >> h >> w >> d;
  map<int, P> map;
  int a;
  rep(i, 0, h) rep(j, 0, w) {
    cin >> a;
    map[a] = make_pair(i, j);
  }
  vector<vector<int>> vec(d);
  rep(i, 0, d) {
    int j = i + 1;
    int di = (j == d) ? 0 : j;
    vec[di].emplace_back(0);
    while ((j + d) <= h * w) {
      int cost = abs(map[j+d].first - map[j].first) + abs(map[j+d].second - map[j].second);
      int last = vec[di].back();
      vec[di].emplace_back(last + cost);
      j += d;
    }
  }
  cin >> q;
  int l,r;
  rep(i, 0, q) {
    cin >> l >> r;
    if (l%d == 0) {
      cout << vec[l%d][(r/d)-1] - vec[l%d][(l/d)-1] << endl; 
    } else {
      cout << vec[l%d][(r/d)] - vec[l%d][(l/d)] << endl; 
    }
  }
}