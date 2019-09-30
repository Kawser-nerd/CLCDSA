#include<stdio.h>

int main(){
	int h,w,h2,w2;
	scanf("%d%d%d%d",&h,&w,&h2,&w2);
	if(h==h2){
		puts("YES");
		return 0;
	}if(h==w2){
		puts("YES");
		return 0;
	}if(w==h2){
		puts("YES");
		return 0;
	}if(w==w2){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&h,&w,&h2,&w2);
  ^