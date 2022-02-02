/*Adjacency list for DFS And BFS*/

typedef struct node* nodePointer;  /*每一個節點裝入linkedlist*/
typedef struct node {
    int vertex;
    nodePointer link;
};

bool visited[MAX_VERTICES];  /* intitial: FALSE */
nodePointer graph[MAX_VERTICES];


void dfs(int v)
{/* 從一個點v開始對這個圖的深度優先搜尋 */
    nodePointer w;
    visited[v] = TRUE;
    cout << v;
    for (w = graph[v]; w; w = w->link)
        if (!visited[w->vertex]) {
            cout << " ";
            dfs(w->vertex);
        }
}

void bfs(int v)
{/* 從圖的頂點v開始做廣度(寬度)優先搜尋。
    全域陣列visited初始是0，佇列的運作和第四章的相似，front和rear是全域變數 */
    nodePointer w;
    queue <int> q;/* 佇列初始化 */
    cout << v;
    visited[v] = TRUE;
    q.push(v);
    while (q.size()) {
        v = q.front();
        q.pop();
        for (w = graph[v]; w; w = w->link)
            if (!visited[w->vertex]) {
                cout << " " << w->vertex;
                q.push(w->vertex);
                visited[w->vertex] = TRUE;
            }
    }
}

void create_node(int a, int b) {
    nodePointer temp = new(node);//將 b 接到 graph[a](list) 的最後。
    nodePointer current = graph[a];
    while (current->link) current = current->link;
    temp->vertex = b; current->link = temp; temp->link = NULL;

    nodePointer temp_a = new(node);//將 a 接到 graph[b](list) 的最後。
    current = graph[b];
    while (current->link)current = current->link;
    temp_a->vertex = a; current->link = temp_a; temp_a->link = NULL;
}
int main() {

    int a, b;
    for (int i = 0; i < MAX_VERTICES; i++) {//建立所有list
        nodePointer temp = new(node);
        temp->vertex = i;
        temp->link = NULL;
        graph[i] = temp;
    }
    while (cin >> a >> b) create_node(a, b);
    dfs(0);	/* DFS */
	for (auto& it : visited)it = FALSE;	/* 初始化 */
	bfs(0);	/* BFS */
    return 0;
}