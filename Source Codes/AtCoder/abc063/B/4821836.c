#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

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

int gcd(int a,int b){
	if(!(a % b)) return b;
	return gcd(b,a % b);
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
	nongetpop(array,&(*size));
	return temp;
}

int nongetpop(int *array,int *size){
	realloc(array,sizeof(int) * (*size - 1));
	--(*size);
}

int main(int argc, char const *argv[])
{
	int cnt[259] = { 0 };
	char str[30];
	scanf("%s",str);
	for (int i = 0; i < strlen(str); ++i)	++cnt[(int)str[i]];
	for (int i = 'a'; i <= 'z'; ++i){
		if(cnt[i] > 1){
			puts("no");
			return 0;
		}
	}
	puts("yes");
	return 0;
} ./Main.c: In function ‘pop’:
./Main.c:49:2: warning: implicit declaration of function ‘nongetpop’ [-Wimplicit-function-declaration]
  nongetpop(array,&(*size));
  ^
./Main.c: In function ‘append’:
./Main.c:41:2: warning: ignoring return value of ‘realloc’, declared with attribute warn_unused_result [-Wunused-result]
  realloc(array, sizeof(int) * (*size + 1));
  ^
./Main.c: In function ‘nongetpop’:
./Main.c:54:2: warning: ignoring return value of ‘realloc’, declared with attribute warn_unused_result [-Wunused-result]
  realloc(array,sizeof(int) * (*size - 1));
  ^
./Main.c: In function ‘main’:
./Main.c:62:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^