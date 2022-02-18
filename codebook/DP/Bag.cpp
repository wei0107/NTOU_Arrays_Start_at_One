/*背包問題*/
// n,m,price,value

// 0/1滾動
const int N = 500, W = 2000000; //N個物品,耐重W
int cost[N], weight[N];
int c[W + 1];
void knapsack(int n, int w){
	c[0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = w; j - weight[i] >= 0; --j)
			c[j] = max(c[j], c[j - weight[i]] + cost[i]);
	cout << c[w];
}

// 完全
for (int j = 1; j <= price; ++j)
if (f[j - price] + value > f[j])
f[j] = f[j - price] + value;