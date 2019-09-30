#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define PI 3.14159265358979323


typedef struct point{double x,y;ll n;}P;

//?????????????????????????index????????????
//O(nlogn)????????
#define menseki(p,q)(p.x*q.y-p.y*q.x)
#define EPS 1e-6
ll pindex[110];
int pointhikaku(const void*p,const void*q){
	//??????
	P pp=*(P*)p,qq=*(P*)q;
	if(pp.x<qq.x)return -1;
	if(pp.x>qq.x)return  1;
	if(pp.y<qq.y)return -1;
	return 1;
} 
int pointhikaku2(const void*p,const void*q){
	//arg????
	P pp=*(P*)p,qq=*(P*)q;
	double diff=atan2(pp.y,pp.x)-atan2(qq.y,qq.x);
	return diff>0?1:diff<0?-1:0;
}
ll totuhou(P*a,ll cnt){
	//https://www.jaist.ac.jp/~uehara/course/2014/i481f/pdf/ppt-3.pdf???
	if(cnt<=2){
		rep(i,0,cnt)pindex[i]=i;
		return cnt;
	}
	
	P*t=(P*)malloc(cnt*sizeof(P));
	P O;
	O.x=0,O.y=0;
	rep(i,0,cnt){O.x+=a[i].x/cnt;O.y+=a[i].y/cnt;}

	rep(i,0,cnt){
		t[i].x=a[i].x-O.x;
		t[i].y=a[i].y-O.y;
		t[i].n=a[i].n;
	}

	qsort(t,cnt,sizeof(P),pointhikaku2);
	//????????x???????????????
		
	//x????????
	double mx=10000000;
	ll mi;
	rep(i,0,cnt)if(t[i].x<mx){
		mx=t[i].x;
		mi=i;
	}

	ll anscnt=2;
	pindex[0]=mi;
	pindex[1]=(mi+1)%cnt;
	rep(i,2,cnt+1){
		//???????2????????3???or????1???????????
		//O??????????3?ABC????OAB+?OBC>?OAC
		while(anscnt>=2){
			ll a=pindex[anscnt-2];
			ll b=pindex[anscnt-1];
			ll c=(mi+i)%cnt;
			if(menseki(t[a],t[b])+menseki(t[b],t[c])>menseki(t[a],t[c])+EPS)break;
			anscnt--;
		}
		pindex[anscnt++]=(mi+i)%cnt;
	}
	//???????????????anscnt(=??????)?2
	//???????4?????????????????+1(pindex[0]==pindex[anscnt-1])
	if(anscnt>2){
		rep(i,0,anscnt)pindex[i]=t[pindex[i]].n;//??index???
		return anscnt-1;
	}else{
		//??????????
		//???????????
		qsort(t,cnt,sizeof(P),pointhikaku);
		pindex[0]=t[    0].n;
		pindex[1]=t[cnt-1].n;
		return 2;
	}
}


P ppp[110];
double ans[110];

double kakudo(ll a,ll b,ll c){
	//??????3?a,b,c?????????
	double siita=atan2(ppp[a].y-ppp[b].y,ppp[a].x-ppp[b].x)-atan2(ppp[c].y-ppp[b].y,ppp[c].x-ppp[b].x);
	while(siita>2*PI)siita-=2*PI;
	while(siita<0)siita+=2*PI;
	return siita;
}

int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);
		ppp[i].x=x;
		ppp[i].y=y;
		ppp[i].n=i;
	}

	ll x=totuhou(ppp,n);
	rep(i,0,x){
		ll a=pindex[(i-1+x)%x];
		ll b=pindex[i];
		ll c=pindex[(i+1)%x];
		ans[b]=(PI-kakudo(a,b,c))/(2*PI);
	}
	rep(i,0,n)printf("%.9f\n",ans[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:104:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:107:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^