#include<stdio.h>
int ans, a, i;
char c;
int main(){
	for(i=0; i<12; i++){
		a=0;
		c=getchar();
		while(c!=10){
			if(c=='r'){a=1;}
			c=getchar();
		}
		ans += a;
	}
	printf("%d\n", ans);
}