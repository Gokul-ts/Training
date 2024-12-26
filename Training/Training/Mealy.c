#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

/// <summary> states of the Mealy machine
/// A state transition diagram is attached for clear understanding </summary>
typedef enum {
   S0,  // Initial state
   S1,  // After '0'
   S2,  // After '01'
   S3,  // After '011'
   A1,  // After '1'
   A2,  // After '11'
   A3,  // After '110'
} State;

void Mealy (char inpPath[], char outPath[]);
State NextMealyState (State currentState, int input, int* output);

void main (int argc, char* argv[]) {
   char inpFilePath[MAX_PATH], outFilePath[MAX_PATH];
   strcpy (inpFilePath, argv[1]);
   strcpy (outFilePath, argv[2]);
   Mealy (inpFilePath, outFilePath);
}

// Function to open input file and create a new file and store the result
void Mealy (char inpPath[], char outPath[]) {
   char ch;
   FILE* inpTestFile = fopen (inpPath, "r"), * outTestFile = fopen (outPath, "w");
   if (inpTestFile == NULL || outTestFile == NULL) {
      printf ("Error opening file");
      return;
   }
   State currentState = S0;
   int output = 0;
   while ((ch = fgetc (inpTestFile)) != EOF) {
      currentState = NextMealyState (currentState, ch - '0', &output);
      fprintf (outTestFile, "%d", output);
   }
   fclose (inpTestFile);
   fclose (outTestFile);
}

// Function to get the next state and output based on the current state and input
State NextMealyState (State currentState, int input, int* output) {
   *output = 0;
   switch (currentState) {
      case S0:
         // Transition to S1 after '0'
         // Transition to A1 after '1' 
         return input == 0 ? S1 : A1;
      case S1:
         // Move to S2 after recognizing '01'
         // Stay in S1 if input is '0'
         return input == 1 ? S2 : S1;
      case S2:
         // Move to S3 after recognizing '011'
         // Return to S1 if input is '0'
         return input == 1 ? S3 : S1;
      case S3:
         // Output '1' upon seeing '0110'
         // Move to A3 after recognizing '0110'
         // Return to A2 if input is '1'
         if (input == 0) {
            *output = 1;
            return A3;
         }
         return A2;
      case A1:
         // Move to A2 after recognizing '11'
         // Move to S1 if input is '0'
         return input == 1 ? A2 : S1;
      case A2:
         // Move to A3 after recognizing '110'
         // Stay in A2 if input is '1'
         return input == 0 ? A3 : A2;
      case A3:
         // Output '1' upon seeing '1101'
         // Move to S2 after recognizing '1101'
         // Move to S1 if input is '0'
         if (input == 1) {
            *output = 1;
            return S2;
         }
         return S1;
      default:
         return S0;  // Default return to initial state
   }
}