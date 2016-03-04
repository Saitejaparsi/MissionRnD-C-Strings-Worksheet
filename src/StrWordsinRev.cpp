/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char *i, int s, int e);
void str_words_in_rev(char *input, int len){
	int i, j, count = 0;
	reverse(input, 0, len-1);
	input[len] = '\0';
	for (i = 0; input[i]; i = j +count)
	{
		for (j = i; input[j] != ' '&&input[j]; j++);
		reverse(input, i, j - 1);
		for (count = 1; input[count] == ' '; count++);
	}
}
void reverse(char *i, int s, int e)
{
	int k, j;
	char temp;
	for (k = s, j = e; k < j; k++, j--){
		temp=i[k];
		i[k] = i[j];
		i[j] = temp;
	}
}
//over