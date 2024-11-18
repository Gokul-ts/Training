// --------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// file.c
// C Program to check test cases
// --------------------------------------------------------------------------------------------------------
#pragma warning(disable:6385)
#include "SortAndSearch.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

/// <summary>Gets integer input from user</summary>
/// <param name="prompt"></param>
int GetUserInput (char* prompt);
/// <summary>Implements the search and sort algorithm</summary>
void SortAndSearch (void(*sortFunc)(int[], int), int (*searchFunc)(int[], int, int));
/// <summary>Checks test cases for Sort function</summary>
static void TestCase_Sort (void(*func)(int[], int));
/// <summary>Checks test cases for Search function</summary>
static void TestCase_Search (int (*func)(int[], int, int));
/// <summary>Returns whether the given array is sorted or not</summary>
int IsSorted (int* arr1, int size);
/// <summary>Clears the content on screen</summary>
void ClrScreen ();

int main () {
   while (1) {
      int num = GetUserInput ("1-INSERTION SORT\n2-TEST CASES (InsertionSort)\n3-TEST CASES (BinarySearch)"
                              "\n4-CLR SCREEN\n5-EXIT\nEnter an option:");
      switch (num) {
         case 1:
            SortAndSearch (InsertionSort,BinarySearch);
            break;
         case 2:
            TestCase_Sort (InsertionSort);
            break;
         case 3:
            TestCase_Search (BinarySearch);
            break;
         case 4:
            ClrScreen ();
            break;
         case 5:
            return 0;
         default:
            printf (ANSI_COLOR_RED"Please enter a number between 1 - 6\n"ANSI_RESET_ALL);
      }
   }
   return 0;
}

int GetUserInput (char* prompt) {
   int number = 0;
   if (prompt != "") printf ("%s", prompt);
   for (;;) {
      char strNum[MAX_DIGIT], * endPtr = NULL,
         * strPtr = fgets (strNum, sizeof (strNum), stdin),
         * validInput = strchr (strNum, '\n');
      number = strtol (strNum, &endPtr, 10);
      if (validInput == NULL)  while (getchar () != '\n');
      if (strPtr == NULL || (!isdigit (strNum[0]) && strNum[0] != '-') || *endPtr != '\n') {
         printf (ANSI_COLOR_RED"Invalid Number!!! Please re-enter\n"ANSI_RESET_ALL);
         continue;
      }
      break;
   }
   return number;
}

void SortAndSearch (void(*sortFunc)(int[], int), int (*searchFunc)(int[], int, int)) {
   int size = 0;
   do {
      size = GetUserInput ("\nEnter the size of array: ");
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
   sortFunc (array, size);
   printf ("Sorted Array: ");
   for (int i = 0; i < size; i++) printf (ANSI_COLOR_YELLOW"%d "ANSI_RESET_ALL, array[i]);
   int index = searchFunc (array, GetUserInput ("\n\nEnter the element you want to find?\n"), size);
   printf ((index == -1) ? ANSI_COLOR_RED"Element is not present in array\n\n"ANSI_RESET_ALL :
           ANSI_COLOR_GREEN"Element is present at index %d\n\n"ANSI_RESET_ALL, index);
   free (array);
}

static void TestCase_Sort (void(*func)(int[], int)) {
   printf (ANSI_COLOR_YELLOW"\n-------------------------------------------------INSERTION_SORT_TESTCASES"
           "----------------------------------------------------------------\n"ANSI_RESET_ALL);
   srand ((unsigned int)time (NULL));
   int num = rand () % (50 - 1 + 1) + 1, ** randArr = malloc (num * sizeof (int*)), * size = malloc (num * sizeof (int));
   for (int i = 0; i < num; i++) {
      size[i] = rand () % (10 - 1 + 1) + 1;
      randArr[i] = malloc (sizeof (int) * size[i]);
      for (int j = 0; j < size[i]; j++) randArr[i][j] = rand () % (1073741823 + 1073741823 + 1) - 1073741823;
   }
   for (int i = 0; i < num; i++) {
      printf ("Input Array:  ");
      for (int j = 0; j < size[i]; j++) printf ("%d ", randArr[i][j]);
      func (randArr[i], size[i]);
      printf ("\nSorted Array: ");
      for (int k = 0; k < size[i]; k++) printf ("%d ", randArr[i][k]);
      char lines[] = ANSI_COLOR_YELLOW"--------------------------------------------------------------"
         "---------------------------------------------------------------------------"ANSI_RESET_ALL;
      printf ("\nResult:        %s\n%s\n", IsSorted (randArr[i], size[i]) ?
              ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL : ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL, lines);
   }
   printf ("Number of Test cases checked: "ANSI_COLOR_GREEN"%d\n\n"ANSI_RESET_ALL, num);
   free (randArr);
   free (size);
}

static void TestCase_Search (int (*func)(int[], int, int)) {
   int row1[] = { -8, -1, 0, 2, 20, 25 }, row2[] = { -9, -5, -3, 1, 4, 25 }, row3[] = { -5, -4, -3, -2, -1, 0 },
      row4[] = { -2147483647, -7, -3, 1, 800, 2000 }, row5[] = { 17, 17, 17, 17, 17, 17 }, row6[] = { 1, 5, 5, 5 ,12, 65 },
      * jagArr[] = { row1,row2,row3,row4,row5,row6 },
      inpKey[] = { 0,-9,-2,800,17,5 },
      outIndex[] = { 2,0,3,4,0,1 };
   printf (ANSI_COLOR_YELLOW"\n------------BINARY_SEARCH_TESTCASES------------\n"ANSI_RESET_ALL);
   for (int i = 0; i < TEST_SIZE; i++) {
      printf ("Input Array: ");
      for (int j = 0; j < TEST_SIZE; j++) printf ("%d ", jagArr[i][j]);
      int index = func (jagArr[i], inpKey[i], TEST_SIZE);
      char lines[] = ANSI_COLOR_YELLOW"\n-----------------------------------------------\n"ANSI_RESET_ALL;
      printf ("\nKey:         %d\nIndex:       %d\nResult:      %s%s", inpKey[i], index, index == outIndex[i] ?
              ANSI_COLOR_GREEN"PASS"ANSI_COLOR_YELLOW : ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL, lines);
   }
   printf ("\n");
}

int IsSorted (int* arr, int size) {
   for (int i = 0; i < size - 1; i++)
      if (arr[i] > arr[i + 1])  return 0;
   return 1;
}

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}