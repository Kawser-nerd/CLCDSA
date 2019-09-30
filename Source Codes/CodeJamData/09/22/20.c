#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	FILE* inputfile;
	FILE* outputfile;
	
	char* input;
	
	char* readstring;
	
	int i;
	int j;
	int k;
	int l;
	
	int tempvalue;
	
	int numberofdigits;
	
	int changenumber;
	int changeplace;
		
	int T;
	
	int unhappy;
	
	int bases[10];
	
//	int visitednumbers[4000000];
	
	int visitednumbers[100000];
		
	long working;
	
	int currentbase;
	int divisor;
	
	int arraynumber[70];
	int temparraynumber[70];
	
	char character;
		
	input = calloc(sizeof(char), 100000);
	
	inputfile = fopen("B-large.in","r");
	outputfile = fopen("output","w");
	
	fgets(input, 10000, inputfile);
	sscanf(input, "%d\n", &T);

	for(i = 0; i < T; i++) {
	
		memset(arraynumber, 0, 70*sizeof(int));
		memset(temparraynumber, 0, 70*sizeof(int));
	
		fgets(input, 10000, inputfile);
		
		j = 0;
		character = *input;
		numberofdigits = 0;
		while((character >= '0') && (character <= '9')) {
			temparraynumber[j] = character - '0';
			j++;
			character = *(input+j);
			numberofdigits++;
		}

		for(j = 0; j < numberofdigits; j++) {
			arraynumber[j] = temparraynumber[numberofdigits-1-j];	
		}
		

		for(j = 1; j < numberofdigits; j++) {
			if(arraynumber[j] < arraynumber[j-1]) {
				//Found change point.
				changenumber = 100;
				changeplace = -1;
				for(k = 0; k < j; k++) {
					if((arraynumber[k] <= changenumber) && (arraynumber[k] > arraynumber[j])) {
						changenumber = arraynumber[k];
						changeplace = k;
					}
				}
				arraynumber[changeplace] = arraynumber[j];
				arraynumber[j] = changenumber;
				break;
			}
		}
		//Sort arraynumber[0] - arraynumber[j-1].

		//Insertion sort code.
		for(k = 1; k < j; k++) {

			tempvalue = arraynumber[k];

			for(l = k-1; (l >= 0) && (arraynumber[l] < tempvalue); l--) {

				arraynumber[l+1] = arraynumber[l];

			}

			arraynumber[l+1] = tempvalue;

		}

		if(j == numberofdigits) {
			//Need to add a zero.
			
			//Sort arraynumber[0] arraynumber[numberofdigits-1]
			//Insertion sort code.
			for(k = 1; k < numberofdigits; k++) {

				tempvalue = arraynumber[k];

				for(l = k-1; (l >= 0) && (arraynumber[l] < tempvalue); l--) {

					arraynumber[l+1] = arraynumber[l];

				}

				arraynumber[l+1] = tempvalue;

			}

			//Find first non-zero number.
			for(k = numberofdigits -1; k >= 0; k--) {
				if(arraynumber[k] != 0) {
					arraynumber[numberofdigits] = arraynumber[k];
					arraynumber[k] = 0;
					numberofdigits++;
					break;
				}					
			}
			if(k == -1) {
				arraynumber[0] = 1;
				numberofdigits = 1;	
			}
			
		}

		printf("Case #%d: ", i+1);
		fprintf(outputfile, "Case #%d: ", i+1);
		
		for(j = numberofdigits - 1; j >= 0; j--) {
			printf("%c", (char)(arraynumber[j]+'0'));	
			fprintf(outputfile, "%c", (char)(arraynumber[j]+'0'));	
		}
		printf("\n");
		fprintf(outputfile,"\n");

	}
					
					
	free(input);

	fclose(inputfile);
	fclose(outputfile);
	
	return 0;	
	
}

/*



		memset(bases, 0, 10*sizeof(int));

		fgets(input, 100000, inputfile);
		readstring = strtok(input, " ");
	
		//Read in bases.
		for(j = 0; (j < 10) && (readstring != 0); j++) {
			bases[j] = atoi(readstring);
			readstring = strtok(0, " ");						
		}
		
		//Test numbers.
		for(j = 2; 1; j++) {
			//For each base.
			for(k = 9; k >= 0; k--) {
				if(bases[k] == 0) {
					continue;	
				}
				if(bases[k] == 1) {
					continue;
				}
				currentbase = bases[k];

				memset(visitednumbers, 0, 100000*sizeof(int));
				
				
				nextworking = j;
				unhappy = 0;
				while(1) {
					working = nextworking;
					nextworking = 0;

					//Find start.
					divisor = 1;
					exponent = 0;
					while(divisor <= working) {
						divisor = divisor * currentbase;
						exponent++;
					}

	
					for(l = divisor/currentbase; l > 0; l=l/currentbase) {
						temp = working/l;
						working = working - temp*l;
						nextworking += temp*temp;
					}				
		
					if(nextworking == 1) {
						unhappy = 0;
						break;
					}
					else {
						if(nextworking >= 100000) {
							continue;	
						}
						if(visitednumbers[nextworking] == 1) {
							unhappy = 1;
							break;	
						}
						else {
							visitednumbers[nextworking] = 1;	
						}
					}
				}
				if(unhappy == 1) {
					unhappy = 0;
					break;
				}					
			}
			if(k == -1) {
				//Number is happy!
				printf("Case #%d: %d\n", i+1, j);
				break;
			}
		}				

	}
*/

