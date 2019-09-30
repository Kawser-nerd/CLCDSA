#include<stdio.h>

int main(){
  int i ,j ; 
  int n= 0 ;
  int x = 0 ;
  int wantSum = 0; 
  int count = 0 ; 
  int lestChiled;
  int okChildFlag;
  scanf("%d",&n);
  lestChiled = n ;
  scanf("%d",&x);
  int a[n] ; 
  for( i = 0; i < n ; i++)
  {
    scanf("%d",&a[i]);
    wantSum += a[i];
  }
  int min = 1000000000;
  int max = 0 ;
  for (i = 0 ; i < n ; i++) {
    if(a[i] > max) max = a[i];
    if(a[i] < min)
    {
      okChildFlag = i;
      min = a[i];
    }
    }

  while(x >= min && lestChiled > 1){
    x       -= min; 
    min =           1000000000;
    a[okChildFlag]= 1000000000;
    count++;
    lestChiled--;
    for (i = 0 ; i<n ; i++){
      if(a[i] < min) {
        min = a[i];
        okChildFlag = i;
      }
    }
  }
 if (x == max) count++;
  printf("%d\n",count);
  return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^