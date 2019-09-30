#include<stdio.h>
#include<stdlib.h>

int main(void){
	int h,w;
	scanf("%d %d",&h,&w);
	char s[51][51];
	for(int i = 0;i < h*w;i++){
			scanf("%s",&s[i]);
	}
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(s[i][j]=='#'){
				if(s[i - 1][j] == '.' && s[i][j - 1] == '.' && s[i][j + 1] == '.' && s[i + 1][j] == '.'){
					printf("No");
					return 0;
				}
			}
		}
	}
	printf("Yes");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[51]’ [-Wformat=]
    scanf("%s",&s[i]);
          ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&w);
  ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",&s[i]);
    ^