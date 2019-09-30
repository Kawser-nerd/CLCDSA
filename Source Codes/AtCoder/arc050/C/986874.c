#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <regex.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define alloc(type,size) calloc(sizeof(type),size)

lli euclid(lli a,lli b){
	if(a) return euclid(b%a,a);
	return b;
}

lli lli_pow(lli a,lli n,lli mod){
	lli ret = 1;
	for(;n!=0;n=n>>1){
		if(n&1) ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret;
}

lli** mat_alloc(lli size){
	lli **ret;
	int i;
	ret = alloc(lli*,size);
	for(i=0;i<size;i++){
		ret[i] = alloc(lli,size);
	}
	return ret;
}

lli** mat_mul(lli **a,lli **b,lli size,lli mod){
	lli **ret;
	lli i,j,k;
	ret = mat_alloc(size);
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			for(k=0;k<size;k++){
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
			}
		}
	}
	return ret;

}

lli** mat_pow(lli **a,lli n,lli size,lli mod){
	lli **ret;
	int i;
	ret = mat_alloc(size);
	for(i=0;i<size;i++){
		ret[i][i] = 1;
	}
	for(;n!=0;n=n>>1){
		if(n&1) ret = mat_mul(ret,a,size,mod);
		a = mat_mul(a,a,size,mod);
	}
	return ret;
}


int main(void){
	lli a,b,m;

	
	lli g;
	lli **mat;
	lli res;

	

	scanf("%lld%lld%lld",&a,&b,&m);
	g = euclid(a,b);

	mat = mat_alloc(2);
	mat[0][0] = 10; mat[0][1] = 1;
	mat[1][0] = 0 ; mat[1][1] = 1;
	mat = mat_pow(mat,a-1,2,m);
	res = (mat[0][0] + mat[0][1]) % m;
	mat[0][0] = lli_pow(10,g,m); mat[0][1] = 1;
	mat[1][0] = 0;				 mat[1][1] = 1;
	mat = mat_pow(mat,b/g-1,2,m);
	res = (res * (mat[0][0] + mat[0][1])) % m;
	printf("%lld\n", res);			 




    return 0;
} ./Main.c: In function ‘main’:
./Main.c:79:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&m);
  ^