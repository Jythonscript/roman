#include <stdio.h>

//data for information about roman numerals
#define NUMLETTERS 7
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
int romanToInt(char *input) {

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

//return index of the argument int in the romanLetters array
int indexOf(int num) {

	int i;
	for (i = 0; i < NUMLETTERS; i++) {
		if (romanLetters[i] == num) {
			return i;
		}
	}
	return -1;
}
