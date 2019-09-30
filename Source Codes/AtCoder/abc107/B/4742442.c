#include <stdio.h>
int main(void){
	int h,w;
	int i,j;
	scanf ("%d %d",&h,&w);
	char s[101][101];
	int Linetobeblank[101]={0};
	int Columntobeblank[101]={0};
	for(i=0;i<h;i++){
		scanf("%s",s[i]);
	}
	//????????
	for(i=0;i<h;i++){
		int flag = 0;
		for(j=0;j<w;j++){
			if(s[i][j]=='.'){
				flag ++;
			}
		}
		if(flag==w){
			//??i???????
			Linetobeblank[i]=1;
		}
	}
	//????????
	for(i=0;i<w;i++){
		int flag = 0;
		for(j=0;j<h;j++){
			if(s[j][i]=='.'){
				flag ++;
			}
		}
		if(flag==h){
			//??i???????
			Columntobeblank[i]=1;
		}
	}
	/*
	printf("????????\n");
	for(i=0;i<h;i++){
		if(Linetobeblank[i]==1){
			printf("%d??\n",i);
		}
	}
	printf("????????\n");
	for(i=0;i<w;i++){
		if(Columntobeblank[i]==1){
			printf("%d??\n",i);
		}
	}
	*/
	for(i=0;i<h;i++){
		if( Linetobeblank[i]!=1){
			for(j=0;j<w;j++){
				if(Columntobeblank[j]!=1){
					printf("%c",s[i][j]);
				}
				
			}
			if(i<(h-1)){
				printf("\n");
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d %d",&h,&w);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s[i]);
   ^