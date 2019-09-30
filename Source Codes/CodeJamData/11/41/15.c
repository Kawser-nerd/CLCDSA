#include<stdio.h>
struct A{
	int b,e,w;
}walk[1000];
int cmp(const void *a, const void *b){
	return (((struct A*)a)->w-((struct A*)b)->w);
}
int main(){
	int T,pp;
	scanf("%d",&T);
	for(pp=1;pp<=T;pp++){
		int x,s,r,_t,n;
		double t;
		memset(walk,0,sizeof(walk));
		scanf("%d%d%d%d%d",&x,&s,&r,&_t,&n);
		t=_t;
		int i;
		double plain=x;
		for(i=0;i<n;i++){
			scanf("%d%d%d",&walk[i].b,&walk[i].e,&walk[i].w);
			plain-=walk[i].e-walk[i].b;
		}
		qsort(walk,n,sizeof(struct A),cmp);
		double ans=0;
		double time=plain/(double)r;
		if(time>t){
			time=t+(plain-r*t)/(double)s;
			t=0;
		}else{
			t-=time;
		}
		ans+=time;
		for(i=0;i<n;i++){
			double time=((double)(walk[i].e-walk[i].b))/(double)(r+walk[i].w);
			if(time>t){
				time=t+((double)(walk[i].e-walk[i].b)-(r+walk[i].w)*t)/(double)(s+walk[i].w);
				t=0;
			}else
				t-=time;
			ans+=time;
		}
		printf("Case #%d: %.8lf\n",pp,ans);
	}
	return 0;
}


