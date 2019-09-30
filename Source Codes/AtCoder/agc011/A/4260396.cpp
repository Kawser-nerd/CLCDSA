#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int T[100050];
int N,C,K;
int main()
{
	scanf("%d%d%d",&N,&C,&K);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&T[i]);
	}
	sort(T,T+N);
	int sum=1;
	int cnt=1;
	int st=T[0];
	for(int i=1;i<N;++i)
	{
		if(st+K<T[i])
		{
			sum++;
			cnt=1;
			st=T[i];
			continue;
		}
		if(st+K>=T[i])
		{
			cnt++;
			if(cnt>C)
			{
				cnt=1;
				sum++;
				st=T[i];
			}
		}
	}
	printf("%d",sum);
}