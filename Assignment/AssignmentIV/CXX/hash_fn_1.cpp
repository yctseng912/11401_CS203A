/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation from prof. Huang
    - 2025/11/17: Update developer information,
                  Initial implement of myHashInt() by two method
                  Initial implement of myHashString()
    - 2025/11/18: Refactored to use hash_fn.hpp
                  Add Fool-proof
    - 2025/11/23: Add headfile for exception
                  Refactor method 1 into a separate source file.
   
   Developer: Yung-Chi Tseng <s1121411@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <stdexcept>
using namespace std;

int myHashInt(int key, int m) {

    if (m <= 0) {
        throw invalid_argument("Hash table size m must be positive.");
    }

    //method 1: Basic - Division Method (Formula: h(k) = k mod m)
    int hashValue = key % m;
    if(hashValue < 0) hashValue += m;

    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;

    if (str.empty()) {
        return 0;
    }

    //Sumation of the ASCII values ​​of each character
    for (char c : str) {
        hash += static_cast<unsigned long>(c);  
    }

    return static_cast<int>(hash % m);  // basic division method
}
