#include <stdio.h>
#include "roman.c"

int romanToInt(char *roman);

/*
   Roman Numeral Conversion
   1. Check if there is stdin or an argument or neither
   2. If there is, then print value then quit
   3. Otherwise, start REPL
*/

int main() {

	char input1[10] = "IX";//9
    printf("IX: %d\n", romanToInt(input1));

	char input2[10] = "XIV";//14
    printf("XIV: %d\n", romanToInt(input2));

	char input3[10] = "CCC";//300
    printf("CCC: %d\n", romanToInt(input3));

	char input4[10] = "MDCCLXXVI";//1776
    printf("MDCCLXXVI: %d\n", romanToInt(input4));
	return 0;
}

