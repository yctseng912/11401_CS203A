# Trees
## 核心概念與定義
### 1. 什麼是樹？
樹是一種**非線性**的階層式資料結構 。它由通過邊（Edges）連接的節點（Nodes）組成 。

* **關鍵特性**:

  * 每個節點可以有零個或多個子節點 (Child nodes)，形成**父子關係** (Parent-child relationships) 。

  * 樹中**沒有迴圈** (No cycles) 。


### 2. 日常應用範例樹結構常用於表示階層關係 ：

* **文件系統階層結構** (File system hierarchy) 

* **族譜** (Family tree) 

* **組織結構** (Organizational structures) 


### 3. Link List → Tree
樹可以視為一種特殊的 Link List ：

* 如果 Link List 中的節點能有多個指標（例如 `left` 和 `right`），它就能分支，從**線性結構**轉變為**階層式結構** 。

  * **二元樹節點** (Binary Tree Node) 包含兩個指標：`left` 和 `right` 。
 
<img width="464" height="261" alt="截圖 2025-12-15 晚上11 58 56" src="https://github.com/user-attachments/assets/4ea51e18-6bd6-483d-8726-42d6ca7ae13c" />


## 基本術語 (Terminology)

| 術語 (Term) | 定義 (Definition) |
| --- | --- |
| **Root** | 樹的最頂層節點 。
| **Parent** / **Child** | 父節點是具有分支指向其他節點的節點 ；子節點是從父節點延伸出的節點 。
| **Leaf** | 沒有任何子節點的節點 。
| **Sibling** | 共享相同父節點的節點群 。
| **Edge** | 連接兩個節點的連線 。
| **Depth** | 節點到**根節點**的距離 。
| **Height** | 從根節點到**最長路徑上的葉節點**的距離 。
| **Fan-out** (degree) | 一個節點可以擁有的子節點數量 。
| **Subtree** | 樹中以任何節點為根的結構，包含該節點及其所有後代 。
<img width="661" height="177" alt="截圖 2025-12-16 凌晨12 04 07" src="https://github.com/user-attachments/assets/e7cee030-1b83-4c85-b684-0b1c3ca738c7" />

<img width="686" height="176" alt="截圖 2025-12-16 凌晨12 05 02" src="https://github.com/user-attachments/assets/c9f8e706-cf27-41d4-839f-acad24efee53" />

## 樹的家族演化 (Tree Family)

| Level | 名稱 (Name) | 額外規則/約束 (Extra Rule) | 限制類型 (Constraint Type) |
| --- | --- | --- | --- |
| **1** | **Generate Tree** | 僅是根植的階層結構，對子節點數量無限制 | 一般形狀 |
| **2** | **Binary Tree** | 每個節點最多有 2 個子節點 (Left/Right) | **形狀約束** (Arity) |
| **3** | **Binary Search Tree (BST)** | 滿足排序不變數：對於每個節點，**左子樹 < 根 < 右子樹** | **排序約束** (Ordering/Search) |
| **4** | **Balanced BST** | 高度通過額外規則保持在**「小規模」**(\approx \log n) 。| **高度/平衡約束** |

### 主要樹類型 (Core Tree Types)
| 類型 (Type) | 描述 (Description) | 應用 (Application) |
| --- | --- | --- |
| **Full Binary Tree** (滿二元樹) | 每個節點有 0 或 2 個子節點 | 決策節點 |
| **Complete Binary Tree** (完全二元樹) | 除最底層外，所有層次都被填滿 | 堆 (Heap, 優先佇列) |
| **Binary Search Tree (BST)** | 左子節點 < 父節點 < 右子節點 | 搜尋、排序 |
| **Balanced Tree** (AVL/Red-Black) | 高度差異受到控制 | 提高搜尋效率 |
| **Trie** (前綴樹) | 基於字元的分支，用於快速字串檢索 | 字典、自動完成 |
| **B-Tree / B+ Tree** | 用於磁碟/區塊儲存的多路搜尋樹 | 資料庫、檔案系統 |

## 樹的遍歷 (Tree Traversal)
遍歷是按照特定順序訪問樹中每個節點的過程 。複雜度通常為 O(n) 。

### 1. 深度優先遍歷 (DFT: Depth-First Traversal)
使用**遞迴**方式訪問：
| 順序 (Order) | 訪問序列 (Visit Sequence) | 描述/用途 (Description/Use) |
| :--- | :--- | :--- | 
| **Preorder** (前序) | Root-Left-Right (根節點先，然後子節點) | 用於**複製**樹 |
| **Inorder** (中序) | Left-Root-Right (左子節點先，然後根節點) | 對於 BST，將產生**排序後的順序** |
| **Postorder** (後序) | Left-Right-Root (子節點先，然後根節點) | 用於**刪除**或釋放記憶體 |

<img width="585" height="337" alt="截圖 2025-12-16 凌晨12 20 26" src="https://github.com/user-attachments/assets/4b509f6b-11ef-465d-b29a-9769f86df673" />

### 2. 廣度優先遍歷 (BFT: Breadth-First Traversal)
也稱作**層序遍歷** (Level-Order Traversal) ，使用**佇列** (queue) ，一層一層地訪問節點。

<img width="479" height="211" alt="截圖 2025-12-16 凌晨12 21 19" src="https://github.com/user-attachments/assets/ed9826ac-0898-4efa-b48d-e0d7f89e7a6d" />

