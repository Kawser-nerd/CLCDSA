#include<stdio.h>

int main(){
	int a,b,i;
	char s[15];
	scanf("%d%d%s",&a,&b,s);
	if(s[a]!='-'){
		puts("No");
		return 0;
	}
	for(i=0;i<a+b+1;i++){
		if(i!=a){
			if(s[i]!='0'&&s[i]!='1'&&s[i]!='2'&&
			s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&
			s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&
			s[i]!='9'){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%s",&a,&b,s);
  ^