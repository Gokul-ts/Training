// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright Gokul TS (c) Metamation India.
// ------------------------------------------------------------------
// BoardGame.c
// Program to play board game between two players.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void PrintBoard (char pieces[3][3]) {
   printf ("BOARD GAME\n+---+---+---+\n|");
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
         printf (j == 0 && i == 1 || j == 0 && i == 2 ? "| %c |" : " %c |", pieces[i][j]);
         if ((j + 1) % 3 == 0)  printf ("\n+---+---+---+\n");
      }
}

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}

void GetPlayerInput (char prompt, char* pieces) {
   for (;;) {
      printf ("Player %c: ", prompt);
      char ch = getch ();
      int input = ch - 49;
      if (input > 9 || input < 0) {
         printf ("Please enter a number between 1-9\n");
         continue;
      }
      if (pieces[input] != 'X' && pieces[input] != 'O') {
         pieces[input] = prompt;
         break;
      } else printf ("Number already chosen!!\n");
   }
}

int CheckWin (char pieces[3][3], char currentPlayer) {
   for (int i = 0; i < 3; i++)
      if (pieces[i][0] == currentPlayer && pieces[i][1] == currentPlayer && pieces[i][2] == currentPlayer ||
          pieces[0][i] == currentPlayer && pieces[1][i] == currentPlayer && pieces[2][i] == currentPlayer ||
          pieces[0][0] == currentPlayer && pieces[1][1] == currentPlayer && pieces[2][2] == currentPlayer ||
          pieces[0][2] == currentPlayer && pieces[1][1] == currentPlayer && pieces[2][0] == currentPlayer)
         return 1;
   return 0;
}

void main () {
   char pieces[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} }, currentPlayer = 'X';
   PrintBoard (pieces);
   for (int i = 0; i < 9; i++) {
      GetPlayerInput (currentPlayer, *pieces);
      ClrScreen ();
      PrintBoard (pieces);
      if (i > 3) {
         int result = CheckWin (pieces, currentPlayer);
         if (result) {
            printf ("Player %c is the Winner!!!\n", currentPlayer);
            return;
         } else if (!result && i > 7) {
            printf ("Match Draw!!!\n");
            return;
         }
      }
      currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
   }
}