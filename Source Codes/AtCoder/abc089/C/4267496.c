#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int max(int a, int b){
  return a >= b ? a : b;
}
int min(int a, int b){
  return b >= a ? a : b;
}
int sei(int a){
  return a>0 ? a : 0;
}
int factorial(int n) {
    if (n > 0) return n*factorial(n - 1);
		else return 1;
}
int compare_up_int(const void *a, const void *b){
   return *(int*)a - *(int*)b;
}
int compare_down_int(const void *a, const void *b){
   return *(int*)b - *(int*)a;
}
int euclid(int a, int b){
  if(a < b){int tmp = a;a = b;b = tmp;}
  int r = a % b;
  if(r < 0) r += b;
  while(r != 0){
    a = b;b = r;r = a % b;
    if(r < 0) r += b;
  }
  return b;
}

int main(){
  long long int N,count=0,c[5]={0,0,0,0,0};
  scanf("%lld",&N);
  char s[N];
  for(int i=0;i<N;i++) scanf("%s\n",&s[i]);
  for(int i=0;i<N;i++){
    //printf("%c",s[i]);
    if(s[i]=='M')c[0]+=1;
    else if(s[i]=='A')c[1]++;
    else if(s[i]=='R')c[2]++;
    else if(s[i]=='C')c[3]++;
    else if(s[i]=='H')c[4]++;
  }
  for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				count += c[i] * c[j] * c[k];
			}
		}
	}
    printf("%lld",count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&N);
   ^
./Main.c:41:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i=0;i<N;i++) scanf("%s\n",&s[i]);
                        ^