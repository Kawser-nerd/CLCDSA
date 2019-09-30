#include<stdio.h>

#define MOD 1000000007
#define MAX_GRID 100000

/*****memo vector for calculation n!*****/
long factorial[2*MAX_GRID];
long inverse_f[2*MAX_GRID];

long mod(long Num){
	if(Num>=MOD) Num%=MOD;
return Num;
}

long inverse_element(long Num){
	long inv=1;
	long k=MOD-2;

	while(k){
		if(k&1) inv=mod(inv*Num);
		Num=mod(Num*Num);
		k>>=1;
	}

return inv;
}

void setup(int *h, int *w, int *a, int *b){
	scanf("%d %d %d %d", h, w, a, b);
	
	factorial[0]=1;
	for(int n=1; n<(*h+*w); n++){
		factorial[n]=mod(n*factorial[n-1]);
	}

	inverse_f[*h+*w-1]=inverse_element(factorial[*h+*w-1]);
	for(int n=*h+*w-1; n>0; n--) {
		inverse_f[n-1]=mod(n*inverse_f[n]); 
	}
return;
}

long C(int n, int k){
return mod(factorial[n]*mod(inverse_f[k]*inverse_f[n-k]));
}

long sumup(int *h, int *w, int *a, int *b){
	long N=0;
	for(int k=1; k<=*h-*a; k++){
		N += mod(C(*b+k-2, k-1) * C(*w+*h-*b-k-1, *h-k));
	}
return mod(N);
}

int main(void){
	int height, width, a, b;

	setup(&height, &width, &a, &b);
	printf("%ld\n", sumup(&height, &width, &a, &b));
return 0;
} ./Main.c: In function ‘setup’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", h, w, a, b);
  ^