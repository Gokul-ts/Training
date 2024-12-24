// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Change.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>

bool IsChangeRequired (int balance, int expChanges[], int changes[], int size) {
   if (balance < 0) return false;
   for (int i = 0; i < size; i++) {
      expChanges[i] = balance / changes[i];
      balance %= changes[i];
   }
   return true;
}

void TestFunction (int balances[], int expResult[][4], int testArrSize, int changes[]) {
   printf ("TestCase:\n");
   for (int i = 0; i < testArrSize; i++) {
      int expChanges[] = { 0,0,0,0 }, balArrSize = sizeof (expChanges) / sizeof (expChanges[0]);
      IsChangeRequired (balances[i], expChanges, changes, balArrSize);
      if ((expResult[i][0] != expChanges[0]) || (expResult[i][1] != expChanges[1]) ||
          (expResult[i][2] != expChanges[2]) || (expResult[i][3] != expChanges[3])) {
         printf ("Fail!!! For a balance of %d, the following coins were returned:Rs.10(%d),Rs.5(%d),Rs.2(%d),Rs.1(%d)\n",
                 balances[i], expChanges[0], expChanges[1], expChanges[2], expChanges[3]);
         return;
      }
   }
   printf ("Pass\n");
}

void main () {
   int balances[] = { 5,18,1,43,500,-1,2147483647 }, changes[] = { 10,5,2,1 },
      expResult[][4] = { { 0,1,0,0 },{ 1,1,1,1 },{ 0,0,0,1 },{ 4,0,1,1 },{ 50,0,0,0 },{0,0,0,0},{ 214748364,1,1,0 } },
      testArrSize = sizeof (balances) / sizeof (balances[0]);
   TestFunction (balances, expResult, testArrSize, changes);
}
