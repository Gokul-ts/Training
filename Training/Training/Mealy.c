#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

// Define states of the Mealy machine
typedef enum {
   S0,  // Initial state
   S1,  // After '0'
   S2,  // After '01'
   S3,  // After '011'
   A1,
   A2,
   A3
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
   char ch, * tempPath = "temp_file.txt";
   FILE* inpTestFile = fopen (inpPath, "r"), * outTestFile = fopen (outPath, "r"), * tempFile = fopen (tempPath, "w");
   if (inpTestFile == NULL || outTestFile == NULL || tempFile == NULL) {
      printf ("Error opening file");
      return;
   }
   State currentState = S0;
   int output = 0;
   while ((ch = fgetc (inpTestFile)) != EOF) {
      currentState = NextMealyState (currentState, ch - '0', &output);
      fprintf (tempFile, "%d", output);
   }
   fclose (inpTestFile);
   fclose (outTestFile);
   fclose (tempFile);
}

// Function to get the next state and output based on the current state and input
State NextMealyState (State currentState, int input, int* output) {
   switch (currentState) {
      case S0:
         if (input == 0) {
            *output = 0;
            return S1;  // Transition to S1 after '0'
         } else {
            *output = 0;
            return A1;  // Stay in S0 if input is '1'
         }
      case S1:
         if (input == 1) {
            *output = 0;
            return S2;  // Transition to S2 after '01'
         } else {
            *output = 0;
            return S1;  // Stay in S1 if input is '0'
         }
      case S2:
         if (input == 1) {
            *output = 0;  // Output '1' upon seeing '011'
            return S3;    // Move to S3 after recognizing '011'
         } else {
            *output = 0;
            return S1;  // Return to S1 if input is '0'
         }
      case S3:
         if (input == 0) {
            *output = 1;
            return A3;  // Reset to S0 after recognizing '011'
         } else {
            *output = 0;
            return A2;  // Return to S1 if input is '0'
         }
      case A1:
         if (input == 1) {
            *output = 0;
            return A2;
         } else {
            *output = 0;
            return S1;
         }
      case A2:
         if (input == 0) {
            *output = 0;
            return A3;
         } else {
            *output = 0;
            return A2;
         }
      case A3:
         if (input == 1) {
            *output = 1;
            return S2;
         } else {
            *output = 0;
            return S1;
         }
   }
   return S0;  // Default return to initial state
}