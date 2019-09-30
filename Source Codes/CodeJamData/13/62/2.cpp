#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int N;
int arr[50000];

int check(double e, double k)
{
	double lo=arr[0]-e;
	double hi=arr[0]+e;
	for(int i=1; i<N; i++)
	{
		double nlo=arr[i]-i*k-e;
		double nhi=arr[i]-i*k+e;
		if(nhi<lo)
			return -1;
		if(nlo>hi)
			return 1;
		lo=max(lo, nlo);
		hi=min(hi, nhi);
	}
	return 0;
}

bool can(double e)
{
	double lo=0, hi=2e6;
	for(int it=0; it<55; it++)
	{
		double mid=(lo+hi)/2;
		int s=check(e, mid);
		if(s==0)
			return true;
		if(s==1)
			lo=mid;
		if(s==-1)
			hi=mid;
	}
	return false;
}

int main()
{
	int _T;
	string line;
	getline(cin, line);
	istringstream(line)>>_T;
	for(int t=1; t<=_T; t++)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &arr[i]);
		double lo=0, hi=2e6;
		for(int it=0; it<55; it++)
		{
			double mid=(lo+hi)/2;
			if(can(mid))
				hi=mid;
			else
				lo=mid;
		}
		printf("Case #%d: %.9f\n", t, (lo+hi)/2);
	}
}
