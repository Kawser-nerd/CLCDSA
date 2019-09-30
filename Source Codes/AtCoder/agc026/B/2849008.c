#include<stdio.h>

long long int gcm(long long int x,long long int y){
	long long int r,tmp;
	if(x<y){
		tmp=x;
		x=y;
		y=tmp;
	}
	r=x%y;
	while(r!=0){
		x=y;
		y=r;
		r=x%y;
	}
	return(y);
}

int main(){
	int T;
	scanf("%d",&T);
	int q,i;
	long long int A[T],B[T],C[T],D[T];
	long long int a,b,c,d,gcm_bd;
	
	for(q=0;q<T;q++){
		scanf("%lld %lld %lld %lld",&A[q],&B[q],&C[q],&D[q]);
	}
	for(q=0;q<T;q++){
		a=A[q];
		b=B[q];
		c=C[q];
		d=D[q];
		if(a<b || d<b){
			printf("No\n");
		} else if(c>=b){
			printf("Yes\n");
		} else {
			gcm_bd=gcm(b,d);
			a=b-gcm_bd+(a%gcm_bd);
			if(a>c){
				printf("No\n");
			} else{
				printf("Yes\n");
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&T);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld %lld",&A[q],&B[q],&C[q],&D[q]);
   ^