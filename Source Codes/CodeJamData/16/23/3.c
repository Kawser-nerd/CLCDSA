#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fin, *fout;
char dic[2000][21];
int dic2[2000];
int M;
int id[2000];
int g[2000][2000];
int gn[2000];
int N;
int v[2000];

int matched[2000];

int ap(int K){
	v[K] = 1;
	int i;
	for (i = 0; i < gn[K]; i++) {
	    int n = g[K][i];
	    if (v[n]) {
	      continue;
	    }

	    // Base-case. We've reached a node at the end of an alternating path that
	    // ends in a freenode.
	    if (matched[n] == -1) {
	      matched[K] = n;
	      matched[n] = K;
	      return 1;
	    } else if (matched[n] != K) {
	      // This is not your standard DFS. Because we're DFSing along an
	      // alternating path, when we choose the next vertex to visit, we MUST
	      // then go along its matching edge. So we say we've visited the neighbour
	      // trivially and then recursing on matched[neighbour].

	      v[n] = 1;
	      if (ap(matched[n])) {
	        matched[K] = n;
	        matched[n] = K;
	        return 1;
	      }
	    }
	  }

  return 0;
}

int add(char a[21], int b){
	int i;
	for (i=0; i<M; i++){
		if(!strcmp(a, dic[i]) && b ==dic2[i]){
			return i;
		}
	}
	strcpy(dic[M], a);
	dic2[M] = b;
	M++;
	return M-1;
}
void addN(int a, int b){
	g[a][gn[a]] = b;
	gn[a]++;
}

void solve(){
	int i, j;
	char aux[21];
	fscanf(fin, "%d", &N);
	for(i=0; i<2*N; i++){
		bzero(dic[i], 21);
		gn[i] = 0;
	}
	M = 0;
	for(i=0; i<N; i++){
		int a, b;
		fscanf(fin, "%s", aux);
		a = add(aux, 1);
		fscanf(fin, "%s", aux);
		b = add(aux, 2);
		addN(a, b);
		addN(b, a);
	}
	/*
	for(i=0; i<M; i++){
		printf("%s-->", dic[i]);
		for(j=0; j<gn[i]; j++){
			printf("%s ", dic[g[i][j]]);
		}
		printf("\n");
	}
	*/
	int sol = 0;
	for(i=0; i<M; i++){
		matched[i] = -1;
	}
	for(i=0; i<M; i++){
		if(dic2[i] == 1 && matched[i] == -1){
			for(j=0; j<2000; j++) v[j] = 0;
			if(ap(i)){
				sol++;
			}
		}
	}
	for(i=0; i<M; i++){
		if(matched[i] == -1) sol++;
	}
	fprintf(fout, "%d\n", N-sol);
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
			printf("Case #%d: ", i+1);
			solve();
		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}