#include<stdio.h>



int max(int a[],int N );


int main(){
	
	int i,j,k,l,N,a[110],sort[110],alice=0,bob=0;
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
	scanf("%d",&a[i]);
	}
	
	for(j=0;j<N;j++){
	sort[j]=max(a,N);
	/*printf("%d\n",sort[j]);*/
	
	for(l=0;l<N;l++){
	if(a[l]==sort[j]){
		a[l]=0;
		break;
	}
	}
	}
	
	
	
	if(N%2==0){
	for(k=0;k<N/2;k++){
		alice+=sort[2*k];
		bob+=sort[2*k+1];
	}
	}else {
		for(k=0;k<(N-1)/2;k++){
		alice+=sort[2*k];
		bob+=sort[2*k+1];
	}
	alice+=sort[N-1];	
		
	}
	
	
	
	
	printf("\n%d\n\n",alice-bob);
	
	
	return 0;
}


int max(int a[],int N ){

	int i,max;
		max=a[0];
	for(i=0;i<N;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	
	return max;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a[i]);
  ^