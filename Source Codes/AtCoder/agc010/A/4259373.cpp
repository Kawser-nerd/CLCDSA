#include<cstdio>
#include<iostream>
using namespace std;
int N,a,cnt=0;
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&a);
		if(a%2!=0)
		{
			cnt++;
		}
	}
	if(cnt%2==0)
	{
		printf("YES");
		return 0;
	}
	printf("NO");
	return 0;
}