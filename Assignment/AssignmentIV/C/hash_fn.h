/*
   ========================================
   hash_fn.h — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation from prof. Huang
                  Update developer information
    - 2025/11/23: Add headfile <stdlib.h>
    - 2025/11/24: Marked as final version

   Developer: Yung-Chi Tseng <a1121411@mail.yzu.edu.tw>
 */
#ifndef HASH_FN_H
#define HASH_FN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>   // for atoll

int myHashString(const char* str, int m);
int myHashInt(int key, int m);

#endif