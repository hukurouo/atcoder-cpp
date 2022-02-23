# 入出力
行単位での入力 : getline(cin, s); // 変数sで入力を一行受け取る
出力桁数の指定 : printf("%.6f", sqrt(x));
改行 : printf("\n");

# 配列
vector<int> v;
vector<vector<int>> vec(n);
vector<vector<int>> vec(10010, v);
ソート : sort(vec.begin(), vec.end());
sort(A, A + n, greater<long long>());
範囲for文 : for (int x : a) {cout << x << endl;}
auto : for (auto p : a) {auto key = p.first; auto value = p.second; }
先頭n件抽出 : vec.resize(n)
連結 : list.insert(list.end(), d.begin(), d.end());

# コンテナ
// https://atcoder.jp/contests/apg4b/tasks/APG4b_aa
map<int,int> map;
所属判定 : map.count(key); // map[key]でアクセスすると0で初期化される
queue<int> queue; queue.front();
priority_queue<int> pq; pq.top();
priority_queue<int, vector<int>, greater<int>>
set<int> set; // setに属する x より大きい要素のうち最小の要素を取得できる

# define
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)