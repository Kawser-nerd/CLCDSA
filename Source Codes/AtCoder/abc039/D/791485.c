#include <stdio.h>
#define s(a,b) (s[a][b]=='#'||s[a][b]=='\0'||s[a][b]=='0')
#define ss(a,b) if(s[a][b]=='#'){s[a][b]='0';}
int main(void){
	int h,w,i,j;
	scanf("%d%d",&h,&w);
	char s[102][103];
	char t[102][103];
	for(i=0;i<102;i++){
		for(j=0;j<103;j++){
			s[i][j]='0';
		}
	}
	for(i=1;i<=h;i++){
		scanf("%s",&s[i][1]);
	}
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			if(s(i-1,j-1)&&s(i-1,j)&&s(i-1,j+1)&&s(i,j-1)&&s(i,j)&&s(i,j+1)&&s(i+1,j-1)&&s(i+1,j)&&s(i+1,j+1)){
				t[i][j]='#';
				ss(i-1,j-1);
				ss(i-1,j);
				ss(i-1,j+1);
				ss(i,j-1);
				ss(i,j);
				ss(i,j+1);
				ss(i+1,j-1);
				ss(i+1,j);
				ss(i+1,j+1);
			}else{
				t[i][j]='.';
			}
		}
	}
	int judge=1;
	for(i=1;i<=h&&judge;i++){
		for(j=1;j<=w&&judge;j++){
			if(s[i][j]=='#'){
				judge=0;
			}
		}
	}
	if(judge){
		printf("possible\n");
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				printf("%c",t[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("impossible\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&s[i][1]);
   ^