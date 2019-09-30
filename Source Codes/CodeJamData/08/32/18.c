/*
 * Programmer : Kookiat Suetrong (kookiatsuetrong@gmail.com)
 * Compiler   : Visual C++ / ISO C++ / ANSI C
 * Date       : 2008/07/26
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_S			(256)

typedef long long LL;

FILE *fin, *fout;

LL count;
LL ugly;

LL eval(char *s)
{
	int n = (int)strlen(s);
	int i;
	LL sum = 0;

	i = 0;
	while (i < n)
	{
		if (isdigit(s[i]))
		{
			sum *= 10;
			sum += s[i] - '0';
		}
		else if ('+' == s[i])
		{
			return sum + eval(&(s[i+1]));
		}
		else if ('-' == s[i])
		{
			return sum - eval(&(s[i+1]));
		}

		i++;
	}

	return sum;
}

int isUgly(LL n)
{
	if (0 == n % 2) return 1;
	if (0 == n % 3) return 1;
	if (0 == n % 5) return 1;
	if (0 == n % 7) return 1;
	return 0;
}

void gen(char *s, int level)
{
	int i, j;
	char t[MAX_S];
	int n = (int)strlen(s);

	for (i = level + 1; i < n; i++)
	{
		// plus
		for (j = 0; j < i; j++)
		{
			t[j] = s[j];
		}
		t[j] = '+';
		for (j = i; j < n; j++)
		{
			t[j+1] = s[j];
		}
		t[n+1] = '\0';
		//fprintf(fout, "%s = %d\n", t, eval(t));
		if (isUgly(eval(t)))
			ugly++;
		
		if (i + 1 < n)
			gen(t, i + 1);

		// minus
		for (j = 0; j < i; j++)
		{
			t[j] = s[j];
		}
		t[j] = '-';
		for (j = i; j < n; j++)
		{
			t[j+1] = s[j];
		}
		t[n+1] = '\0';
		//fprintf(fout, "%s = %d\n", t, eval(t));
		if (isUgly(eval(t)))
			ugly++;

		if (i + 1 < n)
			gen(t, i + 1);
	}
}


//int main(int argc, char ** argv)
int main(void)
{
	int c;
	int i;
	char str[MAX_S];

	fin = stdin;
	//fin = fopen("release\\test000.txt", "r");
	fout = stdout;
	//fout = fopen("release\\out000.txt", "w");

	// pre-processing for every case

	fscanf(fin, "%d\n", &c);
	for (i = 0; i < c; i++)
	{
		// read data for this case
		fscanf(fin, "%s", str);
		
		// output the result of this case
		fprintf(fout, "Case #%d: ", i + 1);

		// fprintf(fout, "\n");
		ugly = 0;
		if (isUgly(eval(str)))
			ugly++;
		gen(str, 0);

		// solve this test case
		fprintf(fout, "%d\n", ugly);

	}

	fclose(fin);
	fclose(fout);
	return 0;
}
