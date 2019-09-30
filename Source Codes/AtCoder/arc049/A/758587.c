#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int A,B,C,D,i;
	char S[101];
	scanf("%s",S);
	scanf("%d %d %d %d",&A,&B,&C,&D);
	for(i=0;i<A;i++){
		printf("%c",S[i]);
	}
	printf("\"");
	for(i=A;i<B;i++){
		printf("%c",S[i]);
	}
	printf("\"");
	for(i=B;i<C;i++){
		printf("%c",S[i]);
	}
	printf("\"");
	for(i=C;i<D;i++){
		printf("%c",S[i]);
	}
	printf("\"");
	for(i=D;i<strlen(S);i++){
		printf("%c",S[i]);
	}
	printf("\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:12: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  for(i=D;i<strlen(S);i++){
            ^
./Main.c:27:12: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:27:12: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&A,&B,&C,&D);
  ^