#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int i,n,ptr,currcount,lastnum,res=0;
	int *a;
	scanf("%d",&n);
	a=new int [n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	ptr=0;
	while(ptr<n)
	{
		lastnum=a[ptr];
		currcount=0;
		while(ptr<n&&a[ptr]==lastnum)
		{
			currcount++;
			ptr++;
		}
		res+=currcount%2;
	}
	printf("%d\n",res);
	delete [] a;
	return 0;
}