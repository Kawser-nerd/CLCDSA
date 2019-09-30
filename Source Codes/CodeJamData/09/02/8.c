#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNextDirection(int** watershed, int H, int W, int currentheight, int row, int col, int *newrow, int *newcol);

int main() {
	
	FILE* inputfile;
	FILE* outputfile;
	
	char* input;
	
	char* readstring;
	
	int T;
	int H;
	int W;
	
	int i;
	int j;
	int k;

	int nextrow;
	int nextcol;

	int nextheight;

	int startrow;
	int startcol;

	int row;
	int col;

	int newrow;
	int newcol;
	
	int pathdirection;

	int** watershed;

	char** basins;

	int* pathrow;
	int* pathcol;
	
	int pathplace;
	
	int directionreturn;
	
	char currentpathvalue;
	
	char nextpathvalue = 'a';
	
	input = calloc(sizeof(char), 10000);
	
	inputfile = fopen("B-large.in","r");
	outputfile = fopen("output","w");	
	
	fgets(input, 10000, inputfile);
	sscanf(input, "%d\n", &T);
		
	for(i = 0; i < T; i++) {
		nextpathvalue = 'a';
		fgets(input, 10000, inputfile);
		sscanf(input, "%d %d\n", &H, &W);
		
		watershed = calloc(sizeof(int*), H);
		for(j = 0; j < H; j++) {
			watershed[j] = calloc(sizeof(int), W);
		}	

		basins = calloc(sizeof(char*), H);
		for(j = 0; j < H; j++) {
			basins[j] = calloc(sizeof(char), W);
		}	

		
		//Read in watershed.
		for(j = 0; j < H; j++) {
			fgets(input, 10000, inputfile);
			readstring = strtok(input, " ");			
			for(k = 0; k < W; k++) {
				watershed[j][k] = atoi(readstring);
				readstring = strtok(0, " ");						
			}	
		}
		
		printf("Case #%d:\n", i+1);
		fprintf(outputfile, "Case #%d:\n", i+1);
		
		pathrow=calloc(sizeof(int), H*W);
		pathcol=calloc(sizeof(int), H*W);
		for(startrow = 0; startrow < H; startrow++) {
			for(startcol = 0; startcol < W; startcol++) {

				row = startrow;
				col = startcol;

				if(basins[row][col] == 0) {

					memset(pathrow, 0, H*W*sizeof(int));
					memset(pathcol, 0, H*W*sizeof(int));
					pathplace = 0;

					do {

						directionreturn = getNextDirection(watershed, H, W, watershed[row][col], row, col, &newrow, &newcol);
						pathrow[pathplace] = row;
						pathcol[pathplace] = col;
						pathplace++;
						
						row = newrow;
						col = newcol;
	
					} while((directionreturn != -1) && (basins[row][col] == 0));
		
					if(directionreturn == -1) {
						currentpathvalue = nextpathvalue;
						nextpathvalue++;	
					}
					else {
						currentpathvalue = basins[row][col];	
					}
		
					for(j = 0; j < pathplace; j++) {
						basins[pathrow[j]][pathcol[j]] = currentpathvalue;
					}					
										
				}
			}
		}
		
		for(row = 0; row < H; row++) {
			for(col = 0; col < (W-1); col++) {

				printf("%c ", basins[row][col]);
				fprintf(outputfile, "%c ", basins[row][col]);

			}
			printf("%c\n", basins[row][col]);
			fprintf(outputfile, "%c\n", basins[row][col]);

		}

		free(pathrow);
		free(pathcol);
	
		for(j = 0; j < H; j++) {
			free(watershed[j]);
			watershed[j] = 0;
		}	
		free(watershed);
		watershed = 0;

		for(j = 0; j < H; j++) {
			free(basins[j]);
			basins[j] = 0;
		}	
		free(basins);
		basins = 0;

			
	}
	
	free(input);

	fclose(inputfile);
	fclose(outputfile);
	
	return 0;	
	
}

int getNextDirection(int** watershed, int H, int W, int currentheight, int row, int col, int *newrow, int *newcol) {
	
	int bestheight = currentheight;
	int bestdirection;
	
	bestdirection = -1;

	//North, West, East, South
	//North
	if(row > 0) {
		if(watershed[row-1][col] < bestheight) {
			bestheight = watershed[row-1][col];
			bestdirection = 2;
			*newrow = row - 1;
			*newcol = col;

		}
	}
	
	//West
	if(col > 0) {
		if(watershed[row][col-1] < bestheight) {
			bestheight = watershed[row][col-1];
			bestdirection = 1;	
			*newrow = row;
			*newcol = col - 1;
		}
	}

	//East
	if(col < (W-1)) {
		if(watershed[row][col+1] < bestheight) {
			bestheight = watershed[row][col+1];
			bestdirection = 4;	
			*newrow = row;
			*newcol = col + 1;
		}
	}

	//South
	if(row < (H-1)) {
		if(watershed[row+1][col] < bestheight) {
			bestheight = watershed[row+1][col];
			bestdirection = 3;
			*newrow = row + 1;
			*newcol = col;

		}		
	}

	
	return bestdirection;

}
