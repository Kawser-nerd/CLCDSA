#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100010],n;
bool get(int pos)
{
	for(int i=pos+1;i<=n+1;i++)
	{
		if(a[i]>a[i-1]) {return false;break;}
		if(a[i]<a[i-1]) {return true;break;}
	}
}
int main()
{
	int sum=1,pos=1,i=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	get(pos);
while(i<=n)
{
	if(get(pos)==false)
	{
		for(i=pos+1;i<=n;i++)
		{
			if(a[i]<a[i-1]) {sum++;pos=i;break;}
		}
		get(pos);
	}
	else
	{
		for(i=pos+1;i<=n;i++)
		{
			if(a[i]>a[i-1]) {sum++;pos=i;break;}
		}
		get(pos);
	}
}
	printf("%d\n",sum);
	return 0;
} ./Main.cpp:15:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.