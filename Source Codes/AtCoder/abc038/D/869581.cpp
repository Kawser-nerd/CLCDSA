#include<stdio.h>
#include<stdlib.h>
#include<iostream>

typedef struct Hako
{
	long long int w,h,in;
} HAKO;

int sor(const void* a,const void *b)
{
	if((*(HAKO*)a).w < (*(HAKO*)b).w)
	{
		return -1;
	}
	if((*(HAKO*)a).w == (*(HAKO*)b).w)
	{
		if((*(HAKO*)a).h < (*(HAKO*)b).h)
		{
			return -1;
		}
		else if((*(HAKO*)a).h == (*(HAKO*)b).h)
		{
			return 0;
		}
		return 1;
	}
	return 1;
}

int sor2(const void* a,const void *b)
{
	return ((*(HAKO*)a).in - (*(HAKO*)b).in);
}


int main(void)
{
	long long int n,i,f,max;
	int flg=0;
	HAKO* hako;
	scanf("%lld",&n);
	hako=(HAKO*)calloc(n,sizeof(HAKO));
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&hako[i].w,&hako[i].h);
		hako[i].in=0;
	}
	qsort(hako,n,sizeof(HAKO),sor);
/*
	for(i=0;i<n;i++)
	{
		printf("%lld %lld\n",hako[i].w,hako[i].h);
	}
*/
	max=0;
	for(i=1;i<n;i++)
	{
		if(hako[i].h>hako[max].h&&hako[i].w>hako[max].w)
		{
			hako[i].in = hako[max].in+1;
			max=i;
			flg=1;
		}
		for(f=i;f>=0&&flg!=1&&i-f<1000;f--)
		{
			if(hako[i].h>hako[f].h&&hako[i].w>hako[f].w&&hako[i].in<=hako[f].in)
			{
				hako[i].in=hako[f].in+1;
				if(hako[max].in<hako[i].in)
				{
					max=i;
				}
			}
		}
		flg=0;
	}
	qsort(hako,n,sizeof(HAKO),sor2);
	printf("%lld\n",hako[n-1].in+1);
	return 0;
}