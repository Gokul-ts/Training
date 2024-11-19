// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright Gokul TS (c) Metamation India.
// ------------------------------------------------------------------
// file.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#define ANSI_RESET_ALL "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ROW 8
#define COLUMN 8

/// <summary>This function prints the input into both console and text file</summary>
void Print (const wchar_t* const fText, FILE* file);
/// <summary>Returns whether the two input files are equal or not</summary>
int Compare_Files (const char* file1, const char* file2);

int main () {
   int prevMode = _setmode (_fileno (stdout), _O_U8TEXT);
   FILE* file = fopen ("test_file.txt", "w, ccs=UTF-8");
   if (file == NULL) {
      perror (ANSI_COLOR_RED "Error opening file" ANSI_RESET_ALL);
      return 1;
   }
   const wchar_t* const blackPieces[] = { L" ♜ ", L" ♞ ", L" ♝ ", L" ♛ ", L" ♚ " },
      * const whitePieces[] = { L" ♖ ", L" ♘ ", L" ♗ ", L" ♕ ", L" ♔ " };
   Print (L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n", file);
   for (int i = 0; i < ROW; i++) {
      Print (L"┃", file);
      for (int j = 0; j < COLUMN; j++) {
         switch (i) {
            case 0:
               Print (j > 4 ? blackPieces[7 - j] : blackPieces[j], file);
               break;
            case 1:
               Print (L" ♟", file);
               break;
            case 6:
               Print (L" ♙ ", file);
               break;
            case 7:
               Print (j > 4 ? whitePieces[7 - j] : whitePieces[j], file);
               break;
            default:
               Print (L"   ", file);
         }
         Print (L"┃", file);
      }
      if (i < 7) Print (L"\n┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n", file);
   }
   Print (L"\n┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n", file);
   fclose (file);
   int comp_Result = Compare_Files ("test_file.txt", "existing_file.txt");
   wprintf (comp_Result == -1 ? ANSI_COLOR_YELLOW L"Error opening file" ANSI_RESET_ALL :
            comp_Result ? ANSI_COLOR_GREEN L"Test case passed" ANSI_RESET_ALL :
            ANSI_COLOR_RED L"Test case failed" ANSI_RESET_ALL);
   return 0;
}

int Compare_Files (const char* file1, const char* file2) {
   FILE* f1 = fopen (file1, "r"), * f2 = fopen (file2, "r");
   if (f1 == NULL || f2 == NULL) return -1;
   char ch1, ch2;
   int result = 1;
   while (((ch1 = fgetc (f1)) != EOF) && ((ch2 = fgetc (f2)) != EOF))
      if (ch1 != ch2) {
         result = 0;
         break;
      }
   if (fgetc (f1) != EOF || fgetc (f2) != EOF) result = 0;
   fclose (f1);
   fclose (f2);
   return result;
}

void Print (const wchar_t* const fText, FILE* file) {
   fwprintf (file, L"%s", fText); //prints to the file
   wprintf (L"%s", fText); //prints to the Console
}