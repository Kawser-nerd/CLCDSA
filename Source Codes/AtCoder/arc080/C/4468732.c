#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF 1000000

//???????
//*
//???????
typedef struct atai{int o,oi,e,ei;}atai;
atai xx(atai x,atai y){
	atai r;
	if(x.o<y.o){
		r.o=x.o;
		r.oi=x.oi;
	}else{
		r.o=y.o;
		r.oi=y.oi;
	}
	if(x.e<y.e){
		r.e=x.e;
		r.ei=x.ei;
	}else{
		r.e=y.e;
		r.ei=y.ei;
	}
	return r;
}
//???????

int segNUM;
atai segN[1<<19],*seg;
void seguse(int n){segNUM=n;seg=segN+segNUM;}

//seg[]???????????
void seginit(){for(int node=segNUM-1;node;node--)segN[node]=xx(segN[node*2],segN[node*2+1]);}
void segupdate(int node,atai x){
	//seg[node]?x???
	node+=segNUM;
	segN[node]=x;
	while(node/=2)segN[node]=xx(segN[node*2],segN[node*2+1]);
}

atai segcalcsub(int l,int r,int k,int cl,int cr){
	//???????
	if(l<=cl&&cr<=r)return segN[k];

	int cm=(cl+cr)/2;
	//????
	if(r<=cm)return segcalcsub(l,r,2*k  ,cl,cm);
	//????
	if(cm<=l)return segcalcsub(l,r,2*k+1,cm,cr);
	//??
	return xx(segcalcsub(l,r,2*k,cl,cm),segcalcsub(l,r,2*k+1,cm,cr));
}
atai segcalc(int l,int r){return segcalcsub(l,r,1,0,segNUM);}
//???????
//*/




//*
//??????????????????????
ll heap[1<<18];
int cnt;
int al[1<<18],ar[1<<18],ax[1<<18];
//int PQhikaku(int i,int j);//j???????????true???
int PQhikaku(ll*heap,int i,int j){return ax[heap[i]]>ax[heap[j]];}
void heap_utod(ll*heap,int n){
	if(2*n>heap[0])return;
	int rflag=(2*n+1<=heap[0])&&(PQhikaku(heap,2*n,2*n+1));
	if(PQhikaku(heap,n,2*n+rflag)){
		ll temp=heap[2*n+rflag];
		heap[2*n+rflag]=heap[n];
		heap[n]=temp;
		heap_utod(heap,2*n+rflag);
	}
}
void heap_dtou(ll*heap,int n){
	if(n==1||PQhikaku(heap,n,n/2))return;
	ll temp=heap[n];
	heap[n]=heap[n/2];
	heap[n/2]=temp;
	heap_dtou(heap,n/2);
}
ll PQpop(ll*heap){
	ll rr=heap[1];
	heap[1]=heap[heap[0]--];
	heap_utod(heap,1);
	return rr;
}
void PQpush(ll*heap,ll l,ll r){
	al[cnt]=l;
	ar[cnt]=r;
	atai x=segcalc(l,r);
	if(l%2==0)ax[cnt]=x.e;
	else ax[cnt]=x.o;
	heap[++heap[0]]=cnt;
	cnt++;
	heap_dtou(heap,heap[0]);
}
//*/



int main(){
	ll n;
	scanf("%lld",&n);
	seguse(1<<18);
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		if(i%2==0){
			seg[i].o=INF;
			seg[i].e=t;
		}else{
			seg[i].o=t;
			seg[i].e=INF;
		}
		seg[i].ei=seg[i].oi=i;
	}
	rep(i,n,1<<18)seg[i].o=seg[i].e=INF;
	seginit();
	
	PQpush(heap,0,n);
	rep(i,0,n/2){
		int t=PQpop(heap);
		int l=al[t],r=ar[t];
		atai x=segcalc(l,r);
		if(l%2==0){
			printf("%d ",x.e);
			atai y=segcalc(x.ei+1,r);
			printf("%d ",y.o);
			if(l!=x.ei)PQpush(heap,l,x.ei);
			if(x.ei+1!=y.oi)PQpush(heap,x.ei+1,y.oi);
			if(y.oi+1!=r)PQpush(heap,y.oi+1,r);
		}else{
			printf("%d ",x.o);
			atai y=segcalc(x.oi+1,r);
			printf("%d ",y.e);
			if(l!=x.oi)PQpush(heap,l,x.oi);
			if(x.oi+1!=y.ei)PQpush(heap,x.oi+1,y.ei);
			if(y.ei+1!=r)PQpush(heap,y.ei+1,r);
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:109:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:113:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^