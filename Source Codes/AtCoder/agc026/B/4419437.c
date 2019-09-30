#include<stdio.h>

long long int gcd(long long int a, long long int b){
	long long int r, t;
	if(a<b){
		t = a;
		a = b;
		b = t;
	}
	r = a % b;
	while(r!=0){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int T, i;
long long int A, B, C, D, g, b;

int main(){
	scanf("%d", &T);
	for(i=0; i<T; i++){
		scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
		if(B>A){
			puts("No");
		}else if(B>D){
			puts("No");
		}else if(C>=B){
			puts("Yes");
		}else{
			g = gcd(B, D);
			b = B - g + A%g;
			if(b > C){
				puts("No");
			}else{
				puts("Yes");
			}
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &T);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
   ^