## 平衡 (Balance) 的重要性

<img width="392" height="157" alt="截圖 2025-12-16 凌晨12 22 21" src="https://github.com/user-attachments/assets/18d55b6e-8b55-410b-b87e-f1ec4a3c3776" />

### 1. 什麼是不平衡？
當樹的一側變得**過於深**（退化 Degenerate/Skewed）時，例如 BST 的輸入資料是排序好的序列（1, 2, 3, 4, 5），樹會退化成一個單向鏈結串列 。

### 2. 影響
在不平衡的情況下，搜尋和插入操作的效率會從最佳的 O(\log n) **退化**到 O(n) 。

### 3. 平衡策略
平衡樹（Self-balancing BST）能確保樹的高度保持在對數級別，維持 O(\log n) 的效率 。

| 類型 (Type) | 平衡規則 (Balancing Rule) | 應用 (Application) |
| --- | --- | --- |
| **AVL Tree** | 左右子樹高度差 \le 1 | 快速查找 |
| **Red-Black Tree** | 通過顏色限制來平衡 | C++ STL map, Linux kernel |
| **B-Tree / B+Tree** | 多層次、多鍵節點 | 資料庫和檔案系統 |


## 樹的表示法 (Representation of Trees)
在資料結構中，表示樹的方法主要有三種，它們決定了如何將階層關係轉換為電腦可處理的儲存結構。

### 1. 括號表示法 (Parenthesis Representation)
是一種抽象且簡潔的表示方式，它使用**括號**來表達節點之間的父子和階層關係 。

* **原理**: 根節點後面跟著一組括號，括號內是其所有子節點的列表。每個子節點如果還有自己的子樹，則會再次使用一組巢狀括號來表示 。

* **格式**: \text{(Root}(\text{Child}_1, \text{Child}_2, \dots))
  
* **範例 (Tree A-M)**: (A ( B ( E (K, L), F), C (G), D ( H (M), I, J ) ) )
  * 根節點 A 有子樹 B, C, D 。
  * 子樹 B 有子節點 E, F 。
  * 子樹 E 有葉節點 K, L 。
    
<img width="539" height="174" alt="截圖 2025-12-16 凌晨12 56 43" src="https://github.com/user-attachments/assets/f2802467-72e8-4788-b4f7-d0ac0daa3773" />

---

### 2. 列表表示法 (List Representation)
<img width="642" height="131" alt="截圖 2025-12-16 凌晨1 01 01" src="https://github.com/user-attachments/assets/e03e582e-95ff-478b-99d3-fef273d7334b" />

---

### 3. 左子右兄弟表示法 (Left Child-Right Sibling Representation)
這是一種將**一般樹** (General Tree, 每個節點可能有 N 個子節點) 轉化為只使用兩個指標儲存的方法 。

*  **原理**: 每個節點只需要兩個指標來定義其結構 ：
 * **左子 (Left Child)**：指向該節點的**第一個**（最左邊的）子節點。
 * **右兄弟 (Right Sibling)**：指向該節點的**下一個**兄弟節點。
  
* **優點**: 它允許我們使用**二元樹**的節點結構（兩個指標欄位）來實現任何具有任意多子節點的樹 。

<img width="466" height="170" alt="截圖 2025-12-16 凌晨12 54 59" src="https://github.com/user-attachments/assets/8157025a-d34f-480a-9422-4d6fac5b7217" />


---

### 4. 表示為度為二的樹 (Representation as a Degree-Two Tree)這是將「左子右兄弟表示法」的結構進行視覺化旋轉後得到的**標準二元樹**形式 。

* **轉換過程**：
1. 先使用**左子右兄弟表示法**連接節點 。


2. 將圖形**順時針旋轉 45^{\circ}** 。

* **結果**: 產生一個完整的**二元樹** (Binary Tree) 。

  * 原樹中的父子關係 (Left Child) 保持為新樹的**左分支** 。

  * 原樹中的兄弟關係 (Right Sibling) 變為新樹的**右分支**（成為左子節點的右子樹） 。

<img width="619" height="258" alt="截圖 2025-12-16 凌晨1 02 17" src="https://github.com/user-attachments/assets/cf824880-ab22-4876-8e95-73f7c4bd90ba" />


---

### 5. 陣列表示法 (Array Representation)
陣列表示法常運用於具有特定結構的樹，尤其是**完全二元樹** (Complete Binary Tree) 。

* **原理**: 樹的節點值依據層級 (Level) 順序，存儲在一維陣列中。對於完全二元樹，節點之間的父子關係可以直接透過陣列索引計算出來 。

* **缺點 (BST 情況)**: 對於不平衡或稀疏的 **二元搜尋樹** (BST)，將其映射到陣列中時，會導致陣列中出現大量的**「洞」（holes）**，造成記憶體空間的浪費 。

<img width="514" height="286" alt="截圖 2025-12-16 凌晨1 08 14" src="https://github.com/user-attachments/assets/73ee8789-eb04-45fd-b5e3-a60d95b49855" />


---

## Transform General Tree to Binary Tree

<img width="674" height="257" alt="截圖 2025-12-16 凌晨12 29 56" src="https://github.com/user-attachments/assets/29eb5597-8ef0-44c4-ab23-2dc6e24b1de3" />

