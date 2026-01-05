# Graphs: 網路與關係建模
## 核心定義與應用
圖是一種抽象資料結構，用於表示實體之間的關係 。

### 1. 圖的數學定義
一個圖 G 由一組頂點 V 和一組邊 E 組成 。 $G = (V, E)$ 

* **V (Vertices)**：一組**頂點**（Vertex），也稱為**節點**（Node）或**點**（Point） 。

* **E (Edges)**：一組**邊**（Edge），也稱為**連結**（Links）或**線**（Lines），用於連接頂點 。在**無向圖** (Undirected Graph) 中，邊是無序的頂點對 。

### 2. 圖的應用圖用於對網路進行建模，例如：

* **社交網路**（Social connections） 

* **交通運輸系統**（Transportation systems，如 Google Maps 的路線規劃） 

* **網頁超連結**（Web pages with hyperlinks） 

* **最短路徑問題**（如柯尼斯堡的七橋問題） 

## 圖與樹的區別
樹是圖的一種特殊形式 。圖是更為通用的結構 。

| 特性 (Property) | 樹 (Tree) | 圖 (Graph) |
| --- | --- | --- |
| **迴圈** (Cycles) | 否 (No) | 是 (Yes) |
| **連通性** (Connectivity) | 總是連通 (Always connected) | 可能不連通 (May be disconnected) |
| **方向** (Direction) | 無方向性 | 有方向 (Directed) 或無方向 (Undirected) |
| **階層** (Hierarchy) | 有（根節點） | 沒有固有的階層結構 |

## 圖的分類 (Classification)
圖可以根據邊的特性和結構來分類:

| 類型 (Type) | 描述 (Description) | 範例 (Example) |
| --- | --- | --- |
| **無向圖** (Undirected Graph) | 邊沒有方向 | 朋友關係網路 |
| **有向圖** (Directed Graph / Digraph) | 邊具有方向 | Instagram 的「追蹤」關係 |
| **加權圖** (Weighted Graph) | 每條邊有一個**成本** (cost) | Google Maps 上的距離 |
| **無權圖** (Unweighted Graph) | 所有邊的權重相等 | 棋盤遊戲地圖 |
| **環狀圖** (Cyclic Graph) | 包含迴路（Loops） | 城市環路 |
| **非環狀圖** (Acyclic Graph) | 不包含迴路 | 族譜 |
| **連通圖** (Connected Graph) | 每個節點都可以到達其他所有節點 | 道路網路 |
| **不連通圖** (Disconnected Graph) | 某些節點是孤立的 | 沒有橋樑連接的島嶼 |

## Degree of a Vertex
指與該頂點相連的邊數 。

* **在有向圖中** (Directed Graph):
  
* **In-degree**: 指向該頂點的邊數 (即該頂點作為邊的「頭」Head 的數量) 。
  
* **Out-degree**: 從該頂點出發的邊數 (即該頂點作為邊的「尾」Tail 的數量) 。





## 圖的表示法 (Graph Representation)
圖在計算機記憶體中主要有兩種表示方法：

### 1. 鄰接矩陣 (Adjacency Matrix)
* **結構**: 是一個 $V \times V$ 的矩陣（其中 V 是頂點數），用於記錄兩個頂點之間是否存在邊 。

* **儲存內容**: $\text{Matrix}[i][j]$ 儲存頂點 i 和 j 之間邊的數量（或在加權圖中儲存權重） 。


| Feature | Adjacency Matrix |
| --- | --- |
| **空間複雜度** (Space) | $O(V^2)$ |
| **邊查詢** (Edge lookup) | $O(1)$ (直接查詢 $\text{matrix}[u][v]$) |
| **添加邊** (Add edge) | $O(1)$ |
| **遍歷 BFS/DFS** | $O(V^2)$ |
| **優點** (Pros) | <ul><li>實作簡單 </li><li>適用於**稠密圖** (Dense graphs) </li><li>需要**快速邊查詢**的演算法（如 Floyd-Warshall）</ul>|
| **缺點**  (Cons) |<ul><li>空間浪費 (特別是稀疏圖 Sparse graphs) </li><li>獲取鄰居需要掃描整行 $O(V)$ </li></ul>|

### 2. 鄰接串列 (Adjacency List)
* **結構**: 每個頂點只儲存其**鄰居**（Neighbors）的串列 。

* **儲存內容**: 透過陣列搭配鏈結串列或動態陣列來儲存。

| Feature | Adjacency List |
| --- | --- |
| **空間複雜度** (Space) | $O(V+E)$ |
| **邊查詢** (Edge lookup) | $O(\text{deg}(v))$ (需要掃描頂點 v 的鄰接串列) |
| **添加邊** (Add edge) | $O(1)$ |
| **遍歷 BFS/DFS** | $O(V+E)$ |
| **優點** (Pros) | <ul><li>適用於**稀疏圖** (Sparse graphs)</li><li>鄰居存取快速 $(O(\text{deg}(v)))$ </li><li>適合大多數圖演算法（如 BFS/DFS、Dijkstra、Prim、Kruskal）</li></ul> |
| **缺點** (Cons) | <ul><li>實作較複雜</li><li>邊查詢較慢 $(O(\text{deg}(u)))$</li></ul> |

## 圖的遍歷 (Graph Traversal / Graph Search)
圖的遍歷（Graph Traversal）是系統性地探索圖中所有節點的過程 。與樹遍歷相似，但必須處理圖的獨特挑戰 。

### 關鍵差異：需要 $\text{visited}[]$
圖可能存在**迴圈**和**多重路徑**，為了防止無限迴圈或重複訪問，圖遍歷**必須**追蹤已訪問的節點 。

### 1. 廣度優先搜索 (BFS: Breadth-First Search)* 
**原理**: 類似於樹的**層序遍歷** (Level-order traversal) 。它以一層一層的方式系統性地探索節點。

* **資料結構**: 使用**佇列** (Queue)（先進先出，FIFO）來確保按層次順序訪問 。

* **演算法基礎**:

1. 初始化空**佇列**和空 $\text{visited}$ 集合。
2. 將起始頂點入隊。
3. 當佇列非空時，出隊頂點 v。
4. 如果 v 未被訪問，標記 v 為已訪問並將其所有未訪問的鄰居**入隊**。


* **用途**: 用於尋找**最短路徑**（在無權圖中）。

### 2. 深度優先搜索 (DFS: Depth-First Search)

* **原理**: 類似於樹的**前序遍歷** (Preorder traversal) 。它沿著一條路徑深入探索，直到到達盡頭再回溯 (Backtracking) 。

* **資料結構**: 使用**堆疊** (Stack)（後進先出，LIFO）來記住探索路徑和回溯點 。

* **演算法基礎**:

1. 初始化空**堆疊**和空 $\text{visited}$ 集合。
2. 將起始頂點推入堆疊。
3. 當堆疊非空時，彈出頂點 v。
4. 如果 v 未被訪問，標記 v 為已訪問並將其所有未訪問的鄰居**推入堆疊**。

* **用途**: 用於拓撲排序、尋找連通分量、尋找迴路。
