# Hashing
---
## 一、 核心架構圖
```
Hash Table
│
├── Hash Function (雜湊函式) 
│   ├── Division (除法取餘數) 
│   ├── Mid-Square (平方取中法) 
│   └── Folding (摺疊法) 
│
├── Collision Handling (衝突處理) 
│   ├── Chaining (拉鏈法/鏈結法) 
│   └── Open Addressing (開放定址法) 
│       ├── Linear Probing (線性探測) 
│       ├── Quadratic Probing (平方探測) 
│       └── Double Hashing (雙重雜湊)
│
├── Table Management
│   ├── Static Hashing (靜態雜湊)
│   └── Dynamic Hashing (動態雜湊：自動擴展/縮小)
│
├── Performance (效能)
│   ├── Average: O(1) 
│   └── Worst: O(n) 
│
└── Dictionary ADT Implementation (字典實作)
```
---
## 二、基本定義與目標
* **定義**: Hashing 一種使用「hash function」將 key 轉換成整數 index，並將 key-value pair 存放在 hash table（通常是 array）中的技術
* **目標**: 在不需搜尋全部元素的情況下，透過 Key 快速找到對應資料，實現平均常數時間的搜尋
  * 加速 search, insert, delete, etc. operators
  * 讓 average time complexity = O(1)

* **與其他查找資料的方法比較時間複雜度**
  - binary search tree：O(log n)
  - sorted binary search：O(log n)
  - Hash table：average O(1)
 
## 三、Dictionary ADT
Hash Table 是 Dictionary 的一種實作方式
* **定義**: 一組 `<Keym Value>`的集合，其中 Key 通常是唯一的

* **主要操作**:
  - Create(m): 建立一個擁有 $m$ 個桶（Buckets）的空 Hash table
  - IsEmpty(d)
  - Search(h, k)：回傳 Key 是否存在於表中
  - Retrieve(h, k)：搜尋對應桶中的 Key 並回傳 Value，若無則報錯
  - Insert(h, k, v): 計算 $i = h(k) \pmod m$，若 Key 已存在則更新其值，否則加入桶中；若超過 MAX_LOAD_FACTOR 則需進行 Resize 。
  - Delete(h, k)：從桶中移除指定的 <Key, Value> 對
 
## 四、Hash Table 基本結構
### 底層結構
- Array：儲存 buckets
- Chaining（常用）：每個 bucket 裝一個 linked list（或其他 DS）
- Open addressing（另一種方法）：整個表不用 linked list，只用 array probe

### Can it be sorted? 
不擅長排序（因為 Hashing 破壞了順序）

### Approach to Managing Hash Table
- Static Hashing: the size of the hash table is fixed when it is created.
- Dynamic Hashing: Allows the **hash table to grow or shrink automatically**.
#### Comparision
| Aspect            | Static Hashing               | Dynamic Hashing                      |
| ----------------- | ---------------------------- | ------------------------------------ |
| Table Size        | Fixed                        | Variable (grows/shrinks dynamically) |
| Hash Function     | Constant                     | Adaptive (changes with size)         |
| Memory Usage      | Predictable                  | May expand dynamically               |
| Performance (α ↑) | Degrades with high load      | Remains efficient                    |
| Rehashing         | Entire table must be rebuilt | Only local bucket splits             |
| Implementation    | Simple                       | Complex (directory or pointer-based) |
| Best Use Case     | Small, fixed datasets        | Large or growing datasets            |

## 五、Hash Function
好的 hash function 必備以下特性:
1. Deterministic (確定性)：相同 key → 相同輸出
2. Uniform(diverse)：keys 均勻分散
3. Fast：計算快

### 常見 hash function
1. Division Method（Basic）
  ```
  h(k) = k mod m
  ```
- 建議 m 用質數 → 減少 pattern 造成的 clustering

2. Mid-Square Method
- 先平方 → 取中間位數

3. Folding Method
- key 切成數段加總

