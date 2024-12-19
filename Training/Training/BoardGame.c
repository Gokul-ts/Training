// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Gokul TS
// ------------------------------------------------------------------
// BoardGame.c
// Program to play board game between two players.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define ANSI_RESET_ALL "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void PrintBoard (char board[3][3]) {
   printf ("Tic-Tac-Toe\n+---+---+---+\n|");
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
         printf (j == 0 && i != 0 ? "| %s%c%s |" : " %s%c%s |", board[i][j] == 'X' ? ANSI_COLOR_RED :
                 board[i][j] == 'O' ? ANSI_COLOR_GREEN : "", board[i][j], ANSI_RESET_ALL);
         if ((j + 1) % 3 == 0)  printf ("\n+---+---+---+\n");
      }
}

void GetPlayerInput (char player, char* board) {
   for (;;) {
      printf ("Player %c: ", player);
      char ch = getch ();
      int input = ch - 49;
      if (input > 9 || input < 0) {
         printf ("Please select an empty square between 1 and 9\n");
         continue;
      }
      if (board[input] != 'X' && board[input] != 'O') {
         board[input] = player;
         break;
      } else printf ("Number already chosen!!\n");
   }
}

int CheckWin (char pieces[3][3], char currentPlayer) {
   for (int i = 0; i < 3; i++)
      if ((pieces[i][0] == currentPlayer) && (pieces[i][1] == currentPlayer) && (pieces[i][2] == currentPlayer) ||
          (pieces[0][i] == currentPlayer) && (pieces[1][i] == currentPlayer) && (pieces[2][i] == currentPlayer) ||
          (pieces[0][0] == currentPlayer) && (pieces[1][1] == currentPlayer) && (pieces[2][2] == currentPlayer) ||
          (pieces[0][2] == currentPlayer) && (pieces[1][1] == currentPlayer) && (pieces[2][0] == currentPlayer))
         return 1;
   return 0;
}

void main () {
   char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} }, currentPlayer = 'X';
   PrintBoard (board);
   for (int i = 0; i < 9; i++) {
      GetPlayerInput (currentPlayer, *board);
      system ("cls");
      PrintBoard (board);
      if (i > 3) {
         int result = CheckWin (board, currentPlayer);
         if (result) {
            printf ("Player %c is the Winner!!!\n", currentPlayer);
            return;
         } else if (!result && i > 7) {
            printf ("Match Draw!!!\n");
            return;
         }
      }
      currentPlayer ^= ('X' ^ 'O');
   }
}