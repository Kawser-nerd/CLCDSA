#include<stdio.h>
#include<math.h>
char *P[]={"No","Yes"};
char f;

int x, y;
char c;
int main(){
	while((c=getchar())!=10){
		if('0'<=c && c<='9'){
			x = x*10 + (c-'0');
		}
	}
	y = sqrt(x);
	f = y*y == x;
	puts(P[f]);
}