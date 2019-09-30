#include<iostream>
#include<cstdio>
#include<vector>
#define N 110
using namespace std;

int n,m,num[N],cnt;
vector<int>ans,js;

inline void out(int u)
{
	int i;
	for(i=0;i<=u;i+=2) ans.push_back(2);
}

int main()
{
	int i,j,p,q;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]%2)
		{
			cnt++;
			js.push_back(num[i]);
		}
	}
	if(cnt>2)
	{
		puts("Impossible");
		return 0;
	}
	if(!js.empty()) out(js[0]);
	else ans.push_back(1);
//	cout<<" ";for(i=0;i<ans.size();i++) cout<<ans[i]<<" ";return 0;
	for(i=1;i<=m;i++)
	{
		if(num[i]%2) continue;
		ans.push_back(num[i]);
	}
	if(cnt<=1)
	{
		p=ans[ans.size()-1]-2;
		ans.pop_back();
		ans.push_back(1);
		if(p) ans.push_back(p);
	}
	else
	{
		out(js[1]);
		ans.pop_back();
	}
	if(cnt) printf("%d ",js[0]);
	for(i=1;i<=m;i++) if(num[i]%2==0) printf("%d ",num[i]);
	if(cnt>1) printf("%d ",js[1]);
	printf("\n%d\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%d ",ans[i]);
	}
} ./Main.cpp:57:18: warning: format specifies type 'int' but the argument has type 'size_type' (aka 'unsigned long') [-Wformat]
        printf("\n%d\n",ans.size());
                  ~~    ^~~~~~~~~~
                  %lu
1 warning generated.