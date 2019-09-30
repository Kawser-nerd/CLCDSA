#include<stdio.h>
int compare_string(const void *a, const void *b){
	while(*(char*)a!=0 && *(char*)a==*(char*)b){
		(char*)a++; (char*)b++;
	}
	if(*(char*)a==0){
		return 1;
	}else{
		return 0;
	}
}

int n, i;
char s[101], t[101];
int main(void){
  scanf("%d%s%s", &n, s, t);
  for(i=0; i<n; i++){
    if(compare_string(s+i, t)){break;}
  }
  printf("%d\n", n+i);
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%s%s", &n, s, t);
   ^