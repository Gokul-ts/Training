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
   int left = 0, isValidChar = 0;
   int right = (int)strlen (phrase) - 1;
   while (left <= right) {
      if (!isalnum (phrase[left])) {
         left++; continue;
      }
      if (!isalnum (phrase[right])) {
         right--; continue;
      }
      isValidChar = 1; //to check for valid characters
      if (toupper (phrase[left++]) != toupper (phrase[right--])) return NOT_PALINDROME;
   }
   return (isValidChar) ? PALINDROME : ERR_INVALID;
}