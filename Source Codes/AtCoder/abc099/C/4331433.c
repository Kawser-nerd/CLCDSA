#include <stdio.h>
#include <limits.h>

int FIND_MIN(int basis,int n);
int MIN(int a,int b);
int main(void){
   
   int N;
   
   scanf("%d",&N);
   
   int i;
   int ans = INT_MAX;
   
   for(i = 0;i <= N;i++){
      ans = MIN(ans,FIND_MIN(6,i) + FIND_MIN(9,N - i));
   }

   printf("%d\n",ans);
  
   return 0;
}

int MIN(int a,int b){
   if(a > b){
      return b;
   }
   else {
      return a;
   }
}

int FIND_MIN(int basis,int n){
   
   int count = 0;
   
   while(n > 0){
      count = count + n%basis;
      n = n/basis;
   }
   
   return count;
   
} ./Main.c: In function ‘main’:
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&N);
    ^