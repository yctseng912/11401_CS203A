
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

   Developer: Yung-Chi Tseng <s1121411@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    // method 1
    // return key % m;  // division method example

    long long squareKey = (long long)key * (long long)key;

    // Count digits
    long long temp = squareKey;
    int numDigits = 0;
    while (temp > 0) {
        temp /= 10;
        numDigits++;
    }

    if (numDigits <= 2)
        return squareKey % m;

    // Extract middle digits (same as substr(1, len-2))
    // Remove left digits
    long long shifted = squareKey / 10;

    // Take mid digits: shifted % 10
    long long midNum = squareKey % 10;

    return midNum % m;
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += (unsigned long)(str[i]);
    }
    return (int)(hash % m); // basic division method
}