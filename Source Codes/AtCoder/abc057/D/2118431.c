#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

ll choose(int n,int r){
	if(n<r)return 0;
	ll s=1;
	rep(i,0,r)s=s*(n-i)/(i+1);
	return s;
}

ll v[60];
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	rep(i,1,n+1)scanf("%lld",v+i);
	sortdown(v+1,n);
	
	ll s=0;
	rep(i,1,a+1)s+=v[i];
	printf("%.9f\n",(double)s/a);
	
	ll m=v[a];
	int l=a,r=a;
	while(l>1&&v[l-1]==m)l--;
	while(r<n&&v[r+1]==m)r++;
	if(l==1){
		//r??????a???b?????
		ll ans=0;
		rep(i,a-l+1,b-l+2)ans+=choose(r-l+1,i);
		printf("%lld\n",ans);
	}else{
		//r-l+1??????a-l+1???
		printf("%lld\n",choose(r-l+1,a-l+1));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^
./Main.c:20:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,1,n+1)scanf("%lld",v+i);
              ^