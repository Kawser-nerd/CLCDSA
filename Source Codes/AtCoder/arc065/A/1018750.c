#include<stdio.h>
#include<string.h>

long num;
char s[100001];
char dream[7]={'d','r','e','a','m','e','r'};
char erase[6]={'e','r','a','s','e','r'};

int search(long i){
	long j;
	if(i==num) return 1;
	if(s[i]==dream[0]){
		for(j=1;j<7;j++){
			if(i+j==num) break;
			if(s[i+j]!=dream[j]) break;
		}
		if(j==7){
			if(search(i+7)) return 1;
		}
		if(j>4){
			if(search(i+5)) return 1;
		}
	}else if(s[i]==erase[0]){
		for(j=1;j<6;j++){
			if(i+j==num) break;
			if(s[i+j]!=erase[j]) break;
		}
		if(j==6){
			if(search(i+6)) return 1;
		}
		if(j>4){
			if(search(i+5)) return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%s",s);
	num=strlen(s);
	if(search(0)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^