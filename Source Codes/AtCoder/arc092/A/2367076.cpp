#include<cstdio>
#include<cstring>
#define N 105
using namespace std;
int n,o_t[N];
int ans;
bool line[N][N],f[N];
struct node
{
	int x;int y;
}red[N];

struct node blue[N]; 

void read()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&red[i].x,&red[i].y);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&blue[i].x,&blue[i].y);
}
int PD(int x)
{
	for(int j=1;j<=n;j++)
	{
		if(line[x][j]&&!f[j])
		{
			f[j]=1;
			if(o_t[j]==0||PD(o_t[j]))
			{
				o_t[j]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(red[i].x<blue[j].x&&red[i].y<blue[j].y)
			line[i][j]=1;
		}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof f);
		if(PD(i)) ans++;
	}
	printf("%d",ans);
 }