#include<stdio.h>
#include<string.h>

int min(int a,int b){if(a>b){return b;}return a;}

int main(void){
	int b[128],r[128],n,l,i,j;
	char s[64];
	scanf("%d",&n);
	for(i = 0;i <= 127;i++){r[i] = 128;}
	for(i = 1;i <= n;i++){
		for(j = 0;j <= 127;j++){b[j] = 0;}
		scanf("%s",s);
		l = strlen(s);
		for(j = 0;j < l;j++){b[s[j]]++;}
		for(j = 0;j <= 127;j++){r[j] = min(r[j],b[j]);}
	}
	for(i = 97;i <= 122;i++){
		for(j = 1;j <= r[i];j++){printf("%c",i);}
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^