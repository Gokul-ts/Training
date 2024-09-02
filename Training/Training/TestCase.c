// ------------------------------------------------------------------------------------------------
// Assignment3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// DecimalConversion.c
// C program to check the test cases of Decimal conversion
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "DecimalConversion.h"

void main () {
   //test cases for Binary conversion
   printf ("-----Decimal to Binary-----\n");
   int input[] = { 0,651,-545,999,-4875,15756,-4654,-1,-2147483647 };
   char* output1[] = {
      "00000000000000000000000000000000",
      "00000000000000000000001010001011",
      "11111111111111111111110111011111",
      "00000000000000000000001111100111",
      "11111111111111111110110011110101",
      "00000000000000000011110110001100",
      "11111111111111111110110111010010",
      "11111111111111111111111111111111",
      "10000000000000000000000000000001" };
   for (int i = 0; i < 9; i++) {
      int num1 = input[i];
      printf ("Test Case%d: Input--> %d ", i + 1, num1);
      char* binResult1 = DecToBin (num1);
      int m = strcmp (binResult1, output1[i]);
      if (m == 0) printf ("\033[1;32mPASS\033[0m\n");
      else printf ("\033[1;31mFAIL\033[0m\n");
   }
   //checking for decimal numbers exceeding integer range
   long long int inputLong1 = -2147483649ll;
   char* outputLong1 = "1111111111111111111111111111111101111111111111111111111111111111";
   printf ("Test Case10: Input--> %lld ", inputLong1);
   char* binResultLong1 = DecToBin (inputLong1);
   int k = strcmp (binResultLong1, outputLong1);
   if (k == 0) printf ("\033[1;32mPASS\033[0m\n");
   else {
      printf ("\033[1;31mFAIL\033[0m\n");
      printf ("Expected: \033[1;34m%s\033[0m Output: \033[1;31m%s\033[0m\n", outputLong1, binResultLong1);
   }

   //test cases for Hexadecimal conversion
   printf ("\n-----Decimal to Hexadecimal-----\n");
   char* output2[] = {
      "0000000000000000",
      "000000000000028B",
      "FFFFFFFFFFFFFDDF",
      "00000000000003E7",
      "FFFFFFFFFFFFECF5",
      "0000000000003D8C",
      "FFFFFFFFFFFFEDD2",
      "FFFFFFFFFFFFFFFF",
      "FFFFFFFF80000001" };
   for (int i = 0; i < 9; i++) {
      int num2 = input[i];
      printf ("Test Case%d: Input--> %d ", i + 1, num2);
      char* binResult2 = DecToHex (num2);
      int n = strcmp (binResult2, output2[i]);
      if (n == 0) printf ("\033[1;32mPASS\033[0m\n");
      else printf ("\033[1;31mFAIL\033[0m\n");
   }
   //checking for decimal numbers exceeding integer range
   long long int inputLong2 = -2147483649ll;
   char* outputLong2 = "FFFFFFFF7FFFFFFF";
   printf ("Test Case10: Input--> %lld ", inputLong2);
   char* binResultLong2 = DecToHex (inputLong2);
   int l = strcmp (binResultLong2, outputLong2);
   if (l == 0) printf ("\033[1;32mPASS\033[0m\n");
   else {
      printf ("\033[1;31mFAIL\033[0m\n");
      printf ("Expected: \033[1;35m%s\033[0m Output: \033[1;31m%s\033[0m\n", outputLong2, binResultLong2);
   }
}