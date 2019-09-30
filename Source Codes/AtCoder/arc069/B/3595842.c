#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//?????
	int n;
	char s[100010];
	int sint[100010];
	int animal[100010];
	int flag=0;
	int i,j,k;
	
	//????????
	scanf("%d\n%s",&n,&s);
	
	for(i=0;i<n;i++){
		if(s[i]=='o'){
			sint[i]=0;
		}else{
			sint[i]=1;
		}
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=0;i<4;i++){
		if(i%2==0){
			animal[0]=0;
		}else{
			animal[0]=1;
		}
		if(i<2){
			animal[1]=0;
		}else{
			animal[1]=1;
		}
		
		for(j=2;j<=n;j++){
			animal[j]=(animal[j-2]+animal[j-1]+sint[j-1])%2;
		}
		
//		printf("0?%d,n?%d\n",animal[0],animal[n]);
		if(animal[n]==animal[0]&&animal[1]==(animal[n-1]+animal[n]+sint[0])%2){
			flag=1;
			break;
		}
	}
	
	
//	for(i=0;i<n;i++){
//		printf("sint[%d]=%d\n",i,sint[i]);
//	}
	
//	for(i=0;i<n;i++){
//		printf("animal[%d]=%d\n",i,animal[i]);
//	}
	
	
//	printf("??????\n");
	
	//??
	
	if(flag==1){
		for(i=0;i<n;i++){
			if(animal[i]==0){
				printf("S");
			}else{
				printf("W");
			}
		}
	}else{
		printf("-1");
	}
	
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[100010]’ [-Wformat=]
  scanf("%d\n%s",&n,&s);
        ^
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%s",&n,&s);
  ^