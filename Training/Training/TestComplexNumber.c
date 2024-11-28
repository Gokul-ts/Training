// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright Gokul TS (c) Metamation India.
// ------------------------------------------------------------------
// TestComplexNumber.c
// TestProgram to check the implementation of ComplexNumber operations.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <float.h>
#include <math.h>
#include "ComplexNumber.h"


CompNum GetUserInput (char* prompt) { // gets the complex number from user
   CompNum compNum;
   char c1, c2;
   printf ("\nEnter real and imaginary parts of complex number%s:\nReal:", prompt);
   while (!scanf_s ("%f%c", &compNum.realPart, &c1, 1) || c1 != '\n' || fabs (compNum.realPart) > FLT_MAX) { // check for valid input
      printf ("Invalid input. Please enter values within the float range (3.40282e(+/-)038): ");
      while (getchar () != '\n');
   }
   printf ("Imag:");
   while (!scanf_s ("%f%c", &compNum.imagPart, &c2, 1) || c2 != '\n' || fabs (compNum.imagPart) > FLT_MAX) { // check for valid input
      printf ("Invalid input. Please enter values within the float range (3.40282e(+/-)038): ");
      while (getchar () != '\n');
   }
   return compNum;
}

void printComplex (CompNum compNum, char* prompt) { // prints complex number to the console
   if (compNum.imagPart >= 0)
      printf ("\n%s Result: %f + %fi\n", prompt, compNum.realPart, compNum.imagPart);
   else
      printf ("\n%s Result: %f - %fi\n", prompt, compNum.realPart, -compNum.imagPart);
}

void PrintResult (CompOutput out1, CompOutput out2) { // prints test case result
   printf ("\n***Testcases***\n");
   printf (out1.add.imagPart == out2.add.imagPart && out1.add.realPart == out2.add.realPart ? "Addition Passed\n" : "Addition Failed\n");
   printf (out1.sub.imagPart == out2.sub.imagPart && out1.sub.realPart == out2.sub.realPart ? "Subtraction Passed\n" : "Subtraction Failed\n");
   printf (out1.mul.imagPart == out2.mul.imagPart && out1.mul.realPart == out2.mul.realPart ? "Multiplication Passed\n" : "Multiplication Failed\n");
   printf ((out1.conj1.imagPart == out2.conj1.imagPart && out1.conj1.realPart == out2.conj1.realPart) &&
           (out1.conj2.imagPart == out2.conj2.imagPart && out1.conj2.realPart == out2.conj2.realPart) ? "Conjugate Passed\n" : "Conjugate Failed\n");
   printf (out1.mod1 == out2.mod1 && out1.mod2 == out2.mod2 ? "Modulus Passed\n" : "Modulus Failed\n");
}

void TestCases () { // Runs test cases
   CompNum num1 = { 10.17f,-19.80f }, num2 = { -18010.25f,-10219.48f };
   CompOutput output = { Op_Add (num1, num2),Op_Sub (num1, num2),Op_Mul (num1, num2) ,Op_Mod (num1) , Op_Mod (num2),Op_Conj (num1) ,Op_Conj (num2) };
   CompNum add = { -18000.080078f,-10239.280273f }, sub = { 18020.419922f,10199.680664f }, mul = { -385509.937500f,252670.812500f }, conj1 = { 10.17f,19.799999f }, conj2 = { -18010.25f,10219.480469f };
   float mod1 = 22.259130f, mod2 = 20707.654297f;
   CompOutput ExpOutput = { add,sub,mul,mod1,mod2,conj1,conj2 };
   PrintResult (output, ExpOutput);
}
void PrintAll (CompNum num1, CompNum num2) { // prints all operation results to the console
   CompNum resAdd = Op_Add (num1, num2);
   CompNum resSub = Op_Add (num1, num2);
   CompNum resMul = Op_Add (num1, num2);
   float resMod1 = Op_Mod (num1);
   float resMod2 = Op_Mod (num2);
   if (isinf (resAdd.realPart) || isinf (resAdd.imagPart) || isinf (resSub.realPart) || isinf (resSub.imagPart) || isinf (resMul.realPart) || isinf (resMul.imagPart) || isinf (resMod1) || isinf (resMod2)) {
      printf ("\nOutput exceeds float range!!!\n");
      return;
   }
   printComplex (Op_Add (num1, num2), "Add");
   printComplex (Op_Sub (num1, num2), "Sub");
   printComplex (Op_Mul (num1, num2), "Mul");
   printf ("\nMod1 Result: %f\n\nMod2 Result: %f\n", Op_Mod (num1), Op_Mod (num2));
   printComplex (Op_Conj (num1), "Conj1");
   printComplex (Op_Conj (num2), "Conj2");
}

int main () {
   while (1) {
      int option = 0; char c;
      printf ("***COMPLEX_NUMBER***\nMENU:\n1-ADD\n2-SUBTRACT\n3-MULTIPLY"
              "\n4-MODULUS\n5-CONJUGATE\n6-All\n7-TEST CASES\n8-EXIT\nEnter an option:");
      while (!scanf_s ("%d%c", &option, &c, 1) || c != '\n') { // check for valid input
         printf ("Invalid input!!!\n");
         while (getchar () != '\n');
      }
      switch (option) {
         case 1: { // Addition
            CompNum num1 = GetUserInput ("1");
            CompNum num2 = GetUserInput ("2");
            CompNum result = Op_Add (num1, num2);
            if (isinf (result.realPart) || isinf (result.imagPart)) {
               printf ("\nOutput exceeds float range!!!\n"); // check whether output exceeds float range
               break;
            }
            printComplex (result, "Add");
            break;
         }
         case 2: { // Subtraction
            CompNum num1 = GetUserInput ("1");
            CompNum num2 = GetUserInput ("2");
            CompNum result = Op_Sub (num1, num2);
            if (isinf (result.realPart) || isinf (result.imagPart)) {
               printf ("\nOutput exceeds float range!!!\n"); // check whether output exceeds float range
               break;
            }
            printComplex (result, "Sub");
            break;
         }
         case 3: // Multiplication
         {
            CompNum num1 = GetUserInput ("1");
            CompNum num2 = GetUserInput ("2");
            CompNum result = Op_Mul (num1, num2);
            if (isinf (result.realPart) || isinf (result.imagPart)) { // check whether output exceeds float range
               printf ("\nOutput exceeds float range!!!\n");
               break;
            }
            printComplex (result, "Mul");
            break;
         }
         case 4: { // Modulus
            float result = Op_Mod (GetUserInput (""));
            if (isinf (result)) { // check whether output exceeds float range
               printf ("\nOutput exceeds float range!!!\n");
               break;
            }
            printf ("\nMod Result: %f\n", result);
            break;
         }
         case 5: // Conjugate
         {
            printComplex (Op_Conj (GetUserInput ("")), "Conj");
            break;
         }
         case 6: // All operations
         {
            CompNum num1 = GetUserInput ("1");
            CompNum num2 = GetUserInput ("2");
            PrintAll (num1, num2);
            break;
         } 
         case 7: // test cases
         {
            TestCases ();
            break;
         }
         case 8: // terminate program
         {
            return 0;
            break;
         }
         default: {
            printf ("Please enter a number between 1 - 8\n");
            break;
         }
      }
      printf ("\n");
   }
   return 0;
}