#include <stdio.h>
int main(void){
	int Tn,Ti,A,B,K,i,j,r;
	scanf("%d",&Tn);
	/*
	NOTE: small only
	*/
	for(Ti=1;Ti<=Tn;Ti++){
		scanf("%d %d %d",&A,&B,&K);
		r=0;
		for(i=0;i<A;i++){
			for(j=0;j<B;j++){
				if((i&j)<K)r++;
			}
		}
		printf("Case #%d: %d\n",Ti,r);
	}
}

