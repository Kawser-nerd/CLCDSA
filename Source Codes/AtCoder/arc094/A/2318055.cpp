#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
using namespace std;
inline bool odd(int k) {return k&1;}
int main()
{
	int a[3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	if(odd(a[2]-a[1]))
	{
		if(odd(a[1]-a[0]))printf("%d",(a[2]-a[0])/2+(a[2]+1-a[1])/2+1);
		else printf("%d",(a[2]*2-a[0]-a[1])/2);
	}else
	{
		if(odd(a[1]-a[0]))printf("%d",(a[2]-a[0]+1)/2+(a[2]-a[1])/2+1);
		else printf("%d",(a[2]*2-a[0]-a[1])/2);
	}
}