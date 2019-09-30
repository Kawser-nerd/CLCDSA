#include <stdio.h>
#include <stdlib.h>
#define bool int
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

//??????????????????????
ll heapN,heap[1<<20];
//int PQhikaku(int i,int j);//j???????????true???
int PQhikaku(int i,int j){return heap[i]<heap[j];}
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

ll a[100010];
ll ans[100010];
bool p[100010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%lld",a+i);
	ll M=-1;
	rep(i,0,n+1)if(M<a[i]){
		p[i]=1;
		M=a[i];
	}
	
	ll cnt=0,bi=-1;
	for(ll i=n;i>=0;i--){
		if(p[i]){
			if(bi==-1){
			}else{
				ll temp=(a[bi]-a[i])*cnt;
				while(heapN>0&&heap[1]>=a[i])temp+=PQpop()-a[i],cnt++;
				ans[bi]=temp;
			}
			bi=i;
			cnt++;
		}else{
			PQpush(a[i]);
		}
	}
	rep(i,1,n+1)printf("%lld\n",ans[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:45:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,1,n+1)scanf("%lld",a+i);
              ^