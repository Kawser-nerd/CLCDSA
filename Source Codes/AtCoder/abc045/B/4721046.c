#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long 

// fact(n)
int fact(int n){
	if(n == 1)	return 1;
	else return (n * fact(n - 1));
}

// combination(n,r)
int combination(int n, int r){
	if(r == 0 || r == n)	return 1;
	else if(r == 1)	return n;
	return (combination(n - 1, r - 1) + combination(n - 1, r));
}

// gcd(a,b)
int gcd(int a,int b){
	return (b == 0) ? a : gcd(b, a % b);
}

// lcm(a.b)
int lcm(int a,int b){
	return (a * b) / gcd(a,b);
}

// qsort(array, size, sizeof(int),comp);
int comp(const int *a,const int *b){
	return (*a - *b);
}

// append(array,*size,addNum)
void append(int *array,int *size,int num){
	realloc(array, sizeof(int) * (*size + 1));
	array[(*size)] = num;
	++(*size);
}

// pop(array,*size) & nongetpop(array,*size)
int pop(int *array,int *size){
	int temp = array[(*size - 1)];
	realloc(array,sizeof(int) * (*size - 1));
	--(*size);
	return temp;
}

void nongetpop(int *array,int *size){
	realloc(array,sizeof(int) * (*size - 1));
	--(*size);
}

int main(int argc, char const *argv[]){
	int player = 0,turn[3] = {0,-1,-1};
	char card[3][120];
	scanf("%s %s %s",card[0],card[1],card[2]);
	for (int i = 0; i < strlen(card[0]) + strlen(card[1]) + strlen(card[2]); ++i){
		switch(card[player][turn[player]]){
			case 'a':
				player = 0;
				break;
			case 'b':
				player = 1;
				break;
			case 'c':
				player = 2;
				break;
		}
		if(++turn[player] > strlen(card[player])){
			printf("%c\n", (player + 'A'));
			return 0;
		}
	}
	printf("%c\n", (player + 'A'));
	return 0;
} ./Main.c: In function ‘append’:
./Main.c:40:2: warning: ignoring return value of ‘realloc’, declared with attribute warn_unused_result [-Wunused-result]
  realloc(array, sizeof(int) * (*size + 1));
  ^
./Main.c: In function ‘pop’:
./Main.c:48:2: warning: ignoring return value of ‘realloc’, declared with attribute warn_unused_result [-Wunused-result]
  realloc(array,sizeof(int) * (*size - 1));
  ^
./Main.c: In function ‘nongetpop’:
./Main.c:54:2: warning: ignoring return value of ‘realloc’, declared with attribute warn_unused_result [-Wunused-result]
  realloc(array,sizeof(int) * (*size - 1));
  ^
./Main.c: In function ‘main’:
./Main.c:61:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s %s",card[0],card[1],card[2]);
  ^