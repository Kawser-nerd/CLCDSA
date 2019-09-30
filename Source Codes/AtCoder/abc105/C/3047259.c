#include<stdio.h>
#include<stdlib.h>

int main(){
		int n,count=0,keta[100];
		scanf("%d",&n);
		if(n==0){
				puts("0");
				return 0;
		}
		while(n!=0){
				if(abs(n)%2==0){
						keta[count]=0;
				}
				if(abs(n)%2==1){
						if(count%2==0)n--;
						else n++;
						keta[count]=1;
				}
				n=n/2;
				count++;
		}
		count--;
		while(count>=0){
				printf("%d",keta[count]);
				count--;
		}
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^