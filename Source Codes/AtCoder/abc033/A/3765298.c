#include<stdio.h>
char c, a;
int main(){
	a=getchar();
	c=getchar();
	if(a!=c){printf("DIFFERENT\n"); return 0;}
	a=getchar();
	if(a!=c){printf("DIFFERENT\n"); return 0;}
	c=getchar();
	if(a!=c){printf("DIFFERENT\n"); return 0;}
	printf("SAME\n");
}