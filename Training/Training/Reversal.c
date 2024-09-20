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

int NumIsPalindrome (int num, long long int* revNum) {
   bool isNegative = false;
   if (num < 0) { // special case for negative numbers
      num = -num;
      isNegative = true;
   }
   int org = num;
   long long int rev = 0;
   while (num != 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
   }
   if (isNegative == true) {
      *revNum = -rev;
      return NOT_PALINDROME;
   } else *revNum = rev;
   return (rev == org);
}

int StrIsPalindrome (char* phrase, int type) {
   int j = 0, length = 0;
   length = (int)strlen (phrase);
   if (type == 1) length--; //used to remove '\n' from user input 
   if (length > MAX_CHAR - 2) return ERR_INVALID; // invalid input exceeds buffer
   char temp[MAX_CHAR];
   for (int i = 0; i < length; i++) {
      if (isalnum (phrase[i]) != 0)
         temp[j++] = phrase[i];
   }
   temp[j] = '\0';
   if (j == 0) return ERR_INVALID; //invalid if no alphanumeric is present
   for (int n = 0; n < (j / 2); n++) {
      if (toupper (temp[n]) != toupper (temp[j - n - 1])) return NOT_PALINDROME;
   }
   return PALINDROME;
}