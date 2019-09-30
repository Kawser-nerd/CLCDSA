#include<stdio.h>
int a[6];
char c;
int main(){
	c=getchar();
	while('A'<=c && c<='F'){
		a[c-'A']++;
		c=getchar();
	}
	printf("%d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
}