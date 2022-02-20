# 入出力
行単位での入力 : getline(cin, s); // 変数sで入力を一行受け取る
出力桁数の指定 : printf("%.6f", sqrt(x));
改行 : printf("\n");

# 配列
vector<int> v;
vector<vector<int>> vec(n);
ソート : sort(vec.begin(), vec.end());
範囲for文 : for (int x : a) {cout << x << endl;}
先頭n件抽出 : vec.resize(n)
連結 : list.insert(list.end(), d.begin(), d.end());

# define
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)