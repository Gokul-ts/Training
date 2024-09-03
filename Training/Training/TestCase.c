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

#define ANSI_RESET_ALL "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[36m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

/// <summary>Function to get input from user</summary>
int UserInput ();
/// <summary>Function to check binary values</summary>
void TestDecToBin (int input[], char* outputBin[], int arrLength);
/// <summary>Function to check hexadecimal values</summary>
void TestDecToHex (int input[], char* outputHex[], int arrLength);

void main () {
   int input[] = { 0,651,-545,999,-4875,15756,-4654,-1,-2147483647 };
   int length1 = sizeof (input) / sizeof (input[0]);
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
   TestDecToBin (input, output1, length1);
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
   TestDecToHex (input, output2, length1);
   printf ("\n");
   int input2[] = { 1,255,1023,16384,2147483647,-1,-5,-2147483647,-2147483648ll };
   int length2 = sizeof (input) / sizeof (input[0]);
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
      "0000000000000001",
      "00000000000000FF",
      "00000000000003FF",
      "0000000000004000",
      "000000007FFFFFFF",
      "FFFFFFFFFFFFFFFF",
      "FFFFFFFFFFFFFFFB",
      "FFFFFFFF80000001",
      "FFFFFFFF80000000" };
   TestDecToHex (input2, output4, length2);
   UserInput (); //Validating user input values
}

int UserInput () {
   int dec;
   char term;
   while (1) {
      printf ("\nEnter a decimal number:");
      if (scanf_s ("%d%c", &dec, &term, 1) != 2 || term != '\n') {
         printf (ANSI_COLOR_RED"Please enter a VALID NUMBER!!!\n"ANSI_RESET_ALL);
         for (;;) {
            term = fgetc (stdin);
            if (term == EOF || term == '\n') break;
         }
      } else {
         char* binNum = DecToBin (dec);
         printf ("Binary value(0b): "ANSI_COLOR_BLUE"%s"ANSI_RESET_ALL, binNum);
         char* hexNum = DecToHex (dec);
         printf ("\nHexadecimal value(0x): "ANSI_COLOR_MAGENTA"%s\n"ANSI_RESET_ALL, hexNum);
      }
   }
   return 0;
}

void TestDecToBin (int input[], char* outputBin[], int arrLength) {
    //test cases for Binary conversion
   printf ("-----Decimal to Binary-----\n");
   for (int i = 0; i < arrLength; i++) {
      printf ("Test Case%d: Input--> %d ", i + 1, input[i]);
      char* binResult1 = DecToBin (input[i]);
      (strcmp (binResult1, outputBin[i]) == 0) ? printf (ANSI_COLOR_GREEN"PASS\n"ANSI_RESET_ALL) : printf (ANSI_COLOR_RED"FAIL\n"ANSI_RESET_ALL);
   }
}

void TestDecToHex (int input[], char* outputHex[], int arrLength) {
    //test cases for Hexadecimal conversion
   printf ("\n-----Decimal to Hexadecimal-----\n");
   for (int i = 0; i < arrLength; i++) {
      printf ("Test Case%d: Input--> %d ", i + 1, input[i]);
      char* binResult2 = DecToHex (input[i]);
      (strcmp (binResult2, outputHex[i]) == 0) ? printf (ANSI_COLOR_GREEN"PASS\n"ANSI_RESET_ALL) : printf (ANSI_COLOR_RED"FAIL\n"ANSI_RESET_ALL);
   }
}