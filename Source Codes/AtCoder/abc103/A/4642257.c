#include<stdio.h>

int main(){
	int a[3],b[3];
	int i,c;
	for(i=0;i<3;i++){
		scanf("%d",&a[i]);
		if(a[i]<0){
			a[i]=-a[i];
		}
	}

	if(a[0]>a[1]){
		c=a[0];
		a[0]=a[1];
		a[1]=c;
	}
	if(a[1]>a[2]){
		c=a[2];
		a[2]=a[1];
		a[1]=c;
	}
	if(a[0]>a[1]){
		c=a[0];
		a[0]=a[1];
		a[1]=c;
	}
	if(a[1]>a[2]){
		c=a[2];
		a[2]=a[1];
		a[1]=c;
	}

	printf("%d",a[2]-a[0]);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^