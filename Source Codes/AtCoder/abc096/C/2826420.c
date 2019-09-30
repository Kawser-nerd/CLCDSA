#include <stdio.h>
int main(){
	int h,w;
	scanf("%d %d",&h,&w);
	char s[51][51];
	int i,j;
	for(i=0;i<h;i++){
			scanf("%s",&s[i]);
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){	
			if(s[i][j]=='#'){
				if(s[i-1][j]=='.'&&s[i][j-1]=='.'&&s[i][j+1]=='.'&&s[i+1][j]=='.'){
					printf("No");
					return 0;
				}
			}
		}
	}
	printf("Yes");
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:8:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[51]’ [-Wformat=]
    scanf("%s",&s[i]);
          ^
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&w);
  ^
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",&s[i]);
    ^