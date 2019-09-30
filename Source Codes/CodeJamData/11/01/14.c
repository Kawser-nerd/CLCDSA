#include<stdio.h>

int n;
char oper[100];
int pos[100];	

int findNext(char ch, int last)
{
	do
	{
		last++;
	}while (last<n && oper[last]!=ch);
	return last;
}

int abs(int a)
{
	if (a>0) return a; else return -a;
}

int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);
	int ca,count;
	scanf("%d",&ca);
	for (count=1;count<=ca;count++)
	{
		scanf("%d", &n);
		int i;
		for (i=0;i<n;i++) 
			scanf(" %c %d",&oper[i],&pos[i]);
		int nextO=-1,nextB=-1;
		nextO=findNext('O', nextO);
		nextB=findNext('B', nextB);
		int posO=1,posB=1;
		int ans=0;
		while (nextO<n || nextB<n)
		{
			int ti;
			if (nextO<nextB)
			{
				ti=abs(pos[nextO]-posO)+1;
				posO=pos[nextO];
				if (nextB<n)
				{
					if (ti>=abs(pos[nextB]-posB))
						posB=pos[nextB];
					else if (abs(pos[nextB]-posB-ti)<abs(pos[nextB]-posB+ti))
						posB+=ti;
					else
						posB-=ti;
				}
				ans+=ti;
				nextO=findNext('O', nextO);
			}
			else
			{
				ti=abs(pos[nextB]-posB)+1;
				posB=pos[nextB];
				if (nextO<n)
				{
					if (ti>=abs(pos[nextO]-posO))
						posO=pos[nextO];
					else if (abs(pos[nextO]-posO-ti)<abs(pos[nextO]-posO+ti))
						posO+=ti;
					else
						posO-=ti;
				}
				ans+=ti;
				nextB=findNext('B', nextB);	
			}
		}
		printf("Case #%d: %d\n",count,ans);
	}
	return 0;
}	
