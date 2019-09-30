#include<stdio.h>
int p[1010],count[1010];
int main(){
	int t,T,n,m,c,x,y,i,r,sum;
	
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d%d%d",&n,&c,&m);
		r = 0;
		for(i=0;i<1010;i++){
			p[i]=0;
			count[i]=0;
		}
		for(i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			count[y]++;
			p[x]++;
			if(r<count[y])
				r = count[y];
		}
		for(i=1,sum=0;i<=n;i++){
			sum+=p[i];
			while(sum>i*r)
				r++;
		}
		for(i=1,sum=0;i<=n;i++){
			if(p[i]>r)
				sum+=p[i]-r;
		}
		printf("Case #%d: %d %d\n",t,r,sum);
		
	}
}
