#include <stdio.h>

#define INF 1234567
#define MIN(A,B) ((A<B)?(A):(B))

int main () {
  int n,m,v;
  int t,i;
  int ins;
  int node[15000][2];
  int cost[15000][2];
  int x;

  scanf("%d", &n);
  for (t=1; t<=n; t++) {
    scanf("%d%d",&m,&v);
    ins=(m-1)/2;
    for (i=0; i<ins;i++)
      scanf("%d%d",node[i]+0, node[i]+1);
    for (i=ins;i<m;i++) {
      scanf("%d", &x);
      cost[i][x]=0;
      cost[i][1-x]=INF;
    }
    for (i=ins-1;i>=0;i--) {
      if (node[i][1]==0) { /*not change*/
	if (node[i][0]==0) { /*OR*/
	  cost[i][0]=cost[i*2+1][0]+cost[i*2+2][0];
	  if (cost[i][0]>=INF) cost[i][0]=INF;
	  cost[i][1]=MIN(cost[i*2+1][1], cost[i*2+2][1]);
	}
	if (node[i][0]==1) { /*AND*/
	  cost[i][1]=cost[i*2+1][1]+cost[i*2+2][1];
	  if (cost[i][1]>=INF) cost[i][1]=INF;
	  cost[i][0]=MIN(cost[i*2+1][0], cost[i*2+2][0]);
	}
      }
      else { /*change*/
	if (node[i][0]==0) { /*OR*/
	  cost[i][0]=MIN(cost[i*2+1][0]+cost[i*2+2][0], 1+ MIN(cost[i*2+1][0], cost[i*2+2][0]));
	  if (cost[i][0]>=INF) cost[i][0]=INF;
	  cost[i][1]=MIN(MIN(cost[i*2+1][1], cost[i*2+2][1]), 1+ cost[i*2+1][1]+cost[i*2+2][1]);
	  if (cost[i][1]>=INF) cost[i][1]=INF;
	}
	if (node[i][0]==1) { /*AND*/
	  cost[i][1]=MIN(cost[i*2+1][1]+cost[i*2+2][1], 1 + MIN(cost[i*2+1][1], cost[i*2+2][1]));
	  if (cost[i][1]>=INF) cost[i][1]=INF;
	  cost[i][0]=MIN(MIN(cost[i*2+1][0], cost[i*2+2][0]), 1 + cost[i*2+1][0]+cost[i*2+2][0]);
	  if (cost[i][0]>=INF) cost[i][0]=INF;
	}


      } 
    }
    printf("Case #%d: ",t);
    if (cost[0][v]>=INF) printf("IMPOSSIBLE\n");
    else printf("%d\n", cost[0][v]);
  }

  return 0;
}
