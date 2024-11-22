// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define MAX 50

void ChangeRequired (int* balance, int* change1, int* change2, int* change3, int* change4) {
   int num = *balance;
   while (num >= 10) {
      *change1 = num / 10;
      num = num % 10;
   }
   while (num >= 5) {
      *change2 = num / 5;
      num = num % 5;
   }
   while (num >= 2) {
      *change3 = num / 2;
      num = num % 2;
   }
   while (num >= 1) {
      *change4 = num / 1;
      num = num % 1;
   }
}

void main () {
   char actAmount[MAX] = "";
   char cashPaid[MAX] = "";
   char* endptr1 = NULL;
   char* endptr2 = NULL;
   printf ("Enter the actual amount: ");
   char* inpPtr1 = fgets (actAmount, sizeof (actAmount), stdin);
   printf ("Enter the cash paid: ");
   char* inpPtr2 = fgets (cashPaid, sizeof (cashPaid), stdin);
   if (inpPtr1 == NULL || inpPtr2 == NULL) {
      printf ("Invalid Input!!!");
      return;
   }
   int billAmount = strtol (actAmount, &endptr1, 10);
   int recAmount = strtol (cashPaid, &endptr2, 10);
   int diff = billAmount - recAmount;
   int change1 = 0, change2 = 0, change3 = 0, change4 = 0;
   printf ("Balance Amount: %d", diff);
   ChangeRequired (&diff, &change1, &change2, &change3, &change4);
   printf ("\nChange given: Rs10(%d),Rs5(%d),Rs2(%d),Rs1(%d)", change1, change2, change3, change4);
}
