#include<stdio.h>
#include<stdlib.h>

int cmp( const void *p, const void *q ) {
    return *(int*)p - *(int*)q;
}

int get_gcd(int a, int b);

int main()
{
	int i, n, lx, tmp, gcd; 
	
	scanf("%d %d", &n, &lx);
	
	int x[n + 1], diff[n];
	
	for(i = 0; i < n; i++){
		scanf("%d", &x[i]);
	}
	
	x[n] = lx;
	
	qsort(x, n + 1, sizeof(int), cmp);
	
	for(i = 0; i < n; i++){
		diff[i] = x[i + 1] - x[i];
	}
	
	qsort(diff, n, sizeof(int), cmp);
	
	gcd = diff[0];
	for(i = 1; i < n; i++){
		gcd = get_gcd(gcd, diff[i]);
		if(gcd == 1){
			break;
		}
	}
	
	printf("%d", gcd);
	

	return 0;
}

int get_gcd(int a, int b)
{
    int c, tmp, mod;

    if (a < b) {
        tmp = a;
		a = b;
		b = tmp;
    }

    while (b != 0) {
        mod = a % b;
        a = b;
        b = mod;
    }

    return a;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &lx);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &x[i]);
   ^