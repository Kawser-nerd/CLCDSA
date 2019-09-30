#include<stdio.h>
#include<stdlib.h>
int main(void){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if((b-a)==(c-b)){
		printf("YES\n");
	} else{
		printf("NO\n");
	}
	system("pause");
}