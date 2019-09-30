#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)


//???????
//*
//???????
typedef struct atai{ll a;}atai;
atai xx(atai x,atai y){
	atai r;
	r.a=x.a+y.a;//sum
	return r;
}
//???????

int segNUM;
atai segN[1<<18],*seg;
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

char s[200010];
int c[30];
int a[200010];
int p[200010];

ll ans;
int main(){
	scanf("%s",s);
	ll n=strlen(s);
	rep(i,0,n)c[s[i]-'a']++;
	
	int idx=-1;
	rep(i,0,26)if(c[i]%2){
		if(idx==-1)idx=i;
		else{
			puts("-1");
			return 0;
		}
	}
	
	rep(i,0,26)c[i]/=2;
	c[idx]++;

	rep(i,0,n){
		int t=s[i]-'a';
		if(c[t]){
			if(c[t]==1&&t==idx)a[i]=-2;
			else a[i]=-1;
			c[t]--;
		}else a[i]=-3;
	}
	
	//?????
	{
		int cnt=0;
		rep(i,0,n){
			if(a[i]==-1||a[i]==-2)ans+=cnt;
			if(a[i]==-2||a[i]==-3)cnt++;
		}
	}
	
	int cnt=0;
	rep(i,0,n)if(a[i]==-1)a[i]=cnt++;
	cnt=0;
	for(int i=n-1;i>=0;i--)if(a[i]==-3)a[i]=cnt++;
	
	//?????
	rep(i,0,26){
		for(int l=0,r=n-1;l<r;l++,r--){
			while(l<r&&s[l]-'a'!=i)l++;
			if(l==r)break;
			while(s[r]-'a'!=i)r--;
			p[a[l]]=a[r];
		}
	}
	
	//??????
	seguse(1<<17);
	rep(i,0,n/2){
		ans+=segcalc(p[i],n/2).a;
		atai r={1};
		segupdate(p[i],r);
	}
	
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:54:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^