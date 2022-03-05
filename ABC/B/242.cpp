#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc242/tasks/abc242_b

int main() {
  string s;
  getline(cin, s);
  int n = s.length();
  char A[n];
  rep(i, 0, n) A[i] = s[i];
  sort(A, A + n);
  rep(i, 0, n) cout << A[i];
  cout << endl;
}