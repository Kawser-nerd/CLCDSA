#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fin, *fout;
int d[35];
char w[200];
int K, L, S;


int isRepeated(int i){
	int end, init = 0;
	for(end=i; end<L; end++, init++) if(w[end]!=w[init]) return 0;
	return 1;
}

double solve(){
	int i,j;
	char c;
	for(i=0; i<30; i++){
		d[i]=0;
	}
	fscanf(fin, "%d %d %d", &K, &L, &S);
	fscanf(fin, "%c", &c);
	for(i=0; i<K; i++){
		fscanf(fin, "%c", &c);
		d[c-'A'] = d[c-'A']+1;
	}
	fscanf(fin, "%c", &c);
	for(i=0; i<L; i++){
		fscanf(fin, "%c", &w[i]);
	}
	w[i]='\0';
	fscanf(fin, "%c", &c);
	double p=1;
	for(i=0; i<L; i++){
		if(d[w[i]-'A']==0){
			return (double)0.;
		}
		p=p*(d[w[i]-'A']*1.0)/((double)K);
	}
	j = L;
	for(i=1; i<L; i++) if(isRepeated(i)){
						j = i;
						break;
					   }
	int max = (S-L)/j+1;
	
	return (double)max-p*(S-L+1);
}

int main(int argc, char *argv[]){
	char c;
	int abcd, i;
	double sol;

	fin=fopen(argv[1], "r");
	fout=fopen("out.txt", "w");
	if ( fin == NULL || fout == NULL ){
		printf("ERROR WITH FILE.\n");
	}else{
		fscanf(fin, "%d", &abcd);
		fscanf(fin, "%c", &c);
		for ( i = 0; i < abcd; i++ ){
			sol=solve();
			fprintf(fout, "Case #%d: %lf\n", i+1, sol);
		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}