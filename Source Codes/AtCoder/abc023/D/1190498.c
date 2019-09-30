#include<stdio.h>
#include<stdlib.h>

int sortfnc(const void *a,const void *b){
    if(*(long long*)a == *(long long*)b){return 0;}
    if(*(long long*)a > *(long long*)b){return -1;}
    return 1;
}

int main(void){
	long long jud,n,h[131072],s[131072],i,st,f,t[131072],nt;
	scanf("%lld",&n);
	for(i = 1;i <= n;i++){scanf("%lld%lld",&h[i],&s[i]);}
	st = 0;f = 123456789012345;
	while(st!=f){
		jud = (st+f)/2;
		for(i = 0;i <= 131071;i++){t[i] = 0;}
		for(i = 1;i <= n;i++){
			if(jud < h[i]){t[131071]++;break;}
			nt = (jud-h[i])/s[i];
			if(nt > n){nt = n;}
			t[nt]++;
		}
		if(t[131071]){st = jud+1;continue;}
		nt = 0;
		for(i = 0;i <= n;i++){
			nt++;
			nt-=t[i];
			if(nt < 0){st = jud+1;break;}
			if(i == n){f = jud;break;}
		}
	}
	printf("%lld\n",st);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:13:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= n;i++){scanf("%lld%lld",&h[i],&s[i]);}
                        ^