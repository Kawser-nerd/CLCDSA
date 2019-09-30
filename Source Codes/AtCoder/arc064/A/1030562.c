#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define DIGIT 1000000000

typedef struct wide_int{
	int x1;
	int x2;
}wint;

wint add_wint(wint a, wint b){
	int carry=0, bias=0;
	wint r;

	if(a.x2 + b.x2 >= DIGIT){
		carry += 1;
		bias = DIGIT;
	}
	r.x1 = a.x1 + b.x1 + carry;
	r.x2 = a.x2 + b.x2 - bias;

	return r;
}

wint to_wint(int a){
	wint r;
	
	r.x1 = a/DIGIT;
	r.x2 = a%DIGIT;

	return r;
}

print_wint(wint a){
	if(a.x1 == 0) printf("%d\n", a.x2);
	else printf("%d%09d\n", a.x1, a.x2);
}

int main(void){
	int n, x;
	int a[N], b[N];
	int i;
	wint r;

	r.x1=0;
	r.x2=0;
	scanf("%d %d", &n, &x);
	for(i=0; i<n; i++){
		scanf("%d", &(a[i]));
		b[i] = a[i];
	}
	if(b[0] > x) b[0] = x;
	for(i=1; i<n; i++){
		if(b[i-1]+b[i] > x) b[i] = x-b[i-1];
	}
	for(i=0; i<n; i++){
		r = add_wint(r, to_wint(a[i]-b[i]));
	}

	/*for(i=0; i<n; i++){
		printf("%d ", b[i]);
		} */
	printf("\n");
	print_wint(r);
	


	return 0;
} ./Main.c:35:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 print_wint(wint a){
 ^
./Main.c: In function ‘main’:
./Main.c:48:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &x);
  ^
./Main.c:50:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &(a[i]));
   ^