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
ulli c;
//int t;
int w7[50];
int eval(int n,int *ss,int *w)
{
	int t2;
	int m2,m3,m5,m7;
	int i1;
	int i=0;
	int j;
	int s;

	m2=0; m3=0; m5=0; m7=0;
	s=1;
	i=-1;
	do
	{
		i++;
		i1=i;
		while((w[i]==0)&&(i<(n-1))) i++;

		for(j=i1; j<=i; j++)
		{
			m3+=(ss[j]%3)*s;
			m7+=((ss[j]%7)*w7[i-j])*s;
		}
		m2+=((ss[i]%2))*s;
		m5+=((ss[i]%5))*s;
		
		s=w[i]; 
	} while(i<(n-1));
	
	m3=m3%3;
	m7=m7%7; m2=m2%2; m5=m5%5;
	m3+=3;
	m7+=7;
	m5+=5;
	m2+=2;
m3=m3%3;
	m7=m7%7; m2=m2%2; m5=m5%5;
	/*
	if(m3<0) 
		printf("%d",m3);
	if(m2<0)
		printf("%d",m2);
	if(m5<0) 
		printf("%d",m5);
	if(m7<0)
		printf("%d",m7);*/
	if((m2==0)||(m3==0)||(m5==0)||(m7==0))
		return(1);
	else
		return(0);
}
ulli sol(int n,int m,int *s,int *w)
{
	if(m==0) c=0;	
	if(m==(n-1))
	{
		if(eval(n,s,w))
			c++;
	}
	else
	{
		w[m]=1;
		sol(n,m+1,s,w);
		w[m]=0;
		sol(n,m+1,s,w);
		w[m]=-1;
		sol(n,m+1,s,w);
		
	}
	return(c);

}
int buildw7(int n)
{	int i,t;
	t=1;
	for(i=0; i<n; i++)
	{
		t=t%7;
		w7[i]=t;
		t*=10;
	}
}
void lee(char *in)
{
	int F,D,B;	
	FILE *fp,*fp2;
	int i,j,k;
	ulli  res[3];
	int N;
	char f[50];
	int ss[50];
	int w[50]={0};
	
	
	char out[100];
	if((fp=fopen(in,"rt"))==NULL) exit(0);
	sprintf(out,"%s.out",in);
	fp2=fopen(out,"wt");
	buildw7(45);
	//while(!feof(fp))
	{
		fscanf(fp,"%d\n",&N);
		for(i=0; i<N; i++)
		{
			fscanf(fp,"%s\n",f);
			memset(w,0,sizeof(int)*50);
			for(j=0; j<strlen(f); j++)
				ss[j]=f[j]-'0';
			res[0]=sol(strlen(f),0,ss,w);
			fprintf(fp2,"Case #%d: %d\n",i+1,res[0]);
			
		}
	}
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

