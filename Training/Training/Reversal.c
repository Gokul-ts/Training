// ------------------------------------------------------------------------------------------------
// Assignment4 ~ A training program for new joiners at Metamation, Batch - Sept 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// Reversal.c
// C program to Check Palindrome or not
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ANSI_RESET_ALL "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[36m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

#define MAX_DIGIT 13
#define MAX_CHAR 50

/// <summary>Function to check given number is palindrome or not </summary>
bool NumIsPalindrome (int num);
/// <summary>Function to check given string is palindrome or not </summary>
bool StrIsPalindrome (char* phrase);
/// <summary>Function to get integer input from user</summary>
void IntegerInput (int option);
/// <summary>Function to get string input from user</summary>
void StringInput (int option);
/// <summary>Function to check test cases</summary>
void OutputCheck ();
/// <summary>Function to print result</summary>
void PrintResult (bool value);
/// <summary>Clears the content on screen </summary>
void ClrScreen ();
/// <summary>Clears buffer values </summary>
void ClrBuffer (char option);


void main () {
   while (1) {
      bool breakLoop = false;
      int count = 0;
      printf (ANSI_COLOR_MAGENTA"1-PALINDROME CHECKER\n2-REVERSE A NUMBER\n3-TEST CASES\n4-CLEAR SCREEN\n5-EXIT\n"ANSI_RESET_ALL"Enter an option:");
      char option = fgetc (stdin);
      int num = option;
      if (num != 10) {
         for (;;) {
            option = fgetc (stdin);
            if (option == '\n') break;
            count++;
         }
      }
      if (count == 0 && (num < 54 && num > 48)) {
         switch (num) {
            case '1': {
               IntegerInput (option);
               break;
            }
            case '2': {
               StringInput (option);
               break;
            }
            case '3': {
               OutputCheck ();
               break;
            }
            case '4': {
               ClrScreen ();
               break;
            }
            case '5': {
               breakLoop = true;
               break;
            }
         }
      } else printf (ANSI_COLOR_RED"Please enter number between 1-5\n\n"ANSI_RESET_ALL);
      if (breakLoop == true) break;
   }
}


bool NumIsPalindrome (int num) {
   if (num < 0) {
      printf ("Output:%7s", "INVALID");
      return false;
   }
   int org = num;
   long long int rev = 0;
   while (num != 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
   }
   printf ("Output:%7lld", rev);
   return (rev == org);
}

bool StrIsPalindrome (char* phrase) {
   int i = 0, j = 0, length = 0;
   length = (int)strlen (phrase);
   char temp[MAX_CHAR] = { '0' };
   while (i < length) {
      if (isalnum (phrase[i]) != 0)
         temp[j++] = phrase[i];
      i++;
   }
   temp[j] = '\0';
   if (j == 0) return false;
   for (int n = 0; n < (j / 2); n++) {
      if (toupper (temp[n]) != toupper (temp[j - n - 1])) return false;
   }
   return true;
}

void IntegerInput (int option) {
   char ch = '\n';
   char phrase[MAX_CHAR];
   printf ("\nEnter a Phrase: ");
   char* j = fgets (phrase, sizeof (phrase), stdin);
   char* strResult = strchr (phrase, ch);
   if (j != NULL && phrase[0] != '\n' && strResult != NULL) {
      PrintResult (StrIsPalindrome (phrase));
   } else {
      printf (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL);
      ClrBuffer (option);
   }
}

void StringInput (int option) {
   char ch = '\n';
   char input[MAX_DIGIT];
   int number = 0;
   char* endptr;
   printf ("\nEnter an integer: ");
   char* i = fgets (input, sizeof (input), stdin);
   char* intResult = strchr (input, ch);
   number = strtol (input, &endptr, 10);
   if (intResult == NULL) ClrBuffer (option);
   if (i == NULL || endptr == input || *endptr != '\n' && *endptr != '\0' || input[0] == ' ' || input[0] == '\t') printf (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL);
   else if (errno == ERANGE) printf (ANSI_COLOR_RED"INDEX OUT OF RANGE\n\n"ANSI_RESET_ALL);
   else PrintResult (NumIsPalindrome (number));
}

void OutputCheck () {
   printf ("\n-----PALINDROME CHECKER-----\n");
   char* strInput[] = { "Don't nod","I did, did I?","Was it a car or a cat I saw?","Trumpf Metamation","RADAR","NASA","CIVIC","NUN","LEVEL" };
   int strLength = sizeof (strInput) / sizeof (strInput[0]);
   for (int i = 0; i < strLength; i++) {
      printf ("Test Case%d: Input--> %28s ", i + 1, strInput[i]);
      printf ((StrIsPalindrome (strInput[i]) == true) ? "%25s", ANSI_COLOR_GREEN"PASS\n"ANSI_RESET_ALL : ANSI_COLOR_RED"FAIL\n"ANSI_RESET_ALL);
   }
   printf ("\n-----REVERSE A NUMBER-----\n");
   int numInput[] = { 0,94867,121,34543,8888,-1,-111,154,12121 };
   int numLength = sizeof (numInput) / sizeof (numInput[0]);
   for (int i = 0; i < numLength; i++) {
      printf ("Test Case%d: Input--> %6d ", i + 1, numInput[i]);
      printf ((NumIsPalindrome (numInput[i]) == true) ? ANSI_COLOR_GREEN" PASS\n"ANSI_RESET_ALL : ANSI_COLOR_RED" FAIL\n"ANSI_RESET_ALL);
   }
   printf ("\n");
}

void PrintResult(bool value){ 
   printf (value ? (ANSI_COLOR_GREEN"\nIt is a Palindrome\n\n"ANSI_RESET_ALL) : (ANSI_COLOR_RED"\nIt is not a Palindrome\n\n"ANSI_RESET_ALL));
}

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#else
   system ("clear");
#endif 
}

void ClrBuffer (char option) {
   for (;;) {
      option = fgetc (stdin);
      if (option == '\n' || option == EOF) break;
   }
}