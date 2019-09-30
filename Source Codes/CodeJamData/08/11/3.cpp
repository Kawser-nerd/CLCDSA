#include <stdio.h>
#define infile "a1.in"
#define outfile "a1.out"

FILE *fin=fopen(infile,"r"),
	*fout=fopen(outfile,"w");

//__int64!!!!!!!!!!!!!
//%I64d!!!!!!!!!!!!!!

__int64 a[1000],b[1000],n;

void px(__int64 a[])
{
	__int64 i,j,k;
	for (i=2; i<=n; i++)
	{
		j=i-1;
		k=a[i];
		while ((j>=1)&&(k<a[j]))
		{
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=k;
	}
}

int main()
{
	__int64 i,j,t,result;
	fscanf(fin,"%I64d",&t);
	for (i=1; i<=t; i++)
	{
		fscanf(fin,"%I64d",&n);
		for (j=1; j<=n; j++)
			fscanf(fin,"%I64d",&a[j]);
		for (j=1; j<=n; j++)
			fscanf(fin,"%I64d",&b[j]);
		px(a);
		px(b);
		result=0;
		for (j=1; j<=n; j++)
			result+=a[j]*b[n-j+1];
		fprintf(fout,"Case #%I64d: %I64d\n",i,result);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}