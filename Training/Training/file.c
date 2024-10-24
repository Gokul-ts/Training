// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// file.c
// C Program to check test cases
// ------------------------------------------------------------------------------------------------
#include "SortAndSearch.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/// <summary>Gets integer input from user</summary>
/// <param name="prompt"></param>
int GetUserInput (char* prompt);
/// <summary>Implements the search and sort algorithm</summary>
void SearchAndSort (void(*func)(int[], int));
/// <summary>Checks test cases</summary>
void TestCases (void(*func)(int[], int), char* sortType);
/// <summary>Returns whether two arrays are equal or not</summary>
int CompareArrays (int* input, int* output, int size);
/// <summary>Clears the content on screen</summary>
void ClrScreen ();

int main () {
   while (1) {
      int num = GetUserInput ("1-BUBBLE SORT\n2-INSERTION SORT\n3-TEST CASES (B.S)"
                              "\n4-TEST CASES (I.S)\n5-CLR SCREEN\n6-EXIT\nEnter an option:");
      if (num > 6 || num < 1)
         printf (ANSI_COLOR_RED"Please enter a number between 1-6\n"ANSI_RESET_ALL);
      else
         switch (num) {
            case 1:
               SearchAndSort (BubbleSort);
               break;
            case 2:
               SearchAndSort (InsertionSort);
               break;
            case 3:
               TestCases (BubbleSort, "Bubble Sort:     ");
               break;
            case 4:
               TestCases (InsertionSort, "Insertion Sort:  ");
               break;
            case 5:
               ClrScreen ();
               break;
            case 6:
               return 0;
         }
   }
   return 0;
}

int GetUserInput (char* prompt) {
   int number = 0;
   for (;;) {
      if (prompt != "") printf ("%s", prompt);
      char strNum[MAX_DIGIT], * endPtr = NULL,
         * strPtr = fgets (strNum, sizeof (strNum), stdin), * validInput = strchr (strNum, '\n');
      number = strtol (strNum, &endPtr, 10);
      if (validInput == NULL)  while (getchar () != '\n');
      if (strPtr == NULL || validInput == NULL || (!isdigit (strNum[0]) && strNum[0] != '-') || *endPtr != '\n') {
         printf (ANSI_COLOR_RED"Invalid Number!!! Please re-enter\n"ANSI_RESET_ALL);
         continue;
      }
      break;
   }
   return number;
}

void SearchAndSort (void(*func)(int[], int)) {
   int size = 0;
   do {
      size = GetUserInput ("\nEnter the size of array:");
      if (size <= 0)  printf (ANSI_COLOR_RED"Invalid Number!!! Please re-enter\n"ANSI_RESET_ALL);
   } while (size <= 0);
   int* array = (int*)malloc (size * sizeof (int));
   if (array == NULL) {
      printf ("Memory allocation failed!\n");
      return;
   }
   printf ("\nEnter the elements of the array:\n");
   for (int i = 0; i < size; i++) {
      printf ("[%d]", i);
      array[i] = GetUserInput ("");
   }
   func (array, size);
   printf ("Sorted Array: ");
   for (int i = 0; i < size; i++) printf (ANSI_COLOR_YELLOW"%d "ANSI_RESET_ALL, array[i]);
   int index = BinarySearch (array, GetUserInput ("\n\nEnter the element you want to find?\n"), size);
   printf ((index == -1) ? ANSI_COLOR_RED"Element is not present in array\n\n"ANSI_RESET_ALL :
           ANSI_COLOR_GREEN"Element is present at index %d\n\n"ANSI_RESET_ALL, index);
   free (array);
}

void TestCases (void(*func)(int[], int), char* sortType) {
   printf (ANSI_COLOR_YELLOW"\n-----------------TESTCASES-----------------\n"ANSI_RESET_ALL);
   int inpArray[][TEST_SIZE] = { { 25,20,-1,-8,0,2 },{ -214748,2547,154,87,4,9,10 },{ -3,25,-9,-5,4,1,-21 },
           { 0,1,2,3 },{ 0,-1,-2,-3 },{ 2000,-2147483647,800,-3,-7 },{ 17,17,17,17,17 },{ 1,12,5,5,65,5 } },
      outArray[][TEST_SIZE] = { { -8,-1,0,2,20,25 },{ -214748,4,9,10,87,154,2547 },{ -21,-9,-5,-3,1,4,25 },
          { 0,1,2,3 },{ -3,-2,-1,0 },{ -2147483647,-7,-3,800,2000 },{ 17,17,17,17,17 },{ 1,5,5,5,12,65 } },
      arrSize = sizeof (inpArray) / sizeof (inpArray[0]),
      sizes[] = { 6,7,7,4,4,5,5,6 },
      inpKey[] = { 0,154,-9, 4,-2,800,17,5 },
      outIndex[] = { 2,5,1,-1,1,3,0,1 };
   for (int i = 0; i < arrSize; i++) {
      int size = sizes[i];
      printf ("Input Array:     ");
      for (int j = 0; j < size; j++) printf ("%d ", inpArray[i][j]);
      func (inpArray[i], size);
      printf ("\nSorted Array:    ");
      for (int j = 0; j < size; j++) printf ("%d ", inpArray[i][j]);
      printf ("\n%s%s", sortType, CompareArrays (inpArray[i], outArray[i], size) ? ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL :
              ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL);
      int index = BinarySearch (inpArray[i], inpKey[i], size);
      printf ("\nKey:             %d\nIndex:           %d\nBinary Search:   %s", inpKey[i], index, index == outIndex[i] ?
              ANSI_COLOR_GREEN"PASS"ANSI_COLOR_YELLOW"\n-------------------------------------------\n"ANSI_RESET_ALL :
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