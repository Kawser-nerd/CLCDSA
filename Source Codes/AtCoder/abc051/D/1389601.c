#include<stdio.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF (int)1e9
#define MIN(a,b) (((a)<(b)) ? (a):(b))

int main(){
	int n,m,a[1002],b[1002],c[1002],root[102][102];

	FOR(i,0,102){
		FOR(j,0,102){
			if(i == j) root[i][j] = 0;
			else root[i][j] = INF;
		}
	}

	scanf("%d %d",&n,&m);
	FOR(i,0,m){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		root[a[i]][b[i]] = c[i];
		root[b[i]][a[i]] = c[i];
	}

	FOR(k,1,n+1)	//???
		FOR(i,1,n+1)	//??
			FOR(j,1,n+1)	//??
				root[i][j] = MIN(root[i][j],root[i][k]+root[k][j]);

	int ans = m;

	FOR(k,0,m)	//?????
			FOR(i,1,n+1)	//??
				if(root[i][a[k]] + c[k] == root[i][b[k]]){	//?????????
					ans--;
					break;
				}

	printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a[i],&b[i],&c[i]);
   ^