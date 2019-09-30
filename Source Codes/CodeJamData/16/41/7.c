#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fin, *fout;
int M;

char * min(char *a, char *b){
	if(strcmp(a, b)<0) return a;
	return b;
}

char * smin(char *a, char* b, char *c){
	return min(min(a, b), c);
}

void f(int m, int P, int R, int S, char c[5000]){
	if(m == M) return;
	int i;
	char aux[5000];
	bzero(aux, 5000);
	for(i=0; i<m; i++){
		switch(c[i]){
			case 'P': 
				if(R > 0){
					R--;
					aux[2*i] = 'P'; 
					aux[2*i+1] = 'R'; 
					break;
				}else{
					bzero(c, 5000);
					return;
				}
			case 'R': 
				if(S > 0){
					S--;
					aux[2*i] = 'R'; 
					aux[2*i+1] = 'S'; 
					break;
				}else{
					bzero(c, 5000);
					return;
				}
			case 'S': 
				if(P > 0){
					P--;
					aux[2*i] = 'P'; 
					aux[2*i+1] = 'S'; 
					break;
				}else{
					bzero(c, 5000);
					return;
				}
		}
	}
	strcpy(c, aux);
	f(2*m, P, R, S, c);
}

void order(char s[5000], int i, int m){
	if(m-i == 1) return;
	/*
	char a[5000], b[5000];
	bzero(a, 5000);
	bzero(b, 5000);
	strncpy(a, &s[i], (m-i+1)/2);
	strncpy(b, &s[i+(m-i+1)/2], (m-i+1)/2);
	*/
	order(s, i, i+(m-i+1)/2-1);
	order(s, i+(m-i+1)/2, m);
	if(strncmp(&s[i], &s[i+(m-i+1)/2], (m-i+1)/2)>0){
		char t[5000];
		bzero(t, 5000);
		strncpy(t, &s[i], (m-i+1)/2);
		strncpy(&s[i], &s[i+(m-i+1)/2], (m-i+1)/2);
		strncpy(&s[i+(m-i+1)/2], t, (m-i+1)/2);
	}
}


void solve(){
	int i;	
	int N, P, R, S;
	fscanf(fin, "%d %d %d %d", &N, &R, &P, &S);
	M = 1;

	for(i = 0; i<N; i++){
		M = M*2;
	}

	char p[5000];
	char r[5000];
	char s[5000];
	bzero(p, 5000);
	bzero(r, 5000);
	bzero(s, 5000);
	if(P>0){
		p[0] = 'P';
		f(1, P-1, R, S, p);
	}
	if(R>0){
		r[0] = 'R';
		f(1, P, R-1, S, r);
	}
	if(S>0){
		s[0] = 'S';
		f(1, P, R, S-1, s);
	}
	if(p[0] == '\0' && r[0] == '\0' && s[0] == '\0'){
		fprintf(fout, "IMPOSSIBLE\n");
		return;
	}
	printf("%s %s %s\n", p, r, s);

	if(p[0] != '\0'){
		order(p, 0, M-1);
	}else{
		for(i=0; i<5000; i++) p[i] = 'Z';
	}
	if(r[0] != '\0'){
		order(r, 0, M-1);
	}else{
		for(i=0; i<5000; i++) r[i] = 'Z';
	}
	if(s[0] != '\0'){
		order(s, 0, M-1);
	}else{
		for(i=0; i<5000; i++) s[i] = 'Z';
	}
	fprintf(fout, "%s\n", smin(p, r, s));	
	printf("%s\n", smin(p, r, s));	

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
			printf( "Case #%d: \n", i+1);
			solve();
		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}