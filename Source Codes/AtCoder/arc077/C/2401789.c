#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

//?????????

//???????
typedef struct sayouso{ll p,q;}sayouso;
typedef struct atai{ll a,index;}atai;
//???????
typedef struct node{sayouso T;atai x;}node;

node lsegN[1<<18],*lseg;
ll lsegNUM,lsegk;

//????????
sayouso id={0,0};
atai xx(atai x,atai y){// <--????
	atai ret={0,0};
	return ret;
}
atai Tx(sayouso T,atai x){
	atai ret;
	ret.a=T.p*x.index+x.a+T.q;
	ret.index=x.index;
	return ret;
}
sayouso TT(sayouso S,sayouso T){
	sayouso ret;
	ret.p=S.p+T.p;
	ret.q=S.q+T.q;
	return ret;
}
sayouso fT(sayouso T,ll k){
	sayouso ret;
	ret.p=T.p;
	ret.q=T.q<<k;
	return ret;
}
//????????

void lseguse(ll n){
	lsegNUM=n;
	lseg=lsegN+lsegNUM;
	lsegk=0;while(n/=2)lsegk++;
}
void lseginit(){
	for(ll i=lsegNUM-1;i>0;i--)lsegN[i].x=xx(lsegN[2*i].x,lsegN[2*i+1].x);
	rep(i,1,2*lsegNUM)lsegN[i].T=id;
}
void lsegupdatesub(ll l,ll r,sayouso T,ll i,ll cl,ll cr,ll ck){
	//disjoint???
	if(cr<=l||r<=cl)return;
	//???????
	if(l<=cl&&cr<=r){
		lsegN[i].T=TT(T,lsegN[i].T);
		return;
	}
	//?????????
	//????
	lsegN[2*i  ].T=TT(lsegN[i].T,lsegN[2*i  ].T);
	lsegN[2*i+1].T=TT(lsegN[i].T,lsegN[2*i+1].T);
	//??????
	ll cm=(cl+cr)/2;
	lsegupdatesub(l,r,T,2*i  ,cl,cm,ck-1);
	lsegupdatesub(l,r,T,2*i+1,cm,cr,ck-1);
	//???node???
	lsegN[i].x=xx(Tx(fT(lsegN[2*i].T,ck-1),lsegN[2*i].x),Tx(fT(lsegN[2*i+1].T,ck-1),lsegN[2*i+1].x));
	lsegN[i].T=id;
}
void lsegupdate(ll l,ll r,sayouso T){lsegupdatesub(l,r,T,1,0,lsegNUM,lsegk);}
atai lsegcalcsub(ll l,ll r,ll i,ll cl,ll cr,ll ck){
	//???????
	if(l<=cl&&cr<=r)return Tx(fT(lsegN[i].T,ck),lsegN[i].x);

	ll cm=(cl+cr)/2;
	//????(??????????????)
	lsegN[2*i  ].T=TT(lsegN[i].T,lsegN[2*i  ].T);
	lsegN[2*i+1].T=TT(lsegN[i].T,lsegN[2*i+1].T);
	lsegN[i].x=Tx(fT(lsegN[i].T,ck),lsegN[i].x);
	lsegN[i].T=id;

	//????
	if(r<=cm)return lsegcalcsub(l,r,2*i  ,cl,cm,ck-1);
	//????
	if(cm<=l)return lsegcalcsub(l,r,2*i+1,cm,cr,ck-1);
	//??
	return xx(lsegcalcsub(l,r,2*i,cl,cm,ck-1),lsegcalcsub(l,r,2*i+1,cm,cr,ck-1));
}
atai lsegcalc(ll l,ll r){return lsegcalcsub(l,r,1,0,lsegNUM,lsegk);}

//?????????

int a[100010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
 
	rep(i,1,n+1)scanf("%d",a+i);
	
 	lseguse(1<<17);
	rep(i,1,m+1)lseg[i].x.index=i;
	
	rep(i,1,n){
		//a[i],a[i+1]???
		int l=a[i],r=a[i+1];
		if(r<l)r+=m;
		if(r-l<=1)continue;
		if(r>m){
			sayouso T;
			T.p=1;
			T.q=-a[i]-1;
			lsegupdate(l+2,m+1,T);
			T.q+=m;
			lsegupdate(1,r-m+1,T);
		}else{
			sayouso T;
			T.p=1;
			T.q=-a[i]-1;
			lsegupdate(l+2,r+1,T);
		}
//	rep(i,1,m+1)printf("%d ",lsegcalc(i,i+1).a);puts("");
	}
	
	ll otoku=0;
	rep(i,1,m+1){
		ll t=lsegcalc(i,i+1).a;
		otoku=max(otoku,t);
	}
	
	ll sum=0;
	rep(i,1,n)sum+=(a[i+1]-a[i]+m)%m;
	
	printf("%lld\n",sum-otoku);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:99:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:101:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,1,n+1)scanf("%d",a+i);
              ^