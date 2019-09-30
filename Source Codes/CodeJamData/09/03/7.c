#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	FILE* inputfile;
	FILE* outputfile;
	
	char* input;

	char* matchstring="welcome to code jam\n";

	int matchstringlength;
	int inputstringlength;

	int N;
	
	int i;
	int j;
	int k;
	
	int** dynamic;
	
	char inputstring[1000];
	
	matchstringlength = strlen(matchstring);
	
	input = calloc(sizeof(char), 10000);

	inputfile = fopen("C-large.in","r");
	outputfile = fopen("output","w");	

	fgets(input, 10000, inputfile);
	sscanf(input, "%d\n", &N);
	
	for(i = 0; i < N; i++) {

		fgets(inputstring, 1000, inputfile);
		
		inputstringlength = strlen(inputstring);
		
		dynamic = calloc(sizeof(char), (matchstringlength+1)*(inputstringlength+1));

		dynamic = calloc(sizeof(int*), matchstringlength+1);

		for(j = 0; j < matchstringlength + 1; j++) {
			dynamic[j] = calloc(sizeof(int), inputstringlength+1);	
		}

		for(j = 0; j < inputstringlength + 1; j++) {
			dynamic[0][j] = 1;
		}

		
		for(j = 0; j < matchstringlength; j++) {
			for(k = 0; k < inputstringlength; k++) {
				if(matchstring[j] == inputstring[k]) {
					dynamic[j+1][k+1] = (dynamic[j][k+1] + dynamic[j+1][k]) % 10000;	
				}
				else {
					dynamic[j+1][k+1] = dynamic[j+1][k] % 10000;
				}	
			}
		}
		
		printf("Case #%d: %04d\n", i+1, dynamic[matchstringlength][inputstringlength]);
		fprintf(outputfile, "Case #%d: %04d\n", i+1, dynamic[matchstringlength][inputstringlength]);
		
		free(dynamic);
		
	}
	
	return 0;
	
}