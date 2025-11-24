
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
                  Refactor division method into a separate source file - hash_fn_1.c.
    - 2025/11/24: Marked as final version

   Developer: Yung-Chi Tseng <s1121411@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    if (m <= 0) return -1; // invalid table size

    //method 2: Advance - Mid Square Method
    long long squareKey = (long long)key * (long long)key;

    // Count digits
    char buffer[32];
    sprintf(buffer, "%lld", squareKey);

    int len = strlen(buffer);

    if (len <= 2)    return squareKey % m;

    // Extract middle digits (same as substr(1, len-2))
    char mid[32];
    int midLen = len - 2;

    for (int i = 0; i < midLen; i++) {
    mid[i] = buffer[i + 1];
}
    mid[midLen] = '\0';
    long long midNum = atoll(mid);

    return midNum % m;
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += (unsigned long)(str[i]);
    }
    return (int)(hash % m); // basic division method
}
