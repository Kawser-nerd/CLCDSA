#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

char ans[100010],s[100010];
int n;

void f(){
	rep(i,2,n){
		if((ans[i-1]=='S')^(s[i-1]=='o'))ans[i]=-ans[i-2]+'S'+'W';
		else ans[i]=ans[i-2];
	}
	if(((ans[n-2]==ans[0])^(s[n-1]=='o')^(ans[n-1]=='S'))
		&&((ans[n-1]==ans[1])^(s[0]=='o')^(ans[0]=='S'))){
		puts(ans);
		exit(0);
	}
}

int main(){
	scanf("%d%s",&n,s);
	ans[0]='S';ans[1]='S';f();
	ans[0]='S';ans[1]='W';f();
	ans[0]='W';ans[1]='S';f();
	ans[0]='W';ans[1]='W';f();
	puts("-1");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s",&n,s);
  ^