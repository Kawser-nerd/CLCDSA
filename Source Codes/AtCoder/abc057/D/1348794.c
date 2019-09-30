#include<stdio.h>
#include<string.h>
#include<math.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ABS(a) ((a)>0 ? (a):-(a))
#define ll long long
#define SWAP(a,b) {a+=b;b=a-b;a-=b;}

ll cmb[52][52];

ll comb(ll n,ll r){
	if(r == 0 || n == r) return 1ll;
	if(r == 1) return n;
	if(cmb[n][r] != 0) return cmb[n][r];
	else return cmb[n][r] = comb(n-1,r-1) + comb(n-1,r);
}

int main(){
	ll n,a,b,v[52];
	double ave = 0;
	ll numin = 0,numall = 0,ch = 0;

	//input
	scanf("%lld %lld %lld",&n,&a,&b);
	FOR(i,0,n) scanf("%lld",&v[i]);

	//sort
	FOR(i,0,n-1){
		FOR(j,i+1,n)
		if(v[i] < v[j]) SWAP(v[i],v[j]);
	}

	//average
	FOR(i,0,a) ave += v[i];
	ave /= a;

	//choices
	FOR(j,0,a) if(v[j] == v[a-1]) numin ++;
	FOR(j,0,n) if(v[j] == v[a-1]) numall ++;

	memset(cmb,0,sizeof(cmb));

	if(v[0] == v[a-1]){
		FOR(k,a,fmin(b+1,numall+1)) ch += comb(numall,k);
	}else{
		ch = comb(numall,numin);
	}

	//output
	printf("%f\n",ave);
	printf("%lld\n",ch);
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld",&n,&a,&b);
  ^
./Main.c:25:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%lld",&v[i]);
             ^