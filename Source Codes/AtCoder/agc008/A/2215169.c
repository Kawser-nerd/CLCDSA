#include<stdio.h>
#include<math.h>

int main(){
  
  long long x,y;

  scanf("%lld%lld",&x,&y);

  if(x==y){
    printf("0\n");
  }
  
  else if(x==0){
    if(y>0){
      printf("%lld\n",y);
    }
    else{
      printf("%lld\n",1-y);
    }
  }

  else if(y==0){
    if(x>=0){
      printf("%lld\n",x+1);
    }
    else{
      printf("%lld\n",-1*x);
    }
  }

  else if(y>=x){
    if(x>=0||y<=0){
      printf("%lld\n",y-x);
    }
    else{
      if(-1*x<=y){
	printf("%lld\n",y+x+1);
      }
      else{
	printf("%lld\n",-y-x+1);
      }
    }
  }
  
  else{
    if(y>=0||x<=0){
      printf("%lld\n",x-y+2);
    }
    else{
      if(x+y>=0){
	printf("%lld\n",x+y+1);
      }
      else{
	printf("%lld\n",-x-y+1);
      }
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^