#include<cstdio>
#include<deque>
using namespace std;
int n,a;
int main()
{
	scanf("%d",&n);
	deque<int> b;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(i&1)b.push_front(a);
		else b.push_back(a);
	}
	if(n&1)for(int i=n-1;i>=0;i--)printf("%d ",b[i]);
	else for(int i=0;i<n;i++)printf("%d ",b[i]);
	puts("");
	return 0;
}