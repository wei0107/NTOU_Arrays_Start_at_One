/*--------常用工具--------*/
swap(a,b);
min(a,b);
max({ a, b, c });

//math
abs(x);
pow(x);
sqrt(x);
__gcd(x, y);
__lg(x)  //以2為底數
log(x)	 //以e為底數
log10(x) //以10為底數

//陣列處理
sort(arr,arr+n);
reverse(arr,arr+n);
*min_element(arr, arr+n); //value
min_element(arr, arr+n) - arr; //index
*lower_bound(arr, arr+4, c) << '\n'; //第一個大於等於 c 
*upper_bound(arr, arr+4, c) << '\n'; //第一個大於 c 
fill(arr, arr+3, 123); //取代 arr[0]=123 arr[1]=123 arr[2]=123

//輸出
cout << fixed << setprecision(10); //四捨五入 或是更高精度(int)10 * 位數 + 0.5
cout << setw(n) << setfill(c) << ; //寬度n 用char(c)填補

//迭代器
T.begin() //返回一個迭代器，它指向容器c的第一個元素
T.end() //返回一個迭代器，它指向容器c的最後一個元素的下一個位置
T.rbegin() //返回一個逆序迭代器，它指向容器c的最後一個元素
T.rend() //返回一個逆序迭代器，它指向容器c的第一個元素前面的位置
T.find() //可用於set,map的earse()。