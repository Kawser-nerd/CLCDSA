#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int solve(int *pr,int *prison,int P,int Q,int num,int lucky) {
	int i,j,k,aux,coins,c,min;	
	int *prl,*prisonl;
	prl=(int*)malloc(sizeof(int)*Q);
	prisonl=(int*)malloc(sizeof(int)*P);
	memcpy(prl,pr,Q*sizeof(int));
	memcpy(prisonl,prison,P*sizeof(int));
	aux=prl[num];
	prl[num]=prl[lucky];
	prl[lucky]=aux;
	prisonl[prl[num]-1]=1;
	coins=0;
	i=prl[num]-2;
	while(i>=0 && prisonl[i]==0) {
		coins++;
		i--;
	}
	i=prl[num];
	while(i<P && prisonl[i]==0) {
		coins++;
		i++;
	}
	if(num+1==Q)
		return coins;
	min=solve(prl,prisonl,P,Q,num+1,num+1);
	for(i=num+2;i<Q;i++) {
		c=solve(prl,prisonl,P,Q,num+1,i);
		if(c<min)
			min=c;
	}
	free(prl);
	free(prisonl);
	return coins+min;
}	

int main() {
	int T,P,Q,ca,i,j,k,coins,min;
	int *prison,*pr;
	scanf("%d ",&T);
	for(ca=1;ca<=T;ca++) {
		scanf("%d %d ",&P,&Q);
		prison=(int*)calloc(P,sizeof(int));
		pr=(int*)malloc(Q*sizeof(int));
		for(i=0;i<Q;i++)
			scanf("%d ",pr+i);
		min=solve(pr,prison,P,Q,0,0);
		for(i=0;i<Q;i++) {
			coins=solve(pr,prison,P,Q,0,i);
			if(coins<min)
				min=coins;			
		}
		printf("Case #%d: %d\n",ca,min);
		free(prison);
		free(pr);
	}	
	return 0;
}
