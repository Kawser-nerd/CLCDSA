#include<stdio.h>

int main(){
	int a[3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	for(int i=0;i<2;i++){
		for(int j=0;j<2-i;j++){
			if(a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	if(a[0]+a[1]==a[2]){
		printf("Yes");
	}
	else{
		printf("No");
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a[0],&a[1],&a[2]);
  ^