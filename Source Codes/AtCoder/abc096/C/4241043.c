#include<stdio.h>

int main(){
	int h,w,i,j,f=0;
	char s[52][53]={0};
	for(i=0;i<52;i++){
		for(j=0;j<52;j++)s[i][j]='.';
	}
	scanf("%d%d",&h,&w);
	for(i=0;i<h;i++){
		char t[51];
		scanf("%s",t);
		for(j=1;j<=w;j++)s[i][j]=t[j-1];
	}
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			if(s[i][j]=='#'){
				if(s[i][j-1]=='.'
				&&s[i][j+1]=='.'
				&&s[i+1][j]=='.'
				&&s[i-1][j]=='.')f=1;
			}
		}
	}
	if(f==0)puts("Yes");
	else puts("No");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",t);
   ^