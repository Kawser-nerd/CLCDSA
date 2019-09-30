#include<stdio.h>

int main(){
	int H,W;
	scanf("%d%d",&H,&W);
	char s[H][W+1];
	for(int i=0;i<H;i++)scanf("%s",s[i]);
	
	for(int i=0;i<H;i++)for(int j=0;j<W;j++){
		if(s[i][j]=='#'){
			if(i>0 && s[i-1][j]=='#')continue;
			if(i<H-1 && s[i+1][j]=='#')continue;
			if(j>0 && s[i][j-1]=='#')continue;
			if(j<W-1 && s[i][j+1]=='#')continue;
			
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&H,&W);
  ^
./Main.c:7:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<H;i++)scanf("%s",s[i]);
                      ^