#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)

int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

ll d[1000000];
ll cnt;

ll ans[10];
int main(){
	ll h,w,n;
	scanf("%lld%lld%lld",&h,&w,&n);
	while(n--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		rep(dx,-1,2)rep(dy,-1,2)d[cnt++]=((x+dx)<<32)|(y+dy);
	}
	sortup(d,cnt);
	
	int c=1;
	rep(i,0,cnt){
		if(d[i]==d[i+1])c++;
		else{
			int x,y;
			x=d[i]>>32;
			y=d[i]&0xFFFFFFFF;
			if(2<=x&&x<=h-1&&2<=y&&y<=w-1)ans[c]++;
			c=1;
		}
	}
	ll s=0;
	rep(i,1,10)s+=ans[i];
	ans[0]=(h-2)*(w-2)-s;
	rep(i,0,10)printf("%lld\n",ans[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&h,&w,&n);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^