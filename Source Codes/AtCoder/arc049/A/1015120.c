#include<stdio.h>
#include<string.h>
int main(void)
{
	int i,j,n,a[4];
	char s[100];
	scanf("%s",s);
	for(i=0;i<4;i++){
		scanf("%d",&a[i]);
	}
	j=0;
	n=strlen(s);
	for(i=0;i<=n;i++){
		if(a[j]==i){
			printf("\"");
			j++;
		}
		if(i==n){
			printf("\n");
		}
		else{
			printf("%c",s[i]);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^