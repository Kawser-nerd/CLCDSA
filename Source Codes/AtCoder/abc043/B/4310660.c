#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int res[10];
int top = 0;

void push(int x){
	res[top] = x;
	top++;
}

void pop(){
	res[top] = -1;
	if(top > 0)top--;
}

int main(void){
	char s[11];
	int i;
	scanf("%s",s);
	for(i=0;i<10;i++){
		if(s[i]=='0'){
			push(0); 
		}else if(s[i]=='1'){
			push(1);
		}else if(s[i]=='B'){
			pop();
		}
	}
	for(i=0;i<top;i++){
		printf("%d",res[i]);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^