#include<cstdio>
#include<queue>
#include<algorithm>
#define MAXN 300006
using namespace std;
int n;
struct node
{
	int x,id;
}a[MAXN];
int ans;
bool cmp(node a,node b)
{
	return a.x<b.x;
}
int main()
{
	//freopen("sort.in","r",stdin);
	//freopen("sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		if((i-a[i].id)%2) ans++;
	printf("%d",ans/2);
}