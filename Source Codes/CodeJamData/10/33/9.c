#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

#define MIN(x,y) ((x)<(y)?(x):(y))
char map[520][520];
char occ[510][520];
int sum[520][520];

int sol[1024]={0};
int table[256]={0};
int N=0,M=0;

void init(){
	char i=0;
	for (i='0';i<='9';i++){
		table[i] = i-'0';
	}

	for (i='A';i<='F';i++){
		table[i] = i-'A'+10;
	}
}

int check(int x,int y,int z){
	int i=0,j=0,k=0;
	if (occ[x][y] == -1) return 0;

	for (i=x;i<x+z;i++){
		if (i>=M || sum[i][y]<z) return 0;
		if (i!=x && (map[i][y] == map[i-1][y])) return 0;
		for (j=y;j<y+z;j++){
			if ( occ[i][j] == -1) return 0;
		}
		
	}

	for (i=x;i<x+z;i++){
		for (j=y;j<y+z;j++){
			occ[i][j] = -1;
		}
	}

	return 1;
}

int main(int argc, char *argv[])
{
	int i=0,j=0,k=0;
	int T=0,xnext=0,ynext=0;
	int cas=1,cnt=0,x=0;
	char buff[1024];

	init();
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&M,&N);
		
		memset(map,0,sizeof(map));
		memset(occ,0,sizeof(occ));
		memset(sum,0,sizeof(sum));
		memset(sol,0,sizeof(sol));
		cnt=0;

		for (i=0;i<M;i++){
			scanf("%s",buff);
			for (j=0;j<N/4;j++){
				x = table[buff[j]];
				for (k=j*4+3;k>=j*4;k--){
					map[i][k] = x %2 + '0';
					x/=2;
				}
			}
		}

		for (i=0;i<M;i++){
			for (j=N-1;j>=0;j--){
				if (j == N-1){
					sum[i][j]=1;
				}else{
					if (map[i][j] != map[i][j+1]){
						sum[i][j] = sum[i][j+1]+1;
					}else{
						sum[i][j] = 1;
					}
				}
			}
		}

		for (k=MIN(N,M);k>=1;k--){
			i=j=0;
			while (i<M){
				j=0;
				while (j<N){
					if (check(i,j,k)!=0){
						sol[k]++;
						xnext = k;
						ynext = k;
					}else{
						xnext = 1;
						ynext = 1;
					}
					j+=1;
				}
				i+=1;
			}
		}

		for (i=MIN(N,M);i>=1;i--){
			if (sol[i] != 0) cnt++;
		}
		printf("Case #%d: %d\n",cas++,cnt);
		for (i=MIN(N,M);i>=1;i--){
			if (sol[i]!=0){
				printf("%d %d\n",i,sol[i]);
			}
		}

	}
	return 0;
}
