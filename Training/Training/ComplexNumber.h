#pragma once
// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Gokul TS
// ------------------------------------------------------------------
// ComplexNumber.h
// header file for ComplexNumber.c
// ------------------------------------------------------------------------------------------------
typedef struct ComplexNumber {
   float RealPart;
   float ImagPart;
}CompNum;

/// <summary>Returns the sum of two complex numbers</summary>
CompNum Op_Add (CompNum compNum1, CompNum compNum2);
/// <summary>Returns the subtraction of two complex numbers</summary>
CompNum Op_Sub (CompNum compNum1, CompNum compNum2);
/// <summary>Returns the product of two complex numbers</summary>
CompNum Op_Mul (CompNum compNum1, CompNum compNum2);
/// <summary>Returns the modulus of a complex number</summary>
float Op_Mod (CompNum compNumber);
/// <summary>Returns the conjugate of a complex number</summary>
CompNum Op_Conj (CompNum compNumber);