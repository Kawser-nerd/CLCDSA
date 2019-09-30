#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g[128][128],d[128][128],c[128][128];
char lt[30];
int color;
int H,W;

void init()
{
	int i, j;
	int lowest;
	
	scanf("%d%d", &H,&W);
	for(i=1;i<=H;i++)
		for(j=1;j<=W;j++)
			scanf("%d", &g[i][j]);

	for(i=1;i<=H;i++)
		for(j=1;j<=W;j++) {
			lowest=20000;
			if (i-1>=1 && g[i][j]>g[i-1][j] && g[i-1][j]<lowest) {
				lowest=g[i-1][j];
				d[i][j]=0;
			}
			if (j-1>=1 && g[i][j]>g[i][j-1] && g[i][j-1]<lowest) {
				lowest=g[i][j-1];
				d[i][j]=1;
			}
			if (j+1<=W && g[i][j]>g[i][j+1] && g[i][j+1]<lowest) {
				lowest=g[i][j+1];
				d[i][j]=2;
			}
			if (i+1<=H && g[i][j]>g[i+1][j] && g[i+1][j]<lowest) {
				lowest=g[i+1][j];
				d[i][j]=3;
			}
			if (lowest==20000) d[i][j]=-1;
		}
	memset(c,0,sizeof(c));
	color=0;
}


void fill(int i,int j)
{
	if (c[i][j]) return;
	
	c[i][j]=color;
	if (i-1>=1 && d[i-1][j]==3) fill(i-1,j);
	if (i+1<=H && d[i+1][j]==0) fill(i+1,j);
	if (j-1>=1 && d[i][j-1]==2) fill(i,j-1);
	if (j+1<=W && d[i][j+1]==1) fill(i,j+1);
}

void solve()
{
	int i, j;
	
	for(i=1;i<=H;i++)
		for(j=1;j<=W;j++)
			if (d[i][j]==-1) {
				color++;
				fill(i,j);
			}

}


void print()
{
	int i, j;
	char letter;
	
	for(i=0;i<=color;i++) lt[i]='#';
	letter='a';
	for(i=1;i<=H;i++)
		for(j=1;j<=W;j++) {
			if(lt[c[i][j]]=='#') {
				lt[c[i][j]]=letter++;
			}
			printf("%c%c", lt[c[i][j]],j!=W?' ':'\n');
		}
}

int main()
{
	int x,X;
	
	scanf("%d", &X);
	for(x=1;x<=X;x++) {
		init();
		solve();
		printf("Case #%d:\n",x);
		print();
	}

	return 0;
}
