// ------------------------------------------------------------------------------------------------
// Assignment3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// DecimalConversion.c
// C program to check the test cases of Decimal conversion
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "DecimalConversion.h"

#define ANSI_RESET_ALL "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[36m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

//integer range
#define INT_MAX 2147483648
#define INT_MIN -2147483649ll

/// <summary>Function to get only integer input from user</summary>
long long int GetIntegerOnly ();
/// <summary>Function to check binary values</summary>
void TestDecToBin (int input[], char* outputBin[], int arrLength);
/// <summary>Function to check hexadecimal values</summary>
void TestDecToHex (int input[], char* outputHex[], int arrLength);


void main () {
//test cases for Binary conversion
   int input1[] = { 0,651,-545,999,-4875,15756,-4654,-1,-2147483647 };
   int length1 = sizeof (input1) / sizeof (input1[0]);
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
   TestDecToBin (input1, output1, length1);
   char* output2[] = {
        "00000000",
        "0000028B",
        "FFFFFDDF",
        "000003E7",
        "FFFFECF5",
        "00003D8C",
        "FFFFEDD2",
        "FFFFFFFF",
        "80000001" };
   TestDecToHex (input1, output2, length1);
   printf ("\n");
//test cases for Hexadecimal conversion
   int input2[] = { 1,255,1023,16384,2147483647,-1,-5,-2147483647,-2147483648ll };
   int length2 = sizeof (input2) / sizeof (input2[0]);
   char* output3[] = {
      "00000000000000000000000000000001",
      "00000000000000000000000011111111",
      "00000000000000000000001111111111",
      "00000000000000000100000000000000",
      "01111111111111111111111111111111",
      "11111111111111111111111111111111",
      "11111111111111111111111111111011",
      "10000000000000000000000000000001",
      "10000000000000000000000000000000" };
   TestDecToBin (input2, output3, length2);
   char* output4[] = {
      "00000001",
      "000000FF",
      "000003FF",
      "00004000",
      "7FFFFFFF",
      "FFFFFFFF",
      "FFFFFFFB",
      "80000001",
      "80000000" };
   TestDecToHex (input2, output4, length2);
//User input validation
   while (1) {
      long long int dec = 0;
      dec = GetIntegerOnly ();
      if (dec != INT_MIN) {
         char* binNum = DecToBin ((unsigned int)dec);
         printf ("Binary value(0b): "ANSI_COLOR_BLUE"%s"ANSI_RESET_ALL, binNum);
         char* hexNum = DecToHex ((unsigned int)dec);
         printf ("\nHexadecimal value(0x): "ANSI_COLOR_MAGENTA"%s\n"ANSI_RESET_ALL, hexNum);
      }
   }
}

void TestDecToBin (int input[], char* outputBin[], int arrLength) {
   printf ("-----Decimal to Binary-----\n");
   for (int i = 0; i < arrLength; i++) {
      printf ("Test Case%d: Input--> %-11d ", i + 1, input[i]);
      char* binResult1 = DecToBin (input[i]);
      printf ((strcmp (binResult1, outputBin[i]) == 0) ? "%11s", ANSI_COLOR_GREEN"PASS\n"ANSI_RESET_ALL : "%11s", ANSI_COLOR_RED"FAIL\n"ANSI_RESET_ALL);
   }
}

void TestDecToHex (int input[], char* outputHex[], int arrLength) {
   printf ("\n-----Decimal to Hexadecimal-----\n");
   for (int i = 0; i < arrLength; i++) {
      printf ("Test Case%d: Input--> %-11d ", i + 1, input[i]);
      char* binResult2 = DecToHex (input[i]);
      printf ((strcmp (binResult2, outputHex[i]) == 0) ? "%11s", ANSI_COLOR_GREEN"PASS\n"ANSI_RESET_ALL : "%11s", ANSI_COLOR_RED"FAIL\n"ANSI_RESET_ALL);
   }
}

long long int GetIntegerOnly () {
   long long int num = 0;
   int sign = 1, ch;
   printf ("\nEnter the input: ");
   ch = getchar ();
   if (ch == '-') {
      sign = -1;
      ch = getchar ();
   }
   if (ch == '\n') {
      printf (ANSI_COLOR_RED"Invalid!!!\n"ANSI_RESET_ALL);
      return INT_MIN;
   }
   while (ch != '\n') {
      if (ch == EOF) {
         printf (ANSI_COLOR_RED"Invalid!!!\n"ANSI_RESET_ALL);
         return INT_MIN;
      }
      if (isdigit (ch)) {
         if (num > (INT_MAX - (ch - '0')) / 10) {
            printf (ANSI_COLOR_RED"Error: Integer overflow\n"ANSI_RESET_ALL);
            for (;;) {
               ch = getchar ();
               if (ch == EOF || ch == '\n') break;
            }
            return INT_MIN;
         }
         num = num * 10 + (ch - '0');
      } else {
         printf (ANSI_COLOR_RED"Error: Special characters are not allowed\n"ANSI_RESET_ALL);
         for (;;) {
            ch = getchar ();
            if (ch == EOF || ch == '\n') break;
         }
         return INT_MIN;
      }
      ch = getchar ();
   }
   if (num > (INT_MAX - 1) && num * sign > 0) {
      printf (ANSI_COLOR_RED"Error: Integer overflow\n"ANSI_RESET_ALL);
      return INT_MIN;
   };
   return num * sign;
}