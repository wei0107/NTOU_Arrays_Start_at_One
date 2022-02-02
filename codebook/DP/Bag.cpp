/*背包問題*/
// n,m,price,value
// 0/1
for (int j = m; j >= price; --j)
if (f[j - price] + value > f[j])
f[j] = f[j - price] + value;
// 完全
for (int j = 1; j <= price; ++j)
if (f[j - price] + value > f[j])
f[j] = f[j - price] + value;