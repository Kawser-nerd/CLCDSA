#include<stdio.h>
#include<math.h>

int main(){
  int n;
  scanf("%d",&n);
  long long a[n];
  int kai[n];
  int ans=0;

  for(int i=0;i<n;i++){
    kai[i]=0;
  }
  
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
    if(a[i]>=n){
      ans++;
    }
    else{
      kai[a[i]]++;
    }
      
  }

  for(int i=0;i<n;i++){
    if(kai[i]>=i){
      ans=ans+kai[i]-i;
    }
    else{
      ans=ans+kai[i];
    }
  }

  for(int i=0;i<n;i++){
    if(a[i]!=n){
      printf("%d\n",ans);
      return 0;
    }
  }
  printf("0\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a[i]);
     ^