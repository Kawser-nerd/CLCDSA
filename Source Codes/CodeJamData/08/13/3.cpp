#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define infile "a3.in"
#define outfile "a3.out"

FILE *fin=fopen(infile,"r"),
	*fout=fopen(outfile,"w");

//using windows calculator
const char* cresult[30+1]={"",
						 "","","","","",
						 "","","","","",
						 "943","471","055","447","463",
						 "991","095","607","263","151",
						 "855","527","743","351","135",
						 "407","903","791","135","647"};

//use __int64!!!

__int64 n,mi2n;
__int64 a[3][3],b[3][3],c[3][3],www[100];

void gei(__int64 a[3][3],__int64 b[3][3])
{
	__int64 i,j;
	for (i=1; i<=2; i++)
		for (j=1; j<=2; j++)
			a[i][j]=b[i][j];
}

void cheng(__int64 a[3][3],__int64 b[3][3],__int64 c[3][3])
{
	__int64 i,j,k;
	for (i=1; i<=2; i++)
		for (j=1; j<=2; j++)
		{
			c[i][j]=0;
			for (k=1; k<=2; k++)
				c[i][j]+=a[i][k]*b[k][j];
			c[i][j]=c[i][j]%1000;
		}
}	

void chengmtrx(__int64 n)
{
	bool first=true;
	gei(b,a);
	while (n)
	{
		if (n%2==1)
		{
			if (first)
			{
				first=false;
				gei(a,b);
			}
			else {
				cheng(a,b,c);
				gei(a,c);
			}
		}
		cheng(b,b,c);
		gei(b,c);
		n/=2;
	}
}

void calc2n(__int64 n)
{
	__int64 b;
	b=2;
	mi2n=1;
	while (n)
	{
		if (n%2==1)
		{
			mi2n=mi2n*b;
			mi2n=mi2n%1000;
		}
		b=b*b;
		b=b%1000;
		n/=2;
	}	
}

int main()
{
	__int64 i,t,w,fn,result;
	double tt;
	fscanf(fin,"%I64d",&t);
	www[1]=www[2]=1;
	for (i=3; i<=30; i++)
	{
		www[i]=(www[i-1]+www[i-2])%1000;
	}

	for (i=1; i<=t; i++)
	{
		fscanf(fin,"%I64d",&n);	
		if (n<=28)
		{
			tt=pow(3+sqrt(5.0),n+0.0);
			tt=(__int64)tt;
			tt-=floor(tt/1000)*1000;
			if (n<=10)
			{
				if (tt<100)
					fprintf(fout,"Case #%I64d: 0%.0lf\n",i,tt);
				else fprintf(fout,"Case #%I64d: %.0lf\n",i,tt);
			}
			else fprintf(fout,"Case #%I64d: %s\n",i,cresult[n]);
		}
		else {
			a[1][1]=0;
			a[1][2]=a[2][1]=a[2][2]=1;
			chengmtrx(n);//n-1);
			fn=a[1][2];
			calc2n(n);
			fn=(fn*fn)%1000;
			result=fn*5*mi2n;
			result=result%1000;
			if (n%2==1)
				result-=mi2n*2;
			else result+=mi2n*2;
			--result; //important!!!
			while (result<0)
				result+=1000;
			while (result>=1000)
				result-=1000;
			if (result<10)
				fprintf(fout,"Case #%I64d: 00",i);
			else if (result<100)
				fprintf(fout,"Case #%I64d: 0",i);
			else fprintf(fout,"Case #%I64d: ",i);
			fprintf(fout,"%I64d\n",result);
		}		
	}
	fclose(fin);
	fclose(fout);
	return 0;
}