#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc218/tasks/abc218_e

struct UnionFind {
  vector<int> data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if (data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

int N, M;

int main() {
  cin >> N >> M;
  vector<tuple<int, int, int>> vec;
  UnionFind uf(N + 1);
  int a, b, c;
  rep(i, 0, M) {
    cin >> a >> b >> c;
    if (c < 0) {
      uf.unite(a, b);
    } else {
      vec.push_back(make_tuple(c, a, b));
    }
  }
  sort(vec.begin(), vec.end());
  long long ans = 0;
  for (auto tp : vec) {
    tie(c, a, b) = tp;
    if (uf.same(a, b)) {
      ans += c;
    } else {
      uf.unite(a, b);
    }
  }
  cout << ans << endl;
}