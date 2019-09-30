#include<stdio.h>
#include<stdint.h>
 
//0??n???XOR
uint64_t XOR(uint64_t n){
	if(n==-1) return 0;
	else if(n%4==1){
		return 1;
	}
	else if(n%4==3){
		return 0;
	}
	else if(n%4==2){
		return 1^n;
	}
	else{
		return n;
	}
}
	
int main(void){
	uint64_t A,B;
	scanf("%llu %llu",&A,&B);
	
	printf("%llu",XOR(A-1)^XOR(B));
} ./Main.c: In function ‘main’:
./Main.c:23:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 2 has type ‘uint64_t * {aka long unsigned int *}’ [-Wformat=]
  scanf("%llu %llu",&A,&B);
        ^
./Main.c:23:8: warning: format ‘%llu’ expects argument of type ‘long long unsigned int *’, but argument 3 has type ‘uint64_t * {aka long unsigned int *}’ [-Wformat=]
./Main.c:25:9: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 2 has type ‘uint64_t {aka long unsigned int}’ [-Wformat=]
  printf("%llu",XOR(A-1)^XOR(B));
         ^
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu %llu",&A,&B);
  ^