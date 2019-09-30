#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;
int h[2501];
int sol[50];
int N;
void solve(){
	int i, j, k, a;
	fscanf(fin, "%d", &N);
	for(i=0; i<2501; i++) h[i] = 0;
	for(i=0; i<50; i++) sol[i] = 0;
	for(i=0; i<(2*N-1)*N; i++){
		fscanf(fin, "%d", &a);
		h[a]++;
	}
	k=0;
	for(i=0; i<2501; i++){
		if(h[i]%2 != 0){
			sol[k] = i;
			k++;
		}
	}
	for(i=0; i<k; i++)
	 for(j=i+1;j<k; j++)
	  if(sol[j]<sol[i]){ int t = sol[i]; sol[i] = sol[j]; sol[j] = t;}
	if(k!=N) printf("ERROR\n");
	for(i=0; i<N; i++){
		fprintf(fout, "%d ", sol[i]);
	}
	fprintf(fout, "\n");
}

int main(int argc, char *argv[]){
	char kk;
	int total, i;

	fin=fopen(argv[1], "r");
	fout=fopen("out", "w");
	if (fin==NULL || fout == NULL)
	{
		printf("Fitxer out.\n");
	}
	else 
	{
		fscanf(fin, "%d", &total);
		fscanf(fin, "%c", &kk);
		for (i = 0; i<total; i++)
		{
			fprintf(fout, "Case #%d: ", i+1);
			solve();
		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}