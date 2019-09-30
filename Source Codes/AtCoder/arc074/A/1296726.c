#include<stdio.h>
#define inf 5000000000000000

long long maxs(long long a,long long b,long long c){
	if(a<=b && b<=c){return c-a;}
	if(a<=c && c<=b){return b-a;}
	if(b<=a && a<=c){return c-b;}
	if(b<=c && c<=a){return a-b;}
	if(c<=a && a<=b){return b-c;}
	if(c<=b && b<=a){return a-c;}
}

long long hk(long long a,long long b){
	if(a<b){return a;}return b;
}

int main(void){
	long long h,w,i,d,min;
	scanf("%lld%lld",&h,&w);
	if((h*w)%3 == 0){printf("0\n");return 0;}
	min = hk(h,w);
	for(i = 1;i <= h-1;i++){
		if(w%2 == 0){d = maxs(w*i,(w/2)*(h-i),(w/2)*(h-i));}
		else{d = maxs(w*i,((w/2)+1)*(h-i),(w/2)*(h-i));}
		min = hk(min,d);
	}
	for(i = 1;i <= w-1;i++){
		if(h%2 == 0){d = maxs(h*i,(h/2)*(w-i),(h/2)*(w-i));}
		else{d = maxs(h*i,((h/2)+1)*(w-i),(h/2)*(w-i));}
		min = hk(min,d);
	}
	printf("%lld\n",min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&h,&w);
  ^