// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Gokul TS
// ------------------------------------------------------------------
// harness.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS  1
#define NTESTS 5 
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <io.h>

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

/// <summary> Prints the result whether two files are equal or errors if any </summary>
void CheckResult (char* expOutPath, char* tempOutPath, char* inpFileName) {
   FILE* f1 = fopen (tempOutPath, "r"), * f2 = fopen (expOutPath, "r");
   if (f1 == NULL || f2 == NULL)
      printf ("Error opening file!!!\n");
   else {
      int refFileSize = filelength (fileno (f1)) + 1,
         outFileSize = filelength (fileno (f2)) + 1;
      if (refFileSize == 1 || outFileSize == 1)
         printf ("File is empty!!!\n");
      else if (refFileSize != outFileSize)
         printf ("File lengths are different!!!\n");
      else {
         char* refFileString = (char*)malloc (refFileSize * sizeof (char)),
            * outFileString = (char*)malloc (outFileSize * sizeof (char));
         if (refFileString == NULL || outFileString == NULL)
            printf ("Error allocating memory!!!\n");
         else {
            fgets (refFileString, refFileSize, f1);
            fgets (outFileString, outFileSize, f2);
            int i, errBitNo = 0;
            for (i = 0; i < refFileSize - 1; i++) {
               errBitNo++;
               if (refFileString[i] != outFileString[i]) {
                  int errBitValue = refFileString[i] - '0';
                  printf ("Failure at bit no. %d in %s\nExpected: %d Actual: %d\n", errBitNo, inpFileName, !errBitValue, errBitValue);
                  break;
               }
            }
            if (refFileString[i] == outFileString[i]) printf ("No error testing %s\n", inpFileName);
            free (refFileString);
            free (outFileString);
         }
      }
      fclose (f1);
      fclose (f2);
   }
}

/// <summary>
/// Test Harness
/// </summary>
/// <param name="argc"></param>
/// <param name="argv">argv[1] is the name of the FSM</param>
/// <returns></returns>
int main (int argc, char** argv) {
   if (argc != 2) {
      printf ("Usage: %s <FSM executable name>\n,", argv[0]);
      return -1;
   }
   for (int i = 0; i < NTESTS; i++) {
      char inpPath[MAX_PATH], outPath[MAX_PATH], * tempOutPath = "C:\\etc\\temp.txt";
      sprintf (inpPath, "TData\\Input%d.txt", i + 1);
      sprintf (outPath, "TData\\ExpOutput%d.txt", i + 1);
      if (ExecProgram (argv[1], inpPath, tempOutPath) != 0)  // changes the name of the input and output files in each set.
         printf ("Error executing test %d\n", i + 1);
      else {
         char* inpFileName = strtok (inpPath, "\\");
         inpFileName = strtok (NULL, "\\");
         CheckResult (outPath, tempOutPath, inpFileName);
      }
   }
   return 0;
}