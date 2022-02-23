#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// https://atcoder.jp/contests/abc217/tasks/abc217_e

int n;

int main() {
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  queue<int> queue;
  rep(i, 0, n) {
    int q, x;
    cin >> q;
    if (q == 1) {
      cin >> x;
      queue.push(x);
    } else if (q == 2) {
      if (pq.size() > 0) {
        cout << pq.top() << endl;
        pq.pop();
      } else {
        cout << queue.front() << endl;
        queue.pop();
      }
    } else {
      int size = queue.size();
      rep(i, 0, size) {
        x = queue.front();
        queue.pop();
        pq.push(x);
      }
    }
  }
}