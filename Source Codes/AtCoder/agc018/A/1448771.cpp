#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int n,a[200000],k;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main()
{
	scanf("%d%d",&n,&k);
	int max=0;
	set<int> s;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		max=max>a[i]?max:a[i];
		if(a[i]==k){puts("POSSIBLE");return 0;}
		s.insert(a[i]%k);
	}
	if(max<k){puts("IMPOSSIBLE");return 0;}
	if(n==1){puts("IMPOSSIBLE");return 0;}
	sort(a,a+n);
	int x=a[0];
	for(int i=1;i<n&&x>1;i++)x=gcd(x,a[i]);
	puts(k%x?"IMPOSSIBLE":"POSSIBLE");
	return 0;
}