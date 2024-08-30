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
int* binary = NULL;
char* hex = NULL;

/// <summary>Converts integers into binary</summary>
void Binary (int number);
/// <summary>Converts integers into hexadecimal</summary>
void DecToHex (int num);

int main () {
   int dec;
   char term;
   while (true) {
      printf ("Enter a decimal number:");
      if (scanf_s ("%d%c", &dec, &term, 1) != 2 || term != '\n') { //condition to check whether input is valid
         printf ("Please enter a VALID NUMBER!!!\n\n");
         for (;;) {
            term = fgetc (stdin);
            if (term == EOF || term == '\n')
               break;
         }
      } else {
         Binary (dec);
         DecToHex (dec);
         binCount = 0;
         hexCount = 0;
      }
   }
   return 0;
}

void Binary (int number) {
   if (number == 0) {
      printf ("Hexadecimal value: 0b%d", number);
      return;
   }
   int temp = 0;
   temp = number;
   while (temp != 0) { //condition to check the num of binary digits
      temp = temp / 2;
      binCount++;
   }
   if (binCount % DIGIT != 0) binCount = binCount + (DIGIT - (binCount % DIGIT)); //changing the digits into 8 bits
   binary = (int*)malloc (binCount * sizeof (int));
   int index = binCount - 1;
   while (index >= 0) {
      if (binary != NULL) {
         binary[index] = number & 1; //storing binary values in array
         index--;
         number >>= 1;
      }
   }
   printf ("Binary Value: 0b");
   for (int i = 0; i < binCount; i++)
      if (binary != NULL) {
         printf ("%d", binary[i]);
      }
   printf ("\n");
   free (binary);
}

void DecToHex (int num) {
   if (num == 0) {
      printf ("\nHexadecimal value: 0x%d\n\n", num);
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
      printf ("Hexadecimal value: 0x%s\n\n", hex);
   }
   free (hex);
}


