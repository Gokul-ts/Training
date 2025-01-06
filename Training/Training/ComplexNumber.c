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
   CompNum result = { compNum1.RealPart + compNum2.RealPart, compNum1.ImagPart + compNum2.ImagPart };
   return result;
}

CompNum Op_Sub (CompNum compNum1, CompNum compNum2) {
   CompNum result = { compNum1.RealPart - compNum2.RealPart, compNum1.ImagPart - compNum2.ImagPart };
   return result;
}

CompNum Op_Mul (CompNum compNum1, CompNum compNum2) {
   CompNum result = { compNum1.RealPart * compNum2.RealPart - compNum1.ImagPart * compNum2.ImagPart,
      compNum1.RealPart * compNum2.ImagPart + compNum1.ImagPart * compNum2.RealPart };
   return result;
}

float Op_Mod (CompNum compNumber) {
   return (float)sqrt (compNumber.RealPart * compNumber.RealPart + compNumber.ImagPart * compNumber.ImagPart);
}

CompNum Op_Conj (CompNum compNumber) {
   CompNum result = { compNumber.RealPart,-(compNumber.ImagPart) };
   return result;
}