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

CompNum Op_Add (CompNum CompNum1, CompNum CompNum2) {
   CompNum Result = { CompNum1.realPart + CompNum2.realPart, CompNum1.imagPart + CompNum2.imagPart };
   return Result;
}

CompNum Op_Sub (CompNum CompNum1, CompNum CompNum2) {
   CompNum Result = { CompNum1.realPart - CompNum2.realPart,CompNum1.imagPart - CompNum2.imagPart };
   return Result;
}

CompNum Op_Mul (CompNum CompNum1, CompNum CompNum2) {
   CompNum Result = { CompNum1.realPart * CompNum2.realPart - CompNum1.imagPart * CompNum2.imagPart,
      CompNum1.realPart * CompNum2.imagPart + CompNum1.imagPart * CompNum2.realPart };
   return Result;
}

float Op_Mod (CompNum CompNumber) {
   return (float)sqrt (CompNumber.realPart * CompNumber.realPart + CompNumber.imagPart * CompNumber.imagPart);
}

CompNum Op_Conj (CompNum CompNumber) {
   CompNum Result = { CompNumber.realPart,-(CompNumber.imagPart) };
   return Result;
}