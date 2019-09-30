#include <stdio.h>

#define MAX 100
#define K 200
long MAXT=MAX*MAX*MAX*2;

long N,M,H;
long F[MAX][MAX], C[MAX][MAX];
long reached[K][MAX][MAX];
long dx[4] = {0,0,1,-1};
long dy[4] = {1,-1,0,0};
double ans; 

long input()
{
	long i,j,k;
	scanf("%ld %ld %ld", &H, &N, &M);
	for (i=0; i<N; i++)
		for (j=0; j<M; j++)
			scanf("%ld", &C[i][j]);
	for (i=0; i<N; i++)
		for (j=0; j<M; j++)
			scanf("%ld", &F[i][j]);
	for (k=0; k<K; k++)
		for (i=0; i<MAX; i++)
			for (j=0; j<MAX; j++)
				reached[k][i][j]=0;
}

long cango(long x, long y, long d, long H)
{
	if (H<0) H=0;
	//if ((x==1)&&(y==1)&&(d==0)) printf(" here0\n");
	long tx = x+dx[d];
	long ty = y+dy[d];
	if (tx<0) return 0;
	if (ty<0) return 0;
	if (tx>=N) return 0;
	if (ty>=M) return 0;
	
	//if ((x==1)&&(y==1)&&(ty==2)) printf(" here1\n");
	if (C[tx][ty]-H<50) return 0;
	//if ((x==1)&&(y==1)&&(ty==2)) printf(" here2\n");
	if (C[tx][ty]-F[x][y]<50) return 0;
	//if ((x==1)&&(y==1)&&(ty==2)) printf(" here3\n");
	if (C[tx][ty]-F[tx][ty]<50) return 0;
	//if ((x==1)&&(y==1)&&(ty==2)) printf(" here4\n");
	if (C[x][y]-F[tx][ty]<50) return 0;
	//if ((x==1)&&(y==1)&&(ty==2)) printf(" here5\n");
	
	if (H-F[x][y]>=20) return 10;
	else return 100;
}

long idx(long H)
{
	return (H+MAXT*K)%K;
}

long go(long d, long H)
{
	long list[MAX*MAX][2];
	long h=0, t=0;
	long i,j;
	long tx, ty;
	long time;
	
	long idxH=idx(H);
	long idxH1 = idx(H-1);
	
	for (i=0; i<N; i++)
		for (j=0; j<M; j++)
			if (reached[idxH][i][j]==1) {
				list[t][0] = i;
				list[t][1] = j;
				t++;
				reached[idxH1][i][j] = 1;
			}
	while (h<t)
	{
		for (i=0; i<4; i++)
		{
			time = cango(list[h][0], list[h][1], i, H);
			if (time>0) {
				tx = list[h][0]+dx[i];
				ty = list[h][1]+dy[i];
				if (d==0) {
					if (reached[idxH][tx][ty] == 0) {
						list[t][0] = tx; 
						list[t][1] = ty;
						reached[idxH][tx][ty] = 1;
						reached[idxH1][tx][ty] = 1;
						t++;
					}
				}
				else {
					reached[idx(H-time)][tx][ty] = 1;
					//if (time==10) {
						//printf("----%ld %ld %ld\n",tx,ty,H);
					//}
				}
			}
		}
		h++;
	}
	//printf("H %ld total %ld\n", H, t);
}

long clear(long h)
{
	long x = idx(h);
	long i,j;
	for (i=0; i<N; i++)
		for (j=0; j<M; j++)
			reached[x][i][j] = 0;
}

long work()
{
	MAXT = N*M*MAX*2;
	reached[idx(H)][0][0] = 1;
	go(0,H);
	
	long h; 
	for (h=H; h>=-MAXT; h--)
	{
		if (reached[idx(h)][N-1][M-1]==1) 
		{
			ans = ((double)(H-h))/10.0;
			return 0;
		}
		go(1,h);
		clear(h);
	}
	//printf("!!!!!!!!!! %ld", H);
}

int main() 
{
	long T,i;
	
	scanf("%d", &T);
	for (i=0; i<T; i++)
	{
		input();
		
		ans = 0;
		work();
		printf("Case #%ld: %.7lf\n", i+1, ans);		
	}
	return 0;
}