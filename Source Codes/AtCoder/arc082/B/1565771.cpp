#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int a[100010],n,x;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]==i)
		{
			swap(a[i],a[i+1]);
			x++;
		}
	printf("%d",x); 
}