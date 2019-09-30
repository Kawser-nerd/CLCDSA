#include<stdio.h>
#include<stdlib.h>
int main(){
	char c,a,e,i,o,u;
	scanf("%c",&c);
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
		printf("vowel\n");
	}else{
		printf("consonant\n");
	}
	system("pause");
}