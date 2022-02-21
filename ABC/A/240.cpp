#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc240/tasks/abc240_a

int main() {
  int a, b;
  cin >> a >> b;

  if (b - a == 1 || b - a == 9) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}