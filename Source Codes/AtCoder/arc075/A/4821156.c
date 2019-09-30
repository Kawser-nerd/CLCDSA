#include<stdio.h>
int main(){
	int N,i,j,a=0,b=0;
	scanf("%d",&N);
	int s[100];
	for(i=0;i<N;i++){
		scanf("%d",&s[i]);
		a+=s[i];
	}
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(s[i]>s[j]){
				b=s[i];
				s[i]=s[j];
				s[j]=b;
			}
		}
	}
	if(a%10!=0){

	}else{
		for(i=0;i<N;i++){
			if((a-s[i])%10 !=0){
				a-=s[i];
				break;
			}
			if(i==N-1){
				a=0;
			}
		}
	}
	printf("%d",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&s[i]);
   ^