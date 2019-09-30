#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=50+5;
const int oo=10000000;

int opt[maxn][maxn][maxn][2][2];
char map[maxn][maxn];
int n,m,F;
int t,cases;

void prepare()
{
	scanf("%d%d%d",&n,&m,&F);
	for (int i=0;i<n;i++)
		scanf("%s",&map[i]);
	for (int i=0;i<m;i++) map[n][i]='#';

	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++)
	for (int k=0;k<=m;k++)
	for (int a=0;a<2;a++)
	for (int b=0;b<2;b++)
		opt[i][j][k][a][b]=oo;
}

int fall(int u,int v)
{
	int now=u+1;
	while (now+1<n && map[now+1][v]=='.') now++;
	return now;
}

void work()
{
	if (n==1) {printf("Case #%d: Yes 0\n",++cases);return;}

	int tmp=0;
	for (int i=0;i<m && map[0][i]=='.' && map[1][i]=='#';i++) tmp++;
	opt[0][0][tmp][0][0]=0;
	for (int i=0;i+1<n;i++)
	for (int j=0;j<m;j++)
	for (int k=1;k<=m;k++)
	for (int a=0;a<2;a++)
	for (int b=0;b<2;b++)
	if (opt[i][j][k][a][b]<oo)
	{
		//printf("%d %d %d\n",i,j,k);

		if (j && map[i+1][j-1]=='.' && (a || map[i][j-1]=='.'))		//直接向左跳
		{
			int _i=fall(i,j-1);
			if (_i-i<=F)
			{
				int _j=j-1;
				while (_j && map[_i][_j-1]=='.' && map[_i+1][_j-1]=='#') _j--;
				int _k=0;
				for (int u=_j;u<m && map[_i][u]=='.' && map[_i+1][u]=='#';u++) _k++;
				int _a=(_j && map[_i][_j-1]=='.');
				int _b=(_j+_k<m && map[_i][_j+_k]=='.');
				opt[_i][_j][_k][_a][_b]=min(opt[_i][_j][_k][_a][_b],opt[i][j][k][a][b]);
			}
		}
		if (j+k<m && map[i+1][j+k]=='.' && (b || map[i][j+k]=='.'))		//直接向右跳
		{
			int _i=fall(i,j+k);
			if (_i-i<=F)
			{
				int _j=j+k;
				while (_j && map[_i][_j-1]=='.' && map[_i+1][_j-1]=='#') _j--;
				int _k=0;
				for (int u=_j;u<m && map[_i][u]=='.' && map[_i+1][u]=='#';u++) _k++;
				int _a=(_j && map[_i][_j-1]=='.');
				int _b=(_j+_k<m && map[_i][_j+_k]=='.');
				opt[_i][_j][_k][_a][_b]=min(opt[_i][_j][_k][_a][_b],opt[i][j][k][a][b]);
			}
		}
		
		for (int u=j;u<j+k-1;u++)
		for (int v=u;v<j+k-1;v++)
		{
			int _i=fall(i,v);
			if (_i-i<=F)
			{
				int _j=v;
				while (_j && (map[_i][_j-1]=='.' || (_i==i+1 && _j-1>=u)) && map[_i+1][_j-1]=='#') _j--;
				int _k=0;
				for (int w=_j;w<m && (map[_i][w]=='.' || (_i==i+1 && w<=v)) && map[_i+1][w]=='#';w++) _k++;
				int _a=(_j && map[_i][_j-1]=='.');
				int _b=(_j && map[_i][_j-1]=='.');
				if (_i==i+1 && _j>u) _a=true;
				if (_i==i+1 && _j+_k-1<v) _b=true;
				opt[_i][_j][_k][_a][_b]=min(opt[_i][_j][_k][_a][_b],opt[i][j][k][a][b]+v-u+1);
			}
		}

		for (int v=j+k-1;v>j;v--)
		for (int u=v;u>j;u--)
		{
			int _i=fall(i,u);
			if (_i-i<=F)
			{
				int _j=u;
				while (_j && (map[_i][_j-1]=='.' || (_i==i+1 && _j-1>=u)) && map[_i+1][_j-1]=='#') _j--;
				int _k=0;
				for (int w=_j;w<m && (map[_i][w]=='.' || (_i==i+1 && w<=v)) && map[_i+1][w]=='#';w++) _k++;

				int _a=(_j && map[_i][_j-1]=='.');
				int _b=(_j && map[_i][_j-1]=='.');
				if (_i==i+1 && _j>u) _a=true;
				if (_i==i+1 && _j+_k-1<v) _b=true;
				opt[_i][_j][_k][_a][_b]=min(opt[_i][_j][_k][_a][_b],opt[i][j][k][a][b]+v-u+1);
			}
		}
	}

	int res=oo;
	for (int i=0;i<m;i++)
	for (int j=1;j<=m;j++)
	for (int a=0;a<2;a++)
	for (int b=0;b<2;b++)
	{
		//if (opt[n-1][i][j]<res)
		//	printf("%d %d\n",i,j);
	
		res=min(res,opt[n-1][i][j][a][b]);
	}

	if (res==oo) printf("Case #%d: No\n",++cases);
	else printf("Case #%d: Yes %d\n",++cases,res);
}


int main()
{
	freopen("input.txt","r",stdin);

	for (scanf("%d",&t);t;t--)
	{
		prepare();
		work();
	}
}