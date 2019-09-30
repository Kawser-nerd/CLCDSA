#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
	int value;
	int devid;
	int index;
} arr[100050];
bool comp1(const Node &A,const Node &B)
{
	return A.value<B.value;
}
bool comp2(const Node &A,const Node &B)
{
	return A.index < B.index;
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&arr[i].value);
		arr[i].index=i;
	}
	sort(arr+1,arr+N+1,comp1);
	for(int i=1;i<=N;++i)
	{
		arr[i].devid=i;
	}
	sort(arr+1,arr+N+1,comp2);
	int B[100050];
	for(int i=1;i<=N;++i)
	{
		B[i]=arr[i].devid;
	}
	int cnt=0;
	for(int i=1;i<=N;++i)
	{
		if(B[i]%2!=i%2)
		{
			cnt++;
		}
	}
	printf("%d",cnt/2);
	return 0;
}