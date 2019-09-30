#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}

int main(){
	
	int i,k,N,a[110],alice=0,bob=0;
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
	scanf("%d",&a[i]);
	}
	
	qsort(a,N,sizeof(int),compare);
	
	if(N%2==0){
	for(k=0;k<N/2;k++){
		alice+=a[2*k];
		bob+=a[2*k+1];
	}
	}else {
		for(k=0;k<(N-1)/2;k++){
		alice+=a[2*k];
		bob+=a[2*k+1];
	}
	alice+=a[N-1];	
		
	}
	
	
	
	
	printf("\n%d\n\n",alice-bob);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a[i]);
  ^