#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc185/tasks/abc185_f

template <typename T>
struct BinaryIndexedTree {
 private:
  int n;
  vector<T> data;

 public:
  BinaryIndexedTree() = default;

  explicit BinaryIndexedTree(int n) : n(n) { data.assign(n + 1, 0); }

  explicit BinaryIndexedTree(const vector<T> &v)
      : BinaryIndexedTree((int)v.size()) {
    build(v);
  }

  void build(const vector<T> &v) {
    assert(n == (int)v.size());
    for (int i = 1; i <= n; i++) data[i] = v[i - 1];
    for (int i = 1; i <= n; i++) {
      int j = i + (i & -i);
      if (j <= n) data[j] ^= data[i];
    }
  }

  void apply(int k, const T &x) {
    for (++k; k <= n; k += k & -k) data[k] ^= x;
  }

  T prod(int r) const {
    T ret = T();
    for (; r > 0; r -= r & -r) ret ^= data[r];
    return ret;
  }

  T prod(int l, int r) const { return prod(r) ^ prod(l); }
};

int n, q;
int main() {
  cin >> n >> q;
  int a;
  vector<int> v;
  rep(i, 0, n) {
    cin >> a;
    v.emplace_back(a);
  }
  BinaryIndexedTree<int> bit(v);

  int t, x, y;
  rep(i, 0, q) {
    cin >> t >> x >> y;
    if (t == 1) {
      bit.apply(x-1, y);
    } else {
      cout << bit.prod(x-1, y) << endl;
    }
  }
}