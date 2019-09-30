#include <stdio.h>
#include <stdlib.h>
int main(){
	int C,c;
	int N,K,B,T;
	int *X,*V,*e,*d;
	int i,p,k,swapped,no_swaps,tmp;
	scanf("%d",&C);
	for (c=1;c<=C;c++){
		scanf("%d",&N);
		scanf("%d",&K);
		scanf("%d",&B);
		scanf("%d",&T);
		X=(int*)malloc(N*sizeof(int));
		V=(int*)malloc(N*sizeof(int));
		d=(int*)calloc(N,sizeof(int));
		e=(int*)calloc(N,sizeof(int));
		for (i=0;i<N;i++)
			scanf("%d",&X[i]);
		for (i=0;i<N;i++)
			scanf("%d",&V[i]);
		p=0;
		for(i=0;i<N;i++){
			if (V[i]*T+X[i]<B)
				d[i]=0;
			else{
				d[i]=1;
				p++;
			}
		}
		if (p<K){
			printf("Case #%d: IMPOSSIBLE\n",c);
			continue;
		}

		for (i=N-1,p=0,k=0;p<K;i--,k++){
			e[k]=d[i];
			if (e[k]==1)
				p++;
		}
		
		no_swaps=0;
		do{
			swapped=0;
			for(i=0;i<k-1;i++)
				if(e[i]<e[i+1]){
					swapped=1;
					tmp=e[i];
					e[i]=e[i+1];
					e[i+1]=tmp;
					no_swaps++;
				}
		}while(swapped);
		free(X);
		free(V);
		free(d);
		free(e);
		printf("Case #%d: %d\n",c,no_swaps);
	}
	return 0;
}
