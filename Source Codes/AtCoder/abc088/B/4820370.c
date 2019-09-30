#include<stdio.h>
int main(){
	int N,i,j,b=0,c=0,d=0;
	scanf("%d",&N);
	int a[100];
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(a[i]<a[j]){
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	for(i=0;i<N;i++){
		if(i%2==0){
			c+=a[i];
		}else{
			d+=a[i];
		}
	}
	printf("%d",c-d);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^