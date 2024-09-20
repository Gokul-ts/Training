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

/// <summary>Function to get string input from user</summary>
void GetStringInput ();
/// <summary>Function to get integer input from user</summary>
void GetIntegerInput ();
/// <summary>Function to print result</summary>
void PrintResult (int value);
/// <summary>Function to print result along with reversed number</summary>
void PrintResultInt (int value, long long int num);
/// <summary>Function to check test cases</summary>
void OutputCheck ();
/// <summary>Clears the content on screen</summary>
void ClrScreen ();

int main () {
   while (1) {
      char ch = '\n';
      char option[3];
      printf ("1-PALINDROME CHECKER\n2-REVERSE A NUMBER\n3-TEST CASES\n4-CLEAR SCREEN\n5-EXIT\nEnter an option:");
      fgets (option, sizeof (option), stdin);
      char* Result = strchr (option, ch);
      if (Result == NULL) {
         while (getchar () != '\n');
         printf (ANSI_COLOR_RED"Please enter number between 1-5\n\n"ANSI_RESET_ALL);
      } else {
         int num = atoi (option);
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
               break;
         }
      }
   }
   return 0;
}

void GetStringInput () {
   char ch = '\n';
   char phrase[MAX_CHAR];
   printf ("\nEnter a Phrase: ");
   char* j = fgets (phrase, sizeof (phrase), stdin);
   char* strResult = strchr (phrase, ch); //To check whether input exceeds limit
   if (strResult == NULL) while (getchar () != '\n');
   (j != NULL && phrase[0] != '\n' && strResult != NULL) ? PrintResult (StrIsPalindrome (phrase, 1)) : printf (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL);
}

void GetIntegerInput () {
   errno = 0;
   char ch = '\n';
   char input[MAX_DIGIT];
   int number = 0;
   char* endptr;
   printf ("\nEnter an integer: ");
   char* i = fgets (input, sizeof (input), stdin);
   char* intResult = strchr (input, ch); //To check whether input exceeds limit
   number = strtol (input, &endptr, 10);
   long long int revNum = 0;
   long long int* ptr = &revNum;
   if (intResult == NULL) while (getchar () != '\n');
   (i == NULL || endptr == input || *endptr != '\n' || input[0] == ' ' || input[0] == '\t') ? printf (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL) :
      (errno == ERANGE) ? printf (ANSI_COLOR_RED"INPUT LIMIT EXCEEDED!!!\n\n"ANSI_RESET_ALL) : PrintResultInt (NumIsPalindrome (number, ptr), revNum);
}

void PrintResult (int value) {
   printf (value == 1 ? (ANSI_COLOR_GREEN"It is a Palindrome\n\n"ANSI_RESET_ALL) :
           value == 0 ? (ANSI_COLOR_RED"It is not a Palindrome\n\n"ANSI_RESET_ALL) : (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL));
}

void PrintResultInt (int value, long long int num) {
   printf ("Output: %lld\n", num);
   PrintResult (value);
}

void OutputCheck () {
   printf ("\nPALINDROME CHECKER:\n\n--------------INPUT----------------------OUTPUT------------RESULT---");
   char* strInput[] = { "Don't nod","I did, did I?","Was it a car or a cat I saw?","@@@","RADAR","NASA","CIVIC","NUN","TRUMPF METAMATION" };
   int strLength = sizeof (strInput) / sizeof (strInput[0]);
   for (int i = 0; i < strLength; i++) {
      char* strOutput = "It is not a Palindrome";
      char* strResult = ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL;
      int result = StrIsPalindrome (strInput[i], 0);
      if (result == 1 || result == 0 || result == -1) strResult = ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL;
      if (result == 1)strOutput = "It is a Palindrome";
      else if (result == -1) strOutput = "INVALID!!!";
      printf ("\n| %-28s | %-22s |   %6s   |"ANSI_COLOR_MAGENTA"\n--------------------------------------------------------------------"ANSI_RESET_ALL, strInput[i], strOutput, strResult);
   }
   printf ("\n\nREVERSE A NUMBER:\n\n-----INPUT-------REVERSE-----------OUTPUT-------------RESULT---");
   int numInput[] = { 0,94867,121,34543,8888,-1,-111,154,12121 };
   int numLength = sizeof (numInput) / sizeof (numInput[0]);
   for (int i = 0; i < numLength; i++) {
      char* numOutput = "It is not a Palindrome";
      char* numResult = ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL;
      long long int revNum = 0;
      long long int* ptr = &revNum;
      int res = NumIsPalindrome (numInput[i], ptr);
      if (res == 1 || res == 0) numResult = ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL;
      if (res == 1) numOutput = "It is a Palindrome";
      printf ("\n| %-10d | %-10lld | %-22s |   %6s   |"ANSI_COLOR_MAGENTA"\n---------------------------------------------------------------"ANSI_RESET_ALL, numInput[i], revNum, numOutput, numResult);
   }
   printf ("\n\n");
}

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}