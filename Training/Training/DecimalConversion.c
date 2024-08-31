// ------------------------------------------------------------------------------------------------
// Assignment3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// DecimalConversion.c
// C program for converting a decimal number into binary and hexadecimal number
// ------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define INT_SIZE sizeof(int) * 8
int binInt[INT_SIZE];
char binChar[INT_SIZE + 1];
char hex[INT_SIZE + 1];

/// <summary>Converts integers into binary</summary>
char* DecToBin (int num);
/// <summary>Converts integers into hexadecimal</summary>
char* DecToHex (int num);

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
   long long int inputLong1 = -2147483649ll;
   char* outputLong1 = "1111111111111111111111111111111101111111111111111111111111111111"; 
   printf ("Test Case10: Input--> %lld ", inputLong1);
   char* binResultLong1 = DecToBin (inputLong1);
   int k = strcmp (binResultLong1, outputLong1);
   if (k == 0) printf ("\033[1;32mPASS\033[0m\n");
   else printf ("\033[1;31mFAIL\033[0m\n");

   //test cases for Hexadecimal conversion
   printf ("\n-----Decimal to Hexadecimal-----\n");
   char* output2[] = {
      "00000000000000000000000000000000",
      "0000000000000000000000000000028B",
      "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDF",
      "000000000000000000000000000003E7",
      "FFFFFFFFFFFFFFFFFFFFFFFFFFFFECF5",
      "00000000000000000000000000003D8C",
      "FFFFFFFFFFFFFFFFFFFFFFFFFFFFEDD2",
      "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF",
      "FFFFFFFFFFFFFFFFFFFFFFFF80000001"};
   for (int i = 0; i < 9; i++) {
      int num2 = input[i];
      printf ("Test Case%d: Input--> %d ", i + 1, num2);
      char* binResult2 = DecToHex (num2);
      int n = strcmp (binResult2, output2[i]);
      if (n == 0) printf ("\033[1;32mPASS\033[0m\n");
      else printf ("\033[1;31mFAIL\033[0m\n");
   }
   long long int inputLong2 = -2147483649ll;
   char* outputLong2 = "FFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFF";
   printf ("Test Case10: Input--> %lld ", inputLong2);
   char* binResultLong2 = DecToBin (inputLong2);
   int l = strcmp (binResultLong2, outputLong2);
   if (l == 0) printf ("\033[1;32mPASS\033[0m\n");
   else printf ("\033[1;31mFAIL\033[0m\n");
}

char* DecToBin (int num) {
   int index = INT_SIZE - 1;
   while (index >= 0) {
      binInt[index--] = num & 1;
      num >>= 1;
   }
   for (int i = 0; i < INT_SIZE; i++) binChar[i] = binInt[i] + '0';
   binChar[INT_SIZE] = '\0';
   return binChar;
}

char* DecToHex (int num) {
   if (num == 0) {
      for (int i = 0; i < INT_SIZE; i++) hex[i] = '0';
      hex[INT_SIZE] = '\0';
   }
   unsigned int unsNum = (unsigned int)num;
   char hexChars[] = "0123456789ABCDEF";
   for (int i = INT_SIZE - 1; i >= 0; i--) {
      if (unsNum != 0) {
         hex[i] = hexChars[unsNum & 0xF];
         unsNum >>= 4;
      } else if (unsNum == 0 && num < 0) hex[i] = 'F';
      else if (unsNum == 0 && num > 0) hex[i] = '0';
   }
   hex[INT_SIZE] = '\0';
   return hex;
}


