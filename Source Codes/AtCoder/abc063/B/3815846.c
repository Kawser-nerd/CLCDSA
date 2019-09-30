#include<stdio.h>
char A[26], c;
int main(){
	c=getchar();
	while(c!=10){
		if(A[c-'a']){
			printf("no\n");
			return 0;
		}
		A[c-'a']=1;
		c=getchar();
	}
	printf("yes\n");
}