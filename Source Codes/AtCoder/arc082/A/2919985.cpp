#include<iostream>
#include<string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int a[100010],a1[300030];
int sum[100010]={0};
int h=0;
int main()
{
	int N,max,j=0,a;
	int h=0;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>a;
		sum[a-1]++;
		sum[a]++;
		sum[a+1]++;
	}
	sort(sum,sum+100001);
	cout<<sum[100000];
}