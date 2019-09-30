#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll a[100010];
ll m=INF,M;
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		int t;
		scanf("%d",&t);
		a[t]++;
		m=min(m,t);
		M=max(M,t);
	}
	if(M-m>1){
		puts("No");
	}else if(M==m){
		//???????
		if(M==n-1)puts("Yes");
		//????2???
		//n??M?
		else if(M*2<=n)puts("Yes");
		//??
		else puts("No");

	}else{
		//???????????????
		//????a[m]???????????
		//???n-a[m]??M-a[m]?
		if(M-a[m]>0&&(M-a[m])*2<=n-a[m])puts("Yes");
		else puts("No");
	}
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d",&n);
  ^
./Main.c:11:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:11:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:20:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts("No");
   ^