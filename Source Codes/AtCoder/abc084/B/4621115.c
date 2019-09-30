#include<stdio.h>
char *P[]={"No","Yes"};
char f;

int a, b, i;
char c;
int main(){
	f=1;
	scanf("%d%d\n", &a, &b);
	for(i=0; i<a; i++){
		if(getchar()=='-'){f=0;}
	}
	if(getchar()!='-'){f=0;}
	for(i=0; i<b; i++){
		if(getchar()=='-'){f=0;}
	}
	puts(P[f]);
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d\n", &a, &b);
  ^