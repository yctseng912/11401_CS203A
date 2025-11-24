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
                  Refactor division method into a separate source file - hash_fn_1.cpp.
    - 2025/11/24: Marked as final version.
   
   Developer: Yung-Chi Tseng <s1121411@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <stdexcept>
using namespace std;

int myHashInt(int key, int m) {

    if (m <= 0) {
        throw invalid_argument("Hash table size m must be positive.");
    }

    //method 2: Advance - Mid Square Method 
    //Square the value of the key
    long long squareKey = key * key;
  
    //Calculate the number of digits in a square.
    int numDigits = 0;  
    long long temp = squareKey;
    while (temp > 0) {
        temp /= 10;
        numDigits++;
    }

    //Extract the middle digits as the value
    string s = to_string(squareKey);
    if (s.length() <= 2)  return squareKey % m;
    string mid = s.substr(1, s.length() - 2);
    long long midNum = stoll(mid);

    return midNum % m;
    
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
