#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define INF 1023456789

#define modp(x) (((x)%P+P)%P)

typedef long long ll;

ll isqrt(ll n){
	if(n==0)return 0;
	ll x=n;
	for(;;){
		ll y=(x+n/x)/2;
		if(y>=x)return x;
		x=y;
	}
}

main(){
	int datasuu;
	scanf("%d ",&datasuu);
	for(int casenum=1;casenum<=datasuu;casenum++){
		printf("Case #%d: ",casenum);
		
		int qpos[50];
		int cnt=0;
		char buf[200];
		gets(buf);
		int l=strlen(buf);
		for(int i=0;i<l;i++)if(buf[i]=='?')qpos[cnt++]=i;
		
		//small
		for(int b=0;b<(1<<cnt);b++){
			ll num=0;
			int pos=0;
			for(int i=0;i<l;i++){
				if(buf[i]=='0')num=num*2;
				if(buf[i]=='1')num=num*2+1;
				if(buf[i]=='?')num=num*2+((b>>(pos++))&1);
			}
			ll c=isqrt(num);
			if(c*c==num){
				for(int i=l-1;i>=0;i--)printf("%d",(num>>i)&1);
				puts("");
			}
		}
	}
}