#include <stdio.h>
#include <stdlib.h>
long long A, B, K;
int main(int argc, char *argv[]){
	FILE *fin, *fout;
	char kk;
	long long  total, i, j, k, sum, aux;

	fin=fopen(argv[1], "r");
	fout=fopen("out", "w");
	if (fin==NULL || fout == NULL)
	{
		printf("Fitxer out.\n");
	}
	else 
	{
		fscanf(fin, "%lld", &total);
		fscanf(fin, "%c", &kk);
		for (i = 0; i<total; i++)
		{
			fscanf(fin, "%lld", &A);
			fscanf(fin, "%lld", &B);
			fscanf(fin, "%lld", &K);

			if (A>B){
				aux=B;
				B=A;
				A=aux;
			}
			if(K>A){
				K=A;
			}
			sum=B*K;

			for(k = K; k < A; k++){
				for (j=0; j<B; j++){
					if((j&k) < K){
						sum++;
					}
				}
			}

			fprintf(fout, "Case #%lld: %lld\n", i+1, sum);

		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}