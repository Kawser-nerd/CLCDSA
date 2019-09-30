#include<cstdio>
#include<iostream>
using namespace std;
int N;
int cnt=1;
int arr[100050];
int check=-1;
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{	
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<N;++i)
	{
		if(check==-1)
		{
			if(arr[i]>arr[i-1])
			{
				check=1;
			}
			else if(arr[i]<arr[i-1])
			{
				check=2;
			}
			else 
			{
				continue;
			}
		}
		if(check==1)
		{
			if(arr[i]>=arr[i-1])
			{
				continue;
			}
			else if(arr[i]<arr[i-1])
			{
				check=-1;
				cnt++;
				continue;
			}
		}
		if(check==2)
		{
			if(arr[i]>arr[i-1])
			{
				check=-1;
				cnt++;
				continue;
			}
			else if(arr[i]<=arr[i-1])
			{
				continue;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}