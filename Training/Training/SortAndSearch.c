// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// SortAndSearch.c
// C Program for Bubble sort and binary search algorithm
// ------------------------------------------------------------------------------------------------
#include "SortAndSearch.h"

void BubbleSort (int arr[], int size) {
   for (int i = 0; i < size - 1; i++)
      for (int j = 0; j < size - i - 1; j++)
         if (arr[j] > arr[j + 1]) {
            arr[j] += arr[j + 1];
            arr[j + 1] = arr[j] - arr[j + 1];
            arr[j] -= arr[j + 1];
         }
}

int BinarySearch (int sortArr[], int key, int size) {
   int low = 0, high = size - 1, result = -1;
   while (low <= high) {
      int mid = (low + high) / 2;
      if (sortArr[mid] == key) {
         result = mid;
         high = mid - 1;
      }
      if (sortArr[mid] < key) low = mid + 1;
      else high = mid - 1;
   }
   return result;
}