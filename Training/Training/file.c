// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Gokul TS Copyright (c) Metamation India.
// ------------------------------------------------------------------
// file.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS  1
#include <windows.h>
#include <stdio.h>
#include <malloc.h>

/// <summary>
/// This function will execute the FSM providing the input and output file names as arguments
/// </summary>
/// <param name="exeFilePathAndName"></param>
/// <param name="inputFilePathAndName"></param>
/// <param name="outputFilePathAndName"></param>
/// <returns></returns>
int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName) {
   char* cmdline = malloc (strlen (exeFilePathAndName) + strlen (inputFilePathAndName) + strlen (outputFilePathAndName) + 3);
   if (cmdline == NULL) {
      printf ("Unable to allocate memory\n");
      return 1;
   }
   sprintf (cmdline, "%s%s%s%s%s", exeFilePathAndName, " ", inputFilePathAndName, " ", outputFilePathAndName);

   // Set up structures for process information
   STARTUPINFOA si;
   PROCESS_INFORMATION pi;

   // Initialize memory for STARTUPINFO and PROCESS_INFORMATION structures
   ZeroMemory (&si, sizeof (si));
   si.cb = sizeof (si);
   ZeroMemory (&pi, sizeof (pi));

   // Attempt to create the process
   if (!CreateProcessA (
      NULL,            // Application name (NULL if using command line)
      cmdline,          // Command line (path to the executable)
      NULL,            // Process handle not inheritable
      NULL,            // Thread handle not inheritable
      FALSE,           // Set handle inheritance to FALSE
      0,               // No creation flags
      NULL,            // Use parent's environment block
      NULL,            // Use parent's starting directory
      &si,             // Pointer to STARTUPINFO structure
      &pi))            // Pointer to PROCESS_INFORMATION structure
   {
      // If CreateProcess fails, print an error message
      int err = GetLastError ();
      printf ("Failed to start process. Error: %lu\n", GetLastError ());
      free (cmdline);
      return 1;
   }

   // Wait until the process has finished execution
   WaitForSingleObject (pi.hProcess, INFINITE);

   // Close handles
   CloseHandle (pi.hProcess);
   CloseHandle (pi.hThread);

   free (cmdline);
   return 0;

}

/// <summary>
/// This function compares two files and returns the result
/// </summary>
/// <param name="file"></param>
/// <param name="errBit"></param>
/// <param name="errBitValue"></param>
/// <returns></returns>
int Compare_Files (char* file, int* errBit, int* errBitValue) {
   FILE* f1 = fopen ("temp_file.txt", "r"), * f2 = fopen (file, "r");
   if (f1 == NULL || f2 == NULL) return -1;
   char ch1, ch2;
   int result = 1; // 1 means files are identical
   while (((ch1 = fgetc (f1)) != EOF) && ((ch2 = fgetc (f2)) != EOF)) {
      (*errBit)++;
      if (ch1 != ch2) {
         result = 0; // Files are different
         *errBitValue = ch1 - '0';
         break;
      }
   }
   if (fgetc (f1) != EOF || fgetc (f2) != EOF) result = 0; // Files are different
   fclose (f1);
   fclose (f2);
   return result;
}

/// <summary>
/// Test Harness
/// </summary>
/// <param name="argc"></param>
/// <param name="argv">argv[1] is the name of the FSM</param>
/// <returns></returns>
int main (int argc, char** argv) {
#define NTESTS 5                    // change this according to the number of tests you design. The more unique and relevant test patterns, the more complete your testing.
   printf ("FSM Test Harness\n");
   if (argc != 2) {
      printf ("Usage: %s <FSM executable name>\n,", argv[0]);
      return -1;
   }
   for (int i = 0; i < NTESTS; i++) {
      char inpPath[MAX_PATH], outPath[MAX_PATH];
      sprintf (inpPath, "TestCases\\Input%d.txt", i + 1);
      sprintf (outPath, "TestCases\\ExpOutput%d.txt", i + 1);
      if (ExecProgram (argv[1], inpPath, outPath) != 0)  // change the name of the input and output files in each set.
         printf ("Error executing test %d\n", i + 1);
      else {
         int errBit = 0, errBitValue = 0, result = Compare_Files (outPath, &errBit, &errBitValue), crtBitValue = errBitValue ? 0 : 1;
         if (result) { 
            sprintf (inpPath, "Input%d.txt", i + 1);
            printf ("No error testing %s\n", inpPath); }
         else if (!result) printf ("Error at bit no. %d in %s\nExpected: %d Actual: %d\n", errBit, inpPath, crtBitValue, errBitValue);
         else printf ("Error opening file %d\n", i + 1);
      }
   }
   return 0;
}