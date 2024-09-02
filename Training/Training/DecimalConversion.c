// ------------------------------------------------------------------------------------------------
// Assignment3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// DecimalConversion.c
// C program for converting a decimal number into binary and hexadecimal number
// ------------------------------------------------------------------------------------------------

#define INT_SIZE1 sizeof(int) * 8 //32-bit range
#define INT_SIZE2 sizeof(int) * 4 //16-bit range
char bin[INT_SIZE1 + 1];
char hex[INT_SIZE2 + 1];

char* DecToBin (int num) {
   int index = INT_SIZE1 - 1;
   //Using bitwise operation the binary digits are stored in array
   while (index >= 0) {
      bin[index--] = (num & 1) + '0';
      num >>= 1; // Shifts bits of 'num' two positions to the right
   }
   bin[INT_SIZE1] = '\0';
   return bin;
}

char* DecToHex (int num) {
   unsigned int unsNum = (unsigned int)num;
   char hexChars[] = "0123456789ABCDEF";
   //Using bitwise operator the Hexadecimal digits are stored in array
   for (int i = INT_SIZE2 - 1; i >= 0; i--) {
      hex[i] = (unsNum != 0) ? hexChars[unsNum & 0xF] : (num < 0 ? 'F' : '0');
      unsNum >>= 4; // Shifts bits of 'unsNum' four positions to the right
   }
   hex[INT_SIZE2] = '\0';
   return hex;
}


