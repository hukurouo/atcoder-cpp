#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc239/tasks/abc239_d

bool is_prime(int num) {
  if (num < 2) {
    return false;
  } else if (num == 2) {
    return true;
  } else if (num % 2 == 0) {
    return false;
  }
  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  vector<int> ab, cd;
  rep(i, a, b + 1) { ab.push_back(i); }
  rep(i, c, d + 1) { cd.push_back(i); }

  for (int x : ab) {
    bool first_win = true;
    for (int y : cd) {
      if (is_prime(x + y)) {
        first_win = false;
      }
    }
    if (first_win) {
      cout << "Takahashi" << endl;
      exit(0);
    }
  }
  cout << "Aoki " << endl;
}