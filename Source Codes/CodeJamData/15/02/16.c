#include <stdio.h>

int main(){
	int t,tt,d,i,j,m,res,tmp;
	int p[1008];
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++){
		scanf("%d",&d);
		m=0;
		for(i=0;i<d;i++){
			scanf("%d",&p[i]);
			if(m<p[i])m=p[i];
		}
		res=m+1;
		for(j=m;j>=1;j--){
			tmp=j;
			for(i=0;i<d;i++)tmp+=((p[i]-1)/j);
			if(res>tmp)res=tmp;
		}
		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}
