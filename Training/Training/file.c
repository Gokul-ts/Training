// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// file.c
// C Program to implement Bubble sort and binary search algorithm with test cases
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_DIGIT 13
#define TEST_SIZE 7
#define ANSI_RESET_ALL "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

/// <summary>Changes the input array into a sorted array</summary>
void BubbleSort (int arr[], int size);
/// <summary>Returns the index of key element in an array</summary>
int BinarySearch (int sortArr[], int key, int size);
/// <summary>Gets integer input from user</summary>
int GetUserInput (char* prompt);
/// <summary>Implements the search and sort algorithm</summary>
void SearchAndSort ();
/// <summary>Clears the content on screen</summary>
void ClrScreen ();
/// <summary>Checks test cases</summary>
void TestCases ();
/// <summary>Compares two arrays and returns the result</summary>
int CompareArrays (int* input, int* output, int size);

int main () {
   while (1) {
      int num = GetUserInput ("1-SORT AND SEARCH\n2-TEST CASES\n3-CLEAR SCREEN\n4-EXIT\nEnter an option:");
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

void BubbleSort (int arr[], int size) {
   for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            arr[j] = arr[j] + arr[j + 1];
            arr[j + 1] = arr[j] - arr[j + 1];
            arr[j] = arr[j] - arr[j + 1];
         }
      }
   }
}

int BinarySearch (int sortArr[], int key, int size) {
   int low = 0, high = size - 1, result = -1;
   while (low <= high) {
      int mid = low + (high - low) / 2;
      if (sortArr[mid] == key) {
         result = mid;
         high = mid - 1;
      }
      if (sortArr[mid] < key) low = mid + 1;
      else high = mid - 1;
   }
   return result;
}

int GetUserInput (char* prompt) {
   int64_t number = 0;
   for (;;) {
      char strNum[MAX_DIGIT];
      char* endPtr = NULL;
      printf ("%s", prompt);
      char* strPtr = fgets (strNum, sizeof (strNum), stdin);
      char* validInput = strchr (strNum, '\n');
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
   BubbleSort (array, size);
   printf ("Sorted Array: ");
   for (int i = 0; i < size; i++) printf (ANSI_COLOR_YELLOW"%d "ANSI_RESET_ALL, array[i]);
   int index = BinarySearch (array, GetUserInput ("\n\nWhich element's index do you want to find?\n"), size);
   printf ((index == -1) ? ANSI_COLOR_GREEN"Element is not present in array\n\n"ANSI_RESET_ALL : ANSI_COLOR_GREEN"Element is present at index %d\n\n"ANSI_RESET_ALL, index);
   free (array);
}

void TestCases () {
   printf (ANSI_COLOR_YELLOW"\n-----------------TESTCASES-----------------\n"ANSI_RESET_ALL);
   int inpArray[][TEST_SIZE] = { { 25,20,-1,-8,0,2 },{ -214748,2547,154,87,4,9,10 } ,{ -3,25,-9,-5,4,1,-21 } ,{ 0,1,2,3 } ,
                         { 0,-1,-2,-3 },{ 2000,-2147483647,800,-3,-7 } ,{ 17,17,17,17,17 },{ 1,12,5,5,65,5 } };
   int outArray[][TEST_SIZE] = { { -8,-1,0,2,20,25 } ,{ -214748,4,9,10,87,154,2547 } , { -21,-9,-5,-3,1,4,25 } ,{ 0,1,2,3 } ,
                         { -3,-2,-1,0 },{ -2147483647,-7,-3,800,2000 },{ 17,17,17,17,17 },{ 1,5,5,5,12,65 } };
   int arrSize = sizeof (inpArray) / sizeof (inpArray[0]);
   int sizes[] = { 6,7,7,4,4,5,5,6 };
   int inpKey[] = { 0,154,-9, 4,-2,800,17,5 };
   int outIndex[] = { 2,5,1,-1,1,3,0,1 };
   for (int i = 0; i < arrSize; i++) {
      printf ("Input Array:   ");
      for (int j = 0; j < sizes[i]; j++) printf ("%d ", inpArray[i][j]);
      BubbleSort (inpArray[i], sizes[i]);
      printf ("\nSorted Array:  ");
      for (int j = 0; j < sizes[i]; j++) printf ("%d ", inpArray[i][j]);
      printf ("\nBubble Sort:   ");
      printf (CompareArrays (inpArray[i], outArray[i], sizes[i]) ? ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL : ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL);
      int index = BinarySearch (inpArray[i], inpKey[i], sizes[i]);
      printf ("\nKey:   %d\nIndex: %d", inpKey[i], index);
      printf ("\nBinary Search: ");
      printf ((index == outIndex[i]) ? ANSI_COLOR_GREEN"PASS"ANSI_RESET_ALL : ANSI_COLOR_RED"FAIL"ANSI_RESET_ALL);
      printf (ANSI_COLOR_YELLOW"\n-------------------------------------------\n"ANSI_RESET_ALL);
   }
   printf ("\n");
}

int CompareArrays (int* input, int* output, int size) {
   for (int i = 0; i < size; i++) {
      if (input[i] != output[i]) {
         return 0;
      }
   }
   return 1;
}

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}