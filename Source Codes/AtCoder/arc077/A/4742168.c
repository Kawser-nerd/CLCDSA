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

void nongetpop(int *array,int *size){
	realloc(array,sizeof(int) * (*size - 1));
	--(*size);
}

int main(int argc, char const *argv[]){
	int n;
	int *a,b[400007];
	int left = 400000 / 2,right = 400000 / 2 + 1;
	scanf("%d",&n);
	a = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)	scanf(" %d",&a[i]);
	for (int i = 0; i < n; ++i){
		if (i % 2 == (n - 1) % 2)	b[left--] = a[i];
		else	b[right++] = a[i];
	}
	for (int i = left + 1; i < right; ++i)	printf ("%d ",b[i]);
	return 0;
} ./Main.c: In function ‘pop’:
./Main.c:48:2: warning: implicit declaration of function ‘nongetpop’ [-Wimplicit-function-declaration]
  nongetpop(array,&(*size));
  ^
./Main.c: At top level:
./Main.c:52:6: warning: conflicting types for ‘nongetpop’
 void nongetpop(int *array,int *size){
      ^
./Main.c:48:2: note: previous implicit declaration of ‘nongetpop’ was here
  nongetpop(array,&(*size));
  ^
./Main.c: In function ‘append’:
./Main.c:40:2: warning: ignoring return value of ‘realloc’, declared with attribute warn_unused_result [-Wunused-result]
  realloc(array, sizeof(int) * (*size + 1));
  ^
./Main.c: In function ‘nongetpop’:
./Main.c:53:2: warning: ignoring return value of ‘realloc’, declared with attribute warn_unused_result [-Wunused-result]
  realloc(array,sizeof(int) * (*size - 1));
  ^
./Main.c: In function ‘main’:
./Main.c:61:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:63:30: warning: ignoring retur...