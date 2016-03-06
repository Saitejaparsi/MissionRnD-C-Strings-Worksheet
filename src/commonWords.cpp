/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int spaces(char *str);
int equal(char *str1, char *str2, int a, int b);
int words(char *str1);
char ** commonWords(char *str1, char *str2) {
	char **com;
	int k,t = 0, count = 0;
	com= NULL;
	if (str1 == NULL || str2 == NULL)
		return NULL;
	int i=0, j=0,r,a=-1,b=0;
	t = spaces(str1);
	if (t == 0)
		return NULL;
	t = spaces(str2);
	if (t == 0)
		return NULL;
	count = words(str1);
	com = (char **)malloc((31)*count);
	for (k = 0; k < count; k++)
		com[k] = (char *)malloc((j - i));
	com[0][0]= '\0';
	for (i = j; str1[i];i=j+1)
	{
		for (j = i; str1[j] != '\0'&&str1[j] != ' '; j++);
		r = equal(str1, str2, i, j - 1);
		if (r == 1)
		{
			a++;
			k = i;
			for (b = 0; b <j - k; b++,i++)
				*(*(com+a)+b) = *(str1+i);
			*(*(com + a) + b) = '\0';
		}
	}
	if (com[0][0] == '\0')
		return NULL;
	return com;
}
int words(char *str1){
	int i = 0,count=0;
	for (i = 0; str1[i]; i++){
		if (str1[i] == ' ' || str1[i] == '\0')
			count++;
	}
	return count;
}
int spaces(char *str)
{
	int i = 0;
	for (i = 0; str[i]; i++){
		if (str[i] != ' ')
			return 1;
	}
	return 0;
}
int equal(char *str1, char *str2, int a, int b)
{
	int i=0, j=0, c,d,flag;
	for (i = 0; str2[i]; i++){
		flag = 0, c = a, d = b;
		if (str1[c] == str2[i]){
			for (j = c + 1, i = i + 1; j <= b; j++, i++)
			{
				if (str1[j] != str2[i]){
					flag = 1;
					break;
				}
			}
		}
		if (j == b + 1)
			return 1;
		if (flag == 1){
			for (i; str2[i] != '-'&&str2[i]; i++);
		}
	}
	return 0;
}











