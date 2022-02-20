#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc239/tasks/abc239_b

long long x;

int main() {
  cin >> x;
  if (x < 0 && x % 10 != 0) {
    cout << x / 10 - 1 << endl;
  } else {
    cout << x / 10 << endl;
  }
}