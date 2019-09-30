#include<stdio.h>
#include<string.h>

int main(){
	char s[1000];
	int n;
	scanf("%d",&n);
	getchar();
	int x=0;
	int max=0;
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='I'){
			x++;
			if(x>max){
				max=x;
			}
		}
		if(s[i]=='D'){
			x--;
		}
	}
	printf("%d",max);
} ./Main.c: In function ‘main’:
./Main.c:11:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[1000]’ [-Wformat=]
  scanf("%s",&s);
        ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&s);
  ^