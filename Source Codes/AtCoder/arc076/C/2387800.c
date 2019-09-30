#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))

typedef struct piar{ll st,len,i;}P;

ll R,C;
int hikaku(const void*p,const void*q){
	P pp=*(P*)p,qq=*(P*)q;
	if(pp.st<qq.st)return -1;
	if(pp.st>qq.st)return 1;
	if(pp.len<qq.len)return -1;
	if(pp.len>qq.len)return 1;
	return 0;
}

P p[200010];
ll cnt;
void set(int x,int y,int i){
	p[cnt].i=i;
	if(x==0){
		p[cnt].st=0;
		p[cnt].len=y;
	}else if(y==C){
		p[cnt].st=1;
		p[cnt].len=x;
	}else if(x==R){
		p[cnt].st=2;
		p[cnt].len=C-y;
	}else if(y==0){
		p[cnt].st=3;
		p[cnt].len=R-x;
	}
	cnt++;
}


ll que[200010];
ll qcnt;
int main(){
	int n;
	scanf("%lld%lld%d",&R,&C,&n);
	rep(i,0,n){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if((a==0||a==R||b==0||b==C)&&(c==0||c==R||d==0||d==C)){
			set(a,b,i);
			set(c,d,i);
		}
	}
	qsort(p,cnt,sizeof(P),hikaku);
	
	rep(i,0,cnt){
		if(qcnt==0||que[qcnt-1]!=p[i].i)que[qcnt++]=p[i].i;
		else qcnt--;
	}
	puts(qcnt?"NO":"YES");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%d",&R,&C,&n);
  ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^