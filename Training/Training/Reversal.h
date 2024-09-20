#pragma once
// ------------------------------------------------------------------------------------------------
// Assignment4 ~ A training program for new joiners at Metamation, Batch - Sept 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// Reversal.h
// HeaderFile for Reversal.c program
// -----------------------------------------------------------------------------------------------

#define MAX_DIGIT 13 //number input range
#define MAX_CHAR 52 //character input range
#define PALINDROME 1
#define NOT_PALINDROME 0
#define ERR_INVALID -1

#define ANSI_RESET_ALL "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[36m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

/// <summary>Function to check given number is palindrome or not</summary>
int NumIsPalindrome (int num,long long int* revNum);
/// <summary>Function to check given string is palindrome or not</summary>
int StrIsPalindrome (char* phrase, int type);