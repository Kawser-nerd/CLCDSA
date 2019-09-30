#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	//?????
	int n;
	char s[610][310];
	char dummy;
	
	//??????
	int i,j,k,l;
	int flag=0;
	long int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%c",&dummy);
		for(j=0;j<n;j++){
			scanf("%c",&s[i][j]);
			s[i+n][j]=s[i][j];
		}
	}
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=0;i<n;i++){
		flag=1;
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(s[j+i][k]!=s[k+i][j]){
					flag=0;
				}
			}
		}
		if(flag==1){
			ans++;
		}
	}
	
	
	
//	printf("??????\n");
	//??
	
	printf("%d",ans*n);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:57:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
  printf("%d",ans*n);
         ^
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&dummy);
   ^
./Main.c:28:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c",&s[i][j]);
    ^