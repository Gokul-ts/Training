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
   A3   // After '110'
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
            return A1;  // Transition to A1 after '1' 
         }
      case S1:
         if (input == 1) {
            *output = 0;
            return S2;  // Move to S2 after recognizing '01'
         } else {
            *output = 0;
            return S1;  // Stay in S1 if input is '0'
         }
      case S2:
         if (input == 1) {
            *output = 0;  
            return S3;  // Move to S3 after recognizing '011'
         } else {
            *output = 0;
            return S1;  // Return to S1 if input is '0'
         }
      case S3:
         if (input == 0) {
            *output = 1;  // Output '1' upon seeing '0110'
            return A3;  // Move to A3 after recognizing '0110'
         } else {
            *output = 0;
            return A2;  // Return to A2 if input is '1'
         }
      case A1:
         if (input == 1) {
            *output = 0;
            return A2;  // Move to A2 after recognizing '11'
         } else {
            *output = 0;
            return S1;  // Move to S1 if input is '0'
         }
      case A2:
         if (input == 0) {
            *output = 0;
            return A3;  // Move to A3 after recognizing '110'
         } else {
            *output = 0;
            return A2;  // Stay in A2 if input is '1'
         }
      case A3:
         if (input == 1) {
            *output = 1;  // Output '1' upon seeing '1101'
            return S2;  // Move to S2 after recognizing '1101'
         } else {
            *output = 0;
            return S1;  // Move to S1 if input is '0'
         }
   }
   return S0;  // Default return to initial state
}