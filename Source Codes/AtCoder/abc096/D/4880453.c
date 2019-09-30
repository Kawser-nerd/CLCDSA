#include<stdio.h>

int so(int a){
	int i;
	for(i=2;i*i<=a;i++){
		if(a%i==0)return -1;
	}
	return 1;
}

int main(){
	int n,i,e=0;
	scanf("%d",&n);
	for(i=11;i<55555;i+=10){
		if(so(i)==1){
			printf("%d ",i);
			e++;
		}
		if(e==n)break;;
	}
	puts("");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^