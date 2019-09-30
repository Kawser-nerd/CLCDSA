#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))



//next_permutation
void nexp(char*a,int cnt){
	int l=cnt-1,r=cnt-1;
	ll t;
	while(--l>=0&&a[l]>a[l+1]);
	if(l>=0){
		while(a[l]>a[r])r--;
		t=a[l];a[l]=a[r];a[r]=t;
	}
	for(l++,r=cnt-1;l<r;l++,r--)t=a[l],a[l]=a[r],a[r]=t;
}


char s[30];
char t[30];
int main(){
	scanf("%s",s);
	ll n=strlen(s);
	if(n<26){
		rep(i,'a','z'+1){
			ll flag=1;
			rep(j,0,n)flag&=(s[j]!=i);
			if(flag){
				s[n]=i;
				puts(s);
				return 0;
			}
		}
	}

	if(strcmp(s,"zyxwvutsrqponmlkjihgfedcba")==0){
		puts("-1");
		return 0;
	}
	
	rep(i,0,n)t[i]=s[i];
	nexp(t,26);
	ll k=0;
	while(t[k]==s[k])k++;
	t[k+1]=0;
	puts(t);
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^