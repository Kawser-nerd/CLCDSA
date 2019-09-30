#include<cstdio>
int n,m,a[2000000],x,y,cnt[2000000],line[2000000];
int main()
{
	scanf("%d%d",&n,&m);
	int empty=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		int p=a[i]-cnt[a[i]]++;
		if(p>0&&!line[p]++)empty--;
	}
	while(m--)
	{
		scanf("%d%d",&x,&y);
		int p=a[x]-cnt[a[x]]--+1;
		if(p>0&&!--line[p])empty++;
		a[x]=y;
		int q=a[x]-cnt[a[x]]++;
		if(q>0&&!line[q]++)empty--;
		printf("%d\n",empty);
	}
	return 0;
}