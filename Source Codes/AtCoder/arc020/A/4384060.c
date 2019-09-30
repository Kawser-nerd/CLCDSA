#include<stdio.h>
#include<stdlib.h>

int main(){
		int a,b;
		scanf("%d%d",&a,&b);
		if(abs(a)>abs(b))puts("Bug");
		if(abs(a)<abs(b))puts("Ant");
		if(abs(a)==abs(b))puts("Draw");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^