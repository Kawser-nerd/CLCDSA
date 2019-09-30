// 3C

#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 510000
#define MOD 1000000007

using namespace std;

int v[maxn],idx[maxn],V[maxn];
int arr[maxn];
int A[maxn];
int n,m,X,Y,Z;

bool cmp(int i,int j){return v[i]<v[j];}

int tsum(int k){
	int res=0;
	for (;k;k-=k&-k) res=(res+arr[k])%MOD;
	return res;
}

void tadd(int k,int sm){
	for (;k<maxn;k+=k&-k) arr[k]=(arr[k]+sm)%MOD;
}

void solve(int cas){
	int i,t;
	long long tmp;
	scanf("%d%d%d%d%d",&n,&m,&X,&Y,&Z);
	for (i=0;i<m;i++) scanf("%d",A+i);
	for (i=0;i<n;i++){
		v[i]=A[i%m];
		tmp=1LL*X*A[i%m]+1LL*Y*(i+1);
		tmp%=Z;
		A[i%m]=(int)(tmp);
		idx[i]=i;
	}
	sort(idx,idx+n,cmp);
	V[idx[0]]=1;
	for (i=1;i<n;i++){
		if (v[idx[i]]==v[idx[i-1]]) V[idx[i]]=V[idx[i-1]];
		else V[idx[i]]=V[idx[i-1]]+1;
	}
	memset(arr,0,sizeof(arr));
	for (i=0;i<n;i++){
		t=tsum(V[i]-1);
		t=(t+1)%MOD;
		tadd(V[i],t);
	}
	printf("Case #%d: %d\n",cas,tsum(maxn-1));
}

int main(){
	int t,cas;
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%d",&t);
	for (cas=1;cas<=t;cas++)
		solve(cas);
	return 0;
}
