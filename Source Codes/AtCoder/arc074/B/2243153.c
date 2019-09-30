#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll heapN,heap[1<<20];
int PQhikaku(int i,int j){return heap[i]<heap[j];}//j???????????true?
void heap_utod(int n){
	if(2*n>heapN)return;
	int rflag=(2*n+1<=heapN)&&(PQhikaku(2*n,2*n+1));
	if(PQhikaku(n,2*n+rflag)){
		ll temp=heap[2*n+rflag];
		heap[2*n+rflag]=heap[n];
		heap[n]=temp;
		heap_utod(2*n+rflag);
	}
}
void heap_dtou(int n){
	if(n==1||PQhikaku(n,n/2))return;
	ll temp=heap[n];
	heap[n]=heap[n/2];
	heap[n/2]=temp;
	heap_dtou(n/2);
}
ll PQpop(){
	ll rr=heap[1];
	heap[1]=heap[heapN--];
	heap_utod(1);
	return rr;
}
void PQpush(ll n){
	heap[++heapN]=n;
	heap_dtou(heapN);
}


ll a[300010];
ll l[300010],r[300010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,3*n)scanf("%d",a+i);
	
	ll s=0;
	rep(i,0,n){
		s+=a[i];
		PQpush(-a[i]);
	}
	l[n]=s;
	rep(i,n,2*n){
		s+=a[i];
		PQpush(-a[i]);
		s+=PQpop();
		l[i+1]=s;
	}
	rep(i,0,n)PQpop();
	
	s=0;
	for(int i=3*n-1;i>=2*n;i--){
		s+=a[i];
		PQpush(a[i]);
	}
	r[2*n]=s;
	for(int i=2*n-1;i>=n;i--){
		s+=a[i];
		PQpush(a[i]);
		s-=PQpop();
		r[i]=s;
	}
	
	ll ans=-INF;
	rep(i,n,2*n+1)ans=max(ans,l[i]-r[i]);
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:20: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  rep(i,0,3*n)scanf("%d",a+i);
                    ^
./Main.c:43:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:44:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,3*n)scanf("%d",a+i);
              ^