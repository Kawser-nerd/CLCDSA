#include<stdio.h>

int main(){
	long long a, b = 2;
	scanf("%d",&a);
	x:
	if(a % b != 0){
		b ++;
		if(b == a){
			printf("YES\n");
		}else{
			goto x;
		}
	}else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%d",&a);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^