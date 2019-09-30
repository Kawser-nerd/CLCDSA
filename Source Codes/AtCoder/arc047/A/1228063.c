#include <stdio.h>

char str[100001];

int main(void)
{
 	int n,l;
 	int t=1,ans=0;
 	scanf("%d%d",&n,&l);
 	scanf("%s",str);
 	for(int i=0;str[i]!='\0';i++){
 		if(str[i]=='+'){
 			if(t==l) ans++,t=1;
 			else t++;
 		}
 		else t--;
 	}
 	printf("%d\n",ans);
 	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&l);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^