/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include <stdlib.h>

char removeSpaces(char *str) {
	int i,j;
	if (str[0] == '\0' || str ==NULL)
		return '\0';
	else
	{
		for (i = 0; str[i] != '\0'; i++){
			if (str[i] == ' ')
			{
				int count = 0;
				for (j = i; str[j]; j++){
					if (str[j] != ' ')
						break;
					count++;
				}
				for (j = i; str[j + count]; j++)
					str[j] = str[j + count];
				str[j] = '\0';
			}
		}
	}
}
//empty string case