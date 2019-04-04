#include <stdio.h>
#include "roman.h"

//data for information about roman numerals
#define NUMROMAN 7
char *romanLetters = "IVXLCDM";
int romanNumbers[7] = {1,5,10,50,100,500,1000};

/*
	convert arg1 (string) from roman numerals to an int

	for each character
		find index for current number
			check next number
			if its not '\0' and greater
				subtract current number
			else
				add current number

    Test cases:
    printf("%d\n", romanToInt("IX")); = 9
    printf("%d\n", romanToInt("XIV")); = 14
    printf("%d\n", romanToInt("CCC")); = 300
    printf("%d\n", romanToInt("MDCCLXXVI")); = 1776
    printf("%d\n", romanToInt("")); = 
*/
int romanToInt(const char *input) {

	int result = 0; //final number to return
	int indexOf(int num);

	char c;
	int i = 0;
	//get each character from the string
	while ((c = input[i]) != '\0') {

		int currentIndex = indexOf(c); //index of current value
		int nextChar = input[i+1]; //value of next char

		//if next value is a number and it is greater
		if (nextChar != '\0' && romanNumbers[indexOf(nextChar)] > romanNumbers[currentIndex]) {

			int nextIndex = indexOf(nextChar);
			//subtract the current number from the total
			result -= romanNumbers[currentIndex];
		}
		else {

			//add the current number to the total
			result += romanNumbers[currentIndex];
		}
		i++;
	}//end while
	return result;
}

/* Convert num to roman numerals, and store the result in out pointer

	Until num is zero
		find largest romanNumbers that you can subtract and keep num >= 0
		subtract value
		append char to a buffer
	check for 4 of the same character in a row, other than largest roman numeral
		find correct sequence by finding 2 character subtraction that is equivalent to the sequence
		either way, append sequence to out pointer

	Test cases:
	intToRoman(ptr, 3); = "III"
	intToRoman(ptr, 14); = "XIV"
	intToRoman(ptr, 100); = "C"
	intToRoman(ptr, 95); = "VC"
	intToRoman(ptr, 1776); = "MDCCLXXVI"
	intToRoman(ptr, 4900); = "MMMMCM"
   	
 */
void intToRoman(char *out, int num) {

	char buf[100]; //TODO make buffer safe with argument
	int bufIndex = 0; //index of next available space in buffer
	while (num > 0) { // runs until entire string is found

		int i;
		for (i = NUMROMAN - 1; i >= 0; i--) {

			if (num - romanNumbers[i] >= 0) {
				//found next letter
				buf[bufIndex] = romanLetters[i];
				bufIndex++;
				num -= romanNumbers[i];
				break; //exit for loop
			}
		} // end for
	} // end while
	buf[bufIndex] = '\0';
	puts(buf);
	//TODO copy buf to out
}

//return index of the argument int in the romanLetters array
//return -1 if not found
int indexOf(int num) {

	int i;
	for (i = 0; i < NUMROMAN; i++) {
		if (romanLetters[i] == num) {
			return i;
		}
	}
	return -1;
}
