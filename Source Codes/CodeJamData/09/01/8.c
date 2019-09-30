#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	FILE* inputfile;
	FILE* outputfile;

	int i;
	int j;
	int k;
	int l;
	
	int x;
	
	int currentchar;
	
	int L;
	int D;
	int N;
	
	char* input;
	
	char** words;

	char** currentword;
	
	int error = 0;
	
	int match;
	
	long long numberofmatches = 0;

	int charlocation = 0;
	
	input = calloc(sizeof(char), 1000);
	
	inputfile = fopen("A-large.in","r");	
	
	outputfile = fopen("output","w");	

	fgets(input, 1000, inputfile);
	sscanf(input, "%d %d %d\n", &L, &D, &N);
	
	printf("%d %d %d\n", L, D, N);
	
	words = calloc(sizeof(char*), D);
	for(i = 0; i < D; i++) {
		words[i] = calloc(sizeof(char), L);
		fgets(input, 100, inputfile);
		sscanf(input, "%s\n", words[i]);		
	}
	
	for(i = 0; i < D; i++) {
		printf("%s\n", words[i]);
	}
	
	currentword = calloc(sizeof(char*), 2*L);
	for(i = 0; i < 2*L; i++) {
		currentword[i] = calloc(sizeof(char), 26);
	}
	
	for(i = 0; i < N; i++) {

		for(j = 0; j < 2*L; j++) {
			memset(currentword[j], 0, 26);
		}

		memset(input, 0, 1000);
		fgets(input, 1000, inputfile);
		charlocation = 0;

		for(j = 0; j < 2*L; j++) {

			currentchar = input[charlocation++];
//			currentchar = fgetc(inputfile);
			
			if(currentchar == '\n') {
				break;	
			}
			else {
				if(currentchar == '(') {

					k = 0;
					do {
						currentchar = input[charlocation++];
//						currentchar = fgetc(inputfile);
						if(currentchar == ')') {
							if(k > 0) {
								break;	
							}
							j = -1; //Invalid word.
							error = 1;
							break;
						}
						else {
							if(currentchar == '\n') {
								j = -1; //Invalid word.
								error = 1;
								break;	
							}
							else {
								for(l = 0; l < k; l++) {
									if(currentword[j][l] == currentchar) {
										break;
									}	
								}
								if(l == k) {
									currentword[j][k] = currentchar;
									k++;
								}
							}
						}
					} while(1);
					
					if(error == 1) {
						error = 0;
						break;	
					}
									
				}
				else {
					currentword[j][0] = currentchar;					
				}
			}
			
		}
printf("Interperted:\n");
for(j = 0; j < L; j++) {
	k = 0;
	while((currentword[j][k] != 0) && (k < 26)) {
		printf("%c", currentword[j][k]);
		k++;
	}
	printf(" ");
}		
printf("\n");		
		if(j != L) {
			//Word is wrong length, skip.
			printf("Case #%d: %d\n", i + 1, 0);
			fprintf(outputfile, "Case #%d: %d\n", i + 1, 0);
			continue;
		}
		
		numberofmatches = 0;
		for(x = 0; x < D; x++) {	
			//Now, check the dictionary for possible matches.
			for(j = 0; j < L; j++) {
				match = 0;
				for(k = 0; (currentword[j][k] != 0) && (k < 26); k++) {
					if(currentword[j][k] == words[x][j]) {
						match = 1;
					}
				}
				if(match != 1) {
					break;	
				}
			}
			if(j == L) {
				numberofmatches = numberofmatches++;
			}
		}
		printf("Case #%d: %lld\n", i + 1, numberofmatches);
		fprintf(outputfile, "Case #%d: %lld\n", i + 1, numberofmatches);
	}	
	
	free(input);
		
	for(i = 0; i < D; i++) {
		free(words[i]);
	}
	free(words);

	for(i = 0; i < L; i++) {
		free(currentword[i]);
	}	
	free(currentword);

	fclose(inputfile);
	
	return 0;	
	
}