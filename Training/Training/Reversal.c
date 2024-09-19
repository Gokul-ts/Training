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
#define MAX_CHAR 52
#define PALINDROME 1
#define NOT_PALINDROME 0
#define INVALID -1

/// <summary>Function to check given number is palindrome or not </summary>
int NumIsPalindrome (int num, int type);
/// <summary>Function to check given string is palindrome or not </summary>
int StrIsPalindrome (char* phrase, int type);
/// <summary>Function to get integer input from user</summary>
void IntegerInput (int option);
/// <summary>Function to get string input from user</summary>
void StringInput (int option);
/// <summary>Function to check test cases</summary>
void OutputCheck ();
/// <summary>Function to print result</summary>
void PrintResult (int value);
/// <summary>Clears the content on screen </summary>
void ClrScreen ();

int main () {
   while (1) {
      int count = 0;
      printf ("1-PALINDROME CHECKER\n2-REVERSE A NUMBER\n3-TEST CASES\n4-CLEAR SCREEN\n5-EXIT\nEnter an option:");
      char option = fgetc (stdin);
      int num = option;
      if (num != 10) while (getchar () != '\n') count++;
      if (count == 0 && (num < 54 && num > 48)) {
         switch (num) {
            case '1':
               StringInput (option);
               break;
            case '2':
               IntegerInput (option);
               break;
            case '3':
               OutputCheck ();
               break;
            case '4':
               ClrScreen ();
               break;
            case '5':
               return 0;
               break;
         }
      } else printf (ANSI_COLOR_RED"Please enter number between 1-5\n\n"ANSI_RESET_ALL);
   }
   return 0;
}

int NumIsPalindrome (int num, int type) {
   bool isNegative = false;
   if (num < 0) {
      num = -num;
      isNegative = true;
   }
   int org = num;
   long long int rev = 0;
   while (num != 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
   }
   if (type == 1) printf ("Output:%lld\n", rev);
   if (isNegative == true) return NOT_PALINDROME;
   return (rev == org);
}

int StrIsPalindrome (char* phrase, int type) {
   int j = 0, length = 0;
   length = (int)strlen (phrase);
   if (type == 1) length--;
   if (length > MAX_CHAR - 2) return INVALID;
   char temp[MAX_CHAR] = { '0' };
   for (int i = 0; i < length; i++) {
      if (isalnum (phrase[i]) != 0)
         temp[j++] = phrase[i];
   }
   temp[j] = '\0';
   if (j == 0) return INVALID;
   for (int n = 0; n < (j / 2); n++) {
      if (toupper (temp[n]) != toupper (temp[j - n - 1])) return NOT_PALINDROME;
   }
   return PALINDROME;
}

void StringInput (int option) {
   char ch = '\n';
   char phrase[MAX_CHAR];
   printf ("\nEnter a Phrase: ");
   char* j = fgets (phrase, sizeof (phrase), stdin);
   char* strResult = strchr (phrase, ch); //To check whether input exceeds limit
   if (strResult == NULL) while (getchar () != '\n');
   (j != NULL && phrase[0] != '\n' && strResult != NULL) ? PrintResult (StrIsPalindrome (phrase, 1)) : printf (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL);
}

void IntegerInput (int option) {
   char ch = '\n';
   char input[MAX_DIGIT];
   int number = 0;
   char* endptr;
   printf ("\nEnter an integer: ");
   char* i = fgets (input, sizeof (input), stdin);
   char* intResult = strchr (input, ch); //To check whether input exceeds limit
   number = strtol (input, &endptr, 10);
   if (intResult == NULL) while (getchar () != '\n');
   (i == NULL || endptr == input || *endptr != '\n' || input[0] == ' ' || input[0] == '\t') ? printf (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL) : (errno == ERANGE) ? printf (ANSI_COLOR_RED"INPUT LIMIT EXCEEDED!!!\n\n"ANSI_RESET_ALL) : PrintResult (NumIsPalindrome (number, 1));
}

void OutputCheck () {
   printf ("\nPALINDROME CHECKER:\n\n--------------INPUT----------------------OUTPUT------------RESULT---");
   char* strInput[] = { "Don't nod","I did, did I?","Was it a car or a cat I saw?","@@@","RADAR","NASA","CIVIC","NUN","TRUMPF METAMATION" };
   int strLength = sizeof (strInput) / sizeof (strInput[0]);
   for (int i = 0; i < strLength; i++) {
      char* strOutput = "It is not a Palindrome";
      char* strResult = ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL;
      if (StrIsPalindrome (strInput[i], 0) == 1 || StrIsPalindrome (strInput[i], 0) == 0 || StrIsPalindrome (strInput[i], 0) == -1) strResult = ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL;
      if (StrIsPalindrome (strInput[i], 0) == 1)strOutput = "It is a Palindrome";
      else if (StrIsPalindrome (strInput[i], 0) == -1) strOutput = "INVALID!!!";
      printf ("\n| %-28s | %-22s |   %6s   |"ANSI_COLOR_MAGENTA"\n--------------------------------------------------------------------"ANSI_RESET_ALL, strInput[i], strOutput, strResult);
   }
   printf ("\n\nREVERSE A NUMBER:\n\n-----INPUT--------------OUTPUT-----------RESULT---");
   int numInput[] = { 0,94867,121,34543,8888,-1,-111,154,12121 };
   int numLength = sizeof (numInput) / sizeof (numInput[0]);
   for (int i = 0; i < numLength; i++) {
      char* numOutput = "It is not a Palindrome";
      char* numResult = ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL;
      if (NumIsPalindrome (numInput[i], 0) == 1 || NumIsPalindrome (numInput[i], 0) == 0) numResult = ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL;
      if (NumIsPalindrome (numInput[i], 0) == 1) numOutput = "It is a Palindrome";
      printf ("\n| %-10d | %-22s |   %6s   |"ANSI_COLOR_MAGENTA"\n--------------------------------------------------"ANSI_RESET_ALL, numInput[i], numOutput, numResult);
   }
   printf ("\n\n");
}

void PrintResult (int value) {
   printf (value == 1 ? (ANSI_COLOR_GREEN"It is a Palindrome\n\n"ANSI_RESET_ALL) : value == 0 ? (ANSI_COLOR_RED"It is not a Palindrome\n\n"ANSI_RESET_ALL) : (ANSI_COLOR_RED"INVALID!!!\n\n"ANSI_RESET_ALL));
}

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}