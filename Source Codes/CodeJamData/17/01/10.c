#include <stdlib.h>
#include <stdio.h>

#define F0(i,n) for(int i=0;i<n;i++)

int find(int *l,int start, int size,int value){
	for(int i=start;i<size;i++)if(l[i]==value)return i;
	return -1;
}

int main(){
	int T,K,S;
	char tmp;
	int *P = malloc(1000*sizeof(int));
	scanf("%d\n",&T);
	F0(i,T){
		printf("Case #%d: ",i+1);
		S=0;
		scanf("%c",&tmp);
		while(tmp == '+' || tmp == '-'){
			if(tmp == '+')P[S] = 1;
			else P[S] = -1;
			S++;
			scanf("%c",&tmp);
		}
		// S will be the number of pancakes (the length of P)
		scanf("%d\n",&K);
		int flips = 0;
		int index = 0;
		while((index = find(P,index,S,-1)) != -1){
			if(index + K > S){
				// we cannot flip
				flips = -1;
				break;
			}else{
				F0(j,K)P[index+j] = -P[index+j];
				flips++;
			}
		}
		if(flips == -1)printf("IMPOSSIBLE\n");
		else printf("%d\n",flips);
	}
}
