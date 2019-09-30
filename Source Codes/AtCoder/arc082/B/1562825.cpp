#include"iostream"
#include"stdio.h"
using namespace std;
const int Maxn=100005;
int a[Maxn];
int main()
{
//	freopen("text.in","r",stdin);
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]==i)
		{
			int x1=0,x2=0;
			if(a[i-1]!=i)
				x1=1;
			if(a[i+1]!=i)
			{
				if(a[i+1]==i+1)x2=2;
				else x2=1;
			}
			if(x1>x2)swap(a[i],a[i-1]),sum++;
			else swap(a[i+1],a[i]),sum++; 
		}
	printf("%d",sum);
	return 0;
}