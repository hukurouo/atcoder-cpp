#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc241/tasks/abc241_c

int n;
int main() {
  cin >> n;
  char M[n][n];
  rep(i, 0, n) rep(j, 0, n) cin >> M[i][j];

  // yoko
  rep(i, 0, n) {
    rep(j, 0, n - 5) {
      int cnt = 0;
      rep(k, 0, 6) {
        if (M[i][j + k] == '#') {
          cnt += 1;
        }
      }
      if (cnt >= 4) {
        cout << "Yes" << endl;
        exit(0);
      }
    }
  }
  // tate
  rep(i, 0, n - 5) {
    rep(j, 0, n) {
      int cnt = 0;
      rep(k, 0, 6) {
        if (M[i + k][j] == '#') {
          cnt += 1;
        }
        if (cnt >= 4) {
          cout << "Yes" << endl;
          exit(0);
        }
      }
    }
  }
  // naname
  rep(i, 0, n - 5) {
    rep(j, 0, n - 5) {
      int cnt = 0;
      rep(k, 0, 6) {
        if (M[i + k][j + k] == '#') {
          cnt += 1;
        }
        if (cnt >= 4) {
          cout << "Yes" << endl;
          exit(0);
        }
      }
      cnt = 0;
      rep(k, 0, 6) {
        if (M[i + 5 - k][j + k] == '#') {
          cnt += 1;
        }
        if (cnt >= 4) {
          cout << "Yes" << endl;
          exit(0);
        }
      }
    }
  }
  cout << "No" << endl;
}