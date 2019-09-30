#include<stdio.h>
char c;
int f;
int nextInt();

int N;
char a[5];

int main(){
	a[0]=getchar();
	a[1]=getchar();
	a[2]=getchar();
	a[3]=getchar();
	a[4]=getchar();
	N = nextInt();
	putchar(a[(N-1)/5]);
	putchar(a[(N-1)%5]);
	putchar(10);
}

int nextInt(){
	f=0;
	c = getchar();
	while((c<'0')||('9'<c)){
		c=getchar();
	}
	while((c>='0')&&(c<='9')){
		f=f*10+(c-'0');
		c=getchar();
	}
	return f;
}