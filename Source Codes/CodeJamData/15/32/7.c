#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fin, *fout;
int d[30];
char l[102];
int K, L, S;

int c(int j){
	int i;
	//printf("%d\n", j);
	int k = 0;
	for(i=j; i<L; i++, k++){
		//printf("%s\n", );
		if(l[i]!=l[k]){
			//printf("mal %c,%d %c,%d\n", l[i],i, l[k], k);
			return 0;
		}
	}
	return 1;
}

int mx(int m){
	int aux;
	aux = S-L;
	return aux/m+1;
}

void solve(){
	int i;
	char kk;
	int m;
	for(i=0; i<30; i++) d[i]=0;
	fscanf(fin, "%d %d %d", &K, &L, &S);
	fscanf(fin, "%c", &kk);
	for(i=0; i<K; i++){
		fscanf(fin, "%c", &kk);
		d[kk-'A']++;
	}
	fscanf(fin, "%c", &kk);
	for(i=0; i<L; i++){
		fscanf(fin, "%c", &l[i]);
	}
	l[i]='\0';
	fscanf(fin, "%c", &kk);
	double prob=1;
	for(i=0; i<L; i++){
		if(d[l[i]-'A']==0){
			fprintf(fout, "0.0\n");
			return;
		}
		prob = prob * (d[l[i]-'A']*1.0)/(K*1.0);
	}
	m = L;
	for(i=1; i<L; i++){
		if(c(i)){
			m = i;
			break;
		}
	}
	fprintf(fout, "%lf\n", ((double)mx(m))-prob*(S-L+1));
	
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
			printf( "Case #%d: ", i+1);
			solve();
		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}