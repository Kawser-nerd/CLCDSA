#include<stdio.h>
int x, y, q, ans;
char c;
int main(){
	c=getchar();
	while(c-10){
		switch(c){
			case 'L': x--; break;
			case 'R': x++; break;
			case 'U': y++; break;
			case 'D': y--; break;
			case '?': q++; break;
		}
		c=getchar();
	}
	ans = (x<0?-x:x) + (y<0?-y:y);
	c=getchar();
	if(c=='1'){
		printf("%d\n", ans+q);
	}else{
		if(q>ans){
			if(ans%2 == q%2){
				printf("0\n");
			}else{
				printf("1\n");
			}
		}else{
			printf("%d\n", ans-q);
		}
	}
}