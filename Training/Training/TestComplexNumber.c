// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Gokul TS
// ------------------------------------------------------------------
// TestComplexNumber.c
// TestProgram to check the implementation of ComplexNumber operations.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include "ComplexNumber.h"

CompNum GetUserInput (char* prompt) { // gets the complex number from user
   CompNum compNumber = { 0.0,0.0 };
   printf ("\nEnter real and imaginary parts of complex number%s:\n", prompt);
   float* fltArr[] = { &compNumber.RealPart ,&compNumber.ImagPart };
   char* partArr[] = { "Real:","Imag:" };
   for (int i = 0; i < 2; i++) {
      char c;
      printf ("%s", partArr[i]);
      while (!scanf_s ("%f%c", fltArr[i], &c, 1) || c != '\n' || fabs (*fltArr[i]) > FLT_MAX) { // check for valid input
         printf ("Invalid input. Please enter values within the float range (3.40282e(+/-)038): ");
         while (getchar () != '\n');
      }
   }
   return compNumber;
}

void printComplex (CompNum compNumber, char* funcName) { // prints Complex number to the console with specified function name
   printf ("\n%s Result: %f %c %fi\n", funcName, compNumber.RealPart, (compNumber.ImagPart >= 0) ? '+' : '-', fabs (compNumber.ImagPart));
}

bool IsEqual (CompNum num1, CompNum num2) {
   return (num1.RealPart == num2.RealPart && num1.ImagPart == num2.ImagPart) ? true : false;
}

void TestCases () { // Runs test cases
   CompNum compNums1[] = { { 10.17f,-19.80f } ,{25,10} ,{-1,894},{-111,75} },
      compNums2[] = { { -18010.25f,-10219.48f},{10,25},{-718,29},{125,45} },
      add[] = { { -18000.080078f,-10239.280273f },{35,35},{-719,923},{14,120} },
      sub[] = { { 18020.419922f,10199.680664f },{15,-15},{717,865},{-236,30} },
      mul[] = { { -385509.937500f,252670.812500f },{0,725},{-25208,-641921},{-17250,4380} },
      conj1[] = { { 10.17f,19.799999f },{25,-10},{-1,-894},{-111,-75} },
      conj2[] = { { -18010.25f,10219.480469f },{10,-25},{-718,-29},{125,-45} };
   float mod1[] = { 22.259130f,26.925823f,894.000549f, 133.962677f },
      mod2[] = { 20707.654297f,26.925823f,718.585388f,132.853302f };
   int size = sizeof (compNums1) / sizeof (compNums1[0]);
   printf ("\n\nTestcases:\n");
   for (int i = 0; i < size; i++) {
      bool conditions[] = {
        IsEqual (Op_Add (compNums1[i], compNums2[i]), add[i]),
        IsEqual (Op_Sub (compNums1[i], compNums2[i]), sub[i]),
        IsEqual (Op_Mul (compNums1[i], compNums2[i]), mul[i]),
        IsEqual (Op_Conj (compNums1[i]) , conj1[i]) && IsEqual (Op_Conj (compNums2[i]), conj2[i]),
        Op_Mod (compNums1[i]) == mod1[i] && Op_Mod (compNums2[i]) == mod2[i]
      };
      if (!conditions[0] || !conditions[1] || !conditions[2] || !conditions[3] || !conditions[4]) {
         char* funcNames[] = { "Addition","Subtraction","Multiplication","Conjugate","Modulus" };
         for (int j = 0; j < 5; j++)
            if (!conditions[j])
               printf ("Test case%d %s function failed\n", i + 1, funcNames[j]);
         return;
      }
   }
   printf ("Passed\n");
}

void PrintAll (CompNum num1, CompNum num2) { // prints all operation results to the console
   CompNum resAdd = Op_Add (num1, num2), resSub = Op_Sub (num1, num2), resMul = Op_Mul (num1, num2),
      resConj1 = Op_Conj (num1), resConj2 = Op_Conj (num2);
   float resMod1 = Op_Mod (num1), resMod2 = Op_Mod (num2);
   if (isinf (resAdd.RealPart) || isinf (resAdd.ImagPart) || isinf (resSub.RealPart) || isinf (resSub.ImagPart)
       || isinf (resMul.RealPart) || isinf (resMul.ImagPart) || isinf (resMod1) || isinf (resMod2)) {
      printf ("\nOutput exceeds float range!!!\n");
      return;
   }
   char* funcNames[] = { "Add","Sub","Mul","Conj1","Conj2" };
   CompNum funcResults[] = { resAdd,resSub,resMul,resConj1,resConj2 };
   for (int i = 0; i < 5; i++)  printComplex (funcResults[i], funcNames[i]);
   printf ("\nMod1 Result: %f\n\nMod2 Result: %f\n", resMod1, resMod2);
}

int main () {
   while (1) {
      printf ("***COMPLEX_NUMBER***\nMENU:\n1-ALL OPERATION\n2-TEST CASES\n3-EXIT\nEnter an option:");
      int opt = getch () - 48;
      switch (opt) {
         case 1: // All operations
         {
            CompNum num1 = GetUserInput ("1");
            CompNum num2 = GetUserInput ("2");
            PrintAll (num1, num2);
            break;
         }
         case 2: // test cases
            TestCases ();
            break;
         case 3: // terminate program
            return 0;
         default:
            printf ("Please enter a number between 1 - 3\n");
      }
      printf ("\n");
   }
   return 0;
}