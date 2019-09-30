#include<stdio.h>

int main(){
	int h,w,i,j,sum=0;
	char s[8][9];
	scanf("%d%d",&h,&w);
	for(i=0;i<h;i++)scanf("%s",s[i]);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(s[i][j]=='#'){
				sum++;
			}
		}
	}
	if(sum==h+w-1)puts("Possible");
	else puts("Impossible");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:7:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<h;i++)scanf("%s",s[i]);
                  ^