#include<stdio.h>
char a, c;
int b;
int main(){
	c=getchar();
	while(c!='\n'){
		a=c;
		b=0;
		while(c==a){
			b++;
			c=getchar();
		}
		printf("%c%d", a, b);
	}
	putchar('\n');
}