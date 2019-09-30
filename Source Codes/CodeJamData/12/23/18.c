#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fs fscanf
#define fp fprintf
#define rd(x) fscanf(f1,"%d",&x)
#define rld(x) fscanf(f1,"%ld",&x)
#define rlld(x) fscanf(f1,"%lld",&x)
#define rf(x) fscanf(f1,"%f",&x)
#define rlf(x) fscanf(f1,"%lf",&x)
#define rs(x) fscanf(f1,"%s",x)
FILE *f1,*f2;
long int ar[20][2];
long long int s1,s2;
int n;
int same(int l)
{
	int i,j,k;
	s1=s2=0;
	j=k=0;
	for(i=0;i<l;i++)
	{
		if(ar[i][1]==1)
		{
			s1+=ar[i][0];
			j=1;
		}
		else
		if(ar[i][1]==2)
		{
			s2+=ar[i][0];
			k=1;
		}
	}
	if((j==0)||(k==0))
	return(0);
	if(s1==s2)
	return(1);
	else
	return(0);
}
int per(int i,int l)
{
	if(i==(l-1))
	{
	if(same(l))
	return(1);
	return(0);
	}
	if(per(i+1,l))
	return(1);
	ar[i][1]=1;
	if(per(i+1,l))
	return(1);
	ar[i][1]=2;
	if(per(i+1,l))
	return(1);
	ar[i][1]=0;
	return(0);
}
	
int Main()
{
	
	int i,j,k;
	rd(n);
	for(i=0;i<n;i++)
	{
		rld(ar[i][0]);
		ar[i][1]=0;
	}
	for(i=2;i<n;i++)
	{
	if(per(0,i))
	{
	//	printf("i=%d",i);
		fp(f2,"\n");
		for(i=0;i<n;i++)
		{
			if(ar[i][1]==1)
			fp(f2,"%ld ",ar[i][0]);
		}
		fp(f2,"\n");
		for(i=0;i<n;i++)
		{
			if(ar[i][1]==2)
			fp(f2,"%ld ",ar[i][0]);
		}
		return(1);
	}
	}
	fp(f2,"\nImpossible");
	return(0);
}
int main()
{
	f1=fopen("/home/vivek/Desktop/s.in","r");
	f2=fopen("/home/vivek/Desktop/s.out","w");
	int cs,i;
	char c;
	fscanf(f1,"%d",&cs);
	for(i=1;i<=cs;i++)
	{
		fprintf(f2,"Case #%d: ",i);
		Main();
		c='\n';
		fputc(c,f2);
		printf("%d",i);
	}
	return(1);
}
