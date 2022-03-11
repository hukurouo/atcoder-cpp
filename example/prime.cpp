#include <bits/stdc++.h>
using namespace std;

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