#include <stdio.h>
#include <string.h>
 
long long int miin(long long int a,long long int b,long long int n){
  long long int i,x,s=-1;
  if(a%n==0){
    return a;
  }else{
    x=a + n - a%n;
    if(x <= b){
      return x;
    }else{
      return s;
    }
  }
}
 
long long int maax(long long int a,long long int b,long long int n){
  long long int i,x,s=-1;
  if(b%n==0){
    return b;
  }else{
    x=b - b%n;
    if(x >= a){
      return x;
    }else{
      return s;
    }
  }
}
 
long long int main(){
  long long int k,i,j;
  scanf("%ld",&k);
  long long int a[k];
  for(i=0;i<k;i++){
    scanf("%ld",&a[i]);
  }
  long long int min,max;
  if(a[k-1]!=2){
    printf("-1\n");
  }else{
    min = 2;
    max = 3;
    for(j=k;j>=2;j--){
      min = miin(min,max,a[j-2]);
      max = maax(min,max,a[j-2]) + a[j-2] - 1;
      if(min == -1){
        j = -1;
      }
    }
    if(min==-1 || max == -1){
      printf("%ld\n",min);
    }else{
      printf("%ld %ld\n",min,max);
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:9: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
   scanf("%ld",&k);
         ^
./Main.c:37:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%ld",&a[i]);
           ^
./Main.c:53:14: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
       printf("%ld\n",min);
              ^
./Main.c:55:14: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
       printf("%ld %ld\n",min,max);
              ^
./Main.c:55:14: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 3 has type ‘long long int’ [-Wformat=]
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&k);
   ^
./Main.c:37:5: warning: ignoring retur...