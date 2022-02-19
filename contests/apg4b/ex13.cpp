#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)

// https://atcoder.jp/contests/apg4b/tasks/APG4b_cj

int N, A[1010];

int main() {
  cin >> N;
  rep(i, 0, N) { cin >> A[i]; }
  int t = 0;
  rep(i, 0, N) { t += A[i]; }
  int med = t / N;
  rep(i, 0, N) { cout << abs(A[i] - med) << endl; }
}