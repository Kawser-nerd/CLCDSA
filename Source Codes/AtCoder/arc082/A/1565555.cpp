#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int a[100010],n,x;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		a[x+1]++;
		a[x]++;
		a[x-1]++; 
	}
	for(int i=1;i<=100000;i++)
		n=max(n,a[i]);
	printf("%d",n);
}