//
//  main.c
//  codejam-qr-a
//
//  Created by Yunzhu Li on 12/4/14.
//  Copyright (c) 2014 Yunzhu Li. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* readFourNumbersInLine(char *line);

int main(int argc, const char * argv[])
{
	
	const char *inputFileName;
	char bufLine[16];
	
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
	fgets(bufLine, 16, pFileIn);
	
	int numberOfCases = atoi(bufLine);
	
	for (int caseNum = 1; caseNum <= numberOfCases; caseNum++) {
		// Solve & output a case
		// Four numbers in selected row
		int *selRowFirst;
		int *selRowSecond;
		char bufLineSelected[16] = {0};
		
		// Read answer of first question
		fgets(bufLine, 16, pFileIn);
		int aFirstQuestion = atoi(bufLine);
		
		// Read answered row
		for (int lineNum = 1; lineNum <= 4; lineNum++) {
			fgets(bufLine, 16, pFileIn);
			if (lineNum == aFirstQuestion)
				strcpy(bufLineSelected, bufLine);
		}
		
		// Split info numbers
		selRowFirst = readFourNumbersInLine(bufLineSelected);
		
		// Read answer of second question
		fgets(bufLine, 16, pFileIn);
		int aSecondQuestion = atoi(bufLine);
		
		// Read answered row
		for (int lineNum = 1; lineNum <= 4; lineNum++) {
			fgets(bufLine, 16, pFileIn);
			if (lineNum == aSecondQuestion)
				strcpy(bufLineSelected, bufLine);
		}

		// Split info numbers
		selRowSecond = readFourNumbersInLine(bufLineSelected);
		
		int selectedCard = 0;
		int badMagician = 0;
		for (int i = 0; i < 4; i++) {
			int tmp = selRowFirst[i];
			for (int j = 0; j < 4; j++) {
				if (selRowSecond[j] == tmp) {
					if (selectedCard) {
						badMagician = 1;
					} else {
						selectedCard = tmp;
					}
				}
			}
		}
		
		if (selectedCard && !badMagician) {
			printf("Case #%d: %d\n", caseNum, selectedCard);
		} else if (badMagician) {
			printf("Case #%d: Bad magician!\n", caseNum);
		} else if (!selectedCard) {
			printf("Case #%d: Volunteer cheated!\n", caseNum);
		}
		
	}
	
    return 0;
}

int* readFourNumbersInLine(char *line) {
	int *numbers = malloc(4 * sizeof(int));
	
	char *subStr = NULL;
	subStr = strtok(line, " ");
	numbers[0] = atoi(subStr);
	
	for (int i = 1; i < 4; i++) {
		subStr = strtok(NULL, " ");
		numbers[i] = atoi(subStr);
	}

	return numbers;
}



