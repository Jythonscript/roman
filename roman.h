//ROMAN_H include guard
#ifndef ROMAN_H
#define ROMAN_H

//convert arg1 (string) from roman numerals to an int
int romanToInt(const char *input);
//return index of the argument int in the romanLetters array
int indexOf(int num);
//convert arg2 int to roman numerals, and store it in out pointer
void intToRoman(char *out, int num);

#endif //ROMAN_H include guard
