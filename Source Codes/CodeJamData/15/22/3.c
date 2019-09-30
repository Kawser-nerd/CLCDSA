#include <stdio.h>

int bitcount(int x, int n){
	int i,s=0;
	for(;x>0;x=x>>1){s += (x&1); }
	return s;
}

int main(){
	int i,j,k,t,T,R,C,N;
	int x,n;

	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d %d %d", &R, &C, &N);
		int smin = 1000000;
		int sminbit;
		for(i=0;i<(1<<R*C);i++){
			int s = 0;
			if(bitcount(i,R*C) != N) continue;
			//printf("%x\n",i);
			for(j=0;j<R;j++){
				for(k=0;k<C-1;k++){
					s += ((i>>(j*C+k))&1) & ((i>>(j*C+k+1))&1);
				}
			}
			for(j=0;j<R-1;j++){
				for(k=0;k<C;k++){
					s += ((i>>(j*C+k))&1) & ((i>>((j+1)*C+k))&1);
				}
			}
			if(smin > s){
				smin = s;
				sminbit = i;
			}
		}
		//printf("%d %x\n",smin, sminbit);
		printf("Case #%d: %d\n", t, smin);
	}
}
