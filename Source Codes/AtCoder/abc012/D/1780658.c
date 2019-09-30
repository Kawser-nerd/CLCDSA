#include <stdio.h>
#include <stdlib.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define loINF (long)10000000000
#define shINF (short)10000
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/*global*/
long dist[310][310];	//????????????
short V;			//???

short Warshall_Floyd (void){
	//????-1?????????0??????
	short i,j,k;

	REP(k,V){
		REP(i,V){
			REP(j,V){
				dist[i][j] = MIN(dist[i][j],dist[i][k] + dist[k][j]);

				#ifdef DEBUG
				printf("dist[%d][%d] ==> %ld\n",i,j,dist[i][j]);
				#endif //DEBUG

				if (dist[i][j] < 0){
					return (-1);
				}
			}
		}
	}
	return 0;
}

int main (void){
	short i,j;
	long E;
	short edge1,edge2;
	long weight,ans;
	long tmp;

	scanf("%hd",&V);	//??????
	scanf("%ld",&E);	//

	/*???*/
	REP(i,V){
		REP(j,V){
			dist[i][j] = loINF;
		}
		dist[i][i] = 0;
	}
	/*????*/
	REP(i,E){
		scanf("%hd%hd%ld",&edge1,&edge2,&weight);
		dist[edge1-1][edge2-1] = weight;
		dist[edge2-1][edge1-1] = weight;
	}


	#ifdef DEBUG
		printf("??????????\n");
		REP(i,V) 
			REP(j,V) 
				printf("dist[%d][%d] ==> %ld\n",i,j,dist[i][j]);
	#endif

	j = Warshall_Floyd();

	ans = loINF;
	tmp = 0;

	REP(i,V){
		REP(j,V){
			if (tmp < dist[i][j]) tmp = dist[i][j];
		}
		if (tmp < ans) ans = tmp;
		tmp = 0;
	}

	printf("%ld\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd",&V); //??????
  ^
./Main.c:43:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&E); //
  ^
./Main.c:54:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd%hd%ld",&edge1,&edge2,&weight);
   ^