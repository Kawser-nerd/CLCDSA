#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		int x,y;scanf("%d%d",&x,&y);
		printf("Case #%d: ",__);
		if(x>0)
		{
			for(int i=0;i<x;i++)printf("WE");
		}else
		{
			for(int i=0;i<-x;i++)printf("EW");
		}
		if(y>0)
		{
			for(int i=0;i<y;i++)printf("SN");
		}else
		{
			for(int i=0;i<-y;i++)printf("NS");
		}
		puts("");
	}
	return 0;
}