// ------------------------------------------------------------------------------------------------
// Assignment4 ~ A training program for new joiners at Metamation, Batch - Sept 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// TestReversal.c
// C program to check test cases
// ------------------------------------------------------------------------------------------------
#include "Reversal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

/// <summary>Gets string input from user</summary>
void GetStringInput ();
/// <summary>Gets integer input from user</summary>
void GetIntegerInput ();
/// <summary>Checks test cases</summary>
void OutputCheck ();
/// <summary>Clears the content on screen</summary>
void ClrScreen ();

int main () {
   while (1) {
      char option[3];
      printf ("1-PALINDROME CHECKER\n2-REVERSE A NUMBER\n3-TEST CASES\n4-CLEAR SCREEN\n5-EXIT\n");
      printf ("Enter an option:");
      char* strPtr = fgets (option, sizeof (option), stdin);
      char* result = strchr (option, '\n');
      int num = atoi (option);
      if (result == NULL)  while (getchar () != '\n');
      if (strPtr == NULL || result == NULL || isdigit (option[0]) == 0 || num > 5 || num < 1)
         printf (ANSI_COLOR_RED"Please enter a number between 1-5\n\n"ANSI_RESET_ALL);
      else {
         switch (num) {
            case 1:
               GetStringInput ();
               break;
            case 2:
               GetIntegerInput ();
               break;
            case 3:
               OutputCheck ();
               break;
            case 4:
               ClrScreen ();
               break;
            case 5:
               return 0;
         }
      }
   }
   return 0;
}

void GetStringInput () {
   char phrase[MAX_CHAR];
   printf ("\nEnter a Phrase: ");
   char* strPtr = fgets (phrase, sizeof (phrase), stdin);
   char* strResult = strchr (phrase, '\n'); //To check whether input exceeds limit
   if (strResult == NULL) while (getchar () != '\n');
   if (strPtr == NULL || phrase[0] == '\n' || strResult == NULL) {
      printf (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL);
      return;
   }
   int result = IsStrPalindrome (phrase);
   printf ((result == PALINDROME) ? (ANSI_COLOR_GREEN"It is a Palindrome\n\n"ANSI_RESET_ALL) :
           (result == NOT_PALINDROME) ? (ANSI_COLOR_RED"It is not a Palindrome\n\n"ANSI_RESET_ALL) :
           (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL));
}

void GetIntegerInput () {
   char input[MAX_DIGIT];
   char* endPtr = NULL;
   printf ("\nEnter an integer: ");
   char* strPtr = fgets (input, sizeof (input), stdin);
   char* intResult = strchr (input, '\n'); //To check whether input exceeds limit
   int64_t number = strtoll (input, &endPtr, 10);
   if (intResult == NULL) while (getchar () != '\n');
   if (strPtr == NULL || endPtr == input || *endPtr != '\n' || isdigit (input[0]) == 0) {
      printf (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL);
      return;
   }
   if (number < INT32_MIN || number > INT32_MAX) {
      printf (ANSI_COLOR_RED"INPUT LIMIT EXCEEDED!!!\n\n"ANSI_RESET_ALL);
      return;
   }
   long long int revNum = 0;
   int result = IsNumPalindrome ((int)number, &revNum);
   printf ("Output: %lld\n", revNum);
   printf ((result == PALINDROME) ? (ANSI_COLOR_GREEN"It is a Palindrome\n\n"ANSI_RESET_ALL) : (ANSI_COLOR_RED"It is not a Palindrome\n\n"ANSI_RESET_ALL));
}

void OutputCheck () {
   printf ("\nPALINDROME CHECKER:\n\n");
   printf ("--------------INPUT----------------------OUTPUT------------RESULT---");
   char* strInput[] = { "Don't nod","I did, did I?","Was it a car or a cat I saw?","@@@","RADAR","NASA","CIVIC","NUN","TRUMPF METAMATION" };
   int strExpOutput[] = { 1,1,1,-1,1,0,1,1,0 };
   int strLength = sizeof (strInput) / sizeof (strInput[0]);
   for (int i = 0; i < strLength; i++) {
      char* strOutput = NULL;
      char* strResult = NULL;
      int result = IsStrPalindrome (strInput[i]);
      (result == strExpOutput[i]) ? (strResult = ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL) : (strResult = ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL);
      (result == 1) ? (strOutput = "It is a Palindrome") : (result == -1) ? (strOutput = "INVALID!!!") : (strOutput = "It is not a Palindrome");
      printf ("\n| %-28s | %-22s |   %s   |"ANSI_COLOR_MAGENTA
              "\n--------------------------------------------------------------------"ANSI_RESET_ALL,
              strInput[i], strOutput, strResult);
   }
   printf ("\n\nREVERSE A NUMBER:\n\n");
   printf ("-----INPUT-------REVERSE-----------OUTPUT-------------RESULT---");
   int numInput[] = { 0,94867,121,34543,8888,-1,-123,154,12121 };
   int numExpOutput[] = { 1,0,1,1,1,0,0,0,1 };
   int numLength = sizeof (numInput) / sizeof (numInput[0]);
   for (int i = 0; i < numLength; i++) {
      char* numOutput = NULL;
      char* numResult = NULL;
      long long int revNum = 0;
      int res = IsNumPalindrome (numInput[i], &revNum);
      (res == numExpOutput[i]) ? (numResult = ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL) : (numResult = ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL);
      (res == 1) ? numOutput = "It is a Palindrome" : (numOutput = "It is not a Palindrome");
      printf ("\n| %-10d | %-10lld | %-22s |   %s   |"ANSI_COLOR_MAGENTA
              "\n---------------------------------------------------------------"ANSI_RESET_ALL,
              numInput[i], revNum, numOutput, numResult);
   }
   printf ("\n\n");
}

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}