#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

//????
int cocomp(ll*a,int n){
	ll*b=(ll*)malloc(sizeof(ll)*n);
	memcpy(b,a,sizeof(ll)*n);
	sortup(b,n);
	int cnt=1;
	rep(r,1,n)if(b[r]!=b[cnt-1])b[cnt++]=b[r];
	rep(i,0,n){
		int l=0,r=cnt;
		while(r-l>1){int m=(l+r)/2;if(b[m]>a[i])r=m;else l=m;}
		a[i]=l+1;
	}
	free(b);
	return cnt;
}


//seg?
int segNUM;	
ll seg[1<<20],*segN;
//??segNUM<=2^19(2??)???
void seguse(int n){if(n==(n&-n)){segNUM=n;segN=seg+segNUM-1;}}
//segN[]?????????????????????????????
void seginit(){
	for(int node=segNUM-1;node--;)seg[node]=seg[node*2+1]+seg[node*2+2];//sum
}

//segN[node]?x???
void segupdate(int node,ll x){
	node+=segNUM-1;
	seg[node]=x;
	while(node>0){
		node=(node-1)/2;
		seg[node]=seg[node*2+1]+seg[node*2+2];//??
//		seg[node]=min(seg[node*2+1],seg[node*2+2]);//min
	}
}

ll subq(int a,int b,int k,int l,int r){
	//seg[k]?[l,r)?????
	//disjoint?????????
	if(r<=a||b<=l)return 0;//sum

	if(a<=l&&r<=b)return seg[k];//?????
	int left=subq(a,b,k*2+1,l,(l+r)/2),right=subq(a,b,k*2+2,(l+r)/2,r);
	return left+right;//sum
}

//[a,b)???????
ll query(int a,int b){return subq(a,b,0,0,segNUM);}


ll a[200010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		a[i+1]=a[i]+t-k;
	}
	cocomp(a,n+1);
	
	seguse(1<<18);
	ll ans=0;
	rep(i,0,n+1){
		ans+=query(0,a[i]+1);
		segupdate(a[i],segN[a[i]]+1);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:65:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:68:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^