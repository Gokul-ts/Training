// ------------------------------------------------------------------------------------------------
// Assignment4 ~ A training program for new joiners at Metamation, Batch - Sept 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// Reversal.c
// C program to Check Palindrome or not
// ------------------------------------------------------------------------------------------------
#include "Reversal.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int IsNumPalindrome (int num, long long int* revNum) {
   bool isNegative = false;
   if (num < 0) { // special case for negative numbers
      num = -num;
      isNegative = true;
   }
   int org = num;
   long long int rev = 0; //Used for storing reversed number exceeding int range
   while (num != 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
   }
   *revNum = isNegative == true ? -rev : rev;
   return (*revNum == org);
}

int IsStrPalindrome (char* phrase) {
   int left = 0, validChar = 0;
   int count = (int)strlen (phrase);
   int right = count - 1;
   if (count > MAX_CHAR - 2) return ERR_INVALID; //to check if test case input exceeds buffer
   while (left <= right) {
      while (left <= right && !isalnum (phrase[left])) left++;
      while (left <= right && !isalnum (phrase[right])) right--;
      if (left <= right) {
         if (toupper (phrase[left]) != toupper (phrase[right])) return NOT_PALINDROME;
         validChar++; // to check the count of valid characters
         left++;
         right--;
      }
   }
   return (count == 0 || validChar == 0) ? ERR_INVALID : PALINDROME;
}