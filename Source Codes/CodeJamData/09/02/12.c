#include <stdio.h>
#include <memory.h>
int map[100][100];
char area[100][100];
int h,w;
int t;
int i,j,k;
char sum;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
char findlowest(int x,int y)
{
	int min;
	int mini;
	int i;
	min=20000; mini=-1;
	for (i=0;i<4;i++)
	{
		if (x+dx[i]>=0 && x+dx[i]<h && y+dy[i]>=0 && y+dy[i]<w)
		{
			if (map[x+dx[i]][y+dy[i]]<map[x][y]&&min>map[x+dx[i]][y+dy[i]]) 
			{
				min=map[x+dx[i]][y+dy[i]];
				mini=i;
			}
		}
	}
	if (mini==-1) return (area[x][y]=sum++);
	if (area[x+dx[mini]][y+dy[mini]]==0) return (area[x][y]=findlowest(x+dx[mini],y+dy[mini]));
	else return (area[x][y]=area[x+dx[mini]][y+dy[mini]]);
}

void main()
{
	freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);

	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		scanf("%d %d",&h,&w);
		for (j=0;j<h;j++)
			for (k=0;k<w;k++)
			{
				scanf("%d",&map[j][k]);
			}
		sum='a';
		//2 fill
		memset(area,0,sizeof(area));
		for (j=0;j<h;j++)
			for (k=0;k<w;k++)
			{
				if (area[j][k]==0) 
					area[j][k]=findlowest(j,k);
			}		
		//3 print
		printf("Case #%d:\n",i);
		for (j=0;j<h;j++)
		{
			for (k=0;k<w;k++)
			{
				printf("%c ",area[j][k]);
			}	
			printf("\n");
		}
	}
}
