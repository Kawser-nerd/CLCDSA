#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//????(?)
long long int big(long long int a, long long int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

//????(?)
long long int small(long long int a, long long int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

main() {
	long long int a=0,b=0,c=0,n, m, k = 0;
	int str[5],str2[5];
	
	scanf("%d%d%d", &str[0],&str[1],&str[2]);
	
	if (str[0] == str[1]) { printf("%d\n",str[2]); }
	else if (str[0] == str[2]) {  printf("%d\n",str[1]); }
	else if(str[1] == str[2]){  printf("%d\n",str[0]);  }
} ./Main.c:24:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main() {
 ^
./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &str[0],&str[1],&str[2]);
  ^