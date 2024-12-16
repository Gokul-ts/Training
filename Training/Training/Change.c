// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Change.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#define ERR -1

void ChangeRequired (int* balance, int* expChanges) {
   int changes[] = { 10,5,2,1 }, num = *balance,
      arrSize = sizeof (changes) / sizeof (changes[0]);
   if (num < 0) {
      for (int i = 0; i < arrSize; i++) expChanges[i] = ERR;
      return;
   }
   for (int i = 0; i < arrSize; i++) {
      expChanges[i] = num / changes[i];
      num %= changes[i];
   }
}

void main () {
   int balances[] = { 5,18,1,43,500,-1,0 }, expResult[][4] = { { 0,1,0,0 },{ 1,1,1,1 },{ 0,0,0,1 },{ 4,0,1,1 },{ 50,0,0,0 },{-1,-1,-1,-1},{ 0,0,0,0 } },
      arrSize = sizeof (balances) / sizeof (balances[0]), expChanges[] = { 0,0,0,0 };
   printf ("TestCases:\n");
   for (int i = 0; i < arrSize; i++) {
      ChangeRequired (&balances[i], expChanges);
      if (expResult[i][0] == expChanges[0] && expResult[i][1] == expChanges[1] && expResult[i][2] == expChanges[2] && expResult[i][3] == expChanges[3]) {
         printf ("%d.Pass\n",i+1);
      } else printf ("%d.Fail!!! For a balance of %d, the following coins were returned:Rs.10(%d),Rs.5(%d),Rs.2(%d),Rs.1(%d)\n",
                     i + 1,balances[i], expChanges[0], expChanges[1], expChanges[2], expChanges[3]);
   }
}
