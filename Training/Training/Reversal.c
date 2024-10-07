// ------------------------------------------------------------------------------------------------
// Assignment4 ~ A training program for new joiners at Metamation, Batch - Sept 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// Reversal.c
// C program to Check Palindrome or not
// ------------------------------------------------------------------------------------------------
#include "Reversal.h"
#include <string.h>
#include <ctype.h>

int IsNumPalindrome (int num, long long int* revNum) {
   *revNum = NumReverse (num);
   return (num < 0) ? NOT_PALINDROME : (*revNum == num);
}

int IsStrPalindrome (char* phrase) {
   int left = 0, right = (int)strlen (phrase) - 1, isValidChar = 0;
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

long long int NumReverse (int num) {
   long long int rev = 0; //to store reversed number exceeding int range
   while (num != 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
   }
   return rev;
}