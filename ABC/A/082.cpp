#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < (t); ++i)

// https://atcoder.jp/contests/abc082/tasks/abc082_a

int main() {
  int a, b;
  cin >> a >> b;
  int t = a + b;
  if (t % 2 == 0) {
    cout << t / 2 << endl;
  } else {
    cout << t / 2 + 1 << endl;
  }
}