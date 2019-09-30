#include <stdio.h>

static int numlist[6] = {1,2,3,4,5,6};

void swap(int *a,int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main(int argc, char const *argv[])
{
	long int N;
	scanf("%d",&N);
	N = N % 30;
	for (long i = 0; i < N; ++i)	swap(&numlist[i % 5 + 0], &numlist[i % 5 + 1]);
	for (long i = 0; i < 6; ++i)	printf("%d", numlist[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
  scanf("%d",&N);
        ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^