#include <stdio.h>
#include <math.h>

#define N_MAX 1000

int xs, ys, xt, yt;
int N;
int x[N_MAX + 2];
int y[N_MAX + 2];
int r[N_MAX + 2];

double cost[N_MAX + 2][N_MAX + 2];
double minDistance[N_MAX + 2];
int kettei[N_MAX + 2];

int main(void) {
	int i, j;
	if(scanf("%d%d%d%d", &xs,&ys,&xt,&yt)!=4)return 1;
	if(scanf("%d", &N)!=1)return 1;
	for(i=0;i<N;i++) {
		if(scanf("%d%d%d", &x[i],&y[i],&r[i])!=3)return 1;
	}
	x[N] = xs;
	y[N] = ys;
	r[N] = 0;
	x[N + 1] = xt;
	y[N + 1] = yt;
	r[N + 1] = 0;
	N += 2;

	for(i=0;i<N;i++) {
		cost[i][i]=0;
		for(j=i + 1;j<N;j++) {
			double abiru = sqrt(((double)x[i]-x[j])*((double)x[i]-x[j])+
				((double)y[i]-y[j])*((double)y[i]-y[j])) - ((double)r[i]+r[j]);
			if (abiru < 0) abiru = 0;
			cost[i][j] = cost[j][i] = abiru;
		}
	}

	for(i=0;i<N;i++)minDistance[i]=-1;
	minDistance[N-2] = 0;
	do {
		double minScore = -1;
		int minPos = -1;
		for(i=0;i<N;i++) {
			if(!kettei[i] && minDistance[i]>=0) {
				if(minScore <0 || minDistance[i]<minScore) {
					minScore=minDistance[i];
					minPos=i;
				}
			}
		}
		if(minPos<0)break;
		kettei[minPos]=1;
		for(i=0;i<N;i++) {
			if(minDistance[i]<0 || minDistance[minPos]+cost[minPos][i]<minDistance[i]) {
				minDistance[i]=minDistance[minPos]+cost[minPos][i];
			}
		}
	} while(!kettei[N-1]);

	printf("%.15f\n", minDistance[N-1]);
	return 0;
}