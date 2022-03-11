#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
using ll = long long;
using P = pair<int, int>;

// https://atcoder.jp/contests/abc096/tasks/abc096_d

vector<bool> prime_table(int n) {
  vector<bool> prime(n + 1, true);
  if (n >= 0) prime[0] = false;
  if (n >= 1) prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

vector<int> enumerate_primes(int n) {
  if (n <= 1) return {};
  auto d = prime_table(n);
  vector<int> primes;
  primes.reserve(count(begin(d), end(d), true));
  for (int i = 0; i < d.size(); i++) {
    if (d[i]) primes.push_back(i);
  }
  return primes;
}

int n;
int main() {
  cin >> n;
  auto d = enumerate_primes(55555);
  int cnt = 0;
  for (int p : d) {
    if (p % 5 == 1) {
      cout << p;
      cnt++;
      if (cnt == n) {
        cout << endl;
        return 0;
      } else {
        cout << " ";
      }
    }
  }
}