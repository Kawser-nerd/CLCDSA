#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
#define Maxn 100009
#define x first
#define y second
typedef long long LL;
map <int,int> k;
int n,a[Maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		++k[a[i]];
	}
	int x = 0, y = 0;
	for (auto i : k)
	{
		if (i.y >= 4) x = y = i.x;
		else if (i.y >= 2)
		{
			if (x < y) x = i.x;
			else y = i.x;
		}
	}
	printf("%lld\n",LL(x)*y);
	return 0;
}