/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int tostr(int n,char *str);
void rev(char *str, int a, int c);
void number_to_str(float number, char *str, int afterdecimal)
{
	int i = 0,j,index;
	if (number < 0)
	{
		str[i] = '-';
		number = -number;
		i++;
	}
	int n = (int)number;
	float d = number - (float)n;
	index=tostr(n, str+i);
	rev(str, i, index+i);
	if (afterdecimal != 0){
		i = index + i + 1;
		str[i] = '.';
		int value=1;
		for (j = 0; j <afterdecimal; j++)
			value *= 10;
		d = d * value;
		n = (int)d;
		index=tostr(n, str + i + 1); 
		rev(str,( i + 1), (i + 1 + index));
	}

}
int tostr(int n,char *str)
{
	int r, i;
	for (i = 0; n > 0; i++, n = n / 10)
	{
		r = n % 10;
		str[i] = r + '0';
	}
	return i - 1;
}
void rev(char *str, int a, int c)
{
	char b;
	for (a, c; a < c; a++, c--)
	{
		b = str[a];
		str[a] = str[c];
		str[c] = b;
	}
}
//over