#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
using ll = long long;
using P = pair<int, int>;

// https://atcoder.jp/contests/abc200/tasks/abc200_d

int n;
int main() {
  cin >> n;
  int A[n];
  rep(i, 0, n) cin >> A[i];
  int dp[200][200];
  set<int> memo;
  bool supecial_case = false;
  memo.insert(0);
  rep(i, 0, n) {
    int a = A[i] % 200;
    if (i == 0 && a == 0) {
      supecial_case = true;
    }
    if (i > 0 && supecial_case) {
      cout << "Yes" << endl;
      cout << 1 << " " << 2 << endl;
      cout << 2 << " " << 1 << " " << 2 << endl;
      return 0;
    }
    vector<int> tv;
    for (int m : memo) {
      int d = (m + a) % 200;
      if (memo.count(d)) {
        bool flag = false;
        rep(j, 0, n) {
          if (dp[d][j] == 1) flag = true;
        }
        if (flag) {
          int b = 1, c = 0;
          vector<int> bl, cl;
          rep(j, 0, n) {
            if (dp[m][j] == 1) {
              b++;
              bl.emplace_back(j + 1);
            }
          }
          bl.emplace_back(i + 1);
          rep(j, 0, n) {
            if (dp[d][j] == 1) {
              c++;
              cl.emplace_back(j + 1);
            }
          }
          cout << "Yes" << endl;
          cout << b;
          rep(j, 0, bl.size()) cout << " " << bl[j];
          cout << endl;
          cout << c;
          rep(j, 0, cl.size()) cout << " " << cl[j];
          cout << endl;
          return 0;
        }
      }
      rep(j, 0, i) if (dp[m][j] == 1) dp[d][j] = 1;
      dp[d][i] = 1;
      tv.emplace_back(d);
    }
    for (int t : tv) {
      memo.insert(t);
    }
  }
  cout << "No" << endl;
}