## 六、Collision Handling
當不同 Key 經計算後得到相同索引時，即發生 Collision。Collision 不可避免，只能降低頻率與有效處理

### Collision Handling Strategies

A. Chaining(最常見）
- 每個 bucket 一條 linked list
- 簡單、容錯高，發生衝突時，將新節點加入該索引對應的鏈結中
- 平均時間複雜度：O(1 + α)

<img width="470" height="269" alt="截圖 2025-12-01 晚上7 21 47" src="https://github.com/user-attachments/assets/b8167e76-329a-49c4-a4aa-dc1d8faf10bb" />


B. Open Addressing（只用 array） 
當發生衝突時，依特定規則搜尋下一個可用索引 。

1. **Linear Probing**：依序檢查下一個位置，容易造成 Primary Clustering （跑出一大條連續區塊）
```
h(k, i) = (h(k) + i) mod m
```

<img width="491" height="194" alt="截圖 2025-12-01 晚上7 23 32" src="https://github.com/user-attachments/assets/de373823-623b-464b-a509-da26f3f910da" />


2. **Quadratic Probing**：以平方間距探測，避免原始叢集但仍有 Secondary Clustering 
```
h(k, i) = h(k) + c1*i + c2*i^2
```

<img width="480" height="217" alt="截圖 2025-12-01 晚上7 25 15" src="https://github.com/user-attachments/assets/4b10bbf3-1f99-459c-9167-f10392f27aa5" />


3. **Double Hashing**（最佳 open addressing）：使用第二個雜湊函式決定探測步長
```
h(k, i) = h1(k) + i * h2(k)
```
- 優點:
  - 最能打散 probe sequence
  - clustering 最小
 
<img width="562" height="184" alt="截圖 2025-12-01 晚上7 26 04" src="https://github.com/user-attachments/assets/cf01c913-5d7b-4b81-8e14-73b54ec2c13c" />

#### Primary clustering vs. Secondary clustering
| 類型                       | 聚集成因              | 結果樣式          | 常見於                   |
| ------------------------ | ----------------- | ------------- | --------------------- |
| **Primary Clustering**   | 同樣方向逐格探查（例如 +1）   | 形成大條連續區塊      | **Linear probing**    |
| **Secondary Clustering** | 同 h(k) → 相同固定探查序列 | 多個分散但固定的小型聚集點 | **Quadratic probing** |

 
## 七、Probing 的特性

- Deterministic：同 key → 同 sequence
- Bounded：最多 m 個位置
- Load factor sensitive：α 越高 → 探查變慢
- Clustering：linear & quadratic 的常見問題

## 八、Table Size (m)
### Traditional: Prime number
- 對差的 hash function 比較有保護力
- 減少 pattern 與 clustering

### modern: 2 的次方
- AND 位元運算比 mod 快很多
- 缺點：若低位元分布不好會造成集中碰撞

## 九、Performance (time complexity)
| Operation | Avg  | Worst |
| --------- | ---- | ----- |
| Search    | O(1) | O(n)  |
| Insert    | O(1) | O(n)  |
| Delete    | O(1) | O(n)  |

- Worst case 發生時機:
  - load factor 過高
  - clustering
  - hash function 分布不均
 
## 十、Pros / Cons
### Pros
- 非常快（平均 O(1)）
- 適合快速查找
- 複雜度與資料量無關（平均）

### Cons
- 無法排序
- 不適合 range queries
- 需要良好 hash function
- dynamic resizing（rehash）成本高
  
---
## Use Cases
- Dictionary（字典查詢）
- Cache / symbol table / compiler lookup

## Supplementary
### Key Concept
| Component        | Description                                                |
| ---------------- | ---------------------------------------------------------- | 
| Hash Table       | 用來儲存 key-value pairs                                    |
| Key              | 要儲存的 data 或 identifier                                 |
| Hash Function    | 將 key 轉換成 hash table 中的 index                          |
| Load Factor (α)  | α = number of elements / table size，計算出該 table 滿的程度  |
