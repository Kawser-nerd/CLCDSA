#include <stdio.h>
#include <stdlib.h>
#define MAX(u,v) (((u)>(v))?(u):(v)) 
#define MOD (1000002013)
typedef struct pair{
	long long a,p;
}PAIR;
PAIR p[2008];
int stack[2008];

int comp(const void *_p,const void *_q){
	PAIR *p=(PAIR *)_p,*q=(PAIR *)_q;
	if(p->a>q->a)return 1;
	if(p->a<q->a)return -1;
	return 0;
}

int main(){
	int i,j,pn,sn,f,t,t2,n,m;
	long long tmp,tmp2,tmp3,tmp4,o,e,pp;
	scanf("%d",&t);
	for(t2=1;t2<=t;t2++){
		tmp3=tmp4=0;pn=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
			scanf("%lld%lld%lld",&o,&e,&pp);
			tmp=e-o;
			tmp2=(tmp*n-tmp*(tmp-1)/2)%MOD;
			tmp3=(tmp3+tmp2*pp)%MOD;
			//REC o
			f=0;
			for(j=0;j<pn;j++){
				if(p[j].a==o){p[j].p+=pp;f=1;break;}
			}
			if(!f){
				p[pn].a=o;p[pn++].p=pp;
			}
			//Rec e
			f=0;
			for(j=0;j<pn;j++){
				if(p[j].a==e){p[j].p-=pp;f=1;break;}
			}
			if(!f){
				p[pn].a=e;p[pn++].p=-pp;
			}
		}
		qsort(p,pn,sizeof(PAIR),comp);
		sn=0;
		for(i=0;i<pn;i++){
			if(p[i].p==0)continue;
			if(p[i].p>0){
				stack[sn++]=i;
			}else{
				f=1;
				while(p[stack[sn-1]].p+p[i].p<=0){
					sn--;
					p[i].p+=p[stack[sn]].p;
					tmp=p[i].a-p[stack[sn]].a;
					tmp2=(tmp*n-tmp*(tmp-1)/2)%MOD;
					tmp4=(tmp4+tmp2*(p[stack[sn]].p%MOD))%MOD;
					p[stack[sn]].p=0;
					if(sn==0){f=0;break;}
				}
				if(f){
					tmp=p[i].a-p[stack[sn-1]].a;
					tmp2=(tmp*n-tmp*(tmp-1)/2)%MOD;
					tmp4=(tmp4+tmp2*((-p[i].p)%MOD))%MOD;
					p[stack[sn-1]].p+=p[i].p;
				}
			}
		}
		printf("Case #%d: %lld\n",t2,(tmp3+MOD-tmp4)%MOD);
	}
	return 0;
}