#include <stdio.h>
#include "roman.h"

/*
   Roman Numeral Conversion
   1. Check if there is stdin or an argument or neither
   2. If there is, then print value then quit
   3. Otherwise, start REPL
*/

int main() {

	char roman[10];
	intToRoman(roman, 6);

	/*
    printf("IX: %d\n", romanToInt("IX"));

    printf("XIV: %d\n", romanToInt("XIV"));

    printf("CCC: %d\n", romanToInt("CCC"));

    printf("MDCCLXXVI: %d\n", romanToInt( "MDCCLXXVI"));
	*/
	return 0;
}

