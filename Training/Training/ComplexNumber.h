#pragma once
// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright Gokul TS (c) Metamation India.
// ------------------------------------------------------------------
// ComplexNumber.h
// header file for ComplexNumber.c
// ------------------------------------------------------------------------------------------------
typedef struct ComplexNumber {
   float realPart;
   float imagPart;
}CompNum;

typedef struct CompOutput {
   CompNum add;
   CompNum sub;
   CompNum mul;
   float mod1;
   float mod2;
   CompNum conj1;
   CompNum conj2;
}CompOutput;

/// <summary>Returns the sum of two complex numbers</summary>
CompNum Op_Add (CompNum compNum1, CompNum compNum2);
/// <summary>Returns the subtraction of two complex numbers</summary>
CompNum Op_Sub (CompNum compNum1, CompNum compNum2);
/// <summary>Returns the product of two complex numbers</summary>
CompNum Op_Mul (CompNum compNum1, CompNum compNum2);
/// <summary>Returns the modulus of a complex number</summary>
float Op_Mod (CompNum compNum);
/// <summary>Returns the conjugate of a complex number</summary>
CompNum Op_Conj (CompNum comp_Num);