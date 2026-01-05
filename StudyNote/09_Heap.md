# Heaps: 完全二元樹與優先佇列
## 核心定義
Heap 是一種特殊的二元樹 。它必須同時滿足兩個主要特性：

### 1. 形狀特性 (Shape Property / Structure)
本質上是一個**完全二元樹** (Complete Binary Tree) 。

* **定義**: 樹的每一層都被完整填滿了，除了**最底層**可能例外 。

* **填充規則**: 最底層的節點必須**從左到右**連續填滿 。

* **儲存優勢**: 這個特性保證了堆可以被**高效地儲存在陣列**中，不會產生間隙 (no gaps) 。



### 2. 堆序特性 (Heap-Order Property / Ordering)
堆序特性定義了父節點和子節點之間的**值關係**，即資料的**優先級 (Priority)** 規則 。

* **Max Heap (最大堆)**:

  * 每個父節點的鍵值**大於或等於**其所有子節點 (parent ≥ children)。

  * 最大元素**永遠位於根節點** 。

* **Min Heap (最小堆)**:

  * 每個父節點的鍵值**小於或等於**其所有子節點（parent ≤ children） 。

  * 最小元素**永遠位於根節點** 。
    
<img width="592" height="195" alt="截圖 2025-12-16 下午2 04 42" src="https://github.com/user-attachments/assets/33f4a2f8-33d5-452e-935e-5844b1c41adb" />


## 主要用途與特性

* **典型用途**: 堆通常用於實現**優先佇列** (Priority Queues) 和**堆排序** (Heapsort) 演算法 。
  
* **優先級表示**: 在堆中，**鍵值** (Key value) 用來表示元素的優先級 。

  * 在 Max-Heap 中，**最大**的鍵值 = **最高**優先級 。

  * 在 Min-Heap 中，**最小**的鍵值 = **最高**優先級 。


* **儲存方式**: 儲存在**陣列**中最為高效 。

---

## 操作與時間複雜度 (Time Complexity)
堆操作的效能優勢在於它們大多是**對數級** (Logarithmic) 的 。

| 操作 (Operation) | 描述 (Description) | 時間複雜度 (Time Complexity) |
| --- | --- | --- |
| $\text{insert}(x)$ | 新增元素並恢復堆序 | $O(\log n)$ |
| `extract_root()` | 移除最大 (Max) 或最小 (Min) 元素 | $O(\log n)$ |
| `peek_root}()` | 存取最大 (Max) 或最小 (Min) 元素 | $O(1)$ |
| `build_heap(array)` | 將陣列轉換成堆 | $O(n)$ |
| $\text{heapify}(i)$ | 在節點 i 處恢復堆特性 | $O(\log n)$ |

---

## 範例：Max Heap 的操作步驟
### 1. Max Heap 結構範例
* **結構**: 根節點 (80) 滿足 $\text{parent} \ge \text{children}$ 的規則。
* **陣列表示**: [80, 70, 60, 30, 20, 50] 

### 2. 插入操作 $(\text{insert}(200))$
1. **插入新節點**: 將新元素 200 插入到堆結構中**最底層的最左邊**（以維持完全二元樹的形狀特性） 。

* **陣列變化**: \text{[80, 70, 60, 30, 20, 50, 55, 200]} 

2. **恢復堆序 (上浮 / Percolate Up)**: 將新節點與其父節點比較，如果違反堆序特性，則進行**交換 (swap)** 。

* 200 > 30 (swap) \rightarrow 200 上移 

* 200 > 70 (swap) \rightarrow 200 上移 

* 200 > 80 (swap) \rightarrow 200 上移至根節點 

3. **結果**: 堆序特性恢復，最大元素 200 位於根部 。

* **最終陣列**: [200, 80, 60, 70, 20, 50, 55, 30] 

<img width="513" height="195" alt="截圖 2025-12-16 下午2 05 41" src="https://github.com/user-attachments/assets/e6613a00-2d4d-4bbc-a0c5-9226a42b9331" />

<img width="515" height="252" alt="截圖 2025-12-16 下午2 06 32" src="https://github.com/user-attachments/assets/5471d2e0-3f24-40bc-9faa-7776a1dceb3c" />

<img width="514" height="253" alt="截圖 2025-12-16 下午2 06 57" src="https://github.com/user-attachments/assets/51aa1e28-d282-4421-89bf-e4efd1a4d71a" />

<img width="513" height="252" alt="截圖 2025-12-16 下午2 07 13" src="https://github.com/user-attachments/assets/3336086d-03ab-4912-815a-c255e74e9f10" />


### 3. 提取最大值 (\text{Extract Max})
1. **移除根節點**: 移除最大元素 200 。

2. **替換根節點**: 將堆中**最後一個**元素 30 移至根節點位置 。

3. **恢復堆序 (下沉 / Percolate Down / Heapify)**: 將新的根節點 (30) 與其子節點中**較大的那個**進行比較，如果違反堆序特性，則進行交換。這個過程會遞迴地向下執行，直到堆序特性恢復。

4. **結果**: 堆的大小減少，新的最大元素 80 位於根部。
* **最終陣列**: [80, 70, 60, 30, 20, 50, 55] 

<img width="635" height="251" alt="截圖 2025-12-16 下午2 08 13" src="https://github.com/user-attachments/assets/7b63876e-d29f-43ea-9f13-eaf685e6f7b9" />
