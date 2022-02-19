#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rrep(i,a,b) for (int i = a; i >= b; i--)

// https://atcoder.jp/contests/abc107/tasks/abc107_b

int h, w;
string A[110];

int main() {
  cin >> h >> w;
  rep(i,0,h) { cin >> A[i]; }

  vector<bool> yoko(h, false);
  vector<bool> tate(w, false);
  rep(i,0,h) rep(j,0,w) {
    if (A[i][j] == '#') {
      yoko[i] = true;
      tate[j] = true;
    }
  }
  rep(i,0,h) {
    if (!yoko[i]) {
      continue;
    }
    rep(j,0,w) {
      if (tate[j]) {
        cout << A[i][j];
      }
    }
    cout << endl;
  }
}