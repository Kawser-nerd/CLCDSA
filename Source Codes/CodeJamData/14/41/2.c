#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int s[10008];
int c[10008];

int comp(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}

int main(){
	int TT,T,x,n,i,j,res,tmp;
	scanf("%d",&T);
	for(TT=1;TT<=T;TT++){
		scanf("%d%d",&n,&x);
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)scanf("%d",&s[i]);
		qsort(s,n,4,comp);
		res=0;
		for(i=n-1;i>=0;i--){
			if(c[i])continue;
			res++;
			tmp=-1;
			for(j=0;j<i;j++){
				if(!c[j]&&s[j]+s[i]<=x){
					tmp=j;
				}
			}
			if(tmp<0){
				continue;
			}
			c[i]=c[tmp]=1;
		}
		printf("Case #%d: %d\n",TT,res);
	}
	return 0;
}
