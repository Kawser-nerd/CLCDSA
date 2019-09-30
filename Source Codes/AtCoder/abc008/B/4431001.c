#include <stdio.h>
int main(void){
	char s[51][51];
	int n,i=0,j=0,c[50]={0},max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(strcmp(s[i],s[j])==0) c[i]++;
		}
	}
	for(i=0;i<n;i++){
		if(c[i]>=max) max=c[i];
	}
	for(i=0;i<n;i++){
		if(max==c[i]){
			printf("%s\n",s[i]);
			break;
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:7: warning: implicit declaration of function ‘strcmp’ [-Wimplicit-function-declaration]
    if(strcmp(s[i],s[j])==0) c[i]++;
       ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s[i]);
   ^