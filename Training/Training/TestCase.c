// ------------------------------------------------------------------------------------------------
// Assignment3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// DecimalConversion.c
// C program to check the test cases of Decimal conversion
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "DecimalConversion.h"

#define ANSI_RESET_ALL "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[36m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

/// <summary>Function to check binary values and hexadecimal values</summary>
void TestConversion (int input[], char* outputBin[], int arrLength, char* (*func)(int));

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
   printf ("-----Decimal to Binary-----\n");
   TestConversion (input1, output1, length1, DecToBin);
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
   printf ("\n-----Decimal to Hexadecimal-----\n");
   TestConversion (input1, output2, length1, DecToHex);
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
   printf ("-----Decimal to Binary-----\n");
   TestConversion (input2, output3, length2, DecToBin);
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
   printf ("\n-----Decimal to Hexadecimal-----\n");
   TestConversion (input2, output4, length2, DecToHex);
//User input validation
   while (1) {
      char input[20];
      int number = 0;
      char* endptr;
      printf ("\nEnter an integer: ");
      if (fgets (input, sizeof (input), stdin) != NULL) {
         errno = 0;
         number = strtol (input, &endptr, 10);
         if (endptr == input || *endptr != '\n' && *endptr != '\0' || (number == LONG_MAX || number == LONG_MIN) && errno == ERANGE || number > INT_MAX || number < INT_MIN || input[0] == ' ') {
            printf (ANSI_COLOR_RED"INVALID!!!\n"ANSI_RESET_ALL);
         } else {
            printf ("Binary value:"ANSI_COLOR_BLUE"0b%s"ANSI_RESET_ALL, DecToBin (number));
            printf ("\nHexadecimal value:"ANSI_COLOR_MAGENTA"0x%s\n"ANSI_RESET_ALL, DecToHex (number));
         }
      } else printf (ANSI_COLOR_RED"INVALID!!!\n"ANSI_RESET_ALL);
   }
}

void TestConversion (int input[], char* outputBin[], int arrLength, char* (*func)(int)) {
   for (int i = 0; i < arrLength; i++) {
      printf ("Test Case%d: Input--> %11d ", i + 1, input[i]);
      char* binResult1 = func (input[i]);
      printf ((strcmp (binResult1, outputBin[i]) == 0) ? "%11s", ANSI_COLOR_GREEN"PASS\n"ANSI_RESET_ALL : "%11s", ANSI_COLOR_RED"FAIL\n"ANSI_RESET_ALL);
   }
}