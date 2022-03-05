#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc242/tasks/abc242_a

double a,b,c,x;
int main() {
  cin >> a >> b >> c >> x;
  if (x <= a) {
    cout << 1 << endl;
  } else if (x > b) {
    cout << 0 << endl;
  } else {
    double ans = c / (b - a);
    printf("%.8f", ans);
    printf("\n");
  }
}