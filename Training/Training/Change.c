// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Change.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>

void ChangeRequired (int* balance, int* change10, int* change5, int* change2, int* change1) {
   int num = *balance;
   if (num >= 10) {
      *change10 = num / 10;
      num %= 10;
   }
   if (num >= 5) {
      *change5 = num / 5;
      num %= 5;
   }
   if (num >= 2) {
      *change2 = num / 2;
      num %= 2;
   }
   if (num >= 1) {
      *change1 = num / 1;
      num %= 1;
   }
}

void main () {
   int balances[] = { 5,18,1,43,500 }, expResult[][4] = { { 0,1,0,0 },{ 1,1,1,1 },{ 0,0,0,1 },{ 4,0,1,1 },{ 50,0,0,0} };
   printf ("TestCases:\n");
   for (int i = 0; i < 5; i++) {
      int change10 = 0, change5 = 0, change2 = 0, change1 = 0;
      ChangeRequired (&balances[i], &change10, &change5, &change2, &change1);
      if (expResult[i][0] == change10 && expResult[i][1] == change5 && expResult[i][2] == change2 && expResult[i][3] == change1) {
         printf ("Pass\n");
      } else printf ("Fail\n");
   }
}
