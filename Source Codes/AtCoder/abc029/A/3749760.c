#include<stdio.h>
char c;
int main(){
	c=getchar();
	while(c!=10){
		putchar(c);
		c=getchar();
	}
	putchar('s');
	putchar(10);
}