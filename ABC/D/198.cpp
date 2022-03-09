#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
using ll = long long;
using P = pair<int, int>;

// https://atcoder.jp/contests/abc198/tasks/abc198_d

string s1, s2, s3;
int main() {
  cin >> s1 >> s2 >> s3;
  set<char> set;
  rep(i, 0, s1.size()) { set.insert(s1[i]); }
  rep(i, 0, s2.size()) { set.insert(s2[i]); }
  rep(i, 0, s3.size()) { set.insert(s3[i]); }
  if (set.size() > 10) {
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  map<char, int> map;
  int i = 0;
  for (char c : set) {
    map[c] = i;
    i++;
  }
  vector<int> s1c, s2c, s3c;
  rep(i, 0, s1.size()) { s1c.emplace_back(map[s1[i]]); }
  rep(i, 0, s2.size()) { s2c.emplace_back(map[s2[i]]); }
  rep(i, 0, s3.size()) { s3c.emplace_back(map[s3[i]]); }
  int n1 = s1.size();
  int n2 = s2.size();
  int n3 = s3.size();

  vector<int> v;
  rep(i, 0, 10) v.emplace_back(i);
  do {
    ll a1 = 0, a2 = 0, a3 = 0;
    if (v[s1c[0]] == 0 || v[s2c[0]] == 0 || v[s3c[0]] == 0) continue;
    if ((v[s1c[n1 - 1]] + v[s2c[n2 - 1]]) % 10 != v[s3c[n3 - 1]]) continue;
    rep(i, 0, n1) { a1 += v[s1c[i]] * pow(10, n1 - i - 1); }
    rep(i, 0, n2) { a2 += v[s2c[i]] * pow(10, n2 - i - 1); }
    rep(i, 0, n3) { a3 += v[s3c[i]] * pow(10, n3 - i - 1); }
    if (a1 + a2 == a3) {
      cout << a1 << endl;
      cout << a2 << endl;
      cout << a3 << endl;
      return 0;
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << "UNSOLVABLE" << endl;
}