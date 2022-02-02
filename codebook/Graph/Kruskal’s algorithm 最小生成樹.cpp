/*Kruskal’s algorithm 最小生成樹*/
struct Edge {
    int u, v, w;    // 點 u 連到點 v 並且邊權為 w
    friend bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs.w > rhs.w;    //兩條邊比較大小用邊權比較
    }
};

Edge graph[m];    // 宣告"邊"型態的陣列 graph
init(N);    //N個邊
sort(graph, graph + m); // 將邊照大小排序
int ans = 0;    //權重和
for (int i = 0; i < m; i++) {
    if (find(graph[i].u) != find(graph[i].v)) { // 如果兩點未聯通
        merge(graph[i].u, graph[i].v);    // 將兩點設成同一個集合
        ans += graph[i].w;    // 權重加進答案
    }
}

/*使用pq取代sort*/
int main() {
    int i, n, a, b, d;
    while (cin >> n) {

        if (n == 0)break;
        init(n);
        priority_queue<Edge> graph;// 宣告邊型態的陣列 graph
        //priority_queue需改成return lhs.w > rhs.w; 
        for (i = 0; i < n * (n - 1) / 2; i++) {
            cin >> a >> b >> d;
            graph.push(Edge{a,b,d});
        }

        int ans = 0;
        for (i = 0; i < n * (n - 1) / 2; i++) {
            if (find(graph.top().u) != find(graph.top().v)) { // 如果兩點未聯通
                merge(graph.top().u, graph.top().v);    // 將兩點設成同一個集合
                ans += graph.top().w;    // 權重加進答案
            }
            graph.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}