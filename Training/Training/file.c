// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include<stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 13

int GetUserInput (char* prompt) {
   int number = 0;
   if (prompt != "") printf ("%s", prompt);
   for (;;) {
      char strNum[MAX], * endPtr = NULL,
         * strPtr = fgets (strNum, sizeof (strNum), stdin),
         * validInput = strchr (strNum, '\n');
      number = strtol (strNum, &endPtr, 10);
      if (validInput == NULL)  while (getchar () != '\n');
      if (strPtr == NULL || (!isdigit (strNum[0]) && strNum[0] != '-') || *endPtr != '\n') {
         printf ("Invalid Number!!! Please re-enter\n");
         continue;
      }
      break;
   }
   return number;
}


void PrintBoard (char pieces[]) {
   printf ("BOARD GAME\n");
   printf ("+---+---+---+\n|");
   for (int j = 0; j < 9; j++) {
      switch (j) {
         case 0:
            printf (" %c |", pieces[j]);
            break;
         case 1:
            printf (" %c |", pieces[j]);
            break;
         case 2:
            printf (" %c |", pieces[j]);
            break;
         case 3:
            printf ("| %c |", pieces[j]);
            break;
         case 4:
            printf (" %c |", pieces[j]);
            break;
         case 5:
            printf (" %c |", pieces[j]);
            break;
         case 6:
            printf ("| %c |", pieces[j]);
            break;
         case 7:
            printf (" %c |", pieces[j]);
            break;
         case 8:
            printf (" %c |", pieces[j]);
            break;
         default:
            break;
      }
      if ((j + 1) % 3 == 0) {
         printf ("\n");
         printf ("+---+---+---+\n");
      }
   }
}

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}

void main () {
   char pieces[] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
   PrintBoard (pieces);
   int player1 = 0;
   int player2 = 0;
   int input1 = 0, input2 = 0;
   for (int i = 0; i < 4; i++) {
      for (;;) {
         input1 = GetUserInput ("Player1:");
         input2 = GetUserInput ("Player2:");
         if ((input1 > 9 || input1 < 1) || (input2 > 9 || input2 < 1)) {
            printf ("Invalid Number!!! Please re-enter\n");
            continue;
         }
         break;
      }
      pieces[input1 - 1] = 'X';
      pieces[input2 - 1] = 'O';
      ClrScreen ();
      PrintBoard (pieces);
      if (i > 1) {
         for (int i = 0; i < 1; i++) {
            if ((pieces[i] == 'X' && pieces[i + 3] == 'X' && pieces[i + 6] == 'X') ||
                (pieces[i] == 'X' && pieces[i + 1] == 'X' && pieces[i + 2] == 'X') ||
                (pieces[i] == 'X' && pieces[i + 4] == 'X' && pieces[i + 8] == 'X') ||
                (pieces[i + 3] == 'X' && pieces[i + 4] == 'X' && pieces[i + 5] == 'X') ||
                (pieces[i + 6] == 'X' && pieces[i + 7] == 'X' && pieces[i + 8] == 'X') ||
                (pieces[i + 2] == 'X' && pieces[i + 5] == 'X' && pieces[i + 8] == 'X') ||
                (pieces[i + 1] == 'X' && pieces[i + 4] == 'X' && pieces[i + 7] == 'X') ||
                (pieces[i + 6] == 'X' && pieces[i + 4] == 'X' && pieces[i + 2] == 'X'))

            {
               player1++;
            }
            if ((pieces[i] == 'O' && pieces[i + 3] == 'O' && pieces[i + 6] == 'O') ||
                (pieces[i] == 'O' && pieces[i + 1] == 'O' && pieces[i + 2] == 'O') ||
                (pieces[i] == 'O' && pieces[i + 4] == 'O' && pieces[i + 8] == 'O') ||
                (pieces[i + 3] == 'O' && pieces[i + 4] == 'O' && pieces[i + 5] == 'O') ||
                (pieces[i + 6] == 'O' && pieces[i + 7] == 'O' && pieces[i + 8] == 'O') ||
                (pieces[i + 2] == 'O' && pieces[i + 5] == 'O' && pieces[i + 8] == 'O') ||
                (pieces[i + 1] == 'O' && pieces[i + 4] == 'O' && pieces[i + 7] == 'O') ||
                (pieces[i + 6] == 'O' && pieces[i + 4] == 'O' && pieces[i + 2] == 'O')) {
               player2++;
            }

         }
         if (player1 && !player2 || player1 && player2) {
            printf ("Player1 is the Winner!!!\n");
            return;
         } else if (player2 && !player1) {
            printf ("Player2 is the Winner!!!\n");
            return;
         } else if (!player1 && !player2 && (i > 2)) {
            printf ("Match Draw\n");
            return;
         }
      }
   }
}