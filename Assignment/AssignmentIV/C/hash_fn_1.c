
/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation from prof. Huang
    - 2025/11/17: Refactored to use hash_fn.h
                  Update developer information
    - 2025/11/18: Initial implementation of myHashInt(), myHashString()
                  Add Fool-proof
    - 2025/11/23: Fix the logical error in myHashInt()
    - 2025/11/23: Refactor method 1 into a separate source file.

   Developer: Yung-Chi Tseng <s1121411@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    if (m <= 0) return -1; // invalid table size
    
    // method 1
    int hv = key % m;   
    if (hv < 0) hv += m; // make hv be positive
        
    return key % m;  // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += (unsigned long)(str[i]);
    }
    return (int)(hash % m); // basic division method
}
