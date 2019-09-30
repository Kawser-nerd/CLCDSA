#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
const int MAX=1600;

int R,C;
char s[1000];
int a[MAX][MAX];
int px,py;

int check(int x,int y)
{
	int ans=1,i,j,k;
	for(i=2;i<=R-x+1&&i<=C-y+1;i++)
	{
		bool f=0;
		for(j=x;j<=x+i-1;j++)
		{
			if(a[j][y+i-1]+a[j][y+i-2]!=1) {f=1;break;}
		}
		for(j=y;j<=y+i-1;j++)
		{
			if(a[x+i-1][j]+a[x+i-2][j]!=1) {f=1;break;}
		}
		if(f) break;
		ans=i;
	}
	return ans;
}
int gs()
{
	int i,j,res=0;
	for(i=1;i<=R;i++)
	{
		for(j=1;j<=C;j++)
		{
			if(a[i][j]<0) continue;
			int tt=check(i,j);
			if(res<tt)
			{
				res=tt;
				
				px=i;
				py=j;
			}
		}
	}
	return res;
}
void doit(int L)
{
	int i,j;
	for(i=px;i<=px+L-1;i++)
	{
		for(j=py;j<=py+L-1;j++)
		{
			a[i][j]=-50000;
		}
	}
}
int main()
{
	//freopen("F:\\B-large.in","r",stdin);
	//freopen("F:\\B-large.out","w",stdout);
	
	freopen("F:\\C-small-attempt0.in","r",stdin);
	freopen("F:\\C-small-attempt0.out","w",stdout);
	int i,j,T;
	int CN=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&R,&C);
		
		for(i=1;i<=R;i++)
		{
			scanf("%s",s+1);
			int tt;
			for(j=1;j<=C/4;j++)
			{
				if(s[j]>='A'&&s[j]<='F') tt=s[j]-'A'+10;
				else tt=s[j]-'0';
				a[i][4*j-3]=(tt>>3)&1;
				a[i][4*j-2]=(tt>>2)&1;
				a[i][4*j-1]=(tt>>1)&1;
				a[i][4*j]=tt&1;
			}
		}
		map<int,int> my;
		map<int,int>::iterator it;
		int total=R*C;
		while(1)
		{
			int ma=gs();
			if(ma==0) break;
			if(ma==1)
			{
				my[1]=total;
				break;
			}
			total-=ma*ma;
			it=my.find(ma);
			if(it==my.end())
			{
				my[ma]=1;
			}
			else
			{
				my[ma]++;
			}
			doit(ma);
		}
		printf("Case #%d: %d\n",++CN,my.size());
		it=my.end();
		
		while(1)
		{
			it--;
			printf("%d %d\n",it->first,it->second);
			if(it==my.begin()) break;
		}
		
	}
	//system("pause");
	return 0;
}
