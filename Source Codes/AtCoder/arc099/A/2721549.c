#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<string.h>

int main(void){
	int k,n,i;
	int a[100000];

	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",(n-k)/(k-1)+1+((n-k)%(k-1)!=0?1:0));
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d %d",&n,&k);
  ^
./Main.c:11:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:11:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:15:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n",(n-k)/(k-1)+1+((n-k)%(k-1)!=0?1:0));
  ^
./Main.c:15:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:15:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’