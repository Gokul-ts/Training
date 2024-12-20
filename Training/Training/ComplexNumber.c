// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Gokul TS
// ------------------------------------------------------------------
// ComplexNumber.c
// program that contains the definition of complex number operations.
// ------------------------------------------------------------------------------------------------
#include "ComplexNumber.h"
#include <math.h>

CompNum Op_Add (CompNum compNum1, CompNum compNum2) {
   CompNum Result = { compNum1.realPart + compNum2.realPart, compNum1.imagPart + compNum2.imagPart };
   return Result;
}

CompNum Op_Sub (CompNum compNum1, CompNum compNum2) {
   CompNum Result = { compNum1.realPart - compNum2.realPart,compNum1.imagPart - compNum2.imagPart };
   return Result;
}

CompNum Op_Mul (CompNum compNum1, CompNum compNum2) {
   CompNum Result = { compNum1.realPart * compNum2.realPart - compNum1.imagPart * compNum2.imagPart,
      compNum1.realPart * compNum2.imagPart + compNum1.imagPart * compNum2.realPart };
   return Result;
}

float Op_Mod (CompNum compNum) {
   return (float)sqrt (compNum.realPart * compNum.realPart + compNum.imagPart * compNum.imagPart);
}

CompNum Op_Conj (CompNum compNum) {
   CompNum Result = { compNum.realPart,-(compNum.imagPart) };
   return Result;
}