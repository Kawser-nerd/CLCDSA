#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll minord(ll num,ll per)
{
	ll ans=num;
	ll low=num-per-1;
	for(;;)
	{
		if(low==0)
		{
			return ans;
		}
		low=(low-1)/2;
		ans/=2;
	}
}
ll maxord(ll num,ll per)
{
	ll ans=num;
	ll low=per;
	for(;;)
	{
		if(low==0)
		{
			return num+1-ans;
		}
		low=(low-1)/2;
		ans/=2;
	}
}
int main()
{
	FILE *fr=fopen("b-large.in","r");
	FILE *fw=fopen("out0.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		ll num,pri;
		fscanf(fr,"%lld%lld",&num,&pri);
		num=(1LL<<num);
		ll beg1=0,end1=num-1;
		for(;;)
		{
			ll med=(beg1+end1)/2+1;
			//printf("%lld %lld %lld %lld\n",beg1,end1,med,maxord(num,med));
			if(maxord(num,med)>pri)
			{
				end1=med-1;
			}
			else
			{
				beg1=med;
			}
			if(beg1==end1)
			{
				break;
			}
		}
		ll beg2=0,end2=num-1;
		for(;;)
		{
			ll med=(beg2+end2)/2+1;
			if(minord(num,med)>pri)
			{
				end2=med-1;
			}
			else
			{
				beg2=med;
			}
			if(beg2==end2)
			{
				break;
			}
		}
		fprintf(fw,"Case #%d: %lld %lld\n",p+1,beg1,beg2);
	}
}