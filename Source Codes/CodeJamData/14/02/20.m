//
//  main.m
//  codejam-qr-b
//
//  Created by Yunzhu Li on 12/4/14.
//  Copyright (c) 2014 Yunzhu Li. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double* readNFloatsInLine(char *line, int n);

int main(int argc, const char * argv[])
{
	
	const char *inputFileName;
	char bufLine[64];
	
	if (argc > 1) {
		inputFileName = argv[1];
	} else {
		inputFileName = "input.in";
	}
	
	FILE *pFileIn = fopen(inputFileName, "r");
	if (!pFileIn) {
		printf("Cannot open input file:%s.\n", inputFileName);
		exit(0);
	}
	
	// Read a line
	fgets(bufLine, 64, pFileIn);
	
	int numberOfCases = atoi(bufLine);
	
	for (int caseNum = 1; caseNum <= numberOfCases; caseNum++) {
		double C = 0.0f, F = 0.0f, X = 0.0f;
		
		// Read & parse numbers
		fgets(bufLine, 64, pFileIn);
		double *parsedNumbers = readNFloatsInLine(bufLine, 3);
		C = parsedNumbers[0]; F = parsedNumbers[1]; X = parsedNumbers[2];
		
		int numberOfFarms = 0;
		double lastResult = 0;
		int lastResultGenerated = 0;
		
		while (1) {
			double result = 0.0f;
			
			// Calculate
			for (int farmNumber = 0; farmNumber <= numberOfFarms; farmNumber++) {
				if (farmNumber != numberOfFarms) {
					result += (C / (2 + farmNumber * F));
				} else {
					result += (X / (2 + farmNumber * F));
				}
			}
			
			if (lastResultGenerated == 0) {
				lastResultGenerated = 1;
				lastResult = result;
				numberOfFarms++;
				continue;
			}
			
			if (result <= lastResult) {
				lastResult = result;
			} else {
				// Final result
				printf("Case #%d: %.7f\n", caseNum, lastResult);
				break;
			}
			
			numberOfFarms++;
		}
	}
	
    return 0;
}

double* readNFloatsInLine(char *line, int n) {
	double *numbers = malloc(n * sizeof(double));
	
	char *subStr = NULL;
	subStr = strtok(line, " ");
	numbers[0] = atof(subStr);
	
	for (int i = 1; i < n; i++) {
		subStr = strtok(NULL, " ");
		numbers[i] = atof(subStr);
	}
	
	return numbers;
}


