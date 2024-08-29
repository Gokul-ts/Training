// ------------------------------------------------------------------------------------------------
// Assignment3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// DecimalConversion.c
// C program for converting a decimal number into binary and hexadecimal number
// ------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include<malloc.h>

#define DIGIT 8
int binCount = 0, hexCount = 0;
bool isNegative = true;
int* binary = NULL;
char* hex = NULL;

/// <summary>Converts positive integer into binary</summary>
int* PosToBin (int num);
/// <summary>Converts negative integer into binary</summary>
void NegToBin (int num);
/// <summary>Converts negative and positive integer into hexadecimal</summary>
void BinToHex (int num);
/// <summary>Prints the elements of an array</summary>
void PrintResult (int* array);

void main () {
   for (;;) {
      printf ("Enter a decimal number:");
      int input = 0;
      int n = scanf ("%d", &input);
      if (n != 1) { //checking if the number is valid
         printf ("Please enter a VALID NUMBER!!!");
         return;
      }
      if (input < 0) { //checking if the number is negative
         NegToBin (input);
      } else if (input > 0) { //checking if the number is positive
         isNegative = false;
         PosToBin (input);
         free (binary);
      } else printf ("Binary value:0b0"); //checking if the input is zero
      BinToHex (input);
      binCount = 0;
      hexCount = 0;
      isNegative = true;
   }
}

int* PosToBin (int num) {
   int temp = 0;
   temp = num;
   while (temp != 0) { //condition to check the num of binary digits
      temp = temp / 2;
      binCount++;
   }
   if (binCount % DIGIT != 0) binCount = binCount + (DIGIT - (binCount % DIGIT)); //changing the digits into 8 bits
   binary = (int*)malloc (binCount * sizeof (int));
   if (binary != NULL) {
      for (int j = binCount - 1; j >= 0; j--) { //storing binary values in array
         binary[j] = num % 2;
         num = num / 2;
      }
      if (isNegative == false) PrintResult (binary);
      return binary;
   }
   return 0;
}

void NegToBin (int num) {
   int posNum = 0;
   if (num < 0) posNum = -(num);
   int* array = PosToBin (posNum);
   for (int j = 0; j < binCount; j++) {  //condition to add 1's compliment
      if (array[j] == 0) array[j] = 1;
      else array[j] = 0;
   }
   for (int j = binCount - 1; j >= 0; j--) { //condition to add 2's compliment
      if (array[j] == 1)   array[j] = 0;
      else {
         array[j] = 1;
         break;
      }
   }
   PrintResult (array);
   isNegative = true;
   free (binary);
}

void BinToHex (int num) {
   if (num == 0) {
      printf ("\nHexadecimal value:0x%d\n\n", num);
      return;
   }
   int temp = 0;
   temp = num;
   while (temp != 0) { //condition to check the num of hexadecimal digits
      temp = temp / 16;
      hexCount++;
   }
   if (hexCount % DIGIT != 0) hexCount = hexCount + (DIGIT - (hexCount % DIGIT)); //changing the digits into 8 bits
   hex = (char*)malloc (hexCount + 1 * sizeof (char));
   unsigned int unsNum = (unsigned int)num;
   char hexChars[] = "0123456789ABCDEF";
   if (hex != NULL) {
      for (int i = hexCount - 1; i >= 0; i--) { //storing hexadecimal values in array
         hex[i] = hexChars[unsNum & 0xF];
         char c = hex[i];
         unsNum >>= 4;
      }
      hex[hexCount] = '\0';
      printf ("\nHexadecimal value:0x%s\n\n", hex);
   }
   free (hex);
}

void PrintResult (int* array) {
   printf ("Binary value:0b");
   for (int i = 0; i < binCount; i++) printf ("%d", array[i]);
}


