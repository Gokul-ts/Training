// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// file.c
// C Program to check test cases
// ------------------------------------------------------------------------------------------------
#include "SortAndSearch.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/// <summary>Gets integer input from user with specified prompt</summary>
int GetUserInputWithPrompt (char* prompt);
/// <summary>Implements the search and sort algorithm</summary>
void SearchAndSort ();
/// <summary>Clears the content on screen</summary>
void ClrScreen ();
/// <summary>Checks test cases</summary>
void TestCases ();
/// <summary>Returns whether two arrays are equal or not</summary>
int CompareArrays (int* input, int* output, int size);

int main () {
   while (1) {
      int num = GetUserInputWithPrompt ("1-SORT AND SEARCH\n2-TEST CASES\n3-CLEAR SCREEN\n4-EXIT\nEnter an option:");
      if (num > 4 || num < 1)
         printf (ANSI_COLOR_RED"Please enter a number between 1-4\n"ANSI_RESET_ALL);
      else {
         switch (num) {
            case 1:
               SearchAndSort ();
               break;
            case 2:
               TestCases ();
               break;
            case 3:
               ClrScreen ();
               break;
            case 4:
               return 0;
         }
      }
   }
   return 0;
}

int GetUserInputWithPrompt (char* prompt) {
   int64_t number = 0;
   for (;;) {
      printf ("%s", prompt);
      char strNum[MAX_DIGIT], * endPtr = NULL, * strPtr = fgets (strNum, sizeof (strNum), stdin), * validInput = strchr (strNum, '\n');
      number = strtoll (strNum, &endPtr, 10);
      if (validInput == NULL)  while (getchar () != '\n');
      if (strPtr == NULL || validInput == NULL || *endPtr != '\n' || (isdigit (strNum[0]) == 0 && strNum[0] != '-') || number < INT32_MIN || number > INT32_MAX) {
         printf (ANSI_COLOR_RED"Invalid Number!!! Please re-enter\n"ANSI_RESET_ALL);
         continue;
      }
      break;
   }
   return (int)number;
}

void SearchAndSort () {
   int size = 0;
   do {
      size = GetUserInputWithPrompt ("\nEnter the size of array:");
      if (size <= 0)  printf (ANSI_COLOR_RED"Invalid Number!!! Please re-enter\n"ANSI_RESET_ALL);
   } while (size <= 0);
   int* array = (int*)malloc (size * sizeof (int));
   if (array == NULL) {
      printf ("Memory allocation failed!\n");
      return;
   }
   printf ("\nEnter the elements of the array:\n");
   for (int i = 0; i < size; i++) {
      char index[] = "[i]";
      index[1] = i + 48;
      array[i] = GetUserInputWithPrompt (index);
   }
   BubbleSort (array, size);
   printf ("Sorted Array: ");
   for (int i = 0; i < size; i++) printf (ANSI_COLOR_YELLOW"%d "ANSI_RESET_ALL, array[i]);
   int index = BinarySearch (array, GetUserInputWithPrompt ("\n\nEnter the element you want to find?\n"), size);
   printf ((index == -1) ? ANSI_COLOR_GREEN"Element is not present in array\n\n"ANSI_RESET_ALL : ANSI_COLOR_GREEN"Element is present at index %d\n\n"ANSI_RESET_ALL, index);
   free (array);
}

void TestCases () {
   printf (ANSI_COLOR_YELLOW"\n-----------------TESTCASES-----------------\n"ANSI_RESET_ALL);
   int inpArray[][TEST_SIZE] = { { 25,20,-1,-8,0,2 },{ -214748,2547,154,87,4,9,10 } ,{ -3,25,-9,-5,4,1,-21 } ,{ 0,1,2,3 } ,
                                { 0,-1,-2,-3 },{ 2000,-2147483647,800,-3,-7 } ,{ 17,17,17,17,17 },{ 1,12,5,5,65,5 } },
      outArray[][TEST_SIZE] = { { -8,-1,0,2,20,25 } ,{ -214748,4,9,10,87,154,2547 } , { -21,-9,-5,-3,1,4,25 } ,{ 0,1,2,3 } ,
                               { -3,-2,-1,0 },{ -2147483647,-7,-3,800,2000 },{ 17,17,17,17,17 },{ 1,5,5,5,12,65 } },
      arrSize = sizeof (inpArray) / sizeof (inpArray[0]), sizes[] = { 6,7,7,4,4,5,5,6 }, inpKey[] = { 0,154,-9, 4,-2,800,17,5 }, outIndex[] = { 2,5,1,-1,1,3,0,1 };
   for (int i = 0; i < arrSize; i++) {
      int size = sizes[i];
      printf ("Input Array:   ");
      for (int j = 0; j < size; j++) printf ("%d ", inpArray[i][j]);
      BubbleSort (inpArray[i], size);
      printf ("\nSorted Array:  ");
      for (int j = 0; j < size; j++) printf ("%d ", inpArray[i][j]);
      printf ("\nBubble Sort:   ");
      printf (CompareArrays (inpArray[i], outArray[i], size) ? ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL : ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL);
      int index = BinarySearch (inpArray[i], inpKey[i], size);
      printf ("\nKey:   %d\nIndex: %d\nBinary Search: ", inpKey[i], index);
      printf ((index == outIndex[i]) ? ANSI_COLOR_GREEN"PASS"ANSI_COLOR_YELLOW"\n-------------------------------------------\n"ANSI_RESET_ALL :
              ANSI_COLOR_RED"FAIL"ANSI_COLOR_YELLOW"\n-------------------------------------------\n"ANSI_RESET_ALL);
   }
   printf ("\n");
}

int CompareArrays (int* arr1, int* arr2, int size) {
   for (int i = 0; i < size; i++)
      if (arr1[i] != arr2[i])  return 0;
   return 1;
}

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}