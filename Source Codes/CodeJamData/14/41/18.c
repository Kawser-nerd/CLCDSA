#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;
int N, X;
int n[701];

void solve(){
	fscanf(fin, "%d %d", &N, &X);
	int i,j;
	int res=0;
	int s;
	for (i=0; i<700; i++) n[i]=0;
	for (i = 0; i<N; i++){
		fscanf(fin, "%d", &s);
		n[s]++;
	}
	for(i = 700; i>=1; i--){
		while(n[i]>0){
			res++;
			n[i]--;
			for(j = (X-i); j>=1; j--){
				if(n[j]>0){
					n[j]--;
					break;
				}
			}
		}
	}
	fprintf(fout, "%d\n", res);
	
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