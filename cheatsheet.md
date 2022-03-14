# 入出力
行単位での入力 : getline(cin, s); // 変数sで入力を一行受け取る
出力桁数の指定 : printf("%.6f", sqrt(x));
改行 : printf("\n");
cout << setprecision(20);

# 配列
vector<int> v;
vector<vector<int>> vec(n);
vector<vector<int>> vec(10010, v);
ソート : sort(vec.begin(), vec.end());
sort(A, A + n, greater<long long>());
削除 : vec.erase(vec.begin() + idx);
using P = pair<int, int>;
sort(v.begin(), v.end(), [](P& a, P& b) { return a.second < b.second; });
範囲for文 : for (int x : a) {cout << x << endl;}
auto : for (auto p : a) {auto key = p.first; auto value = p.second; }
先頭n件抽出 : vec.resize(n)
連結 : list.insert(list.end(), d.begin(), d.end());
int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
v.insert(v.begin() + idx, x);
削除 : v.erase(v.begin() + idx);
二分探索 : upper_bound(x) xより大きい lower_bound(x) x以上

# コンテナ
// https://atcoder.jp/contests/apg4b/tasks/APG4b_aa
map<int,int> map;
所属判定 : map.count(key); // map[key]でアクセスすると0で初期化される
queue<int> queue; queue.front();
priority_queue<int> pq; pq.top();
priority_queue<int, vector<int>, greater<int>> 小さい順
set<int> set; // setに属する x より大きい要素のうち最小の要素を取得できる
auto it = set.lower_bound(x); it != set.end();
set(pair) : set<P> set; set.emplace(i,j); set.count(P(i,j));

# define
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }