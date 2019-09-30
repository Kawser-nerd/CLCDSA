#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEOUT "output.txt"

#define MAX_CHAR 30 //max length of input filename
#define M 110



typedef struct mychain{
	long long int boxt[M], boxn[M], toyt[M], toyn[M];
	int n, m;
} chain;

long long int fillBox(int boxi, int toyj, chain c);

int main(int argc, char* argv[])
{
	FILE *fin, *fout;
	char filename[MAX_CHAR], buf[MAX_CHAR];
	int T;
	int n, m, i, j, ibox, k;
	long long int res;
	chain c;
	

	if(argc<2) {
		printf("Syntax: %s <filename>\n", argv[0]);
		return(1);
	}

	strcpy(filename,argv[1]);
	
	fin=fopen(filename, "r");

	fout=fopen(FILEOUT, "w");

	fscanf(fin, "%d", &T); // NUMBER OF TEST CASES
	k=0;
	while(T>0){
		T--;
		k++;
		fscanf(fin, "%d %d", &(c.n), &(c.m));
		for(i=0; i<c.n; i++) fscanf(fin,"%Ld %Ld", &(c.boxn[i]), &(c.boxt[i]));
		for(i=0; i<c.m; i++) fscanf(fin,"%Ld %Ld", &(c.toyn[i]), &(c.toyt[i]));
		printf("boxes: %Ld\n", c.boxn[0]);


		
		
		res=fillBox(0, 0, c);
		fprintf(fout, "Case #%d: %Ld\n", k, res);
		printf("Case #%d: %Ld\n", k, res);
		
			
	}

	fclose(fin);
	fclose(fout);
	return(0);
}


long long int fillBox(int boxi, int toyj, chain c){

	long long int reswait=0, resgo=0, reswag=0, maxres=0;
	long long int bleft = c.boxn[boxi];
	
	if(boxi+1<c.n){
	//gonext
		resgo=fillBox(boxi+1, toyj, c);//printf("deb\n");
	}

	//wait
	while(toyj<c.m && bleft){
		if(c.toyt[toyj]!=c.boxt[boxi] && toyj<c.m){
			//different type: gonext
			toyj++; 
		}
		else {
			//same type
			if(bleft<=c.toyn[toyj]){
				//finish boxes left and go on
				c.toyn[toyj]-=bleft;
				reswait+=bleft+fillBox(boxi+1, toyj, c);
				c.toyn[toyj]+=bleft;
				bleft=0;
			}else{
				//finish toys
				bleft-=c.toyn[toyj];
				reswait+=c.toyn[toyj];
				toyj++;
				//decide wheter to wait or to go to next box
				reswag=reswait+fillBox(boxi+1, toyj, c);
				if(reswag>maxres) maxres=reswag;
			}
		}
	}
	if(reswait>maxres) maxres= reswait;
	if(resgo>maxres) maxres= resgo;
	return(maxres);
}




