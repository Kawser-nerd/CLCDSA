#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;

int solve(int R, int C, int W){
	if( W == 1 ){
		return R*C;
	}else{
		if( W == C ){
			return R-1 + W;
		}else{
			if( C % W != 0 ){
				return (C/W)* (R-1) + W + C/W;
			}else{
				return (C/W)* (R-1) + W + C/W - 1;
			}
		}
	}
	// El código para una sola solución. Empieza haciendo los fscanf
	// de fichero de entrada para cada uno de los T tests.
}

int main(int argc, char *argv[]){
	char c;
	int abcd, i, sol, R, C, W;

	fin=fopen(argv[1], "r");
	fout=fopen("out.txt", "w");
	if ( fin == NULL || fout == NULL )
	{
		printf("ERROR WITH FILE.\n");
	}
	else 
	{
		fscanf(fin, "%d", &abcd);
		fscanf(fin, "%c", &c);
		for ( i = 0; i<abcd; i++ ){
			fscanf(fin, "%d", &R);
			fscanf(fin, "%d", &C);
			fscanf(fin, "%d", &W);
			sol=solve(R, C, W);
			fprintf(fout, "Case #%d: %d\n", i+1, sol);
		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}