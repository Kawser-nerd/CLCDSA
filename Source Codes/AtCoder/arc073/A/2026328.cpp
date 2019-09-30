#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

long long sum= 0;

int main()
{
	long long n, t;
	cin>> n >> t;
	long long l = 0, r = 0;
	while (n--)
	{
		long long ti = 0;
		cin>> ti;
		if (ti < l && ti + t >= l)
		{
			l = ti;
		} 
		else if (ti <= r && ti + t > r)
		{
			r = ti + t;
		} 
		else
		{
			sum += r - l;
			l = ti;
			r = ti + t;
		}
	}
	sum += r - l;
	cout<< sum <<endl;
	return 0;	
}