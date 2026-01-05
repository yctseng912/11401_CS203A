# Array

## 一、 陣列基本定義與特性

* **定義**：陣列是存儲在**連續記憶體位置**中的元素集合，每個元素都可以透過**索引 (Index)** 直接存取 。

* **特性**：
  * **固定大小**：靜態陣列在宣告時即確定大小 。

  * **相同型別**：通常所有元素皆為同一資料型態 。

  * **存取效率**：提供常數時間 () 的元素存取 。

---

## 二、 靜態陣列 (Static Array)

靜態陣列的大小在編譯時確定，且無法在執行時更改 。

### 1. 維度分類與實作

| 維度 | 宣告範例 | 說明 |
| --- | --- | --- |
| **一維 (1D)** | `int array[5];` | 5 個整數元素的集合 。|
| **二維 (2D)** | `int array2d[3][4];` | 3 列 (Rows) 4 行 (Columns) 的矩陣 。|
| **三維 (3D)** | `int array3d[2][3][4];` | 2 個區塊 (Planes)，每個區塊為  矩陣 。|

<img width="372" height="222" alt="截圖 2025-12-21 晚上9 22 56" src="https://github.com/user-attachments/assets/9650c95f-145e-497e-ac21-17efd1b82a15" />

<img width="594" height="248" alt="截圖 2025-12-21 晚上9 23 17" src="https://github.com/user-attachments/assets/d5f387c3-af3b-4654-9463-f21ef6ec81cc" />

### 2. 存取範例

* **1D 陣列**：`array[2]` 存取第三個元素 。

* **2D 陣列**：`array2d[1][2]` 存取第 1 列、第 2 行的元素 。

* **3D 陣列**：`array3d[1][2][3]` 。

---

## 三、 動態陣列 (Dynamic Array)

動態陣列允許在執行時 (Runtime) 分配或調整大小 。

* **關鍵函式 (C 語言)**：
  * `malloc`：分配初始記憶體 。

  * `realloc`：調整現有陣列大小（如：將大小加倍）。

  * **注意**：
    * 使用後必須使用 `free` 釋放記憶體以避免記憶體洩漏 。
    * 每次 `malloc` 或 `realloc` 時都需先判斷是否有足夠的空間，若無則回傳例外並結束執行。

* **挑戰**：重新分配記憶體後，陣列的起始地址可能會改變 。

---

## 四、 C++ STL 中的陣列容器

C++ 提供標準模板庫 (STL) 來簡化陣列管理 ：

* **std::array**：靜態陣列，大小固定於編譯期，通常存於堆疊 (Stack) 。

* **std::vector**：動態陣列，大小可在執行期變動，存於堆積 (Heap)，極具靈活性 。

---

## 五、 常見演算法操作

### 1. 排序 (Sorting)

將陣列元素依升序 (Ascending) 或降序 (Descending) 排列 ：

* **氣泡排序 (Bubble Sort)**：重複交換相鄰的錯誤順序元素 。

<img width="590" height="321" alt="截圖 2025-12-21 晚上9 30 00" src="https://github.com/user-attachments/assets/233b8692-c0a1-4033-af58-49571650aa7b" />

* **選擇排序 (Selection Sort)**：每次尋找剩餘部分的最小值並交換 。

<img width="590" height="327" alt="截圖 2025-12-21 晚上9 30 32" src="https://github.com/user-attachments/assets/5e6e2a20-b69c-4827-87d0-c5ce7188d379" />

* **插入排序 (Insertion Sort)**：將元素插入已排序部分的正確位置 。

<img width="591" height="325" alt="截圖 2025-12-21 晚上9 30 57" src="https://github.com/user-attachments/assets/9b8aaa5c-b234-4eb9-9e40-c21074f3da3b" />


### 2. 搜尋 (Search)

* **線性搜尋 (Linear Search)**：適用於未排序陣列，需走訪所有元素 。

* **二元搜尋 (Binary Search)**：適用於**已排序**陣列，效率更高 。

---

## 六、 複雜度分析與總結

1. 時間複雜度 

* **存取 (Access) / 更新 (Update)**：O(1)
* **插入 (Insert) / 刪除 (Delete)**：O(n)（因為需要移動元素）
* **搜尋 (Search)**：未排序 O(n)；排序後使用二元搜尋 O(log n) 

### 2. 優缺點

* **優點**：靜態數據的隨機存取速度極快 。

* **缺點**：頻繁的插入與刪除操作成本高昂，因為需要大量移動數據 。

---

## 七、 實務應用

* **字串處理**：在 C 中，字串本質上是以 `\0` 結尾的字元陣列 。

* **Real-world Example**：Nginx 使用陣列 (`ngx_array_t`) 來管理基於 IP 的存取控制規則 。
