#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc240/tasks/abc240_c

int main() {
  int n, x, A[110], B[110];
  cin >> n >> x;
  rep(i, 0, n) cin >> A[i] >> B[i];

  vector<int> v(10010);
  vector<vector<int>> vec(n + 1, v);
  vec[0][0] = true;
  rep(i, 0, n) {
    rep(j, 0, x + 1) {
      if (vec[i][j]) {
        if (j + A[i] <= x) {
          vec[i + 1][j + A[i]] = true;
        }
        if (j + B[i] <= x) {
          vec[i + 1][j + B[i]] = true;
        }
      }
    }
  }
  if (vec[n][x]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}