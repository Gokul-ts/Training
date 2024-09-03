// ------------------------------------------------------------------------------------------------
// Assignment3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// DecimalConversion.c
// C program for converting a decimal number into binary and hexadecimal number
// ------------------------------------------------------------------------------------------------

#define INT_SIZE1 sizeof(int) * 8 //32-bit range
char bin[INT_SIZE1 + 1];
char hex[INT_SIZE1 / 4 + 1];

char* DecToBin (int num) {
   int index = INT_SIZE1 - 1;
   //Using bitwise operator the binary digits are stored in array
   while (index >= 0) {
      bin[index--] = (num & 1) + '0';
      num >>= 1; // Shifts bits of 'num' two positions to the right
   }
   bin[INT_SIZE1] = '\0';
   return bin;
}

char* DecToHex (int num) {
   char hexChars[] = "0123456789ABCDEF";
   //Using bitwise operator the Hexadecimal digits are stored in array
   for (int i = INT_SIZE1 / 4 - 1; i >= 0; i--) {
      hex[i] = hexChars[num & 0xF];
      num >>= 4; // Shifts bits of 'num' four positions to the right
   }
   hex[INT_SIZE1 / 4] = '\0';
   return hex;
}