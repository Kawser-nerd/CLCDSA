// tren.cpp : Defines the entry point for the console application.
// Oscar Barenys Garcia
// Google Code Jam 2008
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
#include <assert.h>
typedef unsigned long long ulli;

#include <math.h>
int compareA(const void *_a, const void *_b) {
 
        int *a, *b;
        
        a = (int *) _a;
        b = (int *) _b;
        
        return (*b - *a);
}

ulli sol(int P,int K,int L, int *fL)
{
	ulli c=0;
	int i;
	qsort(fL,L,sizeof(int),compareA);
	for(i=0; i<L; i++)
	{
		c+=fL[i]*((i/K)+1);
	}
	return(c);
}



void lee(char *in)
{
	FILE *fp,*fp2;
	int i,j,k;
	ulli  res[3];
	int N;
	int P,K,L;
	int f[2000];
	ulli kk;
	char out[100];
	if((fp=fopen(in,"rt"))==NULL) exit(0);
	sprintf(out,"%s.out",in);
	fp2=fopen(out,"wt");
	//while(!feof(fp))
	{
		fscanf(fp,"%d\n",&N);
		for(i=0; i<N; i++)
		{
			fscanf(fp,"%d %d %d\n",&P,&K,&L);
			for(j=0; j<L; j++)
				fscanf(fp,"%d",&f[j]);
			res[0]=sol(P,K,L,f);
			fprintf(fp2,"Case #%d: %I64d\n",i+1,res[0]);
			
		}
	}

	/*kk=1<<10;
	kk=kk<<30;
	printf("",kk);*/
	fclose(fp);
	fclose(fp2);
}

int main(int argc, char* argv[])
{
	if(argc>1)
	{
		lee(argv[1]);
	}
	return 0;
}

