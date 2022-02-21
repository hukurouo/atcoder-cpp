#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc240/tasks/abc240_d

int main() {
  int n;
  cin >> n;
  int A[n];
  rep(i, 0, n) cin >> A[i];

  stack<int> st;
  stack<pair<int, int>> stm;
  for (auto i : A) {
    if (stm.empty() || stm.top().first != i) {
      stm.push(make_pair(i, 1));
      st.push(i);
    } else {
      int cnt = stm.top().second;
      stm.pop();
      cnt++;
      if (cnt == i) {
        rep(i, 0, cnt-1) st.pop();
      } else {
        stm.push(make_pair(i, cnt));
        st.push(i);
      }
    }
    cout << st.size() << endl;
  }
}
