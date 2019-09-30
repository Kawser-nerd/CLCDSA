//
//  main.c
//  codejam-qr-d
//
//  Created by Yunzhu Li on 12/4/14.
//  Copyright (c) 2014 Yunzhu Li. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAXLEN 65536

int *readNIntegersInLine(char *line, int n);
double *readNFloatsInLine(char *line, int n);

void quickSort(double array[], int begin, int end);

int main(int argc, const char * argv[])
{

	const char *inputFileName;
	char bufLine[LINE_MAXLEN];
	
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
	
	// Read number of cases
	fgets(bufLine, LINE_MAXLEN, pFileIn);
	int numberOfCases = atoi(bufLine);
	
	for (int caseNum = 1; caseNum <= numberOfCases; caseNum++) {
		// Read blocks
		fgets(bufLine, LINE_MAXLEN, pFileIn);
		int numberOfBlocks = atoi(bufLine);
		fgets(bufLine, LINE_MAXLEN, pFileIn);
		double *naomiBlocks = readNFloatsInLine(bufLine, numberOfBlocks);
		fgets(bufLine, LINE_MAXLEN, pFileIn);
		double *kenBlocks = readNFloatsInLine(bufLine, numberOfBlocks);
		
		// Sort
		quickSort(naomiBlocks, 0, numberOfBlocks - 1);
		quickSort(kenBlocks, 0, numberOfBlocks - 1);
		
		// War
		int ken_current_index = 0;
		int naomi_score_war = 0;
		for (int naomi_index = 0; naomi_index < numberOfBlocks; naomi_index++) {
			double naomi_current_weight = naomiBlocks[naomi_index];
			char ken_scored = 0;
			for (int ken_index = ken_current_index; ken_index < numberOfBlocks; ken_index++) {
				double ken_current_weight = kenBlocks[ken_index];
				if (ken_current_weight > naomi_current_weight) {
					ken_scored = 1;
					ken_current_index = ken_index + 1;
					break;
				}
			}
			if (!ken_scored) {
				naomi_score_war += numberOfBlocks - naomi_index;
				break;
			}
		}
		
		// Deceitful war
		int naomi_score_dwar = 0;
		int naomi_block_offset = 0;
		for (int naomi_index = 0; naomi_index < numberOfBlocks; naomi_index++) {
			
			char all_heavier = 1;
			for (int iBlock = 0; iBlock < numberOfBlocks; iBlock++) {
				if (kenBlocks[iBlock] == -1) continue;
				if (naomiBlocks[iBlock + naomi_block_offset] < kenBlocks[iBlock]) {
					all_heavier = 0;
					break;
				}
			}
			
			if (all_heavier) {
				naomi_score_dwar += numberOfBlocks - naomi_block_offset;
				break;
			}
			
			// Burn Naomi's first block with Ken's last block
			kenBlocks[numberOfBlocks - naomi_block_offset - 1] = -1;
			naomi_block_offset++;
		}
		
		printf("Case #%d: %d %d\n", caseNum, naomi_score_dwar, naomi_score_war);
	}
	
    return 0;
}

int *readNIntegersInLine(char *line, int n) {
	int *numbers = malloc(n * sizeof(int));
	
	char *subStr = NULL;
	subStr = strtok(line, " ");
	numbers[0] = atoi(subStr);
	
	for (int i = 1; i < n; i++) {
		subStr = strtok(NULL, " ");
		numbers[i] = atoi(subStr);
	}
	
	return numbers;
}

double *readNFloatsInLine(char *line, int n) {
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

void quickSort(double array[], int begin, int end)
{
	if(begin > end)
		return;
	
	int i = begin, j = end;
	double pivot = array[begin];
	
    while(i < j) {
		while((i < j) && (pivot <= array[j]))
            j--;
		
		if(i < j)
            array[i++]=array[j];
		
		while((i < j) && (array[i] <= pivot))
			i++;
		
		if(i<j)
			array[j--] = array[i];
	}
	array[j] = pivot;
    quickSort(array, begin, i - 1);
    quickSort(array, i + 1, end);
}


