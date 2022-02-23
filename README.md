# NTOU_Arrays_Start_at_One

## Codebook

**by 林一 2022/02/19**
### References
- [**NYCU_gAwr_gurA**](https://github.com/nella17/NYCU_gAwr_gurA)
- [**allem40306/Codebook_Sample**](https://github.com/allem40306/Codebook_Sample.git)
- [**jakao0907**](https://github.com/jakao0907/CompetitiveProgrammingCodebook)
- **NTOU Introduction to Competitive Programming**
- **NCTU PCCA 2022 Winter-Camp**
- **NTHU 2018 ION Camp**

## Training

> A:  賽中 AC <br>
> ***A***: 賽後 AC 

| Contest               | Date      | Rank   | Solved/Total | ***A*** | ***B*** | ***C*** | ***D*** | ***E*** | ***F*** | ***G*** | ***H*** | ***I*** | ***J*** | ***K*** | ***L*** |
| :----------------------------------------------------------: | :--------: | :--: | :----------: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: |
| [2022 PCCA Winter Camp](https://hackmd.io/@qwe854896/BkSMg4MAF) | 2022/1/29 | 77/153 |     1/11     | ***A*** | ***B*** |.|.| ***E*** | ***F*** |.|.|.|.| K |-|
| [2022 NTOU Winter Camp](https://hackmd.io/@jakao/HkDrN96RY#/) | 2022/2/19 | 10/16 |     2/12     |.|***B***|.|.|.| F |.|***H***|***I***| J |.|.|


## Report

### 2022 NTOU Winter Camp

#### B　O(n)質數表（寫題要細心）

```cpp=
for(int i = 2; i < n; i++)
  if(!prime[i])
  for(int j = i; i * j < n; j++) //<-錯誤 
    prime[i * j]++;
```

```cpp=
//error
for(j = i; i * j <= n; j++) 

//correct
for(j = 2; i * j <= n; j++)  
for(j = i; i * j <= n; j+=i) 
```
<br>
#### F　模擬水題（題目應看清楚）
"problem is a <font color="red">string</font> of uppercase Latin letters. The length of each problem doesn't exceed 10."

因看錯題目要求，直覺用char來定義變數，多吃了兩次RE。

* Debug筆記:
RE -> <font color="red">**型態錯誤**</font>、out of range。
<br>
#### J　字串水題（題目應看清楚）

"add <font color="red">**the least characters**</font> achieving the goal."

因看錯題目要求，多吃了兩次WA。
<br>
#### H　DP（題目應看清楚）

1. 誤解題目
2. 不會推導DP轉移式
<br>
#### I　二分搜(題目應先看)

1. 不能只看測資
2. 不能一昧的逃避浮點數
<br>
#### K　

1. 不熟悉演算法模板
2. 題單須做熟
<br>
#### 賽後檢討

1. 沒有帶到codebook(影印機問題)
 -> 應提前做好準備，防範未然。
 
2. 水題花太多時間
 -> 題目應看清楚，減少錯誤發生的機會。
 
3. 題目沒有完全理解 
 -> 加強英文，多練題目與線上賽。
 
4. 不會推導DP轉移式
 -> 多練習DP題單。
