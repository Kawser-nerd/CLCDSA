#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 41

void uglyNumbers (char * inputString, __int64 base, __int64 *output, int canMinus, int * runs)
{
	int len;
	int i;
	char auxStrLeft[BUFF_SIZE];
	char auxStrRight[BUFF_SIZE];
	__int64 intLeft;
	__int64 intRight;
	__int64 num;

	len = strlen(inputString);
	if (len == 1)
	{
		return;
/*
		memset (auxStrLeft,0,BUFF_SIZE);
		memcpy (auxStrLeft,inputString,len);
		num = _atoi64 (auxStrLeft);
		num = base + num;
		if (num%2 == 0 || num %3 == 0 || num%5 == 0 || num%7 == 0)
			*output += 1;
		if (canMinus)
		{
			num = base - num;
			if (num%2 == 0 || num %3 == 0 || num%5 == 0 || num%7 == 0)
				*output += 1;
		}
		return;
*/
	}

	for (i=len-1;i>0;i--)
	{
		*runs += 2 + (canMinus *2);
		memset (auxStrLeft,0,BUFF_SIZE);
		memset (auxStrRight,0,BUFF_SIZE);
		memcpy (auxStrLeft,inputString,i);
		memcpy (auxStrRight,&inputString[i],len-i);
		intLeft = _atoi64 (auxStrLeft);
		intRight = _atoi64 (auxStrRight);
		num = intLeft + intRight;
		num = base + num;
		if (num%2 == 0 || num %3 == 0 || num%5 == 0 || num%7 == 0)
			*output += 1;
		num = intLeft - intRight;
		num = base + num;
		if (num%2 == 0 || num %3 == 0 || num%5 == 0 || num%7 == 0)
			*output += 1;
		if (canMinus)
		{
			num = intLeft + intRight;
			num = base - num;
			if (num%2 == 0 || num %3 == 0 || num%5 == 0 || num%7 == 0)
				*output += 1;
			num = intLeft - intRight;
			num = base - num;
			if (num%2 == 0 || num %3 == 0 || num%5 == 0 || num%7 == 0)
				*output += 1;
		}
		uglyNumbers(auxStrRight,base + intLeft,output,1,runs);
		if (canMinus)
			uglyNumbers(auxStrRight,base - intLeft,output,1,runs);
	}
/*
	memset (auxStrLeft,0,BUFF_SIZE);
	memcpy (auxStrLeft,inputString,1);
	num = _atoi64 (auxStrLeft);
	uglyNumbers (&inputString[1], base + num, output, 1);
	if (canMinus)
		uglyNumbers (&inputString[1], base - num, output, 1);
*/
}


void main (void)
{
	FILE * inputFile;
	FILE * outputFile;
	int paramCount;
	int i;
	char inputString[BUFF_SIZE];
	__int64 output;
	__int64 aux;
	int runs;

	inputFile = fopen ("input.txt", "rt");
	if (inputFile == NULL)
	{
		puts ("File not found");
		return;
	}
	outputFile = fopen ("output.txt", "wt");
	if (outputFile == NULL)
	{
		puts ("Error creating file");
		return;
	}
	fscanf (inputFile,"%d",&paramCount);

	for (i=0;i<paramCount;i++)
	{
		fscanf (inputFile, "%s", inputString);
		output = 0;
		aux = _atoi64 (inputString);
		if (aux%2 == 0 || aux %3 == 0 || aux%5 == 0 || aux%7 == 0)
			output = 1;
		runs = 1;
		uglyNumbers(inputString,0,&output, 0, &runs);
		printf("len = %d\tRuns = %d\n",strlen(inputString),runs);
		fprintf (outputFile, "Case #%d: %d\n",i+1, output);
	}

	fclose (inputFile);
	fclose (outputFile);
}