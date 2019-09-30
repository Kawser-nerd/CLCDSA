#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int D,N;
		scanf("%d %d\n",&D,&N);
		double max_t=0;
		for(int i=0;i<N;i++){
			int K,S;
			scanf("%d %d\n",&K,&S);
			double time=(D-K)/(double)S;
			if(max_t<time) max_t=time;
		}
		double speed=D/max_t;
		printf("Case #%d: %f\n",t,speed);
	}
}