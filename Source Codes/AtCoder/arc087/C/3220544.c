#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

char s[200010];
ll ptr[100010];

char t[200010];
ll tlen;
ll ans;
ll err;

void nxt(){
	//t??tlen????????????t????????????????
	//???????????????(?t?1???????????)err???????
	while(tlen>0&&t[tlen-1]=='1')tlen--;
	if(tlen==0)err=1;
	t[tlen-1]='1';
	t[tlen]=0;
}

int cmp(const void*a,const void*b){
	return strcmp(s+*(ll*)a,s+*(ll*)b);
}
int main(){
	ll n,k;
	scanf("%lld%lld",&n,&k);
	rep(i,0,n){
		scanf("%s",s+ptr[i]);
		ptr[i+1]=ptr[i]+strlen(s+ptr[i])+1;
	}
	qsort(ptr,n,sizeof(ll),cmp);
	s[ptr[n]]='2';//??
	
	
	ll i=0;
	while(!err){
		//strcmp????????
		if(!strcmp(t,s+ptr[i])){
			//???????????
			i++;
			nxt();
		}else if(!strncmp(t,s+ptr[i],tlen)){
			//prefix??????
			t[tlen++]='0';
			t[tlen]=0;
		}else{
			//prefix?????????????????
			//grundy????????
//			puts(t);fflush(0);
			ll temp=k-tlen+1;
			ans^=(temp&-temp);
			nxt();
		}
	}
	//printf("%lld ",ans);
	puts(ans?"Alice":"Bob");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s+ptr[i]);
   ^