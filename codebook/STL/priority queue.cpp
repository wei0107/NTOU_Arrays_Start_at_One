/*--------priority_queue--------*/
• top()
• push()
• pop()
• emplace()

priority_queue<T> pq //預設由大排到小
priority_queue<int, vector<int>, less<int> > pq;
priority_queue<T, vector<T>, greater<T> > pq;  //改成由小排到大
priority_queue<T, vector<T>, cmp> pq; //自行定義 cmp 排序

struct cmp {
    bool operator()(node a, node b) {
        /*priority_queue優先判定為!cmp，所以「由大排到小」需「反向」定義
         實現「最小值優先」*/
        return a.x < b.x;
    }
};