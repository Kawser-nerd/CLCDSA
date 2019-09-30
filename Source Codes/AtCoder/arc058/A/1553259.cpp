#include<cstdio>
using namespace std;
const int N=10010;
int dp[N],n,x,k;
bool can[10];
bool check(int x)
{
	while(x)
	{
		if(can[x%10])
			return 0;
		x/=10;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&k);
	while(k--)
	{
		scanf("%d",&x);
		can[x]=1;
	}
	for(int j=n;; j++)
		if(check(j))
			return 0*printf("%d",j);
}